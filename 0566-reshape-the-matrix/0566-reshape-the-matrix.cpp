class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        
        // If the total number of elements doesn't match, return the original matrix
        if (m * n != r * c) {
            return mat;
        }
        
        // Initialize the new matrix with dimensions r x c
        vector<vector<int>> reshaped(r, vector<int>(c));
        
        // Treat both matrices as a single 1D array to map the values
        for (int i = 0; i < m * n; i++) {
            reshaped[i / c][i % c] = mat[i / n][i % n];
        }
        
        return reshaped;
    }
};