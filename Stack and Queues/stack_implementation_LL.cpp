#include<bits/stdc++.h>
using namespace std;

struct StackNode {
	int data;
	StackNode *next;
	StackNode(int a) {
		data = a;
		next = NULL;
	}
};

class MyStack {
private:
	StackNode *top;

public:
	void push(int x) {
		if (top == NULL) {
			StackNode* topNode = new StackNode(x);
			top = topNode;
		} else {
			StackNode* newNode = new StackNode(x);
			newNode->next = top;
			top = newNode;
		}
	}

	int pop() {
		if (top == NULL) return -1;
		int data = top->data;
		StackNode* a = top;
		top = top->next;
		delete a;
		return data;
	}

	MyStack() { top = NULL; }
};

// 1 x means push x
// 2 means pop
// Input
// 5
// 1 2 1 3 2 1 4 2
// output
// 3 4

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T;
	// No of test cases
	cin >> T;
	while (T--) {
		MyStack *sq = new MyStack();

		int Q;
		// No of push and pop queries
		cin >> Q;
		while (Q--) {
			int QueryType;
			cin >> QueryType;
			if (QueryType == 1) {
				int a;
				cin >> a;
				sq->push(a);
			} else if (QueryType == 2) {
				cout << sq->pop() << " ";
			}
		}
		cout << endl;
	}
}
