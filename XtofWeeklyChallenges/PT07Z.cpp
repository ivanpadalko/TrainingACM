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
#include <climits>
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

void dfs_height(int v, int p, vector<vector<int> >&tree, vector<int>&heights){
	int maxim = 0;
	for(int x : tree[v])
		if(x!=p)
			dfs_height(x, v, tree, heights);	
	for(int x : tree[v])
		if(x!=p)
			maxim = max(heights[x], maxim);
	if(p!=-1 && tree[v].size()==1)
		heights[v] = 0;
	else if(p==-1 && tree[v].size()==0)
		heights[v] = 0;
	else
		heights[v] = 1 + maxim;
}

void dfs_path(int v, int p, vector<vector<int> >&tree, vector<int>&path_length, vector<int>&heights){
	int maxim = 0;
	for(int x : tree[v])
		if(x!=p)
			dfs_path(x, v, tree, path_length, heights);
	for(int x : tree[v])
		if(x!=p)
			maxim = max(path_length[x], maxim);
	if(p!=-1 && tree[v].size() == 1){
		// if v is a leaf
		path_length[v] = 0;
		return;
	}
	else if(p==-1 && tree[v].size()==0){
		// v is the root and a leaf (1 node tree)
		path_length[v] = 0;
		return;
	}
	else if(tree[v].size()==2 || (p==-1 && tree[v].size()==1) ){
		// v has a single son
		maxim = max(heights[v], maxim);
	}
	else if(tree[v].size() >=3 || (p==-1 && tree[v].size()>=2) ){
		// v has at least two sons
		int m1, m2;
		m1 = INT_MIN;
		m2 = INT_MIN;
		int x;
		for(int i=0; i<tree[v].size(); i++){
			x = tree[v][i];
			if(x==p)
				continue;
			if(heights[x]>=m1){
				m2 = m1;
				m1 = heights[x];
			}
			else if(heights[x]>=m2)
				m2 = heights[x];
		}
		maxim = max(2+m1+m2, maxim);	
	}
	path_length[v] = maxim;
	
}

int main()
{
	int n;
	cin >> n;
	int i, j, k, a, b;
	vector<vector<int> >tree(n+1, vector<int>());
	// reading
	for(int i=1; i<n; i++){
		cin >> a >> b;			
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	// we first comute the height of each vertex
	vector<int>heights(n+1, -1);
	// we say the root is v=1
	dfs_height(1, -1, tree, heights);
	
	// now we compute the longest path
	vector<int>path_length(n+1, -1);
	dfs_path(1, -1, tree, path_length, heights);
	
	cout << path_length[1] << endl;
	
	return 0;
}


