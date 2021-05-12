// Maximum difference between two elements such that larger element 
// appears after the smaller number

#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>

using namespace std;

int maxDiff(vector<int> vec) {
    int minElem = vec[0];
    int maxDiff = 0;
    int diff;
    for(int i = 0; i < vec.size(); i++){
        if(vec[i] < minElem)
            minElem = vec[i];
        diff = vec[i] - minElem;
        if(diff >= maxDiff)
            maxDiff = diff;
    }
    return maxDiff;
}

int main() {
    vector<int> vec = {7, 9, 5, 6, 3, 2};
    cout<<maxDiff(vec);
    return 0;
}