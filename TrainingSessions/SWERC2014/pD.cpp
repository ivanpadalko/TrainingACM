/*
Ford-Fulkerson algorithm

1) Initialize Maximal Matching M as empty.
2) While there exists an Augmenting Path p
     Remove matching edges of p from M and add not-matching edges of p to M
     (This increases size of M by 1 as p starts and ends with a free vertex)
3) Return M. 
*/
#include<iostream>
#include<vector>
#include<string.h>
#define MAX 10100

using namespace std;

vector<int>g[MAX];
int m1[MAX];
int m2[MAX];
int visited[MAX];

bool has_augmenting_path(int v){
  // has augmenting path starting at v?
  if(visited[v]) return false;
  visited[v]=true;
  for(auto x : g[v]){
    if(m2[x]==-1 || has_augmenting_path(m2[x]) ){
      m2[x] = v;
      m1[v] = x;
      return true;
    }
  }
  return false;
}

int main()
{
  int n, m;
  cin >> n >> m;
  int a, b;
  for(int i=0; i<m; i++){
    cin >> a >> b;
    g[a].push_back(b);    
  }
  memset(m1, false, sizeof(m1));
  memset(m2, -1, sizeof(m2));
  int cnt=0;
  for(int i=0; i<n; i++){
    memset(visited, false, sizeof(visited));
    if(has_augmenting_path(i))
      cnt++;
  }
  if(cnt==n)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  
}