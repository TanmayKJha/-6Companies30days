//USING BFS
//T.C -> O(N) : S.C -> O(N)

class Solution {  
public:   
    
    void makeGraph(unordered_map<int, vector<int>> &adjList, int parent, TreeNode* currNode) {  
        if (currNode == NULL) {  
             return;
        }
        
        if (parent != -1) {  
            //This line is adding the parent of current node for eg 5->1,4
            adjList[currNode->val].push_back(parent);
        }
        
        if (currNode->left != NULL) {  
           
            adjList[currNode->val].push_back(currNode->left->val);
        }
        
        if (currNode->right != NULL) {  
            // If the current node has a right child, add an edge from the current node to its right child
            adjList[currNode->val].push_back(currNode->right->val);
        }
        
        // Recursively build the graph for the left subtree
        makeGraph(adjList, currNode->val, currNode->left);
        
        // Recursively build the graph for the right subtree
        makeGraph(adjList, currNode->val, currNode->right);
    }

    
    int amountOfTime(TreeNode* root, int start) {
        
        unordered_map<int, vector<int>> adjList;  
     
        makeGraph(adjList, -1, root);    //O(N)
        
        queue<int> que;  
        
        unordered_set<int> visited;  
        
        
        que.push(start);  
        
        
        visited.insert(start);  
        
        int minutes = 0;  
        
        
        while (!que.empty()) {  
           
            
            int n = que.size();  
            
            while (n--) {  
                // Process all nodes at the current level
                
                int curr = que.front();  
                que.pop();  

                
                for (auto &ngbr : adjList[curr]) {  
                    // Iterate through all neighbors of the current node
                    
                    if (visited.find(ngbr) == visited.end()) {  
                        // If the neighbor has not been visited yet
                        
                        que.push(ngbr);  
                        // Add the neighbor to the queue to process in the next level
                        
                        visited.insert(ngbr);  
                        // Mark the neighbor as visited
                    }
                }
            }
            
            minutes++;  
            // Increment the minutes after processing one level
        }
        
        return minutes - 1;  
        // Return the total minutes taken, minus one because the last increment happens after the BFS completes
    }
};
