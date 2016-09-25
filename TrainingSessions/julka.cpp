/* Basic mathematicals operations with big numbers */

#include<bits/stdc++.h>

using namespace std;

void bigNumSub(string &s, string &t){
  int n = s.size();
  int m = t.size();
  for (int i = 1; i <= m; i++){
    if (s[n-i] >= t[m-i])
      s[n-i] = s[n-i]-t[m-i]+'0';
    else{
      s[n-i-1]--;
      s[n-i] = 10+s[n-i]-t[m-i]+'0';
    }
  }
}

void bigNumDiv2(string &tmp){
  for (int i = 0; i < tmp.size()-1; i++){
    tmp[i+1] += (tmp[i]-'0')%2*10;
    tmp[i] = '0' + (tmp[i]-'0')/2;
  }
  tmp[tmp.size()-1] = '0' + (tmp[tmp.size()-1]-'0')/2;
}

void bigNumAdd(string &tmp, string &t){
  int n = tmp.size();
  int m = t.size();
  for (int i = 1; i <= m; i++)
    tmp[n-i] =  t[m-i] + tmp[n-i] - '0';
  for (int i = 1; i < n; i++)
    if (tmp[n-i] >= '0'+10){
      tmp[n-i-1]++;
      tmp[n-i] = '0' + (tmp[n-i]-'0')%10;
    }
}

int main(){
  string s, t, tmp1, tmp2;
  for (int l = 0; l < 10; l++){
    s = string(102, '0');
    t = string(102, '0');
    cin >> tmp1 >> tmp2;
    for (int i = 1; i <= tmp1.size(); i++)
      s[102-i] = tmp1[tmp1.size()-i];
    for (int i = 1; i <= tmp2.size(); i++)
      t[102-i] = tmp2[tmp2.size()-i];
    bigNumSub(s, t);
    bigNumDiv2(s);
    tmp1 = string(s);
    bigNumAdd(s, t);
    bool zero = true;
    for (int i = 0; i < s.size(); i++)
      if (zero){
        if (s[i] == '0')
          continue;
        else{
          zero = false;
          cout << s[i];
        }
      }
      else
        cout << s[i];
    if (zero)
      cout << "0";
    cout << "\n";
    zero = true;
    for (int i = 0; i < tmp1.size(); i++)
      if (zero){
        if (tmp1[i] == '0')
          continue;
        else{
          zero = false;
          cout << tmp1[i];
        }
      }
      else
        cout << tmp1[i];
    if (zero)
      cout << "0";
    cout << "\n";
  }
  return 0;
}
