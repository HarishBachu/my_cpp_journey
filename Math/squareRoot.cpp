#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

int sqrt(int A){
    long long low = 0;
    long long high = A/2;
    long long mid;
    if(A == 0 || A == 1){
        return A;
    }
    while(low!=high - 1){
        mid = (high + low)/2;
        // cout<<"Low: "<<low<<"\nHigh: "<<high<<"\nMid: "<<mid<<"\n";
        if(mid*mid == A){
            cout<<"1st if"<<endl;
            return mid;
        }
        else if(mid*mid < A && (mid+1)*(mid+1) > A){
            cout<<"2nd if"<<endl;
            return mid;
        }
        else if(mid*mid < A){
            cout<<"3rd if"<<endl;
            low = mid;
        }
        else if(mid*mid > A){
            cout<<"4th if"<<endl;
            high = mid;
        }
    }
    int d = abs(low*low - A) < abs(high*high - A) ? low : high;
    return d;
}

int main(){
    int a = 2;
    // cout<<sqrt(a)<<endl;
    cout<<-1%20;
    return 0;
}