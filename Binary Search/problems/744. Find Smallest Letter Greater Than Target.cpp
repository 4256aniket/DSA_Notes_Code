/*
Given a characters array letters that is sorted in non-decreasing order and a character target, return the smallest character in the array that is larger than target.

Note that the letters wrap around.

For example, if target == 'z' and letters == ['a', 'b'], the answer is 'a'.
 

Example 1:
Input: letters = ["c","f","j"], target = "a"
Output: "c"

Example 2:
Input: letters = ["c","f","j"], target = "c"
Output: "f"

Example 3:
Input: letters = ["c","f","j"], target = "d"
Output: "f"
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = 0;
        int r = letters.size()-1;
        int index = 0;
        while(l<=r){
            int m = (l+r)/2;
            if(letters[m]<=target){
                index = m+1;
                l = m+1;
            }else{
                r = m-1;
            }
        }
        if(index == letters.size()){
            index = 0;
        }
        return letters[index];
    }
};