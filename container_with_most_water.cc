// two pointer

class Solution {
public:
  int maxArea(vector<int> &height) {
    // two pointer
    int max_area = 0;
    int left = 0;
    int right = height.size() - 1;
    while (left < right) {
      max_area =
          max(max_area, min(height[left], height[right]) * (right - left));
      if (height[left] <= height[right])
        ++left;
      else
        --right;
    }
    return max_area;
  }
};
