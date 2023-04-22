/*
Given a generic tree, find and return the node with second largest value in given tree.
Note: Return NULL if no node with required value is present.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.
Output Format :
The first and only line of output contains data of the node with second largest data.
Constraints:
Time Limit: 1 sec
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 
Sample Output 1 :
40
*/

#include <bits/stdc++.h>
using namespace std;

template <typename T>
class TreeNode {
public:
	T data;
	vector<TreeNode<T>*> children;

	TreeNode(T data) { this->data = data; }

	~TreeNode() {
		for (int i = 0; i < children.size(); i++) {
			delete children[i];
		}
	}
};

TreeNode<int>* takeInputLevelWise() {
	int rootData;
	cin >> rootData;
	TreeNode<int>* root = new TreeNode<int>(rootData);

	queue<TreeNode<int>*> pendingNodes;

	pendingNodes.push(root);
	while (pendingNodes.size() != 0) {
		TreeNode<int>* front = pendingNodes.front();
		pendingNodes.pop();
		int numChild;
		cin >> numChild;
		for (int i = 0; i < numChild; i++) {
			int childData;
			cin >> childData;
			TreeNode<int>* child = new TreeNode<int>(childData);
			front->children.push_back(child);
			pendingNodes.push(child);
		}
	}

	return root;
}

// Given a generic tree, find and return the node with second largest value in given tree.
// Note: Return NULL if no node with required value is present.
pair<pair<TreeNode<int>*, int> , pair<TreeNode<int>*, int>> helper(TreeNode<int>* root) {
	pair<pair<TreeNode<int>*, int> , pair<TreeNode<int>*, int>>p;
	p.first.first = nullptr;
	p.first.second = 0;
	p.second.first = root;
	p.second.second = root->data;

	for (int i = 0; i < root->children.size(); ++i)
	{
		pair<pair<TreeNode<int>*, int> , pair<TreeNode<int>*, int>>x = helper(root->children[i]);
		if(x.first.second > p.second.second){
			p = x;
		}else if(x.second.second > p.second.second){
			if(x.first.second > p.second.second){
				p.first = x.first;
			}else{
				p.first = p.second;
			}
			p.second = x.second;
		}else if(p.second.second > x.second.second && p.first.second <= x.second.second){
			p.first = x.second;
		}
	}
	return p;
}

TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
	return helper(root).first.first;
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		TreeNode<int>* root = takeInputLevelWise();

		TreeNode<int>* ans = getSecondLargestNode(root);

		if (ans != NULL) {
			cout << ans->data << endl;
		}
	}

}