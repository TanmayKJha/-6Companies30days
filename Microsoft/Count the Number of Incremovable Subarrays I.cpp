//L.C -2970 Count the Number of Incremovable Subarrays I

class Solution {
public:
// Overall Time Complexity->O(n^3)
// Space Complexity->O(1) Mo extra space taken

// This function checks if the array remains strictly increasing 
// after removing the subarray from index `start` to `end`
bool strictlyIncreasing(vector<int>& nums, int start, int end) {
    
    int prev = -1; // Initialize previous element to -1 to start comparisons
    
    // Loop through the array and check elements
    for (int i = 0; i < nums.size(); i++) {   //O(N)
        
        // If the current index is part of the subarray, skip it
        if (i >= start && i <= end) {
            continue;
        }
        
        // Check the strictly increasing condition
        if (prev >= nums[i]) {
            return false; // If the current element is not greater than the previous element, return false
        }
        
        prev = nums[i]; // Update the previous element if the condition holds
    }
    
    return true; // If we have checked all elements and found no violations, the array is strictly increasing
}


    // This function counts the number of incremovable subarrays
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size(); // Get the size of the input array
        int count = 0; // Initialize a counter to keep track of valid subarrays
        
        // Loop through all possible subarrays
        for (int start = 0; start < n; start++) {
            for (int end = start; end < n; end++) { //O(N^2)
                
                // For each subarray, check if removing it results in a strictly increasing array
                if (strictlyIncreasing(nums, start, end)) { //O(N)
                    count++; // Increment the count if the subarray is valid
                }
            }
        }
        
        return count; // Return the total count of valid incremovable subarrays
    }
};
