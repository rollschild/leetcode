class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        map< string, vector <string> > result;
        vector< vector<string> > vec;
        for(auto dir : paths) {
            size_t first = dir.find(' ');
            string root;
            if(first != std::string::npos)
                root = dir.substr(0, first);
            else root = dir;
            dir.erase(0, first+1);
            int left = dir.find('(');
            int right = dir.find(')');
            while(left != string::npos && right != string::npos) {
                result[dir.substr(left+1, right-left-1)].push_back(root+'/'+dir.substr(0,left));
                if(right != dir.length()-1)
                    dir.erase(0, right+2);
                else dir.erase(0, right+1);
                left = dir.find('(');
                right = dir.find(')');
            }
        }
        // now we iterate through the map;
        for(map< string, vector<string> >::iterator itr = result.begin(); itr != result.end(); ++itr) {
            if(itr->second.size() >= 2) {
                // duplicate files exist
                vec.push_back(itr->second);
            }
        }
        return vec;
    }
};
