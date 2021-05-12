// Find a pair with maximum product in array of integers.

#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>

using namespace std;

void maxProduct(vector<int> arr) {
    sort(arr.begin(), arr.end());
    int p1 = arr[0] * arr[1];
    int p2 = arr[arr.size() - 1] * arr[arr.size() - 2];
    if(p1 > p2)
        cout<<arr[0]<<" "<<arr[1];
    else
        cout<<arr[arr.size() - 2]<<" "<<arr[arr.size() - 1];
}

int main() {
    vector<int> vec = {1, 4, 3, 6, 7, 0};
    maxProduct(vec);
    return 0;
}