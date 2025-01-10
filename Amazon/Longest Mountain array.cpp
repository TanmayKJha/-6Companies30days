class Solution {
public:
    int longestMountain(vector<int>& arr) {

        int n = arr.size();
        int ans =0;

        for(int i= 1; i<n-1;){
            
            int count = 1; //include peak element

            if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){ 
                
                int left = i;
                
                while(left>0 && arr[left]>arr[left-1]){ //Checks the condition of peak element
                    left--;  
                    count++;
                }
                
                while(i<n-1 && arr[i]>arr[i+1]){
                    i++;
                    count++;
                }

                ans = max(ans,count);
            }
            else
            {
             i++;
            }
      
        }
        return ans;
        
    }
};
