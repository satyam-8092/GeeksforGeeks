//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if (n==1)return 0;
        
        sort(arr.begin(),arr.end());
        int diff = arr[n-1] - arr[0];
        
        int min_h,max_h;
        int result = diff;
        
        for (int i = 1 ; i < n; i++)
        {
            if (arr[i] - k < 0) continue;
            min_h = min(arr[0] + k, arr[i] - k );
            max_h = max(arr[n-1] -k , arr[i-1] + k);
            result = min(result, max_h - min_h);
            
        }
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, k;
        cin >> k;
        cin.ignore();
        vector<int> a, b, c, d;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution ob;
        auto ans = ob.getMinDiff(a, k);
        cout << ans << "\n";
        cout << '~' << endl;
    }
    return 0;
}
// } Driver Code Ends