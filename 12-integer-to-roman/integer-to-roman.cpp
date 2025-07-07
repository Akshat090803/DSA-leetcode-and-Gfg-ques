class Solution {
public:
    string intToRoman(int num) {
        vector<int> value = {1000, 900, 500, 400, 100, 90, 50,
                             40,   10,  9,   5,   4,   1};
        vector<string> symbol = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                                 "XL", "X",  "IX", "V",  "IV", "I"};
        string result;
        int ind = 0;
        while (num && ind < value.size()) {

            if (num >= value[ind]) {
                num -= value[ind];
                result += symbol[ind];
            } else {
                ind++;
            }
        }
        return result;
    }
};