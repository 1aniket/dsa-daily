/**
 *Problem 
    Move Zeroes To End 

 *Problem Link
    https://www.thejoboverflow.com/problem/19/
 
**/

#include <bits/stdc++.h>
  using namespace std;

  int main() {

    int n;
    cin>>n;
    vector<int>nums(n);
    vector<int>nonzero;
    int zero=0;
    for(int i=0;i<n;i++)cin>>nums[i];
    
    int left=0;
    int right=n-1;
    for(int i=0;i<n;i++)
    {
      if(nums[i]!=0)
      {
        nonzero.push_back(nums[i]);
      }
    }
    
    for(int i=0;i<nonzero.size();i++)
    {
      nums[i]=nonzero[i];
    }
    for(int i=nonzero.size(); i<n;i++)
    {
      nums[i]=0;
    }
    
    for(auto i: nums)
    {
      cout<<i<<" ";
    }

    return 0;
  }