class Solution {
public:
    string complexNumberMultiply(string a, string b) {
        int m, n, p, q;
        int result_l, result_r;
        int i = a.find('+');
        int j = b.find('+');
        m = stoi(a.substr(0, i), nullptr, 10);
        p = stoi(b.substr(0, j));
        n = stoi(a.substr(i+1, a.length()-2-i), nullptr, 10);
        q = stoi(b.substr(j+1, b.length()-2-j), nullptr, 10);
        result_l = m * p - n * q;
        result_r = m * q + n * p;
        return to_string(result_l) + "+" + to_string(result_r) + "i";
    }
};
