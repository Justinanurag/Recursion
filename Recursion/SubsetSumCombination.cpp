#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
//Function of Combination
void subSetSumCombinations(int ind,vector<int>& arr,int n,vector<int>& ans,int sum){
    if(ind==n){
        ans.push_back(sum);
        return;
    }
    //element picked
    subSetSumCombinations(ind+1,arr,n,ans,sum+arr[ind]);
    //element not picked
    subSetSumCombinations(ind+1,arr,n,ans,sum);
}

vector<int> subSetSum(vector<int>& arr){
    int n=arr.size();
    vector<int> ans;
    subSetSumCombinations(0,arr,n,ans,0);
    sort(ans.begin(),ans.end());
    return ans;
}
int main() {
    vector<int> arr = {3, 1, 2};
    vector<int> result = subSetSum(arr);
    
    // Printing the subset sums
    cout << "Subset sums: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}