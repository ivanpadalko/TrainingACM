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
const int N = 1e5;
int n;
int h;
int t[2*N];
int d[N];

void apply(int p, int value){
  t[p] += value;
  if (p < n)
    d[p] += value;
}
void build(int p){
  while(p>1){
    p >>= 1;
    t[p] = max(t[p<<1], t[p<<1|1]) + d[p];
  }
}
void push(int p){
  for (int s = h; s>0; --s){
    int i = p>>s;
    if(d[i]!=0){
      apply(i<<1, d[i]);
      apply(i<<1, d[i]);
      d[i]=0;
    }    
  }  
}
void inc(int l, int r, int value){
  l+=n, r+=n;
  int l0 - l, r0=r;
  for(; l<r; l>>=1, r>>=1){
    if(l&1) apply(l++, value);
    if(r&1) apply(--r, value);
  }
  build(l0);
  build(r0 - 1);
}
int query(int l, int r){
  l += n, r += n;
  push(l);
  push(r-1);
  int res = -2e9;
  for(; l<r; l>>=1, r>>=1){
    if(l&1)
      res = max(res, t[l++]);
    if(r&1)
      res = max(t[r--], res);
  }  
}

int main()
{
  cin >> n;
  h = sizeof(int) * 8 - __builtin_clz(n);


	return 0;
}


