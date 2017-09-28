class Solution {
public:
    int toInt(char direction) {
        switch(direction) {
            case 'U':
                return 1;
            case 'D':
                return -1;
            case 'L':
                return -1;
            case 'R':
                return 1;
            default:
                return 0;
        }
    }
    bool judgeCircle(string moves) {
        int map[2] = {};
        for(int i = 0; i < moves.size(); ++i) {
            if(moves[i] == 'U' || moves[i] == 'D') {
                map[0] += toInt(moves[i]);
            }
            else {
                map[1] += toInt(moves[i]);
            }
        }
        if(map[0] == 0 && map[1] == 0) return true;
        else return false;
    }
};
