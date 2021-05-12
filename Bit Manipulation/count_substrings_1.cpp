// Count number of substrings starting and ending with 1

#include<iostream>
#include<string>
#include<cassert>

using namespace std; 

int countSubStr(string s){
    int countSetBits = 0;
    for(int i = 0; i < s.size(); i++)
        if(s[i] == '1')
            countSetBits++;
    
    return countSetBits*(countSetBits + 1)/2; 

}

int main() {
    string s = "1101001101101";
    cout<<countSubStr(s);
    return 0;
}