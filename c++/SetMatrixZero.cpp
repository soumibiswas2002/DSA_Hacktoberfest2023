#include<bits/stdc++.h>
#include<iostream>
using namespace std;
//set rows replace with '-1' which are not 0
void replaceZeroRow(vector<vector<int>>& matrix, int n, int i){
    for(int j=0; j<n; j++){
        if(matrix[i][j] != 0){
            matrix[i][j] = -1;
        }
    }
}
//set columns replace with '-1' which are not 0
void replaceZeroCol(vector<vector<int>>& matrix, int m, int j){
    for(int i=0; i<m; i++){
        if(matrix[i][j] != 0){
            matrix[i][j] = -1;
        }
    }
}
vector<vector<int>> setZeroes(vector<vector<int>> &matrix, int n, int m){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(matrix[i][j] == 0){
                replaceZeroRow(matrix, n, i);
                replaceZeroCol(matrix, m, j);
            }
        }
    }
    //set zero to the places with '-1'
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(matrix[i][j] == -1){
                matrix[i][j]=0;
            }
        }
    }
    return matrix;
}
int main(){
    vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    int n = matrix.size();
    int m = matrix[0].size();
    cout << "Given matrix is: \n";
    for (auto it : matrix) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "\n";
    }
    vector<vector<int>> ans = setZeroes(matrix, n, m);

    cout << "The Final matrix is: \n";
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "\n";
    }
    return 0;    
}
