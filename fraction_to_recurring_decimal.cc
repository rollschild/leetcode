class Solution {
public:
  string fractionToDecimal(int numerator, int denominator) {
    string res = "";
    if (denominator == 0)
      return res;
    if (numerator == 0)
      return "0";
    if (numerator < 0 ^ denominator < 0) {
      res += "-";
    }
    long long up = abs((long long)numerator);
    long long down = abs((long long)denominator);
    long long result = up / down;
    long long remainder = up % down;
    res += to_string(result);
    if (remainder == 0) {
      return res;
    }
    res += ".";
    unordered_map<long long, long long> dict{};
    while (remainder != 0) {
      if (dict.find(remainder) != dict.end()) {
        // insert before pos
        res.insert(dict[remainder], "(");
        res += ")";
        break;
      }
      dict[remainder] = res.length();
      remainder *= 10;
      result = remainder / down;
      remainder = remainder % down;
      res += to_string(result);
    }
    return res;
  }
};
