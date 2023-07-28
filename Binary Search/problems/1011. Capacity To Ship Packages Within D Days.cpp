/*
A conveyor belt has packages that must be shipped from one port to another within days days.

The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.



Example 1:

Input: weights = [1,2,3,4,5,6,7,8,9,10], days = 5
Output: 15
Explanation: A ship capacity of 15 is the minimum to ship all the packages in 5 days like this:
1st day: 1, 2, 3, 4, 5
2nd day: 6, 7
3rd day: 8
4th day: 9
5th day: 10

Note that the cargo must be shipped in the order given, so using a ship of capacity 14 and splitting the packages into parts like (2, 3, 4, 5), (1, 6, 7), (8), (9), (10) is not allowed.
Example 2:

Input: weights = [3,2,2,4,1,4], days = 3
Output: 6
Explanation: A ship capacity of 6 is the minimum to ship all the packages in 3 days like this:
1st day: 3, 2
2nd day: 2, 4
3rd day: 1, 4
Example 3:

Input: weights = [1,2,3,1,1], days = 4
Output: 3
Explanation:
1st day: 1
2nd day: 2
3rd day: 3
4th day: 1, 1


Constraints:

1 <= days <= weights.length <= 5 * 104
1 <= weights[i] <= 500
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPossible(vector<int> weights, int mid, int days)
    {
        int day = 1, sum = 0; // minimum day and weight
        for (int i = 0; i < weights.size(); i++)
        {
            sum += weights[i];
            if (sum > mid)
            {
                day++;
                sum = weights[i];
            }
        }

        // for mid(weight) how much day it is taking? at next step we reduce wt if this is possible
        return day <= days;
    }

    int shipWithinDays(vector<int> &weights, int days)
    {
        int max_weight = *max_element(weights.begin(), weights.end()),
            total_weight = accumulate(weights.begin(), weights.end(), 0),
            least_weight; // final Answer

        // base case
        if (weights.size() == days)
            return max_weight;

        // search for minimum weight
        while (max_weight <= total_weight)
        {
            // weight to be shipped at a time (candidate)
            int mid = max_weight + (total_weight - max_weight) / 2;

            // function to know if we can allocate this weight(mid) to satisfy condition?
            if (isPossible(weights, mid, days))
            {
                least_weight = mid;

                // to find minimum weight ever after we find a possible candidate
                total_weight = mid - 1;
            }
            else
                max_weight = mid + 1;
        }
        return least_weight;
    }
};