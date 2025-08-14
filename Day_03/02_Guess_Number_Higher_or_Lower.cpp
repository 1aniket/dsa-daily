/*
    *Problem :
        Guess Number Higher or Lower LC(374)
    
    *Problem Link : 
        https://leetcode.com/problems/guess-number-higher-or-lower/description/
*/

class Solution {
public:
    int guessNumber(int n) {
        
        long long x= n;
        long long left =0;
        long long right = x+1;

        while(left+1 < right)
        {
            long long mid = left + (right - left)/2;
            if(guess(mid)==-1)
            {
                right = mid;
            }else if(guess(mid)==1)
            {
                left = mid;
            }else
            {
                return mid;
            }
        }
        return 0;
    }
};