class Solution {
public:
    // using backtracking
    unordered_map<char, string> pattern_dict;
    unordered_map<string, char> string_dict;
    bool ifMatch(string& pattern, string& str, int p_pos, int s_pos) {
        int p_l = pattern.size();
        int s_l = str.size();
        if(p_pos == p_l || s_pos == s_l) {
            if(p_pos == p_l && s_pos == s_l) return true;
            return false;
        }
        
        bool insertion = false;
        for(int k = s_pos; k < s_l; ++k) {
            string piece = str.substr(s_pos, k - s_pos + 1);
            if(pattern_dict.find(pattern[p_pos]) != pattern_dict.end()) {
                if(pattern_dict[pattern[p_pos]] != piece) continue;
            }
            else if(string_dict.find(piece) != string_dict.end()) {
                if(string_dict[piece] != pattern[p_pos]) continue;
            }
            // new 
            else {
                pattern_dict[pattern[p_pos]] = piece;
                string_dict[piece] = pattern[p_pos];
                insertion = true;
            }
            if(ifMatch(pattern, str, p_pos+1, k +1)) return true;
            if(insertion) {
                pattern_dict.erase(pattern[p_pos]);
                string_dict.erase(piece);
            }
        }
        return false;
    }
    
    bool wordPatternMatch(string pattern, string str) {
        if(str.length() < pattern.length()) return false;
        return ifMatch(pattern, str, 0, 0);
    }
};
