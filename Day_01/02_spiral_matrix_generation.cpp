/*
Problem:
Given an integer n, generate an n x n matrix filled with elements from 1 to n^2
in clockwise spiral order.

Example:
Input:
3
Output:
1 2 3
8 9 4
7 6 5
*/

#include<bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  cin>>n;
  int cnt=1;
  int left=0;
  int right=n-1;
  int top=0;
  int bottom=n-1;
  vector<vector<int>>finalLayout(n , vector<int>(n));

  while(left<=right && top<=bottom)
  {
  
    //Moving Top-left -> Top-right
    for(int i=left;i<=right;i++)
    {
        finalLayout[top][i]=cnt++;
    }
    top++;

    //Moving Top-right -> Bottom-right
    for(int i=top;i<=bottom;i++)
    {
        finalLayout[i][right]=cnt++;
    }
    right--;

    //Moving Bottom-right -> Bottom->left
    if(top<=bottom)
    {
        for(int i=right;i>=left;i--)
        {
            finalLayout[bottom][i]=cnt++;
        }
        bottom--;
    }

    //Moving Bottom-left -> Top-left
    if(left<=right)
    {
        for(int i=bottom;i>=top;i--)
        {
            finalLayout[i][left]=cnt++;
        }
        left++;
    }
  }

  for(auto i : finalLayout)
  {
    for(auto j : i)
    {
      if(j<10)cout<<" ";
      cout<<j<<" ";
    }
    cout<<endl;
  }
  return 0;
}