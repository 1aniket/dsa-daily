/*
    *Problem : 
        Capacity To Ship Packages Within D Days LC(1011)

    *Problem Link : 
        https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/

*/

class Solution {

    private:
    bool blackBox(const vector<int>&nums , int mid , int days)
    {
        cout<<mid<<endl;
        long long capacity=0;
        int i;
        for(i=0;i<nums.size() && days>0;)
        {
            while(i<nums.size() && capacity+nums[i]<=mid)
            {
                capacity+=nums[i++];
            }
            days--;
            capacity=0;
        }
       return (days >=0 && i==nums.size())? true : false;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        
        int n =weights.size();
        long long left = 0 ;
        long long right = 0;
        long long sum=0;

        for(int i=0;i<n;i++)
        {
           sum+=weights[i];
        }
        right=sum+1;
        while(left+1 < right)
        {
            long long mid = left + (right -left)/2;
            if(blackBox(weights , mid , days))
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