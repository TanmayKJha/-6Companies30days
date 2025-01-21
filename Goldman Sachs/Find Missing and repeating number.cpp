//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        unordered_map<int,int> mp;
        int n = arr.size();
        // int expectedSum = n*(n+1)/2;
        
        // int actualSum =0;
        for(auto sum : arr){
            // actualSum+=sum;
            mp[sum]++;
        }
        
        int missing = -1;
        int duplicate = -1;
        
        for(int i =1; i<=n; i++){
            if(mp[i]==0){
                missing =i;
            }
            if(mp[i]==2){
                duplicate =i;
            }
        }
        return {duplicate,missing};
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;
        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        auto ans = ob.findTwoElement(arr);
        cout << ans[0] << " " << ans[1] << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
