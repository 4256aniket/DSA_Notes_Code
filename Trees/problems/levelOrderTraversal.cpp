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

void printLevelWise(BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int>*> pendingNodes;
    
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    
    while(!pendingNodes.empty()){
    	BinaryTreeNode<int> *front = pendingNodes.front();
        if(front==NULL){
            if(pendingNodes.size()==1){
                pendingNodes.pop();
            }
        	else{
                pendingNodes.push(NULL);
        		pendingNodes.pop();
                cout<<endl;
        }
        }else{
            cout<<front->data<<" "; 
            pendingNodes.pop();
            if(front->left) pendingNodes.push(front->left);
            if(front->right) pendingNodes.push(front->right);
        }
        
    }
}   

BinaryTreeNode<int>* takeInput() {
    int rootData;

    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    printLevelWise(root);
}