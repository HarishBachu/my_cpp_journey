// Given a number n, find the highest power of 2 that is smaller 
// or equal to n.

#include<iostream>
#include<algorithm>
#include<cassert>

using namespace std;

int find_pow_2 (int n) {
    int power = 1;
    while(power <= n){
        // cout<<power<<endl;
        power = power << 1;
    }
    return power >> 1;
}

int main() {
    cout<<find_pow_2(32);
    return 0;
}