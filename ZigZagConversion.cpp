class Solution {
public:
    string convert(string s, int numRows) {
        int total = s.length();
        vector< vector<int> > arr(numRows, vector<int>(total, -1));
        int row = 0;
        int col = 0;
        bool up = false;
        string result = "";
        if(s.length() == 0) return result;
        if(numRows == 1) return s;
        for(int i = 0; i < total; ++i) {
            arr[row][col] = i;
            if(row < numRows && !up) ++row;
            if(row == numRows){
                up = true;
                row -= 2;
                ++col;
            }
            else if(row < numRows && up){
                up = true;
                --row;
                ++col;
            }
            if(row == 0) {
                up = false;
            }
        }
        for(int j = 0; j < numRows; ++j) {
            for(int k = 0; k < total; ++k) {
                if(arr[j][k] != -1) result += s[arr[j][k]];
            }
        }
        return result;
    }
};
