#include<iostream>
#include<vector>
#include<set>
using namespace std;
#define MAX 10100
#define INF 1<<30

int dist[MAX];

struct compare{
  bool operator()(const int& i, const int& j) const{
    if(dist[i]<dist[j])
      return true;
    else if(dist[i]>dist[j])
      return false;
    else
      return i<j;
  }  
};

int dfs(int v, vector<int>&visited, const vector<vector<int> >&g, const vector<vector<int> >&c){
  if(visited[v])
    return 0;
  visited[v]=true;
  int y,cost;
  int sum=0;
  for(int i=0; i<g[v].size(); i++){
    y = g[v][i];
    cost  = c[v][i];
    if(dist[v]==dist[y]+cost){
      sum+=cost;
      sum+=dfs(y, visited, g, c);
    }
  }
  return sum;    
}



int main(){
  int n, m, a, b, cost, cur, y;
  cin >> n >> m;
  vector<vector<int> >g(n, vector<int>());
  vector<vector<int> >c(n, vector<int>());
  for(int i=0; i<m; i++){
    cin >> a >> b >> cost;
    g[a].push_back(b);
    c[a].push_back(cost);  
    g[b].push_back(a);
    c[b].push_back(cost);
  }
  set<int, compare>myset;
  for(int i=0; i<n; i++)
    dist[i]=INF;
  dist[0]=0;
  myset.insert(0);
  while(!myset.empty()){
    cur = *myset.begin();
    myset.erase(cur);
    for(int i=0; i<g[cur].size(); i++){
      y = g[cur][i];
      cost = c[cur][i];
      if(dist[y] > dist[cur] + cost){
        if(myset.find(y)!=myset.end())
          myset.erase(y);
        dist[y] = dist[cur]+cost;
        myset.insert(y);
      }
    }    
  }
  //for(int i=0; i<n; i++)
    //cout << "dist[" << i << "] = " << dist[i] << ", ";
  //cout << endl;
  vector<int>visited(n, false);
  cout << 2*dfs(n-1, visited, g, c) << endl;
  
}