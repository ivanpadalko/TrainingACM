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

const int N = 1e5; // limit for array size
int n; // array size
int t[2*N];

void build(){ // build the tree
  for(int i=n-1; i>0; --i)
    t[i] = t[i<<1] + t[i<<1|1];  
}
void modify (int p, int value){ // set a value at position p
  for (t[p+=n] = value; p>1; p>>=1)
    t[p>>1] = t[p] + t[p^1];  // p^1 is the other son of p's parent  
}
int query(int l, int r){ // for the sum of interval [l, r)
  int res=0;
  for (l+=n, r+=n; l<r; l>>=1, r>>=1){
    if(l&1)
      res += t[l++];
    if(r&1)
      res += t[--r];
  }
  return res;  
}




int main()
{
  scanf("%d", &n);
  for (int i=0; i<n; ++i)
    scanf("%d", t+n+i);
  build();
  modify(0, 1);
  printf("%d\n", query(3, 11));
  
	return 0;
}


