#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 25

int main()
{
	int T;
	cin >> T;
  int n;
  char s[MAX];  
	for (int in = 0; in < T; in++) {
    cin >> n;
    for(int i=0; i<n; i++)
      cin >> s[i];
    int i;
    for(i=n-1; i>0 && s[i] <= s[i-1]; i--);
    if(i==0){
      cout << "ERROR" << endl;
      continue;
    }
    int ind = i-1;
    for(i=n-1; i>=ind && s[i]<=s[ind]; i--);
    char tem = s[ind];
    s[ind] = s[i];
    s[i] = tem;
    //sort(s+ind+1, s+n);
    // we can do the last line in linear time
    int spc = i;
    char temp[MAX];
    int k=0;
    for(i=n-1; i>=ind+1; i--){
      if(i!=spc && s[i]<=s[spc])
        temp[k++] = s[i];
      else if(i!=spc)
        break;      
    }
    temp[k++] = s[spc];
    for(; i>=ind+1; i--){
      if(i!=spc)
        temp[k++] = s[i];
    }
    for(i=0; i<k; i++)
      s[ind+1+i] = temp[i];
    for(i=0; i<n; i++)
      cout << s[i];
    cout << endl;
	}
	return 0;
}


