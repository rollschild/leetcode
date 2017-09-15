class Solution {
    public:
    
    string dictionary = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    map<string, string> URLmap;
    string header = "http://tinyurl.com/";
    int len = header.length();
    string resolution = "";
    
    string getRandomString() {
        string randString = "";
        default_random_engine generator;
        uniform_int_distribution<int> distribution(0, 61);
        for(int i = 0; i < 6; ++i) {
            randString += dictionary[distribution(generator)];    
        }
        return randString;
    }
    
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {       
        resolution = getRandomString();
        if(URLmap.find(resolution) != URLmap.end()) return URLmap[resolution];
        else {
            URLmap[resolution] = longUrl;
            return header + resolution;         
        }
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        shortUrl.replace(0, len, ""); // you should NOT use len -1
        // second parameter of replace() is the number of chars to replace, NOT a position
        if(URLmap.find(shortUrl) != URLmap.end()) {
            return URLmap[shortUrl];
        }
        else return "";
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
