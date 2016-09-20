#include <iostream>

using namespace std;
/////////////////////////////////////////////////////////////////////

int seq[30];
long long fact[30];
int main()
{
	int T;
	cin >> T;
  fact[0] = 1;
  for(int i=1; i<20; i++)
    fact[i] = i*fact[i-1];
	for (int ind = 0; ind < T; ind++) {
    int n;
    long long ans=0;
    cin >> n;
    for(int i=0; i<n; i++)
      cin >> seq[i];
    ans+=(seq[0]-1) * fact[n-1]; 
    for(int i=1; i<n; i++){
      int rank=0;
      for(int j=i+1; j<n; j++){
        if(seq[j] < seq[i])
          rank++;
      }
      ans += rank*fact[n-i-1];
    }
    ans+=1;
		cout << ans << endl;
	}
	return 0;
}


