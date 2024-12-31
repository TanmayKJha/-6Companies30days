class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        // Define the relative directions for the surrounding cells,
        // including the current cell itself in the middle (0,0)
        vector<vector<int>> directions{
            {-1, -1}, {-1, 0}, {-1, 1},  // Upper left, top, upper right
            {0, -1}, {0, 0}, {0, 1},     // Left, current cell, right
            {1, -1}, {1, 0}, {1, 1}      // Bottom left, bottom, bottom right
        };

        int m = img.size(); // Number of rows
        int n = img[0].size(); // Number of columns

        // Create a result matrix to store the smoothed image
        vector<vector<int>> matrix(m, vector<int>(n, 0));

        // Iterate through each cell in the input image
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                int sum_nbrs = 0; // Sum of values of valid neighboring cells
                int total_nbrs = 0; // Count of valid neighboring cells

                // Iterate through each direction to check surrounding cells
                for (auto &dir : directions) {

                    // Calculate new row and column indices based on direction
                    int i_new = i + dir[0];
                    int j_new = j + dir[1];

                    // Check if the new indices are within bounds of the image
                    if (i_new >= 0 && i_new < m && j_new >= 0 && j_new < n) {
                        sum_nbrs += img[i_new][j_new]; // Add the value of the valid neighbor
                        total_nbrs++; // Increment the valid neighbor count
                    }
                }

                // Calculate the average value of the valid neighboring cells
                // Assign it to the corresponding cell in the result matrix
                matrix[i][j] = sum_nbrs / total_nbrs;
            }
        }

        // Return the smoothed image
        return matrix;
    }
};
