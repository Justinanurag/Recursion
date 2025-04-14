//Problem Name:Power Set
//Problem Link: https://practice.geeksforgeeks.org/problems/power-set4302/1
//Problem Type: Recursion
//Date:14/04/2025
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int n;
vector<string> result;
void solve(string &s, string &curr,int index){
    if(index>=n){
        if(curr!=""){
            result.push_back(curr);
        }
        return;
    }
    // Exclude the current character
    curr.push_back(s[index]);
    solve(s,curr,index+1);
    curr.pop_back();//backtracking
    // Include the current character
    solve(s,curr,index+1);

}
vector<string> AllPossibleStrings(string s){
    result.clear();
    n =s.length();
    string curr="";
    solve(s,curr,0);
    sort(result.begin(),result.end());
    return result;
}
int main(){
    string s;
    cout<<"Enter the string: ";
    cin>>s;
    vector<string> ans = AllPossibleStrings(s);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    cout<<ans.size()<<endl;
    
    return 0;
}