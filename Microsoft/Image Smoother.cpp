class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        //avg of cell[i,j] = sum of all the adjacent cell + current cell/total no of cell

        vector<vector<int>> directions{
        {-1,-1}, {-1,0},{-1,1},
        {0,-1} , {0,0},{0,1},
        {1,-1},{1,0},{1,1}
        };

        
        int m = img.size();
        int n = img[0].size();
        
        vector<vector<int>>matrix(m,vector<int>(n,0));


        for(int i =0;i<m;i++){
            for(int j =0;j<n;j++){

                int sum_nbrs = 0;
                int total_nbrs = 0;

                for(auto &dir : directions){

                    int i_new = i+dir[0];
                    int j_new = j+dir[1];

                    if(i_new>=0 && i_new<m && j_new>=0 && j_new<n ) { //valid coordinate--handling index out of bound condition
                        sum_nbrs+= img[i_new][j_new];
                        total_nbrs++;
                    }
                    
                }
                 matrix[i][j] = sum_nbrs/total_nbrs;
            }
        }
        return matrix;        
    }
};
