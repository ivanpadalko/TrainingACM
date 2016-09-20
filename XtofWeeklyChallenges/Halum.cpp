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
#define INF 1073741823

typedef struct edge edge;
struct edge{
  int a, b;
  int cost;
};

bool dfs_negative_cycle(int v, int n, int sum, vector<vector<int> >&out_n, vector<vector<int> >&costs, vector<int>&status);
bool has_negative_cycle(int n, vector<vector<int> >&out_n, vector<vector<int> >&costs){
  vector<int>status(n+1, 0);
  for(int v=1; v<=n; v++){
    if(dfs_negative_cycle(v, n, 0, out_n, costs, status) )
        return true;    
  }
  return false;
  
}
bool dfs_negative_cycle(int v, int n, int sum, vector<vector<int> >&out_n, vector<vector<int> >&costs, vector<int>&status){
  if(status[v]==2)
    return false;
  if(status[v]==1)
    return sum<0;
  status[v]=1;
  for(int w : out_n[v]){
    if (dfs_negative_cycle(w, n, sum+costs[v][w], out_n, costs, status) ){
      status[v]=2;
      return true;
    }
  }
  status[v]=2;
  return false;
  
}
vector<vector<int> > decrement_costs(int t, int n, vector<vector<int> >costs){
  for(int i=1; i<=n; i++){
    for(int j=1; j<=n; j++){
      if(costs[i][j]!=INF)
        costs[i][j]-=t;
    }
  } 
  return costs;
}


vector<edge>decrement_costs(int t, int n, vector<edge>edges){
  for(int i=0; i<edges.size(); ++i){
    edges[i].cost -= t;
  }
  return edges;
}
bool has_negative_cycle(int n, vector<edge>&edges){
  vector<int>dist(n+1, 0);
  int s = 1;
  dist[s] = 0;
  bool changed = true;
  for(int i=0; i<=n && changed; i++){
    changed = false;
    for(auto e : edges){
      if(dist[e.b] > (dist[e.a]+e.cost)){
        dist[e.b] = dist[e.a]+e.cost;
        changed=true;
      }
    }    
  }
  return changed;
  
}



int main()
{
  int n, m, a, b, c, i, j, k;
  vector<vector<int> >out_n;
  vector<vector<int> >in_n;
  vector<vector<int> >costs;
  vector<vector<int> >decremented_costs;
  vector<edge>edges;
  vector<edge>decremented_edges;
    
  while(cin >> n >> m){
    out_n.clear();
    out_n.resize(n+1, vector<int>());
    in_n.clear();
    in_n.resize(n+1, vector<int>());
    costs.clear();
    costs.resize(n+1, vector<int>());
    edges.clear();
    decremented_edges.clear();
    for(i=0; i<=n; i++)
      costs[i].resize(n+1, INF);
    int maxim = -INF;
    edge e;
    for(k=0; k<m; k++){
      cin >> a >> b >> c;
      out_n[a].push_back(b);
      in_n[b].push_back(a);
      costs[a][b] = c;
      maxim = max(maxim, c);
      e.a = a;
      e.b = b;
      e.cost = c;
      edges.push_back(e);
    }
    int st, en, mi;
    st = 1;
    en = maxim+1;
    decremented_edges = decrement_costs(1, n, edges);
    if(has_negative_cycle(n, decremented_edges)){
      cout << "No Solution" << endl;
      continue;
    }
    decremented_edges = decrement_costs(maxim+1, n, edges);
    if(!has_negative_cycle(n, decremented_edges)){
      cout << "Infinite" << endl;
      continue;
    }
    while(st < en){
      mi = (st+en+1)/2;
      decremented_edges = decrement_costs(mi, n, edges);
      if(!has_negative_cycle(n, decremented_edges))
        st = mi;
      else
        en = mi-1;      
    }
    cout << st << endl;
    /*
    int st, en, mi;
    st = 1;
    en = maxim; 
    decremented_costs = decrement_costs(1, n, costs);
    if(has_negative_cycle(n, out_n, decremented_costs) ){
      cout << "No Solution" << endl;
      continue;
    }
    decremented_costs = decrement_costs(maxim+1, n, costs);
    if(!has_negative_cycle(n, out_n, decremented_costs) ){
      cout << "Infinite" << endl;
      continue;
    }
    while(st < en){
      mi = (st+en+1)/2;
      decremented_costs = decrement_costs(mi, n, costs);
      if(!has_negative_cycle(n, out_n, decremented_costs) )
        st = mi;
      else
        en = mi-1;      
    }
    cout << st << endl;
    */
  }

	return 0;
}


