#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
using namespace std;

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }

const int INF = 1 << 29;
typedef long long ll;

inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n >> b) & 1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while (n && ++res) n -= n&(-n); return res; }

template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }
/////////////////////////////////////////////////////////////////////
#define MAX 1000010
// we will determine all primes smaller than 10^6
#define LM 50
bool is_prime[MAX];
long long primes[MAX];
long long fac[LM]; // 50 > log_2 (MAX)
int ex[LM];

long long pot(long long n, int p){
  long long ans = 1;
  for(int i=0; i<p; i++)
    ans *= n;
  return ans;  
}

int main()
{
	int T;
  long long n;
	cin >> T;
  
  is_prime[1] = false;
  for(int i=2; i<MAX; i++)
    is_prime[i] = true;
  for(int i=2; i<=MAX; i++){
    if(is_prime[i]){
      for (int j=2*i; j<=MAX; j+=i)
        is_prime[j] = false;      
    }    
  }
  int n_p=0;
  for(int i=2; i<=MAX; i++){
    if(is_prime[i])
      primes[n_p++] = i;    
  }
  
	for (int ind = 0; ind < T; ind++) {
    cin >> n;
    long long n_temp = n;      
    int k=0;      
    if(n==1 || n==2){
      cout << "Case " << ind + 1 << ": Impossible" << endl;
      continue;
    }
    for (int i=0; i<n_p; i++){
      if(n_temp==1)
        break;
      if(n_temp%primes[i]==0){
        fac[k] = primes[i];
        ex[k] = 1;
        n_temp/=primes[i];
        while(n_temp%primes[i]==0){
          ex[k]++;
          n_temp/=primes[i];
        }
        k++;
      }        
    }
    if(n_temp>1){
      if(n_temp <= MAX)
        cout << "couldnt detect all primes !!!!!" << endl;
      else{
        fac[k] = n_temp;
        ex[k] = 1;
        k++;
      }
    }     
    // now we have factored n;
    
    if(k==1){
      cout << "Case " << ind + 1 << ": Impossible" << endl;
      continue;       
    }
    int i_min = 0;
    long long p_min = fac[i_min];
    long long dif_max = n/p_min - pot(p_min, ex[i_min]);
    long long p, dif;
    for(int i=1; i<k; i++){
      p = fac[i];
      dif = n/p - pot(p, ex[i]);
      if (dif > dif_max){
        i_min = i;
        dif_max =dif;
        p_min = p;
      } 
    }
    cout << "Case " << ind + 1 << ": " << n/fac[i_min] << " " << pot(fac[i_min], ex[i_min]) << endl;
	}
	return 0;
}


