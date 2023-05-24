#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int l, int m, int r)
    {
         // Your code here
        int left_size = m - l + 1;
        int right_size = r - m;
        
        int left_arr[left_size + 1];
        int right_arr[right_size + 1];
        
        for(int i = 0; i < left_size; i++){
            left_arr[i] = arr[l + i];
        }
        
        for(int i = 0; i < right_size; i++){
            right_arr[i] = arr[m + 1 + i];
        }
        
        left_arr[left_size] = right_arr[right_size] = INT_MAX;
        int l_i = 0, r_i = 0;
        for(int i = l; i <= r; i++){
            if(left_arr[l_i] <= right_arr[r_i]){
                arr[i] = left_arr[l_i++];
            }else{
                arr[i] = right_arr[r_i++];
            }
        }
    }

void mergeSort(int arr[], int l, int r){
    //code here
    if(l == r) return;
    
    int mid = l + (r - l)/2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, r);
    merge(arr, l, mid, r);
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
    	cin >> arr[i];
    }
	mergeSort(arr, 0, n-1);
	for(int i = 0; i < n; i++){
    	cout << arr[i] <<" "; 
    }
}