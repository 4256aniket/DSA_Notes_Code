// Implement min stack with
// Space O(1)

class MinStack {
public:
	stack<long long> st;
	long long mn = INT_MAX;
	MinStack() {

	}

	void push(int val) {
		if (st.size() == 0) {
			mn = val;
		}
		if (val > mn) {
			st.push(val);
		} else {
			long long v = 1ll * val;
			st.push(v + (v - mn));
			mn = val;
		}
	}

	void pop() {
		if (st.top() > mn) {
			st.pop();
		} else {
			mn = 2 * mn - st.top();
			st.pop();
		}
	}

	int top() {
		return (st.top() > mn) ? st.top() : mn;
	}

	int getMin() {
		return mn;
	}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */