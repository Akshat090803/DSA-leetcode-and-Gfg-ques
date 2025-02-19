class Solution {
public:
    string decodeString(string s) {
        stack<pair<string, int>> st; // Stack to store string and repeat count
        string current_string = "";
        int num = 0;

        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0'); // Handle multi-digit numbers       //for eg digit is 112 so it will be num=1 than num=11 than num=112
            } else if (c == '[') {
                st.push({current_string, num}); // Push current string and count
                current_string = "";
                num = 0;
            } else if (c == ']') {
                // string repeated_string = "";
                // for (int i = 0; i < st.top().second; ++i) {
                //     repeated_string += current_string;
                // }
                // current_string =
                //     st.top().first +
                //     repeated_string; // Combine with previous string
                // st.pop();

                //it can be wriiten like this also
                string prevString=st.top().first;
                for (int i = 0; i < st.top().second; ++i) {
                    prevString += current_string;
                }
                current_string=prevString;
                st.pop();

            } else {
                current_string += c; // Append character to current string
            }
        }

        return current_string;
    }
};