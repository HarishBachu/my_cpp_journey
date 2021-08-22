//List all differences between 2 similar strings 
//Different from edit Distance 
//X = ABCDE y = BBCDE => Difference: -A +B B C D E

#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

void LCSLength(string A, string B, vector<vector<int>> &lookup) {
    int m = A.size();
    int n = B.size();
    for(int i = 0; i <= m; i++)
        lookup[i][0] = 0;

    for(int j = 0; j <= n; j++)
        lookup[0][j] = 0; 

    for(int i = 1; i <= m; i++) {
        for(int j = 0; j <= n; j++) {
            if(A[i-1] == B[j-1])
                lookup[i][j] = lookup[i-1][j-1] + 1;
            else 
                lookup[i][j] = max(lookup[i-1][j], lookup[i][j-1]);
        }
    }
}

void diff(string A, string B, int m, int n, vector<vector<int>> lookup) {
    
    //If character is the same
    if(m>0 && n>0 && A[m-1] == B[n-1]) {
        diff(A, B, m-1, n-1, lookup);
        cout<<" "<<A[m-1];
    }

    //If curr character of B not in A
    else if(n > 0 && (m == 0 || lookup[m][n-1] >= lookup[m-1][n])) {
        diff(A, B, m, n-1, lookup);
        cout<<" +"<<B[n-1];
    }

    //If curr character of A not in B
    else if(m > 0 && (n == 0 || lookup[m][n-1] < lookup[m-1][n])) {
        diff(A, B, m-1, n, lookup);
        cout<<" -"<<A[m-1];
    }
}

int main() {
    string A = "ABCDF";
    string B = "BBCDE";
    int m = A.size(), n = B.size();
    vector<vector<int>> lookup(m+1, vector<int>(n+1));

    LCSLength(A, B, lookup);
    
    diff(A, B, m, n, lookup);
    return 0;
}