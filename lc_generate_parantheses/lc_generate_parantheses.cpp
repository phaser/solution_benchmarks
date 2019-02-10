#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;
class Solution {
public:
    string solution_to_string(int* sol, int n) {
        string result;
        result.reserve(2*n);
        int j = 0;
        for (int i = 0; i < 2*n; i++) {
            result.push_back((j < n && i == sol[j] ? '(' : ')'));
            j += (j < n && i == sol[j]) ? 1 : 0;
        }
        return result;
    }
    
    vector<string> generateParenthesis(int n) {
        int sol[128];
        vector<string> result;
        for (int i = 0; i < n; i++) {
            sol[i] = i;
        }
        bool solPossible = true;
        while (solPossible) {
            result.push_back(solution_to_string(sol, n));
            int ce = n - 1;
            sol[ce]++;
            while (ce >= 0 && sol[ce] > (2 * ce)) {
                ce--;
                if (ce >= 0) sol[ce]++;
                else {
                    solPossible = false;
                    break;
                }
            }
            while (++ce < n && ce > 0) { sol[ce] = sol[ce - 1] + 1; }
        }
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
