// Given a positive integer n, count the total number of set bits 
// in binary representation of all numbers from 1 to n. 

#include<iostream>

using namespace std;

int countSetBits(int n) {
    int i = 0;
    int ans = 0;

    while(1<<i <= n){
        bool k = 0;
        int change = 1<<i;
        for(int j = 0; j<= n; j++){
            ans+=k;
            if(change == 1){
                k = !k;
                change = 1<<i;
            }
            else
                change--;
        }
        i++;
    }
    return ans;
}

int main(){
    cout<<countSetBits(5)<<endl;
    return 0;
}