class Solution {
public:
  string nextClosestTime(string time) {
    // vector<char> digits{};
    map<int, char> digits{};
    string result = time;
    for (int i = 0; i < time.length(); i++) {
      if (time[i] != ':')
        digits[time[i] - '0'] = time[i];
    }
    if (digits.size() == 1)
      return time;
    // loop through time string, from back to front
    // time[4]
    int size = time.length();
    int digit = time[size - 1] - '0';
    auto itr = digits.rbegin();
    if (itr->first > digit) {
      // easy case
      auto it = digits.begin();
      while (it->first <= digit) {
        it++;
      }
      char c = it->second;
      result[size - 1] = c;
      return result;
    }
    // last digit is the largest
    // time[4]
    auto itrr = digits.begin();
    result[4] = itrr->second;
    // time[3]
    if (itr->first == result[3] - '0') {
      result[3] = itrr->second;
    } else {
      while (itrr->first <= result[3] - '0' && itrr != digits.end()) {
        itrr++;
      }
      if (itrr == digits.end()) {
        itrr = digits.begin();
        result[3] = itrr->second;
      } else {
        if (itrr->first <= 5)
          result[3] = itrr->second;
        else {
          itrr = digits.begin();
          result[3] = itrr->second;
        }
      }
    }
    // time[1]
    if (result[3] > time[3]) {
      return result;
    }
    itrr = digits.begin();
    if (itr->first == result[1] - '0') {
      result[1] = itrr->second;
    } else {
      while (itrr->first <= result[1] - '0') {
        itrr++;
      }
      if (result[0] - '0' <= 1) {
        if (itrr->first <= 9) {
          result[1] = itrr->second;
        }
      } else {
        if (itrr->first <= 3) {
          result[1] = itrr->second;
        } else {
          itrr = digits.begin();
          result[1] = itrr->second;
        }
      }
    }
    /*
    if(time[1]-'0' == itrr->first) {
        itrr++;
        time[1] = itrr->second;
    } else {
        time[1] = itrr->second;
    }
    8
    */
    return result;
  }
};
