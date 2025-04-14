//Date:14/04/2025
//Problem Name: Subsets
//Problem Link: https://leetcode.com/problems/subsets/description/
//Problem Type: Recursion
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> result;
int n;

void solve(vector<int>& nums, vector<int>& curr, int index) {
    if (index >= n) {
        result.push_back(curr);
        return;
    }

    // Include current element
    curr.push_back(nums[index]);
    solve(nums, curr, index + 1);

    // Exclude current element
    curr.pop_back();
    solve(nums, curr, index + 1);
}

vector<vector<int>> subsets(vector<int>& nums) {
    n = nums.size();
    result.clear();  // Clear previous results
    vector<int> curr;
    solve(nums, curr, 0);
    return result;
}

int main() {
    int size;
    cout << "Enter number of elements: ";
    cin >> size;

    vector<int> nums(size);
    cout << "Enter elements:\n";
    for (int i = 0; i < size; ++i) {
        cin >> nums[i];
    }

    vector<vector<int>> ans = subsets(nums);

    cout << "\nSubsets:\n";
    for (auto subset : ans) {
        cout << "[ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    cout << "\nTotal subsets: " << ans.size() << endl;

    return 0;
}
