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
#define MAX 100
#define PRIME 1000000007


class mat{
  public:
    long long a, b, c, d;
  // a b
  // c d
    mat(long long a, long long b, long long c, long long d) : a(a) , b(b), c(c), d(d){
      }
};
/*(mat prod(mat m1, mat m2){
  mat ans(m1.a *m2.a + m1.b*m2.c, m1.a*m2*b + m1.b*m2.d, m1.c*m2.a+m1.d*m2.c, m1.c*m2.b+m1.d*m2.d);
  return ans;  
}*/
mat operator*(const mat& m1, const mat& m2)
{
  mat ans((m1.a *m2.a + m1.b*m2.c)%PRIME, (m1.a*m2.b + m1.b*m2.d)%PRIME, (m1.c*m2.a+m1.d*m2.c)%PRIME, (m1.c*m2.b+m1.d*m2.d)%PRIME);
  return ans; 
}


long long fib(int n, long long x){
  long long f[MAX];
  if (n>=MAX)
    return -1;
  f[0]=0;
  f[1]=1;
  for(int i=2; i<=n; i++){
    f[i] = f[i-1] + f[i-2];
    if(f[i] > 2*x)
      return -1;
  }
  return f[n];
}

mat pow(mat m, int n){
  if(n==0){
    mat id(1, 0, 0, 1);
    return id;    
  }
  if(n&1){
    mat x = pow(m, n/2);
    return x * x * m;    
  }
  else{
    mat x = pow(m, n /2);
    return x*x;    
  }  
}

int main()
{
	int T;
	cin >> T;
  long long n, x, m, y, k;
  long long f_n, f_np, f_m, f_mp, f_k, f_kp;
  long long a, b;
	for (int ind = 0; ind < T; ind++) {
    cin >> n >> x >> m >> y >> k; 
    bool impossible=false;;
    f_n = fib(n, x);
    if(f_n==-1)
        impossible=true;
    f_m = fib(m, y);
    if(f_m==-1)
      impossible=true;
    if(impossible){
      cout << "Impossible" << endl;
      continue;
    }
    f_mp = fib(m+1, y);
    f_np = fib(n+1, x);
    long long den = f_mp*f_n - f_m*f_np;
    long long num = f_mp*x - f_np*y;
    if(den==0 || num%den!=0)
      impossible = true;
    else
      b = num/den;
    den *= (-1);
    num = f_m*x - f_n*y;
    if(den==0 || num%den!=0)
      impossible = true;
    else
      a = num/den;
    if(a<0 || b<0)
      impossible = true;
    if(impossible){
      cout << "Impossible" << endl;
      continue;
    }
    mat b_m(1, 1, 1, 0);
    mat m_k = pow(b_m, k);
    f_kp = m_k.a;
    f_k = m_k.b;
    long long ans = f_kp*a + f_k*b;
    ans%=PRIME;
    cout << ans << endl;
	}
	return 0;
}


