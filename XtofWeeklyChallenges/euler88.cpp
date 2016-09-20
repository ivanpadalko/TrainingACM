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
#define MAX 100100
bool is_prime[MAX];
int primes[MAX];
int n_p;
int foo(int n){
  if(n==1)
    return 1;
  int ans = n;
  for(int i=0; i<n_p && n>1; i++){
    while(n%primes[i]==0){
      ans -= (primes[i]-1);
      n/=primes[i];
    }    
  }
  if(n>1)
    ans -= (n-1);
  return ans;  
}


int main()
{
  const int N = 12000;
  
  // fist, we fill the prime table till a certain reach
  // it won't be very high. I'll first pick it as 400
  const int reach = 400;
  is_prime[1] = false;
  for(int i=2; i<=reach; i++)
    is_prime[i] = true;
  n_p=0;
  for(int i=2; i<=reach; i++){
    if(is_prime[i]){
      primes[n_p++] = i;
      for(int j=2*i; j<=reach; j+=i)
        is_prime[j] = false;
    }
  }
  for(int i=1; i<= 16; i++)
    cout << "i = " << i << ", foo(i) = " << foo(i) << endl;
  int sum = 0;
  int max = 1;
  int i;
  for(i=4; i<=100000; i++){
    int v = foo(i);
    if(v>max){
      sum += i;
      cout << i << endl;
      max = v;
      if(v>=N)
        break;
    }    
  }
  cout << "sum = " << sum << " and i = " << i << endl;
  cout << "i = " << i << ", foo(i) = " << foo(i) << endl;  
  
  // we want to calculate  f(n)  = n - (p1-1)-(p2-1)-...-(pk-1) till we pass N. We hope we can do so if we compute f(n) for n in range(100000)

  
  

	return 0;
}


