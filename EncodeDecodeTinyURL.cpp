class Solution {
    public:
    map<int, string> URLmap;
    int id = 0;
    string header = "http://tinyurl.com/";
    int length = header.length();
    string resolution = "";
    public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        URLmap[id] = longUrl;
        resolution = header + to_string(id++);
        return resolution;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        shortUrl.replace(0, length, "");
        if(URLmap.find(atoi(shortUrl.c_str())) != URLmap.end()) {
            return URLmap[atoi(shortUrl.c_str())];
        }
        else return "";
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
