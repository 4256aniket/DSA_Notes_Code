// Brute force

class Solution {
public:
    
    void inorder(TreeNode* root,vector<int> &v){
        if(root == nullptr) return;
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
    
    int getMinimumDifference(TreeNode* root) {
        vector<int> v;
        inorder(root, v);
        int mn = INT_MAX;
        for(int i = 0; i < v.size()-1; i++){
            mn = min(mn, abs(v[i]-v[i+1]));
        }
        return mn;
    }
};

// Better


class Solution {
public:
    int diff = INT_MAX;
    TreeNode *prev = NULL;
    
    void dfs(TreeNode *root) {
        
        if (root->left) dfs(root->left);

        if (prev) diff = min(diff, abs(prev->val - root->val));
        prev = root;

        if (root->right) dfs(root->right);
    }
    int getMinimumDifference(TreeNode *root) {
        dfs(root);
        return diff;
    }
};

