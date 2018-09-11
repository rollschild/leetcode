class Solution {
public:
  int maximalRectangle(vector<vector<char>> &matrix) {
    if (matrix.size() == 0)
      return 0;
    int row = matrix.size();
    int col = matrix[0].size();
    int area = 0;
    // left boundary and right boundary
    vector<int> left(col, 0);
    vector<int> right(col, col);

    vector<int> height(col, 0);
    for (int r = 0; r < row; ++r) {
      int cur_left = 0;
      int cur_right = col - 1;

      // height
      for (int j = 0; j < col; ++j) {
        if (matrix[r][j] == '1')
          ++height[j];
        else
          height[j] = 0;
      }
      // left
      for (int k = 0; k < col; ++k) {
        if (matrix[r][k] == '1') {
          left[k] = max(left[k], cur_left);
        } else {
          left[k] = 0;
          cur_left = k + 1;
        }
      }
      // right
      for (int l = col - 1; l >= 0; --l) {
        if (matrix[r][l] == '1') {
          right[l] = min(cur_right, right[l]);
        } else {
          right[l] = col;
          cur_right = l - 1;
        }
      }
      for (int m = 0; m < col; ++m) {
        area = max(area, (right[m] - left[m] + 1) * height[m]);
      }
    }
    return area;
  }
};
