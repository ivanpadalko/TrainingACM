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
#define INF 2147483647

bool find_cycle(int v, vector<vector<int> >&out_n, int &n, vector<int>&status);
bool is_DAG(vector<vector<int> >&out_n, int &n){
  vector<int>status(n+1, 0);
  for(int v=1; v<=n; v++){
    if (find_cycle(v, out_n, n, status))
       return false;
  }
  return true;
}
bool find_cycle(int v, vector<vector<int> >&out_n, int &n, vector<int>&status){
  if(status[v]==1)
    return true;
  status[v]=1;
  for(int w : out_n[v]){
    if (find_cycle(w, out_n, n, status))
      return true;
  }
  status[v] = 2;
  return false;
}
bool can_fill_till_x(int v, int x, int n, vector<bool>&visited, vector<vector<int> >&in_n, vector<vector<int> >&out_n, vector<vector<int> >&costs);
bool can_be_done_with(int x, int n, vector<vector<int> >&in_n, vector<vector<int> >&out_n, vector<vector<int> >&costs){
  //cout << "we now try with x = " <<  x << endl;
  vector<bool>visited(n+1, false);
  for(int i=1; i<=n; i++){
    if ( !can_fill_till_x(i, x, n, visited, in_n, out_n, costs) )
      return false;
  }
  return true; 
  
}
bool can_fill_till_x(int v, int x, int n, vector<bool>&visited, vector<vector<int> >&in_n, vector<vector<int> >&out_n, vector<vector<int> >&costs){
  if(visited[v]){
    for (int w : in_n[v]){
      if(costs[w][v]<x){
        //cout << "x = " << x << " w = " << w << " cost = " << costs[w][v] << endl;
        return false;
      }
    }
    return true;
  }
  int minim = INF;
    //int w_minim=-1;
  for (int w : in_n[v] ){ 
    //if(costs[w][v] < minim)
     // w_minim = w;
    minim = min(minim, costs[w][v]);
  }
  for (int w : in_n[v]){
    //cout << "costs["<<w<<"]["<<v<<"] = " << costs[w][v] << " is updated to " << costs[w][v] + x-minim  << endl;
    costs[w][v] = costs[w][v] + x-minim ;
  }
  for(int w : out_n[v]){
    //cout << "costs["<<v<<"]["<<w<<"] = " << costs[v][w] << " is updated to " << costs[v][w] + minim - x  << endl;
    costs[v][w] = costs[v][w] + minim-x;
  }
  //cout << "for the node " << v << " we got minim = " << minim << " and w_minim = " << w_minim << endl;
  visited[v] = true;
  for (int w : out_n[v]){
    //if(!visited[w])
      //cout << w << " descends from " << v << endl;
    if( !can_fill_till_x(w, x, n, visited, in_n, out_n, costs) )
      return false;
  }
  return true;
}



int main()
{
  int n, m, a, b, c, i, j, k;
  vector<vector<int> >out_n;
  vector<vector<int> >in_n;
  vector<vector<int> >costs;
  vector<vector<int> >copy_of_costs;
  
    
  while(cin >> n >> m){
    out_n.clear();
    out_n.resize(n+1, vector<int>());
    in_n.clear();
    in_n.resize(n+1, vector<int>());
    costs.clear();
    costs.resize(n+1, vector<int>());
    for(i=0; i<=n; i++)
      costs[i].resize(n+1, INF);
    int maxim = -INF;
    for(k=0; k<m; k++){
      cin >> a >> b >> c;
      out_n[a].push_back(b);
      in_n[b].push_back(a);
      costs[a][b] = c;
      maxim = max(maxim, c);
    }
    if (is_DAG(out_n, n)){
      cout << "Infinite" << endl;
      continue;
    }
    copy_of_costs = costs;
    if(!can_be_done_with(1, n, in_n, out_n, copy_of_costs) ){
      cout << "No Solution" << endl;
      continue;
    }
    int st, en, mi;
    st = 1;
    en = maxim;
    while(st < en){
      copy_of_costs = costs;
      mi = st + en - (st+en)/2;
      if(can_be_done_with(mi, n, in_n, out_n, copy_of_costs) )
        st = mi;
      else
        en = mi-1;      
    }
    cout << st << endl;
    
  }

	return 0;
}


