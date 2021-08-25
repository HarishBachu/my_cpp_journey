//Given an array of integers, print all subarrays with sum = 0 

#include<iostream>
#include<vector>
#include<cstring>
#include<unordered_map>

using namespace std; 

vector<pair<int, int>> sumZeroSubArrays(vector<int> vec, int n) {
    unordered_map<int, vector<int>> map;
    vector<pair<int, int>> ids; 

    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += vec[i]; 
        if(sum == 0)
            ids.push_back(make_pair(0, i));

        if(map.find(sum) != map.end()) {
            vector<int> vc = map[sum];
            for(auto it = vc.begin(); it != vc.end(); it++)
                ids.push_back(make_pair(*it+1, i));
        }

        map[sum].push_back(i);
    }
    return ids;
}

void print(vector<int> vec, vector<pair<int, int>> ids) {
    for(auto p : ids) {
        for(int i = p.first; i <= p.second; i++) 
            cout<<vec[i]<<" ";
        // cout<<p.first<<" "<<p.second;
        cout<<"\n";
    }
}

int main() {
    vector<int> vec = {6, 3, -1, -3, 4, -2, 2, 4, 6, -12, -7};
    const int n = vec.size(); 

    vector<pair<int, int>> ids = sumZeroSubArrays(vec, n);

    print(vec, ids);

    return 0;
}