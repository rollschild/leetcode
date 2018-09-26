// TIME LIMIT EXCEEDED
// DO NOT RECOMMEND

class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    int max_area = 0;
    int min_height = 0;
    for (int i = 0; i < heights.size(); ++i) {
      min_height = heights[i];
      for (int j = i; j < heights.size(); ++j) {
        min_height = min(min_height, heights[j]);
        max_area = max(max_area, min_height * (j - i + 1));
      }
    }
    return max_area;
  }
};
