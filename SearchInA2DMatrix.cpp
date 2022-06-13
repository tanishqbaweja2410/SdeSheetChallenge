class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        // Brute : Quadratic TC: O(N*N) 
        
        // Better: Linear Solution TC: O(m + n) SC: O(1)
//         int startRow = 0;
//         int startCol = n - 1;
        
//         while(startRow < m && startCol >= 0) {
//             if(matrix[startRow][startCol] == target) return true;
//             else if(matrix[startRow][startCol] < target) {
//                 startRow++;
//             }
//             else{
//                 startCol--;
//             }
//         }
//         return false;
        
        // Optimal: Binary Search on the Matrix as the first element of each row is greater than 
        // the last of previous row. TC: O(log(m*n)) SC: O(1)
        int s = 0;
        int e = m * n - 1;
        
        while(s <= e) {
            int mid = s + (e - s)/2;
            // find row and col using mid and no of columns
            int row = mid / n;
            int col = mid % n;
            if(matrix[row][col] == target) {
                return true;
            }
            else if(matrix[row][col] < target) {
                s = mid + 1;
            }
            else {
                e = mid - 1;
            }
        }
        return false;
        
        
    }
};