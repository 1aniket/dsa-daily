/*
    *Problem : 
        Find First and Last Position of Element in Sorted Array LC(34)

    *Problem Link : 
        https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
*/

class Solution {

    private:
    bool blackBox(const vector<int>&nums , int mid , int target , int flag)
    {
        if(flag==0)
        {
            if(nums[mid]<target)
            {
                return true;
            }
            return false;
        }
        if(nums[mid]<=target)
        {
            return true;
        }
        return false;
        
    }
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        int n = nums.size();
        int left = -1;
        int right = n;
        vector<int>ans;

        //Finding First Occurence
        while(left+1<right)
        {
            int mid = left + (right -left)/2;
            //current < target
            if(blackBox(nums , mid , target , 0))//balckBox(array , mid , target , occurence flag)
            {
                left = mid;
            }else
            {
                right = mid;
            }
        }

        if(right<n && nums[right]==target)ans.push_back(right);
        else ans.push_back(-1);



        //Finding Last Occurence
        left =-1;
        right = n;
        while(left+1<right)
        {
            int mid = left + (right -left)/2;

            if(blackBox(nums , mid , target , 1))
            {
                left = mid;
            }else
            {
                right = mid;
            }
        }

        if(left >=0 && nums[left]==target)ans.push_back(left);
        else ans.push_back(-1);

        return ans;

    }
};