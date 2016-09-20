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
#define MAX 10010

bool is_valid_cell[MAX];
int valid_neigh[MAX][10];
int n_valid_neigh[MAX];
int n_vis_neigh[MAX];
bool visited[MAX];
int R, C, M, N, W;
void dfs(int v){
  visited[v] = true;
  n_vis_neigh[v] = n_valid_neigh[v];
  //cout << v << ": " << v%C << ", " << v/C << endl;
  for (int i=0; i<n_valid_neigh[v]; i++){
    int w = valid_neigh[v][i]; 
    if(!visited[w]){
      dfs(w);
    }      
  }  
}


int main()
{
	int T;
	cin >> T;
	int n;
  for (int ind = 0; ind < T; ind++) {
    cin >> C >> R >> M >> N;
    n = R*C;
    for(int i=0; i<n; i++)
        is_valid_cell[i] = true;
    cin >> W;
    int tempx, tempy;
    for(int i=0; i<W; i++){
      cin >>  tempx >> tempy;
      is_valid_cell[tempy*C+tempx] = false;
    }
    for(int i=0; i<n; i++)
      n_valid_neigh[i] = 0;
    for(int i=0; i<n; i++){
      int x, y;
      x = i%C;
      y = i/C;
      bool left, right, up, down;
      left = (x-M>=0);
      right = (x+M < C);
      up = (y+N < R);
      down = (y-N >= 0);
      if(left && up && is_valid_cell[C*(y+N)+x-M])
        valid_neigh[i][n_valid_neigh[i]++] = C*(y+N)+x-M;
      
      if(left && down && is_valid_cell[C*(y-N)+x-M])
        valid_neigh[i][n_valid_neigh[i]++] = C*(y-N)+x-M; 
      
      if(right && down && is_valid_cell[C*(y-N)+x+M])
        valid_neigh[i][n_valid_neigh[i]++] = C*(y-N)+x+M; 
      
      if(right && up && is_valid_cell[C*(y+N)+x+M])
        valid_neigh[i][n_valid_neigh[i]++] = C*(y+N)+x+M;
      
      left = (x-N>=0);
      right = (x+N < C);
      up = (y+M < R);
      down = (y-M >= 0);
      if(left && up && is_valid_cell[C*(y+M)+x-N])
        valid_neigh[i][n_valid_neigh[i]++] = C*(y+M)+x-N;
      
      if(left && down && is_valid_cell[C*(y-M)+x-N])
        valid_neigh[i][n_valid_neigh[i]++] = C*(y-M)+x-N;
      
      if(right && down && is_valid_cell[C*(y-M)+x+N])
        valid_neigh[i][n_valid_neigh[i]++] = C*(y-M)+x+N;
      
      if(right && up && is_valid_cell[C*(y+M)+x+N])
        valid_neigh[i][n_valid_neigh[i]++] = C*(y+M)+x+N; 
    }
    for(int i=0; i<n; i++){
      visited[i] = false;
      n_vis_neigh[i] = -1;
    }
    dfs(0);
    int even=0, odd=0;
    for(int i=0; i<n; i++){
      if(n_vis_neigh[i] >= 0){
        if(M==0 || N==0 || M==N)
          n_vis_neigh[i]/=2;
        if(n_vis_neigh[i]%2 == 0)
          even++;
        else
          odd++;
      }
    }
    cout << "Case " << ind + 1 << ": " << even << " " << odd << "\n";
  }
	return 0;
}


