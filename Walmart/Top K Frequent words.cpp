class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
         

        vector<string> result;
        priority_queue<pair<int, string>, vector<pair<int, string>>, 
               function<bool(pair<int, string>, pair<int, string>)>> pq(
    [](pair<int, string> a, pair<int, string> b) {
        if (a.first == b.first) {
            return a.second > b.second; // Lexicographical order for same frequency
        }
        return a.first < b.first; // Higher frequency comes first
    }
);
        unordered_map<string,int>freq;

        for(auto &num :words){
            freq[num]++;
        }

        for(auto fre:freq){
            pq.push({fre.second,fre.first});
        }
        
        while(k--){
            pair<int,string> top = pq.top();
            pq.pop();
            result.push_back(top.second);
        }

        return result;
    }
};
