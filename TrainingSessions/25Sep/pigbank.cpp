/*
http://www.spoj.com/problems/PIGBANK/

Before ACM can do anything, a budget must be prepared and the necessary financial support obtained.
The main income for this action comes from Irreversibly Bound Money (IBM).
The idea behind is simple.
Whenever some ACM member has any small money, he takes all the coins and throws them into a piggy-bank.
You know that this process is irreversible, the coins cannot be removed without breaking the pig.
After a sufficiently long time, there should be enough cash in the piggy-bank to pay everything that needs to be paid.
But there is a big problem with piggy-banks.
It is not possible to determine how much money is inside.
So we might break the pig into pieces only to find out that there is not enough money.
Clearly, we want to avoid this unpleasant situation.
The only possibility is to weigh the piggy-bank and try to guess how many coins are inside. Assume that we are able to determine the weight of the pig exactly and that we know the weights of all coins of a given currency. Then there is some minimum amount of money in the piggy-bank that we can guarantee. Your task is to find out this worst case and determine the minimum amount of cash inside the piggy-bank. We need your help. No more prematurely broken pigs! 

Algorithm: Dynamic programming

  minimum_price (w) = min (p[i]+minimum_price(w-w[i]) for i such that minimum_price(w-w[i])!=-2)
  if there is no such i, then we return -2.
  Thus, minimum_price(w) is the minimum possible price for a given price w
  If there is no possible combination of coins that sums to w, then this function returns -2
  We use a top-down approach to implement this dynamic programming algorithm.

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
#define MAX 510
#define PAX 10010
int n;
long long p[MAX];
long long w[MAX];
long long ans[PAX];
long long foo(int W){
  if(W<0)
    return -2;
  if(W==0)
    return 0;
  if(ans[W]!=-1)
    return ans[W];
  else{
    int minim = -2;
    int cur, prev;
    for(int i=0; i<n; i++){
      prev = foo(W-w[i]);
      if(prev!=-2){
        cur = prev + p[i];
        if(minim==-2)
          minim = cur;
        else
          minim = min(minim, cur);
      }
    }
    ans[W] = minim;
    return minim;    
  }
}


int main()
{
	int T;
	cin >> T;

	for (int ind = 0; ind < T; ind++) {
    int e, f;
    cin >> e >> f;
    int W = f-e;
    cin >> n;
    for(int i=0; i<n; i++)
      cin >> p[i] >> w[i];
    for(int i=0; i<=W; i++)
      ans[i] = -1;
    ans[0] = 0;
    long long answ = foo(W);
    if(answ==-2)
      cout << "This is impossible." << endl;
    else
      cout << "The minimum amount of money in the piggy-bank is " << answ << "." << endl; 
    
	}
	return 0;
}


