/*
You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int i = 0, j = 0;
        list<int> l;
        while (j < nums.size()) {

            while (l.size() > 0 && nums[j] > l.back()) {
                l.pop_back();
            }

            l.push_back(nums[j]);

            if (j - i + 1 < k)j++;
            else if (j - i + 1 == k) {
                ans.push_back(l.front());
                if (nums[i] == l.front())l.pop_front();
                i++;
                j++;
            }

        }
        return ans;
    }
};

int main() {
    int n, k;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; ++i)cin >> v[i];
    cin >> k;
    Solution ob;
    vector<int> ans = ob.maxSlidingWindow(v, k);
    for (int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i] << " ";
    }
}
