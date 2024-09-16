//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // long long fac(long long n)
    
    // {
    //     if (n ==0 ) return 1;
    //     return fac(n-1)*n;
    // }
    vector<long long> factorialNumbers(long long n) {
        // Write Your Code here
        vector<long long>  res;
        long long fact = 1;
        long long i = 1;
        while(fact <= n )
        {
            res.push_back(fact);
            i+=1;
            fact*=i;
        }
        return res;
        
        // for (long long i = 1 ; i <= n; i++)
        // {
        //     long long fact = fac(i);
        //     if (fact<=n) res.push_back(fact);
        //     else break;
        // }
        // return res;

    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        cin >> N;
        Solution ob;
        vector<long long> ans = ob.factorialNumbers(N);
        for (auto num : ans) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends