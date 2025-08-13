
/**
 *Problem 
    Square Root Of N 

 *Problem Link
    https://www.thejoboverflow.com/problem/389/
 
 *TEMPLATE USED
    SBA(Sorted Binary Array)
**/

#include <bits/stdc++.h>
  using namespace std;

  int predicate(long double m , long double target)
  {
    return m*m <= target ? 0 : 1;
  }
  int main() {

    long double n;
    cin>>n;
    
   long double left=0.000;
    long double right=n;
    
    while(left+ 1e-6 < right)
    {
     long double mid=left + (right - left)/2.0;
      
      if(predicate(mid , n)==0)
      {
        left=mid;
      }else
      {
        right=mid;
      }
    }
    
     cout<<fixed<<setprecision(10)<<left<<endl;

    return 0;

  }