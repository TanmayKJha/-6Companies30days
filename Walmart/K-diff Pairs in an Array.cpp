class Solution {
public:
    int findPairs(vector<int>& nums, int k) {

        unordered_map<int,int> map;
        int count= 0;

        for(int i =0; i<nums.size(); i++){
            map[nums[i]]++; 
        }

        for(auto &mp : map){
            if(k==0){
                if(mp.second>1){
                 count++;
                }
                
            }else{
               if(map.find(mp.first+k)!=map.end()){
                count++;
               }
            }
        }
        return count;
        
    }
};
