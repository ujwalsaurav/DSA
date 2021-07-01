class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int rowSize = matrix.size();
        int colSize = matrix[0].size();
        
        int row = 0;
        int col = matrix[0].size()-1;
        
        while(row < rowSize && col >= 0){
            if(matrix[row][col]==target)
                return true;
            else if(target > matrix[row][col])
                row++;
            else
                col--;
        }
        return false;        
    }
};