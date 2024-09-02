class Solution {
public int[][] matrixReshape(int[][] mat, int r, int c) {
    int rows = mat.length;
    int cols = mat[0].length;
    if (rows * cols != r * c) return mat;
    int[][] arr = new int[r][c];
    for (int i = 0; i < rows * cols; i++) {
        arr[i / c][i % c] = mat[i / cols][i % cols];
    }
    return arr;
}
}
