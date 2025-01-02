// LC 299
// T.C -> O(n)
// S.C-> O(1)

class Solution {
public:
    // only contains digits 
    string getHint(string secret, string guess) {

        int bulls = 0;  // Keeps count of characters in guess that exactly match those in secret in both value and position.

        int cows = 0; //Keeps count of characters that match in value but not position
        
        //Arrays of size 10 (for digits 0-9) to store the frequency of unmatched characters in    secret and guess.
        vector<int> secretFreq(10, 0); 
        vector<int> guessFreq(10, 0); 
           
         //base condition if the string size is not equal or secret key is empty
        if (secret.size() != guess.size() || secret.empty()) {
             return "0A0B"; 
             }

        for (int i = 0; i < secret.size(); ++i) {
            char c1 = secret[i]; char c2 = guess[i];
            if (c1 == c2) {
                bulls++; 
            } else {

            //to convert the character c1 (a digit represented as a character) into its corresponding integer value.

            // Explanation:
            // Characters representing digits ('0' to '9') have ASCII values. For example:
            // '0' has an ASCII value of 48,
            // '1' has an ASCII value of 49,
            // '2' has an ASCII value of 50, and so on.
            // Subtracting '0' from a character gives its numerical value. For example:
            // '1' - '0' = 49 - 48 = 1

               secretFreq[c1 - '0']++;  // Increment frequency for the unmatched digit in `secret`
               guessFreq[c2 - '0']++;  // Increment frequency for the unmatched digit in `guess`
            }
        }
        // count b 
        for (int i = 0; i < secretFreq.size(); ++i) {

                //             The min(secretFreq[i], guessFreq[i]) ensures that only valid cows are counted by considering the overlap of unmatched digits between secret and guess.

                // Explanation:
                // secretFreq[i]: Number of times the digit i appears in secret but is not a bull.
                // guessFreq[i]: Number of times the digit i appears in guess but is not a bull.
                // The number of cows for digit i is limited by the smaller of these two values because:
                // A digit can only contribute to cows as many times as it appears in both secret and guess.
                // Example:
                // If secret = "1123" and guess = "0111":

                // Frequencies:
                // secretFreq[1] = 2, guessFreq[1] = 3
                // secretFreq[0] = 0, guessFreq[0] = 1
                // For digit 1, the possible cows are min(2, 3) = 2, because there are only 2 unmatched 1s in secret.
                // For digit 0, the possible cows are min(0, 1) = 0.
                // By taking the minimum, the function correctly handles overlapping digits and prevents over-counting.
            cows += min(secretFreq[i], guessFreq[i]);
        }
        return to_string(bulls) + 'A' + to_string(cows) + 'B';
    }
};
