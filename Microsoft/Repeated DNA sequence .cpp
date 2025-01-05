class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        // Vector to store the resulting repeated sequences
        vector<string> v;

        // Unordered map to store each 10-character substring and its frequency
        unordered_map<string, int> mpp;

        // Loop through the string to extract all 10-character substrings
        for (int i = 0; i + 10 <= s.length(); i++) {
            // Extract a substring of length 10 starting at index 'i'
            string substring = s.substr(i, 10);

            // Increment the frequency of this substring in the map
            mpp[substring]++;
        }

        // Iterate over the map to find substrings that appear more than once
        for (auto& i : mpp) {
            // If the count of the substring is greater than 1, it's repeated
            if (i.second > 1) {
                // Add the repeated substring to the result vector
                v.push_back(i.first);
            }
        }

        // Return the vector containing all repeated 10-character sequences
        return v;
    }
};
