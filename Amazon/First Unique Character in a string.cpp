class Solution {
public:
    // Function to find the index of the first unique character in the string
    int firstUniqChar(string s) {
        unordered_map<char, int> freq;  

        // Step 1: Count the frequency of each character in the string
        for (char c : s) {              // Iterate through each character in the string
            freq[c]++;                  // Increment the frequency count for character 'c'
        }

        // Step 2: Find the index of the first character with frequency 1
        for (int i = 0; i < s.length(); i++) {  
            if (freq[s[i]] == 1) {              // Check if the frequency of the character is 1
                return i;                       
            }
        }

        return -1;  //  no unique character found, return -1
    }
};


//Time Complexity: O(N)
// Space Complexity:
// O(1) if the input is restricted to lowercase English letters.
// O(N) if the input can contain arbitrary characters.

////////////////////////////////////////////////////////////using freq Array////////////////////
class Solution {
public:
    int firstUniqChar(string s) {

        vector<int>freq(26,0);

        for(int i=0;i<s.size();i++){
            char ch = s[i];
            freq[ch-'a']++;
        }

        for(int i=0;i<s.size();i++){
            char ch = s[i];
            if(freq[ch-'a']==1){
                return i;
            }
        }
        return -1;
    }
};
