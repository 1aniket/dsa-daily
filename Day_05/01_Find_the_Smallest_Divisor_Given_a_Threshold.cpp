/*
    Problem :
        Find the Smallest Divisor Given a Threshold LC(1283)
    
    Problem Link :
        https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/
*/

class Solution {
    private:
    bool check(const vector<int>&nums , int possible , int th)
    {
        int sum =0;

        for(int i=0;i<nums.size();i++)
        {
            sum+=ceil((double)nums[i]/possible);
        }
        return sum<=th ? true : false;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int n = nums.size();
        int left =0;
        int right = *max_element(nums.begin() , nums.end())+1;

        while(left+1 < right)
        {
            int mid = left + (right -left)/2;

            if(check(nums , mid , threshold))
            {
                right = mid;
            }else
            {
                left=mid;
            }
        }
        return right;
    }
};