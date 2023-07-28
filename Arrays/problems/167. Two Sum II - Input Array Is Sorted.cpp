/*
Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

Your solution must use only constant extra space.

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].
*/

#include <bits/stdc++.h>
using namespace std;

// Two pointer technique

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int i = 0, j = nums.size() - 1;
        while (i < j)
        {
            int sum = nums[i] + nums[j];
            if (sum == target)
                return {i + 1, j + 1};
            else if (sum > target)
                j--;
            else
                i++;
        }
        return {}; // not found
    }
};

// Binary Search technique

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int j = numbers.size();
        int index1 = 0;
        int index2 = 0;
        for (int i = 0; i < numbers.size() - 1; i++)
        {
            int temp = lower_bound(numbers.begin() + i + 1, numbers.end(), target - numbers[i]) - (numbers.begin() + i + 1);

            if (temp + i + 1 < j && numbers[temp + i + 1] == (target - numbers[i]))
            {
                index1 = i + 1;
                index2 = temp + i + 2;
                break;
            }
        }
        return {index1, index2};
    }
};