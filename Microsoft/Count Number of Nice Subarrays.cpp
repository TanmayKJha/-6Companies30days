// T.C -> O(N)
// S.C -> O(N)  //for map

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        unordered_map<int,int> mp; /// to remember the odd count we have seen in past or not

        int niceArray = 0;
        int oddcount = 0;
        mp[oddcount]=1; //i have already seen oddcount =0 once in past bcz inittially no of odd count is 1.

        int n = nums.size();
      for(int i = 0; i<n; i++){
             if(nums[i]%2==1){
                oddcount++;
             }

             if(mp.count(oddcount-k)){
                niceArray+=mp[oddcount-k];
             }
             mp[oddcount]++;

        }
        return niceArray;
        
    }
};

///////////////////////////////2nd Approach Sliding Window//////////////////////////////////////////////////////////



class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        //dry run this code on 2 1 2  , 2 1 1 and any example from test cases
        int n = nums.size();
        int i = 0;
        int j = 0;
        int niceArray = 0;
        int prevCount = 0;
        int countOdd = 0;

        while(j<n){

            if(nums[j]%2!=0){ //odd no
                countOdd++;
                 prevCount =0;
            }

            while(countOdd == k){
                prevCount++;
               
              if (i<n &&nums[i]%2==1){ //odd no at ith element
                    countOdd--;
                }
                i++;
            }

            niceArray+=prevCount;
            j++;
        }
        return niceArray;
    }
};
