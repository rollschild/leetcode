class Solution {
public:
    int trap(vector<int>& height) {
        // use stack
        // the key is "bounded"
        stack<int> walls;
        int curr = 0;
        int water = 0;
        int size = height.size();
        while(curr < size) {
            while(!walls.empty() && height[curr] > height[walls.top()]) {
                // bounded
                
                int top = walls.top();
                int bar = height[top];
                walls.pop();
                if(walls.empty()) break;
                // now we have a new walls.top()
                int distance = curr - walls.top() - 1;
                if(height[walls.top()] > bar) {
                    water += distance * (min(height[walls.top()], height[curr]) - bar);
                }
            }
            walls.push(curr++);
         }
        return water;
    }
};
