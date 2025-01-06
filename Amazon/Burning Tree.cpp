class Solution { 
public:
    
    // Function to build the graph representation of the tree
    void makeGraph(unordered_map<int, vector<int>> &adjList, int parent, TreeNode* currNode) {
        if (currNode == NULL) {  
            // Base case: if current node is NULL, return (no need to process further)
            return;
        }
        
        if (parent != -1) {  
            // If the parent is not -1 (i.e., it's a valid parent),
            // add an edge from the current node to its parent
            adjList[currNode->val].push_back(parent);
        }
        
        if (currNode->left != NULL) {  
            // If the current node has a left child, add an edge from the current node to its left child
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

    // Function to calculate the time required to spread the infection to all nodes
    int amountOfTime(TreeNode* root, int start) {
        
        unordered_map<int, vector<int>> adjList;  
        // Adjacency list to represent the tree as a graph (node value → list of connected nodes)
        
        makeGraph(adjList, -1, root);  
        // Build the graph starting with the root node and no parent (-1)
        
        queue<int> que;  
        // Queue for BFS to process nodes level by level
        
        unordered_set<int> visited;  
        // Set to keep track of visited nodes and avoid revisiting
        
        que.push(start);  
        // Start BFS from the given starting node
        
        visited.insert(start);  
        // Mark the starting node as visited
        
        int minutes = 0;  
        // Variable to keep track of time (minutes taken to spread infection)
        
        while (!que.empty()) {  
            // While there are nodes to process in the queue
            
            int n = que.size();  
            // Get the number of nodes at the current level (spread of infection occurs level by level)
            
            while (n--) {  
                // Process all nodes at the current level
                
                int curr = que.front();  
                // Get the current node from the front of the queue
                
                que.pop();  
                // Remove the current node from the queue
                
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
