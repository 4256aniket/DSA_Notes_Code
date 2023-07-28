#include<bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
// 2 stack approach
void zigZagOrder(BinaryTreeNode<int> *root) {
    if(root==NULL) return;
    stack<BinaryTreeNode<int>*> s1;
    stack<BinaryTreeNode<int>*> s2;
    s1.push(root);
    
while((!s1.empty()) || (!s2.empty())){
        while(!s1.empty()){
        BinaryTreeNode<int>* top = s1.top();
        s1.pop();
        cout<<top->data<<" ";
        if(top->left) s2.push(top->left);
        if(top->right) s2.push(top->right);
    	}
        cout<<endl;
    
    	while(!s2.empty()){
        BinaryTreeNode<int>* top = s2.top();
        s2.pop();
        cout<<top->data<<" ";
        if(top->right!=NULL) s1.push(top->right);
        if(top->left!=NULL) s1.push(top->left);
    	}
    	cout<<endl;
	}
}


// Simple brute force approach

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	vector<int> rs;
    	
    	if(root == nullptr) return rs;
    	bool leftToright = true;
    	
    	queue<Node*> q;
    	q.push(root);
    	while(!q.empty()){
    	    int size = q.size();
    	    vector<int>ans(size);
    	    for(int i = 0 ;i<size;i++){
    	        Node* frontNode = q.front();
    	        q.pop();
    	        int index = leftToright ? i : size - i -1;
    	        ans[index] = frontNode->data;
    	        
    	        if(frontNode->left) q.push(frontNode->left);
    	        if(frontNode->right) q.push(frontNode->right);
    	    }
    	    leftToright = !leftToright;
    	    for(auto i : ans){
    	        rs.push_back(i);
    	    }
    	    
    	    
    	}
    	return rs;
    }
};
