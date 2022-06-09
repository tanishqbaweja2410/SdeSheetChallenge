class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
//<------Possible Solutions that came to my mind with SC: O(1)-------->
//******* Brute Solution : TC -> O(m*n*(m+n)) SC -> O(1) **************

//         int m = matrix.size();
//         int n = matrix[0].size();
        
//         int marker = -1;
//         int ct = 0;
        
//         for(int i = 0; i < m; i++){
//             for(int j = 0; j < n; j++){
//                 if(matrix[i][j] == 0){
//                     ct++;  // ct to check the number of zeroes in the matrix
//                     int r = 0;
//                     while(r < m) {
//                         matrix[r][j] = (matrix[r][j] == 0) ? 0 : marker; 
//                         r++;
//                     }
//                     int c = 0;
//                     while(c < n) {
//                         matrix[i][c] = (matrix[i][c] == 0) ? 0 : marker; 
//                         c++;
//                     }
//                 }
//             }
//         }
        
//         if(ct == 0) return;
        
//         for(int i = 0; i < m; i++){
//             for(int j = 0; j < n; j++){
//                 if(matrix[i][j] == marker) matrix[i][j] = 0;
//             }
//         }
//         return;
        
//******** Optimised Solution: TC: O(m*n) SC: O(1) *****************
    int m = matrix.size();
    int n = matrix[0].size();
    int col0 = 1;  // flag variable for occurence of 0 in column 0
    
    for(int i = 0; i < m; i++) {
        if(matrix[i][0] == 0) col0 = 0;
        for(int j = 1; j < n; j++) {    
            if(matrix[i][j] == 0) {
                matrix[i][0] = matrix[0][j] = 0;
            }
        }
    }
    
    for(int i = m - 1; i >= 0; i--) {
        for(int j = n - 1; j >= 1; j--) {
            if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
        if(col0 == 0) matrix[i][0] = 0;
    }
    return;
        
    }
};