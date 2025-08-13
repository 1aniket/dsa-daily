/**
 *Problem 
    Max Number

 *Problem Link
    https://www.thejoboverflow.com/problem/68/
 
**/
#include <bits/stdc++.h>
  using namespace std;

  int main() {

   int n;
   cin>>n;
   vector<int>nums;
   int digitCount=0;
   
   while(n>0)
   {
     int digit= n%10;
     digitCount++;
     nums.push_back(digit);
     n/=10;
   }
   
   int nums_size=nums.size();
   if(nums[nums_size-1]==0)
   {
    nums[nums_size-1]=-1;
   }
   
   sort(nums.rbegin() , nums.rend());
   int newNum=0;
   digitCount-=1;
   for(int i=0;i<nums_size;i++)
   {
     if(nums[i]>=0)
     {
        int digit = pow(10 , digitCount)*nums[i];
        newNum+=digit;
        digitCount--;
     }
    
   }
   cout<<newNum<<endl;

    return 0;

  }
