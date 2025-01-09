// T.C -O(N) //
// S.C-O(N)   // taken queue of size N
class Codec {
public:
    string serialize(TreeNode* root) {
        string result = "";
        if(root==NULL){
        return "";
        }
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node==NULL){
                result.append("#,");
            }else{
                result.append(to_string(node->val)+ ',');
                q.push(node->left);  // add left and right child even if its NULL
                q.push(node->right);
            }
          
        }
        return result;
    }

    TreeNode* deserialize(string data) {
        if(data.size()==0){
            return NULL;
        }

        stringstream result(data);
        string token;

        getline(result,token,',');
        TreeNode* root = new TreeNode(stoi(token));
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            getline(result,token,',');
            if(token == "#"){
                node->left =NULL;
            }else{
                TreeNode*leftNode = new TreeNode(stoi(token));
                node->left = leftNode;
                q.push(leftNode);
            }
            getline(result, token,',');
            if(token == "#"){
                node->right = NULL;
            }else{
               TreeNode* rightNode = new TreeNode(stoi(token));
               node->right = rightNode;
               q.push(rightNode); 
            }
        }

        return root;    
    }
};

