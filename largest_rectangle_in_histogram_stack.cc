class Solution {
public:
  int largestRectangleArea(vector<int> &heights) {
    // using stack
    stack<int> stck;
    int max_area = 0;
    stck.push(-1);
    for (int i = 0; i < heights.size(); ++i) {
      /*
      if (i == 0) {
          stck.push(i);
          continue;
      }
      */
      while (stck.top() != -1 && heights[i] <= heights[stck.top()]) {
        int pos = stck.top();
        stck.pop();
        max_area = max((i - stck.top() - 1) * heights[pos], max_area);
      }
      stck.push(i);
    }
    int size = heights.size();
    while (stck.top() != -1) {
      int pos = stck.top();
      stck.pop();
      max_area = max((size - stck.top() - 1) * heights[pos], max_area);
      // stck.pop();
    }
    return max_area;
  }
};
