class Solution {
public:
// T.C = log26(columnNumber)
// S.C = O(1)
    string convertToTitle(int columnNumber) {
        string result = "";

        while(columnNumber>0){
            
            columnNumber--; // Decrement columnNumber by 1 to handle 1-based indexing (Excel titles start from 'A' as 1)

            int remainder = columnNumber%26;
            result+= remainder+'A';  // Convert the remainder to a character ('A' corresponds to 0, 'B' to 1, etc.)
            
            columnNumber = columnNumber/26;
            
        }
        reverse(result.begin(),result.end());
        return result;
        
    }
};

// After the loop, reversing the string takes O(log26(columnNumber)) time because the string length is equal to the number of iterations.
