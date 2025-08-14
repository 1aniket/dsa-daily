/*
    *Problem :
        Search Insert Position LC(35)

    *Problem Link : 
        https://leetcode.com/problems/search-insert-position/description/
*/

class Solution {
    private:

    int blackBox(const vector<int>& nums , int mid , int target)
    {
        if(nums[mid]==target)
        {
            return 0;
        }else if(nums[mid]>target)
        {
            return 1;
        }

        return -1;
    }
public:
    int searchInsert(vector<int>& nums, int target) {

        int n = nums.size();
        int left = -1;
        int right = n;
        while(right -left>1)
        {
            int mid = left + (right -left)/2;

            if(blackBox(nums , mid , target)==0)
            {
                return mid;
            }else if(blackBox(nums , mid , target)==1)
            {
                right = mid;
            }else
            {
                left = mid;
            }

        }

        return right;
        
    }
};