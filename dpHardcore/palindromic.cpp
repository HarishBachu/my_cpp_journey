//Find the length of the longest palindromic subsequence from a given sequence. 

#include<iostream>
#include<string>
#include<vector> 
#include<unordered_map>

using namespace std; 

int LPSLength(string seq, int start, int end) {
    if(start > end)
        return 0;

    if(start == end)
        return 1;
    
    if(seq[start] == seq[end])
        return LPSLength(seq, start+1, end-1) + 2;

    return max(LPSLength(seq, start+1, end), LPSLength(seq, start, end-1));
}

int main() {
    string s = "ABBDCACB";
    cout<<"Longest Palindromic Subsequence: "<<LPSLength(s, 0, s.size()-1);
}