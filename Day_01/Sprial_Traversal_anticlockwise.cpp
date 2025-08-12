// Q :- Anti-clockwise Spiral Traversal of Matrix


#include<bits/stdc++.h>

using namespace std;

int main()
{
  int n,m;
  cin>>n>>m;
  vector<vector<int>>nums(n , vector<int>(m));

  for(int i=0;i<n;i++)
  {
    for(int j =0;j<m;j++)cin>>nums[i][j];
  }

  int left=0;
  int right=m-1;
  int top=0;
  int bottom=n-1;

  while(top<=bottom && left<=right)
  {
    //Moving top-left -> bottom-left
    for(int i=top; i<=bottom;i++)
    {
      cout<<nums[i][left]<<" ";
    }
    left++;

    //Moving bottom-left -> bottom-right
    for(int i=left;i<=right;i++)
    {
      cout<<nums[bottom][i]<<" ";
    }
    bottom--;

    //Moving bottom-right -> top-right
    if(left<=right)
    {
      for(int i=bottom;i>=top;i--)
      {
        cout<<nums[i][right]<<" ";
      }
      right--;
    }
    

    //Moving top-right -> top-left
    if(top<=bottom)
    {
      for(int i=right;i>=left;i--)
      {
        cout<<nums[top][i]<<" ";
      }
      top++;
    }
    
  }
}
