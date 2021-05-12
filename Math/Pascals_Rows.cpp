#include<iostream>
#include<vector>

using namespace std;

vector<int> pascals_row(int N){
    int prev = 1;
    vector<int> row = {prev};
    for(int i = 1; i <= N; i++){
        int curr;
        curr = prev*(N - i + 1)/i;
        row.push_back(curr);
        prev = curr;
    }
    return row;
}

int main(){
    int N;
    cout<<"Enter row number: ";
    cin>>N;
    vector<int> row = pascals_row(N);
    cout<<N<<"th row of Pascal's Triangle: ";
    for(int i = 0; i < row.size(); i++){
        cout<<row[i]<<" ";
    }
    cout<<endl;
    return 0;
}