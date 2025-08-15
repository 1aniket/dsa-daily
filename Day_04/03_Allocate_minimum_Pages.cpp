/*
    *Problem :
        Allocate Minimum Pages

    *Problem Link : 
        https://www.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1
*/

class Solution {
    
    private:
    bool isValid(const vector<int>& arr , int maxAllowed , int k)
    {
        int student =0;
        int sum=0;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]>maxAllowed)return false;
            if(sum<maxAllowed && sum+arr[i]<=maxAllowed)
            {
                sum+=arr[i];
            }else
            {
                student++;
                sum=arr[i];
            }
        }
        
        
        if(sum!=0)student++;
        
        return student<=k ? true : false;
    }
  public:
    int findPages(vector<int> &arr, int k) {
        // code here
        int left =0;
        int right = accumulate(arr.begin() , arr.end() , 0);
        right+1;
        
        if(arr.size()<k)return -1;
        while(left+1<right)
        {
            int mid = left + (right -left)/2;
            
            if(isValid(arr , mid , k))
            {
                right=mid;
            }else
            {
                left=mid;
            }
        }
        
        return right;
    }
};