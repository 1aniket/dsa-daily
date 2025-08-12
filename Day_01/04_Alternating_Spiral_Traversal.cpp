/*
Problem:
Given an n x m matrix, print its elements in spiral order with alternating directions:
- The outermost layer should be traversed in clockwise order.
- The next inner layer should be traversed in counterclockwise order.
- Continue alternating directions until all elements are printed.

Input:
n m   (number of rows and columns)
n*m matrix elements

Output:
Matrix elements printed in the specified alternating spiral order, space-separated.

Example 1:
Input:
3 3
1 2 3
4 5 6
7 8 9

Output:
1 2 3 6 9 8 7 4 5

Example 2:
Input:
4 5
 1  2  3  4  5
14 15 16 17  6
13 20 19 18  7
12 11 10  9  8

Output:
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 20 19 18 17 16
*/


#include<bits/stdc++.h>

using namespace std;

void ClockwiseTraversal(const vector<vector<int>>&matrix , int& left , int& right , int& top , int& bottom)
{
  
   //Top-left --> Top-right
    for(int i=left; i<=right; i++)
    {
      cout<<matrix[top][i]<<" ";
    }
    top++;

    //Top-right --> Bottom-right
    for(int i=top; i<=bottom; i++)
    {
      cout<<matrix[i][right]<<" ";
    }
    right--;

    //Bottom-right --> Bottom-left
    if(top<=bottom)
    {
      for(int i=right;i>=left;i--)
      {
       cout<<matrix[bottom][i]<<" ";
      }
      bottom--;
    }

    //Bottom-left --> Top-left
    if(left<=right)
    {
      for(int i=bottom;i>=top;i--)
      {
        cout<<matrix[i][left]<<" ";
      }
      left++;
    }
  

}

void AntiClockwiseTraversal(const vector<vector<int>>&matrix , int& left , int& right , int& top , int& bottom)
{
  
   //Top-left --> Bottom-left
    for(int i=top; i<=bottom; i++)
    {
      cout<<matrix[i][left]<<" ";
    }
    left++;

    //Bottom-left --> Bottom-right
    for(int i=left; i<=right; i++)
    {
      cout<<matrix[bottom][i]<<" ";
    }
    bottom--;

    //Bottom-right --> Top-left
    if(left<=right)
    {
      for(int i=bottom;i>=top;i--)
      {
       cout<<matrix[i][right]<<" ";
      }
      right--;
    }

    //Top-right --> top-left
    if(top<=bottom)
    {
      for(int i=right;i>=left;i--)
      {
        cout<<matrix[top][i]<<" ";
      }
      top++;
    }
  

}



int main()
{
  int n, m ;
  cin>>n>>m;
  vector<vector<int>>matrix(n, vector<int>(m));
  
  
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)cin>>matrix[i][j];
  }

  int left=0;
  int right=m-1;
  int top=0;
  int bottom=n-1;
  bool clockwise = true;

  while(top<=bottom && left<= right)
  {
    if(clockwise)
    {
      ClockwiseTraversal(matrix ,left , right , top , bottom);
     
    }else
    {
      AntiClockwiseTraversal(matrix ,left , right , top , bottom);
    }
    clockwise = !clockwise;
  }
  
  return 0;
}