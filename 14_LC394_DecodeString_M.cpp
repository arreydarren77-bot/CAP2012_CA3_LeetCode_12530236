#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> counts;
        stack<string> results;

        string current = "";
        int number = 0;

        for (char c : s) {
            if (isdigit(c)) {
                number = number * 10 + (c - '0');
            }
            else if (c == '[') {
                counts.push(number);
                results.push(current);

                number = 0;
                current = "";
            }
            else if (c == ']') {
                int repeat = counts.top();
                counts.pop();

                string temp = results.top();
                results.pop();

                for (int i = 0; i < repeat; i++) {
                    temp += current;
                }

                current = temp;
            }
            else {
                current += c;
            }
        }

        return current;
    }
};

int main() {
    Solution obj;

    string s = "3[a2[c]]";

    cout << "Decoded String: "
         << obj.decodeString(s);

    return 0;
}
