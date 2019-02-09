#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        queue<string> toexpand;
        unordered_set<string> unique;
        toexpand.push("()");
        unique.emplace("()");
        for (int i = 1; i < n; i++) {
            unique.clear();
            int cnt = 2*i;
            while ((toexpand.front()).length() == cnt) {
                string cur = toexpand.front();
                for (int j = 0; j < 2*i; j++) {
                    string ns = cur.substr(0, j) + "()" + cur.substr(j);
                    if (unique.find(ns) == unique.end()) {
                        unique.emplace(ns);
                        toexpand.push(ns);
                    }
                }
                toexpand.pop();
            }
        }
        vector<string> result(unique.begin(), unique.end());
        return result;
    }
};

int main(int argc, char** argv)
{
    int n = atoi(argv[1]);
    Solution s;
    vector<string> result = s.generateParenthesis(n);
    return 0;
}
