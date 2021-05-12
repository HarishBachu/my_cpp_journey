#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

int num_subarrays(vector<int> arr, int k){

    int start = 0, end = 0;
    int sum = arr[0];
    int count = 0;
    int n = arr.size();
    while(start < n && end < n){
        if(sum < k){
            end++;
            if(end >= start)
                count += end - start;
            if(end < n)
                sum += arr[end];
        }
        else{
            sum -= arr[start];
            start++;
        }
    }
    return count;
}

int main(){

    vector<int> arr = {1, 11, 2, 3, 15};
    int k = 10;
    cout<<num_subarrays(arr, k);
    return 0;
}