#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int i, int j, vector<vector<int>> &a, int n, vector<string> &ans, string move, vector<vector<int>> &vis) {
        if (i == n - 1 && j == n - 1) {
            ans.push_back(move);
            return;
        }
        
        // Downward
        if (i + 1 < n && !vis[i + 1][j] && a[i + 1][j] == 1) {
            vis[i][j] = 1;
            solve(i + 1, j, a, n, ans, move + 'D', vis);
            vis[i][j] = 0;
        }
        
        // Left
        if (j - 1 >= 0 && !vis[i][j - 1] && a[i][j - 1] == 1) {
            vis[i][j] = 1;
            solve(i, j - 1, a, n, ans, move + 'L', vis);
            vis[i][j] = 0;
        }
        
        // Right
        if (j + 1 < n && !vis[i][j + 1] && a[i][j + 1] == 1) {
            vis[i][j] = 1;
            solve(i, j + 1, a, n, ans, move + 'R', vis);
            vis[i][j] = 0;
        }
        
        // Upward
        if (i - 1 >= 0 && !vis[i - 1][j] && a[i - 1][j] == 1) {
            vis[i][j] = 1;
            solve(i - 1, j, a, n, ans, move + 'U', vis);
            vis[i][j] = 0;
        }
    }
    
    vector<string> findPath(vector<vector<int>> &mat) {
        int n = mat.size();
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        
        if (mat[0][0] == 1) {
            solve(0, 0, mat, n, ans, "", vis);
        }
        
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> maze = {{1, 0, 0, 0},
                                 {1, 1, 0, 1},
                                 {0, 1, 0, 0},
                                 {1, 1, 1, 1}};
    
    vector<string> paths = sol.findPath(maze);
    
    if (paths.empty()) {
        cout << "No path found" << endl;
    } else {
        for (string path : paths) {
            cout << path << endl;
        }
    }
    
    return 0;
}
