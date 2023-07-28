/*
There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

Example 1:
Input: cardPoints = [1,2,3,4,5,6,1], k = 3
Output: 12
Explanation: After the first step, your score will always be 1. However, choosing the rightmost card first will maximize your total score. The optimal strategy is to take the three cards on the right, giving a final score of 1 + 6 + 5 = 12.

Example 2:
Input: cardPoints = [2,2,2], k = 2
Output: 4
Explanation: Regardless of which two cards you take, your score will always be 4.

Example 3:
Input: cardPoints = [9,7,7,9,7,7,9], k = 7
Output: 55
Explanation: You have to take all the cards. Your score is the sum of points of all cards.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        long long sum_total = 0;
        for(int i = 0 ; i < cardPoints.size(); i++){
            sum_total += cardPoints[i];
        }
        int i = 0;
        int j = 0;
        long long sum = 0;
        long long minSum = INT_MAX;
        int winSize = cardPoints.size()-k;
        if(winSize==0)return sum_total;
         
        while(j<cardPoints.size()){
            sum += cardPoints[j];
            if((j-i+1) < winSize){
                j++;
            }else if((j-i+1) == winSize){
                minSum = min(minSum,sum);
                sum -= cardPoints[i];
                i++;
                j++;
            }
        }
        return (sum_total - minSum);
    }
};