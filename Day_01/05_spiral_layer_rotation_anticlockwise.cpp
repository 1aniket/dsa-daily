/*
Problem:
Given an n x m matrix and an integer k, rotate each spiral layer (ring) of the matrix by k steps in anti-clockwise direction.

Input:
- First line contains three integers n, m, k (rows, columns, rotation steps).
- Next n lines each contain m integers representing the matrix elements.

Output:
- Print the resulting matrix after rotating each spiral layer by k steps anti-clockwise.

Example:
Input:
4 4 2
1  2  3  4
5  6  7  8
9 10 11 12
13 14 15 16

Output:
3  4  8 12
2  7 11 16
1  6 10 15
5  9 13 14
*/


#include<bits/stdc++.h>

using namespace std;

void clockwiseTraverse(vector<vector<int>>& matrix ,vector<int>&ans,int& top , int& bottom, int& left , int& right,const bool get)
{
  int cnt=0;
  
    
    //top-left --> top-right
    for(int i=left;i<=right;i++)
    {
      if(get)
      {
        ans.push_back(matrix[top][i]);
      }else
      {
        matrix[top][i]=ans[cnt++];
      }
    }
    top++;

    //top-right --> bottom-right
    for(int i=top;i<=bottom;i++)
    {
      if(get)
      {
        ans.push_back(matrix[i][right]);
      }else
      {
        matrix[i][right]=ans[cnt++];
      }
    }
    right--;

    //bottom-right --> bottom-left
    if(top<=bottom)
    {
      for(int i=right;i>=left;i--)
      {
        if(get)
        {
          ans.push_back(matrix[bottom][i]);
        }else{
          matrix[bottom][i]= ans[cnt++];
        }
      }
      bottom--;
    }

    //bottom-left --> top->left
   if(top<=bottom)
   {
    for(int i=bottom;i>=top;i--)
    {
      if(get)
      {
        ans.push_back(matrix[i][left]);
      }else
      {
        matrix[i][left]=ans[cnt++];
      }
    }
    left++;
   }
  
}
int main(){

  int n, m, k;
  cin>>n>>m>>k;
  vector<vector<int>>matrix(n, vector<int>(m));
  vector<int>ans;
  int left=0;
  int right=m-1;
  int top=0;
  int bottom=n-1;

  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++)cin>>matrix[i][j];
  }

  while(top<=bottom && left<=right)
  {
    int ttop=top;
    int tbottom=bottom;
    int tleft=left;
    int tright=right;
  clockwiseTraverse(matrix , ans ,top , bottom , left , right, 1);//making get flag true to fill ans array
 
  for(int i=0;i<k;i++)
  {
    ans.push_back(ans[i]);
  }

  ans.erase(ans.begin() , ans.begin()+k);
  clockwiseTraverse(matrix , ans ,ttop , tbottom , tleft , tright, 0);//making get flag false to replace matrix array 
  ans.clear();
  }


  for(auto i : matrix)
  {
    for(auto j : i)
    {
      cout<<j<<" ";
    }
    cout<<endl;
  }


  return 0;
}