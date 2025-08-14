/*
    *Problem :
        Number of occurrence

    *Problem Link : 
        https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1
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
    int countFreq(vector<int>& nums, int target) {
        
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
        if(ans[0]==-1 && ans[1]==-1)return 0;
        return ans[1]-ans[0]+1;

    }
};