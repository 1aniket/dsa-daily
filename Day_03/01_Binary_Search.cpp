/*
    *Problem :
        Binary Search LC(704)
    *Problem Link : 
        https://leetcode.com/problems/binary-search/description/
*/

class Solution {

    private:
    bool blackBox(const vector<int>&nums , int mid , int target)
    {
        if(nums[mid]>target)
        {
            return false;
        }
        return true;
    }
public:
    int search(vector<int>& nums, int target) {
        
        int n = nums.size();
        int left= -1;
        int right = n;

        while(right-left>1)
        {
            int mid = left + (right - left)/2;

            if(nums[mid]==target)
            {
                return mid;
            }else if(blackBox( nums, mid , target))
            {
                left=mid;
            }else
            {
                right=mid;
            }

        } 
       return -1;
    }
};