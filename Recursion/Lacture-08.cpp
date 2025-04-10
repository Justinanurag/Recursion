#include <bits/stdc++.h>
using namespace std;

void findCombinations(int index, vector<int>& candidates, int target, vector<int>& temp, vector<vector<int>>& result) {
    if (target == 0) {  // Agar sum exactly target ke equal ho gaya
        result.push_back(temp);  // Valid combination store karo
        return;
    }
    if (target < 0 || index == candidates.size()) return; // Agar target se zyada ho jaye to return

    // Current element ko include karo
    temp.push_back(candidates[index]);
    findCombinations(index, candidates, target - candidates[index], temp, result);
    temp.pop_back(); // Backtrack karo

    // Current element ko skip karo
    findCombinations(index + 1, candidates, target, temp, result);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> temp;
    findCombinations(0, candidates, target, temp, result);
    return result;
}

int main() {
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> ans = combinationSum(candidates, target);

    for (auto& comb : ans) {
        cout << "[ ";
        for (int num : comb) cout << num << " ";
        cout << "]\n";
    }
    return 0;
}
