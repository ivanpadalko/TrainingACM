/*
http://www.spoj.com/problems/GOODA/
Please refer to the link above.

Algorithm: SCC and longest path in a weighted direct acyclic graph

  - We first reduce the graph to the one formed by its strongest connected components,
  for if the team pass through a given city, then it can pass through any other city in the same strongly connected component without trouble
  - for each vertex v in the reduced graph, we compute the maximal distance from a fixed vertice s (the source) to v using a dynamic programming approach
  
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

vector<vector<int>>g;
vector<vector<int>>g_rev;
vector<int>f;
vector<long long>f_red;
vector<vector<int>>g_red_rev;

void dfs(stack<int>&s, int v, vector<bool>&visited){
  if(visited[v])
    return;
  visited[v] = true;
  for(int x : g[v]){
    dfs(s, x, visited);
  }
  s.push(v);
}
void dfs(int v, int cp, vector<int>&my_comp){
  if(my_comp[v]!=-1)
    return;
  my_comp[v] = cp;
  for(int x : g_rev[v])
    dfs(x, cp, my_comp);
}

vector<long long>memo;
long long max_length(int s, int v){
  if(memo[v]!=-1)
    return memo[v];
  if(v==s){
    memo[v] = f_red[s];
    return memo[v];
  }
  long long maxim = -2;
  for(int x : g_red_rev[v]){
    if(x==v)
      continue;
    long long cur = max_length(s, x);
    if(cur!=-2)
      maxim = max(cur, maxim);
  }
  if(maxim==-2)
    return -2;
  memo[v] = maxim+f_red[v];
  return memo[v];
}


int main()
{
  int n, m, s, e, a, b;
  cin >> n >> m >> s >> e;
  g.resize(n+1, vector<int>());
  g_rev.resize(n+1, vector<int>());
  f.resize(n+1, 0);
  for(int i=1; i<=n; i++)
    cin >> f[i];
  for(int i=0; i<m; i++){
    cin >>  a >> b;
    g[a].push_back(b);
    g_rev[b].push_back(a);
  }
  // we do a post-order traversal of the original graph
  stack<int>my_s;
  vector<bool>visited(n+1, false);
  for(int i=1; i<=n; i++)
    if(!visited[i])
      dfs(my_s, i, visited);
  
  // then we do a pre-order traversal of the reversed graph and find the component of each vertex
  vector<int>my_comp(n+1, -1); 
  int cp = 1;
  while(!my_s.empty()){
    int v = my_s.top();
    //cout << v << " : " << my_comp[v] << endl;
    my_s.pop();
    if(my_comp[v]==-1){
      dfs(v, cp, my_comp); // uses the reversed graph (g_rev)
      cp++;      
    }
  }

  // we now compute the reverse reduced graph
  int ncp = cp-1;
  g_red_rev.resize(ncp+1, vector<int>());
  for(int i=1; i<=n; i++){
    for(int x : g[i]){
        g_red_rev[my_comp[x]].push_back(my_comp[i]);
    }
  }
  f_red.resize(ncp+1, 0);
  for(int i=1; i<=n; i++)
    f_red[my_comp[i]] += f[i];
  // we have computed the reduced graph

  // now we use a dynamic programming algorithm to find the longest path in a DAG
  memo.resize(ncp+1, -1);
  cout << max_length(my_comp[s], my_comp[e]) << endl; // still need to check if length is -2
  // in the problem, we already know that there is a way to get from s to e, so we don't need to worry to check this case
  
	return 0;
}


