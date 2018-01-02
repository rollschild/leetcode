class Solution {
public:
    int trap(vector<int>& height) {
        // now let's try the two-pointer method
        int size = height.size();
        int left = 0;
        int right = size - 1;
        int water = 0;
        int bar = 0;
        int max_left = 0;
        int max_right = 0;
        while(left < right) {
            if(height[left] < height[right]) {
                // depends on left wall
                if(height[left] <= max_left) water += max_left - height[left];
                else {
                    max_left = height[left];
                }
                ++left;
            }
            else {
                if(height[right] <= max_right) water += max_right - height[right];
                else {
                    max_right = height[right];
                }
                --right;
            }
        }
        return water;
    }
};
