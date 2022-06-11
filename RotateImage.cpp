// Leetcode Solution -> Rotate the matrix by 90deg clockwise
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // Take Transpose and then Reverse Each Row
        // TC: O(N*N) + O(N*N) SC: O(1)
        int n = matrix.size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(auto &temp : matrix) {
            reverse(temp.begin(), temp.end());
        }
    }
};


// CodeStudio Solution -> Rotate the elements of matrix by 90deg(Spiral Movement)
#include <bits/stdc++.h> 
void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{  
   // 4 variables
    int startRow = 0;
    int endRow = n - 1;
    int startCol = 0;
    int endCol = m - 1;
    int previous;
    

    while(startRow <= endRow && startCol <= endCol){
        
        if(startRow == endRow || startCol == endCol) break; 
        previous = mat[startRow + 1][startCol];
        
        // Start Row   
        for(int col=startCol;col<=endCol;col++){
            int temp = mat[startRow][col];
            mat[startRow][col] = previous;
            previous = temp;
        }
        startRow++;

        // End Col
        for(int row=startRow;row<=endRow;row++){
            int temp = mat[row][endCol];
            mat[row][endCol] = previous;
            previous = temp;
        }
        endCol--;

        // End Row
        if(startRow <= endRow){
            for(int col=endCol;col>=startCol;col--) {
                int temp = mat[endRow][col];
                mat[endRow][col] = previous;
                previous = temp;
            }
        }
        endRow--;

        // Start Col
        if(startCol <= endCol){
            for(int row=endRow;row>=startRow;row--){

                int temp = mat[row][startCol];
                mat[row][startCol] = previous;
                previous = temp;
            }
        }
        startCol++;
    }

}