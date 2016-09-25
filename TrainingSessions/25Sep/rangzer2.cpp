/*
http://www.spoj.com/problems/RANGZER2/
You are given two integers a and b. Find the number of zeroes in the digits of all the numbers in the range [a,b] inclusive.

Algorithm: Ad-hoc

State: Accepted

*/



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

long long foo(int x){
  // computes the number of zeros in the interval [1, x-1]
  int d[20];
  int c_x=x;
  int i = 0;
  while(c_x > 0){
    d[i++] = c_x%10;
    c_x/=10;
  }
  int n_d = i; // number of digits of x
  long long sum = 0;
  // number of zeros in [1, 100...0), with (n_d-1) zeros
  long long pot = 1;
  for(i=1; i<n_d-1; i++){
    sum += (i*9*pot);
    pot*=10;
  }
  
  // number of zeros in [100..00, d[n_d-1]00...00), with (n_d-1) zeros
  sum += (d[n_d-1]-1)*(n_d-1)*pot;

  // number of zeros in [d[n_d-1]00...00, d[n-d-1]d[n_d-2]...d[1]d[0])
  int n_zeros = 0;
  for(i=n_d-2; i>=0; i--){
    // at each loop, we compute the number of zeros in the interval [d[n_d-1]...d[i+1]00...0, d[n_d-1]...d[i]00...0)
    if(d[i]==0)
      n_zeros++;
    else{
      // if d[i]!=0, 10^i is the number of zeros appearing in the i-th position
      sum += pot;
    }
    // n_zeros * d[i]*10^i is the number of zeros appearing in the positions from i+1 to n_d-1
    sum += n_zeros*d[i]*pot;
    pot/=10;
    // d[i]*10^{i-1} is the number of zeros appeatin in the positions from 0 to i-1.
    // As there are i such positions, we sum this number multiplied by i
    sum += (d[i]*i*pot);
  }
  return sum;
}

int main()
{
	int T;
	cin >> T;

	for (int ind = 0; ind < T; ind++) {
    int a, b;
    cin >> a >> b;
    long long ans = foo(b+1) - foo(a);
    cout << ans << endl;
  }
	return 0;
}


