// TIME LIMIT EXCEEDED
// DO NOT RECOMMEND THIS APPROACH

class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    int max_area = 0;

    for (int i = 0; i < heights.size(); ++i) {
      for (int j = i; j < heights.size(); ++j) {
        int min_height =
            *min_element(heights.begin() + i, heights.begin() + j + 1);
        max_area = max(max_area, min_height * (j - i + 1));
      }
    }

    return max_area;
  }
};
