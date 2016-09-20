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

// from a given array x[0], x[1], ..., x[n-1], we are asked to construct a segment tree data structure

#define MAX 2000000
typedef struct node node;
struct node{
  int val;
  int score;
  int be, en; // [be, en] is the span interval
  node * left;
  node * right;  
  node(int value, int i){
    val = value;
    score = value;
    be=en=i;
    left = nullptr;
    right = nullptr;
  }
  node(int value, node*l, node*r){
    if(r->be - l->en != 1){
      cout << "horrrible mistake" << endl;
    }
    val = value;
    score =l->score+r->score;
    be = l->be;
    en = r->en;
    left = l;
    right = r;
  }
};

class segment_tree{

  private:
    node*root;
    int size;
    int height;
    
      void updateVal(node*p, int a, int b, int inc){
        if(p->en < a || p->be > b)
          return;
        if(p->be>=a && p->en<=b){          
          p->val+=inc;
          return;
        }
        updateVal(p->left, a, b, inc);
        updateVal(p->right, a, b, inc);      
      }  
      void updateScore(node*p, int a, int b, int inc){
        if(p->en < a || p->be > b)
          return;
        if()
      }
      
  public:
    segment_tree(vector<int>&x){
     // cout << "go" << endl;
      int n = x.size();
      size = n;
      height=1;
      vector<node*>v(n, nullptr);
      for(int i=0; i<n; i++)
        v[i] = new node(x[i], i);
      int prev_n = n;
      n=(n+1)/2;
      while(n>1){
        vector<node*>w(n, nullptr);
        for(int i=0; i<n-1; i++)
          w[i] = new node(0, v[2*i], v[2*i+1]);
        if(2*n-1 >= prev_n)
          w[n-1] = v[2*(n-1)]; 
        v = w;
        prev_n = n;
        n = (n+1)/2;
        height++;
      }
      if(prev_n==1)
        root = new node(x[0], 0);
      else
        root = new node(0, v[0], v[1]);    
    }  
    int get(int index){
      //cout <<"get index = " << index << endl;
      if(index<0 || index >= size){
        cout << "this element doesn't exist" << endl;
        return -1;
      }
      int h=height-2;
      node * p = root;
      int sum=0;
      while(p!=nullptr){
        //cout << "span = [" << p->be << ", " << p->en << "]" << endl;
        sum+=(p->val);
        //cout  << "first there" << endl;
        if(p->en == p->be)
          p = p->left;
        else if(p->right==nullptr)
          p=p->left;
        else if(p->left==nullptr){
          cout << "whaat" << endl;
          return -1;
        }
        else if(p->left->en >= index)
          p = p->left;
        else
          p = p->right;
      }
      return sum;
    }  
    void update(int a, int b, int inc){
      if(a>b)
        return;
      updateVal(root, a, b, inc);
      updateScore(root, a, b, inc);
    }
    int getSum(int a, int b){
      
      
      
      
    }
    
    
};






int main()
{
  vector<int>v(5, 2);
  v[2] = 3;
  v[4] = 5;
  v[0] = 1;
  cout << "originally, v is " << endl;
  for(int i=0; i<v.size(); i++)
    cout << v[i] << " ";
  cout << endl;
  
  segment_tree * my_tree = new segment_tree(v);
  int x = my_tree->get(2);
  cout << x << endl;
  my_tree->update(1, 3, 10);
  for(int i=0; i<v.size(); i++)
    cout << my_tree->get(i) << " " ;
  cout << endl;
  
  
  return 0;
}


