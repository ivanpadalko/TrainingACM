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


int main()
{
  int w[10];
  int n;
  while(cin >> n){
    for(int i = 1; i<=n; i++)
      cin >> w[i];
    if(n<=3){
      cout << 1024 << endl;
      continue;
    }
    else if(n==4){
      int sum = w[1]+w[2]+w[3]+w[4];
      bool good = false;
      for(int i=1; i<=n; i++){
        if((sum-w[i])%1024==0){
          good = true;
          break;
        }
      }
      if(good)
        cout << 1024;
      else{
        int cur;
        int max = 0;
        for(int i=1; i<=3; i++){
          for(int j=i+1; j<=4; j++){
            cur = w[i]+w[j];
            if(cur%1024==0)
              cur = 1024;
            else
              cur = cur%1024;
            if(cur > max)
              max = cur;            
          }
        }
        cout << max  << endl;        
      }
    }
    else if(n==5){
      int cur;
      int max = 0;
      int sum = w[1]+w[2]+w[3]+w[4]+w[5];
      for(int i=1; i<=5; i++){
        for(int j=i+1; j<=5; j++){
          if((sum-w[i]-w[j]) % 1024 == 0){
            if((w[i]+w[j])%1024==0)
              cur = 1024;
            else
              cur = (w[i]+w[j])%1024;
            if(cur > max)
              max = cur;
          }
        }
      }
      cout << max<< endl;
    }
    else
      cout << "what" << endl;    
	}
	return 0;
}


