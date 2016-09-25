/*
http://www.spoj.com/problems/FANCY/
Girls usually give only missed calls to their boyfriends and they want them to call back. These boys are now busy with their engineering subjects and cannot remember all girl friends’ mobile number. Because of this, girls make it easy for them by having fancy mobile numbers. A fancy mobile number may contain many continuous digits in it.

For example 9994442200 is a fancy mobile number because the boy can remember simply as triple nine, triple four, double two and double zero. As they are engineering students they do think different. One of the engineering students can spell the above number as double nine, nine, four, double four, two, two, double zero.

The number 100 has only 2 possibilities as it can be spelt as either one, zero, zero (or) one, double zero

Given a mobile number find the number of possibilities that the number can be remembered.

Algorithm: Math

  - We look for blocks of repeated numbers
  - A block of k digits an be spelt in 2^{k-1}. The recurrence relation is n_p(k) = n_p(k-1)+...+n_p(0), which yields n_p(k) = 2^(k-1)
  - We keep track of the exponents resulting from each block and add them in the end, so we can compute (1<<expo), which the desired answer.

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


int main()
{
	int T;
	scanf("%d", &T);
  char s[40];
	for (int ind = 0; ind < T; ind++) {
    scanf("%s", s);
    int repeated = 0;
    int expo = 0;
    for(int i=1; i<strlen(s); i++){
      if(s[i]==s[i-1]){
        repeated++;
      }
      else{
        expo += repeated;
        repeated=0;
      }
    }
    expo+=repeated;
    printf("%d\n", 1<<expo);
  }
	return 0;
}


