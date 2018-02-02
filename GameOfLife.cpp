class Solution {
public:
    int livecount;
    int countLive(vector< vector<int> >& dup, int row, int col, int row_limit, int col_limit) {
        livecount = 0; // initialization
        if(row-1 >= 0 && col-1 >= 0) {
            if(dup[row-1][col-1]) ++livecount;
        }
        if(row-1 >= 0) {
            if(dup[row-1][col]) ++livecount;
            if(col+1 <= col_limit) {
                if(dup[row-1][col+1]) 
                    ++livecount;
            }
        }
        if(col-1 >= 0) {
            if(dup[row][col-1]) ++livecount;
            if(row+1 <= row_limit) {
                if(dup[row+1][col-1])
                    ++livecount;
            }
        }
        if(row+1 <= row_limit && col+1 <= col_limit) {
            if(dup[row+1][col+1]) ++livecount;
        }
        if(row+1 <= row_limit) {
            if(dup[row+1][col]) 
                ++livecount;
        }
        if(col+1 <= col_limit) {
            if(dup[row][col+1]) 
                ++livecount;
        }
        
        return livecount;
    }
    void gameOfLife(vector<vector<int>>& board) {
        vector< vector<int> > dup(board);
        int count = 0;
        for(int i = 0; i < board.size(); ++i) {
            for(int j = 0; j < board[i].size(); ++j) {
                count = countLive(dup, i, j, board.size()-1, board[i].size()-1);
                if(dup[i][j]) {
                    // if live
                    if(count < 2) board[i][j] = 0;
                    if(count > 3) board[i][j] = 0;
                }
                else {
                    // if dead
                    if(count == 3) board[i][j] = 1;
                }
            }
        }
    }
};
