class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        //Stores (value, index)
        vector<pair<int,int>> elements;
        //to store the final output
        vector<int>result;
        //track elements by their index
        priority_queue<pair<int,int>>pq;

        for(int i=0; i<nums.size(); i++){  // Building heap-->O( nums.size()log(nums.size())  )
            pq.push({nums[i],i});
        }

        while(k--){  // popping k elements O( klog(k) )
            pair<int,int> top = pq.top();
            pq.pop();
            //stores the top k elements with their index intact
            elements.push_back(top);
        }
        
        //Now top elements are sorted based on their indexing that is lesser value index comes before
        sort(elements.begin(),elements.end(), [](pair<int, int>& a, pair<int, int>& b){  //sorting k elements -->O(klogk)
            return a.second<b.second;
        });

        //restoring elements in result array with correct indexing 
        for(auto &elem :elements){   // O(k)-->pushing k elements
            result.push_back(elem.first);
        }

        return result;
    }
};


// Time complexity --> O(N()log(N)+ O(klog(k)) + O(k)+ O(klogk) ~  O(NlogN)
// Space Complexity --> Heap Space: O(N).
                         //Auxiliary Space: The elements vector stores k elements-> O(k).
                         // Result Vector: The result vector stores k elements--> O(k).
                        // Overall (N+k)
