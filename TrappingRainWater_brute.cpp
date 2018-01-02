class Solution {
public:
    int trap(vector<int>& height) {
        int l = height.size();
        int bar = 0;
        int water = 0;
        int wall = 0;
        for(int i = 1; i < l - 1; ++i) {
            int max_left = 0;
            int max_right = 0;
            bar = height[i];
            for(int j = i-1; j >=0; --j) {
                max_left = max(max_left, height[j]);
            }
            for(int k = i+1; k < l; ++k) {
                max_right = max(max_right, height[k]);
            }
            wall = min(max_left, max_right);
            if(wall >= bar) water += wall - bar;
        }
        return water;
    }
};
