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
#include <unordered_set>
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
#define MAXR 30100
#define MAXS 60100
typedef struct hseg hseg;
typedef struct rec rec;
struct hseg{
  int a, b;
  int h;
  int i; // rectangle index
  bool is_upper;
};
bool compare(hseg& s1, hseg& s2){
  if (s1.h == s2.h){
    if(s1.is_upper == s2.is_upper)
      return s1.i <s2.i;
    return s1.is_upper;
  }
  return s1.h < s2.h;
}
ostream& operator << (ostream &o, const hseg& s){
  o << "a: " << s.a << "\tb: " << s.b << "\th: " << s.h << endl;
  return o;
}

struct rec{
  int x1, y1, x2, y2;  
};
rec recs[MAXR];
hseg segs[MAXS];


int main()
{
	int T;
	cin >> T;
  int n, k;
  
	for (int ind = 0; ind < T; ind++) {
    cin >> n >> k;
    for(int i=0; i<n; i++){
      cin >> recs[i].x1 >> recs[i].y1 >> recs[i].x2 >> recs[i].y2;
      segs[2*i].a = recs[i].x1;
      segs[2*i].b = recs[i].x2;
      segs[2*i].h = recs[i].y1;
      segs[2*i].i = i;
      segs[2*i].is_upper = false;
      segs[2*i+1].a = recs[i].x1;
      segs[2*i+1].b = recs[i].x2;
      segs[2*i+1].h = recs[i].y2+1;
      segs[2*i+1].i = i;
      segs[2*i+1].is_upper = true;    
    }
    sort(segs, segs+2*n, compare);
    for (int i=0; i<2*n; i++){
      cout << segs[i];
    }
    int cur_k=0;
    unordered_set<int>active_recs;
    for (int i=0; i<2*n; i++){
      if(segs[i].is_upper){
        active_recs.erase(segs[i].i);
        cur_k--;
      }
      else{
        active_recs.insert(segs[i].i);
        cur_k++;
      }
      if(cur_k>=k){
        cout << "i =" << i << ": we are interested in the range: " << "h1 = " << segs[i].h << ", h2 = " << segs[i+1].h << endl;
      }
      cout << "cur_k = " << cur_k << endl;
    }
    

    
		cout << "Case " << ind + 1 << ": "  << endl;
	}
	return 0;
}


