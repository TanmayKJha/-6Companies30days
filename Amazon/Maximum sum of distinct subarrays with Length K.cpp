class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        unordered_set<int>st;

        long long result = 0;
        long long currentSum = 0;
        int n = nums.size();

        int i =0;
        int j =0;

        while(j<n){

            //2 condition me hi shrink karenge window ek toh k size ka subarray mil jaye aur dusra element repeat ho jaye   subarray nme 

            // condition 2 ->elements repeat ho gaye

            while(st.count(nums[j])){
                currentSum-=nums[i];
                st.erase(nums[i]);
                i++;

            }
            currentSum+=nums[j];
            st.insert(nums[j]);

           // condition 1 -> k size ka subarray mil gaya

            if(j-i+1==k){

                result = max(result,currentSum);
                currentSum-=nums[i];
                st.erase(nums[i]);
                i++;
                
            }
            j++;


        }

        return result;
        
    }
};
