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
#define MAX 500100

int x[MAX];
int n;
long long merge_and_count(int be, int mi, int en){
  // merges intervals [be, mi] and [mi+1, en]
  if(be >= en){
    //cout << "horrible mistake" << endl;
    return 0;
  }
  int i, j, k;
  i=be;
  j=mi;
  k=be;
  long long count=0;
  int * temp = new int[en-be];
  //cout << "\tbe = "<<be <<" mi = " << mi << " en = "<<en << " count = "<<count << endl;  
  
  while(k<en){
    if(i>=mi){
      temp[k-be]=x[j];
      j++;      
    }
    else if(j>=en){
      temp[k-be]=x[i];
      count+=(k-i);
      i++;
    }  
    else if(x[i]<=x[j]){
      temp[k-be]=x[i];
      count+=(k-i);
      i++;
    }
    else{
      temp[k-be]=x[j];
      j++;
    }    
    //cout <<"\t\t i="<<i<<" j="<<j<<" k="<<k<< " count="<<count<<endl;    
    k++;
  }
  for(i=be; i<en; i++)
    x[i]=temp[i-be];
  delete temp;
  //cout << "\tbe = "<<be <<" mi = " << mi << " en = "<<en << " count = "<<count << endl;
  return count; 
}
long long merge_sort(int a, int b){
  //cout << "a = " << a <<" b = "  << b << endl;
  long long count = 0;
  if(a>=b-1)
    return 0;
  int mi = (a+b)/2;
  count += merge_sort(a, mi);
  count += merge_sort(mi,b);
  count +=merge_and_count(a, mi, b);
  //cout << "a = " << a <<" b = "  << b << " count="<<count << endl;
  return count; 
}


int main()
{
  //cout << "hi" << endl;
  scanf("%d", &n);
  while(n>0){
    for(int i=0; i<n; i++)
      scanf("%d", &x[i]);
    //cout << endl <<  "n = " << n << endl;
    cout << merge_sort(0, n) << endl;    
    
    scanf("%d", &n);
  }
  
  
  
  
  
	return 0;
}


