class Solution {
public:

    // Time Complexity -- O(m*n)+O(m*n) +o(m*n) ~ O(m*n)
    // Space Complexity -- O(m*n) --for queue
    #define P Pair<int,int>
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        int totalTime =0;
        int FreshOranges =0;
        queue<pair<int,int>>q;

        //O(row*col)
        for(int i =0;i<row;i++){
            for(int j = 0;j<col;j++){
                if(grid[i][j]==2){
                   q.push({i,j});
                }
                if(grid[i][j]==1){
                    FreshOranges++;
                }
            }
        }

        if(FreshOranges ==0){   // all the oranges are rotten so no fresh orange found
            return 0;
        }

        int rowChange[] = {-1,0,+1,0};
        int colChange[] = { 0,+1,0,-1};
        //TC-->(row*col)-->if all the oranges are fresh need to add all
        while(!q.empty()){
            
            int n = q.size();

            while(n--){
              pair<int,int> top = q.front();
              q.pop();

              int rowx = top.first;
              int coly = top.second;
              // this for loop check all the direction in which rotten orange can and make their ngbr infected
              //TC -- 4*(row*col)
              for(int i =0; i<4;i++){
                 int new_row = rowx + rowChange[i];
                 int new_col = coly + colChange[i];
              // checks new row and col are not out of bound && if at that row and col posn if their is fresh orange
                 if(new_row>=0 && new_row<row && new_col>=0 && new_col<col && grid[new_row][new_col]==1){
                    grid[new_row][new_col]=2;
                    FreshOranges--;
                    q.push({new_row,new_col});
                 }
              } 


            }
            if(!q.empty()){
                totalTime++;  //After processing one batch/level, if there are still rotten oranges in the queue (!q.empty()), it means the rotting process will continue, so we increment the minutes counter.
            }
        }
        if(FreshOranges==0){
            return totalTime;
        }else{
          return  -1;
        }

        // return (FreshOranges ==0) ? minutes:-1;
        
    }
};
