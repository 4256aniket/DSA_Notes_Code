/*
Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.
*/
#include<bits/stdc++.h>
using namespace std;

int keypad(int num, string output[]) {
    string arr[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    if (num == 0) {
        output[0] = "";
        return 1;
    }
    int n = num % 10;
    int ans = keypad(num / 10, output);
    int copies = arr[n].size();
    int outputSize = copies * ans;

    int j = 0; int i = 0;
    for (int i = 0; i < copies - 1; i++) {
        for (int j = 0; j < ans; j++) {
            output[j + (i + 1)*ans] = output[j];
        }
    }

    int k = 0;
    for (int i = 0; i < copies; i++) {
        for (int j = 0; j < ans; j++) {
            output[k] = output[k] + arr[n][i];
            k++;
        }
    }
    return outputSize;
}


int main() {
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for (int i = 0; i < count && i < 10000; i++) {
        cout << output[i] << endl;
    }
    cout<<count<<endl;
    return 0;
}


// ad
// ae
// af
// bd
// be
// bf
// cd
// ce
// cf