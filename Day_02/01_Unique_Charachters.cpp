/**
 *Problem 
 Unique Character 

 *Problem Link
 https://www.thejoboverflow.com/problem/238/
 
**/

#include <bits/stdc++.h>
  using namespace std;

  int main() {

    string str;
    cin>>str;
    int n = str.length();
    vector<pair<int , int>>hashMap(26 , {-1 , 0});
    
    for(int i=0;i<n;i++)
    {
      hashMap[(int)(str[i]-'a')].first=i;
      hashMap[(int)(str[i]-'a')].second++;
    }
    int ansIndex=INT_MAX;
    
    for(int i=0;i<25;i++)
    {
      if(hashMap[i].second==1)
      {
        ansIndex = min(ansIndex ,hashMap[i].first );
      }
    }
    ansIndex==INT_MAX ? cout<<-1<<endl : cout<<ansIndex+1<<endl;
    
    return 0;
  }