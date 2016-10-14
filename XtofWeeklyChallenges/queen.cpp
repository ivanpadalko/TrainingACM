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
#define MAX 1010
char tab[MAX][MAX];
int dist[MAX][MAX];
int dir[MAX][MAX];

int main()
{
  int n, m;
  int T;
  cin >> T;
  for(int ind=0; ind<T; ind++){
    cin >> n >> m;
    pair<int,int>s;
    pair<int,int>f;
    for(int i=0; i<m; i++){
      for(int j=0; j<n; j++){
        cin >> tab[i][j];
        if(tab[i][j]=='S')
          s = pair<int,int>(i,j);
        else if(tab[i][j]=='F')
          f = pair<int,int>(i,j);
      }
    }  
    //assert(cpos.size()==2);
    for(int i=0; i<m; i++){
      for(int j=0; j<n; j++){
        dist[i][j]=INF;
        dir[i][j]=-1;
      }
    }
    //cout << "test" << endl;
    deque<int>myqueue;
    myqueue.push_front(n*s.first+s.second);
    dist[s.first][s.second]=0;
    dir[s.first][s.second]=0;
    bool cont=true;
    while(cont && !myqueue.empty()){
        int curi = myqueue.back();
      //cout << cur.first << " " << cur.second << endl;
        myqueue.pop_back();
        int x=curi/n, y=curi%n;
        cout << "(" << x << ", " << y << "), dir = " << dir[x][y] << endl;
        if(dist[x][y]!=INF)
          continue;
        cout << "again : (" << x << ", " << y << "), dir = " << dir[x][y] << endl;
        if(dir[x][y]==1)
          dist[x][y] = 
          
          if(x-1>=0 && tab[x-1][y]!='X'){
              dir[x-1][y] = 1;
              if(dir[x][y]==1){
                myqueue.push_back(n*(x-1)+y);
              }else{
                myqueue.push_front(n*(x-1)+y);
              }
              if(x-1==f.first && y==f.second){
                cont=false;
              }
          }
          if(x+1<m && tab[x+1][y]!='X'){
              dir[x+1][y]=1;
              if(dir[x][y]==1){
                myqueue.push_back(n*(x+1)+y);
              }else{
                myqueue.push_front(n*(x+1)+y);
              }              
              if(x+1==f.first && y==f.second){
                cont=false;
              }
          }
          if(y-1>=0 && tab[x][y-1]!='X'){
              dir[x][y-1] = 2;
              if(dir[x][y]==2){
                myqueue.push_back(n*(x)+y-1);
              }else{
                myqueue.push_front(n*(x)+y-1);
              }

              if(x==f.first && y-1==f.second){
                cont=false;
              }
          }
          if(y+1<n && tab[x][y+1]!='X'){
              dir[x][y+1] = 2;
              if(dir[x][y]==2){
                myqueue.push_back(n*(x)+y+1);
              }else{
                myqueue.push_front(n*(x)+y+1);
              }
              if(x==f.first && y+1==f.second){
                cont=false;
              }
          } 
        
          if(x+1<n && y+1<m && tab[x+1][y+1]!='X'){
              dir[x+1][y+1] = 3;             
              if(dir[x][y]==3){
                myqueue.push_back(n*(x+1)+y+1);
              }else{
                myqueue.push_front(n*(x+1)+y+1);
              }
              
              if(x+1==f.first && y+1==f.second){
                cont=false;
              }
          }
          if(x-1>=0 && y-1>=0 && tab[x-1][y-1]!='X'){
            if(dist[x-1][y-1]==-1){
              dir[x-1][y-1] = 3;
              if(dir[x][y]==3){
                dist[x-1][y-1]  = dist[x][y];
                myqueue.push_back(n*(x-1)+y-1);
              }else{
                dist[x-1][y-1] = dist[x][y]+1;
                myqueue.push_front(n*(x-1)+y-1);
              }
  
              if(x-1==f.first && y-1==f.second){
                cont=false;
              }
            }
          }
          if(x+1<n && y-1>=0 && tab[x+1][y-1]!='X'){
              dir[x+1][y-1] = 4;
              if(dir[x][y]==4){
                myqueue.push_back(n*(x+1)+y-1);
              }else{
                myqueue.push_front(n*(x+1)+y-1);
              }

              if(x+1==f.first && y-1==f.second){
                cont=false;
              }
          }
          if(x-1>=0 && y+1<m && tab[x-1][y+1]!='X'){
              dir[x-1][y+1] = 4;
              if(dir[x][y]==4){
                myqueue.push_back(n*(x-1)+y+1);
              }else{
                myqueue.push_front(n*(x-1)+y+1);
              }

              if(x-1==f.first && y+1==f.second){
                cont=false;
              }
          }
    }  
    int d = dist[f.first][f.second];
    cout << "(" << f.first << ", " << f.second << "), dir = " << d << endl;    
    cout << "go" << endl;
    for(int i=0; i<m; i++){
      for(int j=0; j<n; j++)
        cout << dist[i][j] << ", ";
      cout << endl;
    }
    cout << "end" << endl;
    if(d>=0)
      cout << d<< endl;
    else
      cout << -1 << endl;
  }
  return 0;
}


