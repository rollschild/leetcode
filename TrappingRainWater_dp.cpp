class Solution {
public:
    int trap(vector<int>& height) {
        //  now we want to use dynamic programming
        if(height.size() == 0) return 0;
        int size = height.size();
        int water = 0;
        vector<int> left_wall(size, 0);
        vector<int> right_wall(size, 0);
        left_wall[0] = height[0];
        right_wall[size-1] = height[size-1];
        for(int i = 1; i < size; ++i) {
            left_wall[i] = max(height[i], left_wall[i-1]);
        }
        for(int j = size - 2; j >= 0; --j) {
            right_wall[j] = max(height[j], right_wall[j+1]);
        }
        for(int k = 1; k < size-1; ++k) {
            int bar = height[k];
            int wall = min(left_wall[k], right_wall[k]);
            if(wall >= bar) water += wall - bar;
        }
        return water;
    }
};
