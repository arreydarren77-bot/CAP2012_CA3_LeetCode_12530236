#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(
        vector<int>& nums1,
        vector<int>& nums2) {

        unordered_map<int, int> mp;
        stack<int> st;

        for (int num : nums2) {
            while (!st.empty() && st.top() < num) {
                mp[st.top()] = num;
                st.pop();
            }

            st.push(num);
        }

        vector<int> result;

        for (int num : nums1) {
            if (mp.find(num) != mp.end()) {
                result.push_back(mp[num]);
            }
            else {
                result.push_back(-1);
            }
        }

        return result;
    }
};

int main() {
    Solution obj;

    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    vector<int> result =
        obj.nextGreaterElement(nums1, nums2);

    cout << "Next Greater Elements: ";

    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}
