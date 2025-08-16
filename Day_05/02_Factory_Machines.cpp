/*
    Problem :
        Factory Machines CSES
    
    Problem Link :
        https://cses.fi/problemset/task/1620
*/
#include<bits/stdc++.h>

using namespace std;

class solution{
    private:
    bool check(const vector<int>&nums , long long mid , long long t)
    {
        long long sum =0;
        for(int i=0;i<nums.size();i++)
        {
            
            sum+=mid/nums[i];
            if(sum>=t) return true;
        }
       return false;
    }

    public:
    long long findMinimumTime(vector<int>& nums , long long n , long long t)
    {
        long long left =*min_element(nums.begin() , nums.end())-1;
        long long right = *max_element(nums.begin() , nums.end())*t +1;
        long long maxi=right;
        while(left+1 < right)
        {
            long long mid = left + (right -left)/2;

            if(check(nums , mid , t))
            {
                right=mid;
            }else
            {
                left = mid;
            }
        }
        return right < maxi ? right : -1;
    }

};

int main()
{
    int n, t;
    cin>>n>>t;
    vector<int>machines(n);
    for(int i=0;i<n;i++)cin>>machines[i];

    solution s;
    cout<<s.findMinimumTime(machines , n , t)<<endl;
}