/*

Problem:
Given an n x m matrix, print its elements in reverse spiral order —
starting from the innermost element and spiraling outward to the outermost layer.

Input:
n m   (number of rows and columns)
n*m matrix elements

Output:
Matrix elements printed in reverse spiral order, space-separated.

Example 1:
Input:
3 3
1 2 3
4 5 6
7 8 9

Output:
5 4 7 8 9 6 3 2 1

Example 2:
Input:
4 4
 1  2  3  4
12 13 14  5
11 16 15  6
10  9  8  7

Output:
13 14 15 16 11 12  1  2  3  4  5  6  7  8  9 10

*/
#include<bits/stdc++.h>

using namespace std;

int main()
{
  int n, m ;
  cin>>n>>m;
  vector<vector<int>>matrix(n, vector<int>(m));
  vector<int>ans;
  
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)cin>>matrix[i][j];
  }

  int left=0;
  int right=m-1;
  int top=0;
  int bottom=n-1;

  while(top<=bottom && left<=right)
  {
    //Top-left --> Top-right
    for(int i=left; i<=right; i++)
    {
      ans.push_back(matrix[top][i]);
    }
    top++;

    //Top-right --> Bottom-right
    for(int i=top; i<=bottom; i++)
    {
      ans.push_back(matrix[i][right]);
    }
    right--;

    //Bottom-right --> Bottom-left
    if(top<=bottom)
    {
      for(int i=right;i>=left;i--)
      {
        ans.push_back(matrix[bottom][i]);
      }
      bottom--;
    }

    //Bottom-left --> Top-left
    if(left<=right)
    {
      for(int i=bottom;i>=top;i--)
      {
        ans.push_back(matrix[i][left]);
      }
      left++;
    }
  }

  reverse(ans.begin()  ,ans.end());
  for(auto i : ans)cout<<i<<" ";

  return 0;
}