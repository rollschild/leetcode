class Solution {
public:
    vector<string> split(string& input) {
        vector<string> dic;
        stringstream ss(input);
        string str;
        while(getline(ss, str)) {
            dic.push_back(str);
        }
        return dic;
    }
    int lengthLongestPath(string input) {
        vector<string> paths = split(input);
        vector<int> level(256, 0);
        int maxlength = 0;
        for(auto sentence : paths) {
            int levl = sentence.find_last_of("\t") + 1;
            /*
            if(levl == 0) {
                level[levl] = sentence.length();
            }
            */
            level[levl+1] = level[levl] + sentence.length() - levl + 1; // you need to add '/'
            if(sentence.find('.') != std::string::npos) 
                maxlength = max(maxlength, level[levl+1] - 1);
                // maxlength = maxlength > (level[levl+1] - 1) ? maxlength : level[levl+1] - 1;
        }
        return maxlength;
    }
};
