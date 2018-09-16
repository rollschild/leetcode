class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    if (heights.size() == 0)
      return 0;
    int size = heights.size();
    int area = heights[0];
    for (int i = 0; i < size; ++i) {
      for (int j = size - 1; j >= i; --j) {
        int height = heights[i];
        for (int k = i; k <= j; ++k) {
          height = min(height, heights[k]);
        }
        area = max(area, (j - i + 1) * height);
      }
    }
    return area;
  }
};
