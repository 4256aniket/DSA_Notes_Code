#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vi vector<int>
#define vll vector<long long int>

const int MAX = 500;

int multiply(int x, int res[], int res_size)
{
    int carry = 0;
    for (int i = 0; i < res_size; i++) {
        int prod = res[i] * x + carry;
        res[i] = prod % 10;
        carry = prod / 10;
    }

// here carry can be of more than one digit
// since x can be 1 to 100

    while (carry) {
        res[res_size] = carry % 10;
        carry = carry / 10;
        res_size++;
    }
    return res_size;
}

string solve(int A) {
    int res[MAX];
    res[0] = 1;
    int res_size = 1;

    for (int x = 2; x <= A; x++) {
        res_size = multiply(x, res, res_size);
    }

    string s = "";
    for (int i = res_size - 1; i >= 0; i--) {
        s += to_string(res[i]);
    }
    return s;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    std::ios::sync_with_stdio(false);

    int n;
    cin >> n;
    cout << solve(n) << endl;

}