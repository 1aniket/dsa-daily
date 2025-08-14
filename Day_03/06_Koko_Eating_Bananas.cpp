/*
    *Problem : 
        Koko Eating Bananas LC(875)

    *Problem Link : 
        https://leetcode.com/problems/koko-eating-bananas/description/
*/

class Solution {

    private :
    bool blackBox(const vector<int>& nums , int mid , int h)
    {
        int i=0;
        for( i=0;i<nums.size() && h>0;i++)
        {
            int k=nums[i];
            if(k>mid)
            {
                int a = k/mid;
                if(k%mid!=0)
                {
                    a+=1;
                }
                h-=a;
            }else
            {
                h--;
            }
        }
        return (i==nums.size() && h>=0) ? true : false; 
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int n = piles.size();
        int left =0;
        int right =0;

        for(int i=0;i<n;i++)
        {
            right = max(right , piles[i]);
        }

        right+=1;
        while(left+1 < right)
        {
            int mid = left + (right - left)/2;

            if(blackBox(piles , mid , h))
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