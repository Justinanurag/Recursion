// 10-April-2025 Random problem at GFG
// Problem link-https://www.geeksforgeeks.org/problems/reverse-a-stack/1



#include<iostream>
#include<stack>
using namespace std;
// Function to reverse a stack using recursion
void reverseStack(stack<int>& st){
    //base case
    if(st.size()==0){
        return;
    }
    //top wale ko nikal lo
    int top =st.top();
    st.pop();
    //recursion
    reverseStack(st);
    //ek temp nam ke stack me daal do
    stack<int> temp;
    while(!st.empty()){
        temp.push(st.top());
        st.pop();
    }
    //ab top wale ko daal do
    while(!temp.empty()){
        st.push(temp.top());
        temp.pop();
    }
}

int main(){
    stack<int> st;
    st.push(3); 
    st.push(2);
    st.push(1);
    st.push(7);
    st.push(6);
    cout<<"Original Stack: ";
    stack<int> temp = st; // Create a copy of the original stack for display
    while(!temp.empty()){
        cout<<temp.top()<<" ";
        temp.pop();
    }
    cout<<endl;

    return 0;
}