/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes) {
    int rows = matSize;
    int cols = matColSize[0];

    if (rows * cols != r * c) {
        *returnSize = rows;
        *returnColumnSizes = matColSize;
        return mat;
    }

    int** result = malloc(r * sizeof(int*));
    *returnColumnSizes = malloc(r * sizeof(int));

    *returnSize = r;

    for (int i = 0; i < r; i++) {
        result[i] = malloc(c * sizeof(int));
        (*returnColumnSizes)[i] = c;
    }

    for (int i = 0; i < rows * cols; i++) {
        result[i / c][i % c] = mat[i / cols][i % cols];
    }

    return result;
}
