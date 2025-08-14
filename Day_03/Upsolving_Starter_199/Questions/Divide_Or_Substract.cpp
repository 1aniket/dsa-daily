/*
    *Problem 
        Substract Or Divide
    *Problem Link :
        https://www.codechef.com/problems/SUBDIV

    *Strategy During Contest (Upsolved Question)

        1. **Initial Attempt:** Started with a naive recursion approach.  
        2. **First Optimization:** Switched to a DP approach after hitting TLE, but it was still insufficient to pass all test cases.  
        3. **Alternate Idea:** Tried a bit manipulation method to check if the number was even or odd.  
        4. **Further Optimization:** Used `unordered_set` with `reserve()` and `max_load_factor()` to improve efficiency.  

    **Outcome:**  
        Despite multiple optimizations, these approaches were still insufficient. The problem required a **mathematical solution** with an **O(1) time complexity** to pass all test cases.
*/

#include <iostream>
using namespace std;

int main() {
	// your code goes here

	int tt;
	cin>>tt;
	while(tt--)
	{
	    int n ;
	    cin>>n;

	    int ans =0;
	    if(n<=2)
	    {
	        cout<<n<<endl;
	        continue;
	    }
	    else if(n%2==0)
	    {
	        ans+=n/2;
	        n/=2;
	        if(n%2==0)n--;
	        ans +=(n+1)/2;
	    }else
	    {
	        ans =(n+1)/2;
	    }
	    
	    cout<<ans<<endl;
	}
	
	
	
	return 0;
}