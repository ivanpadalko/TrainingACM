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
  int n, m;
  cin >> n >> m;
  vector<string>tab(m, "");
  vector<pair<int,int> >cpos;
  for(int i=0; i<m; i++){
    cin >> tab[i];
    for(int j=0; j<n; j++)
      if(tab[i][j]=='C')
        cpos.push_back(pair<int,int>(i,j));
  }  
  //assert(cpos.size()==2);
  vector<vector<bool> >visited(m, vector<bool>());
  for(int i=0; i<m; i++)
    visited[i].resize(n, false);
  vector<vector<int> >dist(m, vector<int>());
  for(int i=0; i<m; i++)
    dist[i].resize(n, -1);
  //cout << "test" << endl;
  queue<pair<int,int> >myqueue;
  myqueue.push(cpos[0]);
  dist[cpos[0].first][cpos[0].second]=0;
  while(!myqueue.empty()){
      pair<int,int>cur = myqueue.front();
      //cout << cur.first << " " << cur.second << endl;
      myqueue.pop();
      int x=cur.first, y=cur.second;
      int i,j;
      i=0;
      while(x-i>=0 && tab[x-i][y]!='*'){
        if(dist[x-i][y]==-1){
          dist[x-i][y]  = dist[x][y]+1;
          myqueue.push(pair<int,int>(x-i,y));
        } i++;        
      }
      i=0;
      while(x+i<m && tab[x+i][y]!='*'){
        if(dist[x+i][y]==-1){
          dist[x+i][y]  = dist[x][y]+1;
          myqueue.push(pair<int,int>(x+i,y));
        } i++;
      }
      j=0;
      while(y-j>=0 && tab[x][y-j]!='*'){
        if(dist[x][y-j]==-1){
          dist[x][y-j]  = dist[x][y]+1;
          myqueue.push(pair<int,int>(x,y-j));
        } j++;
      }
      j=0;
      while(y+j<n && tab[x][y+j]!='*'){
        if(dist[x][y+j]==-1){
          dist[x][y+j]  = dist[x][y]+1;
          myqueue.push(pair<int,int>(x,y+j));
        } j++;
      } 
  }  
  cout << dist[cpos[1].first][cpos[1].second]-1 << endl;
	return 0;
}


