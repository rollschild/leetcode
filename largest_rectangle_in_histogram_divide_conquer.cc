class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    // Divide and conquer
    return calArea(heights, 0, heights.size() - 1);
  }

  int calArea(vector<int> &heights, int start, int end) {
    if (start > end)
      return 0;
    // auto pivot = min_element(heights.begin()+start, heights.begin()+end+1);
    // int pos = pivot - heights.begin();
    // int pivot_height = *pivot;

    int pos = start;
    int pivot_height = heights[pos];
    for (int i = start; i <= end; ++i) {
      if (heights[i] < pivot_height) {
        pos = i;
        pivot_height = heights[i];
      }
    }
    return max(
        pivot_height * (end - start + 1),
        max(calArea(heights, start, pos - 1), calArea(heights, pos + 1, end)));
  }
};
