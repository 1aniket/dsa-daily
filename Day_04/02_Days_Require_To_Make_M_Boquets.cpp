/*
    *Problem : 
        Minimum Number of Days to Make m Bouquets LC(1482)

    *Problem Link :
        https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/
*/

class Solution {

    private:
    bool canWeMake(const vector<int>& bloomDay , int mid , int k , int m)
    {
        int day = mid;
        int flowers =k;
        int boquets=0;
        for(int i=0;i<bloomDay.size();i++)
        {
            if(bloomDay[i]<=day && flowers>0)
            {
               flowers--;
            }else if(flowers==0)
            {
                
                flowers=k;
                boquets++;
                if(bloomDay[i]<=day)flowers--;
                
            }else
            {
                flowers=k;
            }
        }

        if(flowers==0)boquets++;

        return (boquets >= m) ? true : false; 
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int n = bloomDay.size();
        int left =0;
        int right = *max_element(bloomDay.begin() , bloomDay.end());
        right+=1;
        int maxi =right;

        while(left + 1 < right)
        {
            int mid = left + (right - left)/2;

            if(canWeMake(bloomDay , mid , k , m))
            {
                right = mid;
            }else
            {
                left=mid;
            }
        }
        return right <maxi ? right : -1 ;
    }
};