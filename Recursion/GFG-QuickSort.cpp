// 12-April-2025 Random problem at GFG
// Problem link-// 10-April-2025 Random problem at GFG
// Problem link-https://www.geeksforgeeks.org/problems/tower-of-hanoi-1587115621/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card

#include<iostream>
#include<vector>
using namespace std;
//partition function to partition the array around a pivot element
int partition(vector<int>& arr,int low,int high){
    int pivot=arr[high];
    int Pi=low;
    for(int i=low;i<high;i++){
        if(arr[i]<=pivot){
            swap(arr[Pi],arr[i]);
            Pi++;
        }
    }
    swap(arr[Pi],arr[high]);
    return Pi;
}

// function to perform quicksort using recursion
void quickSort(vector<int>& arr,int low,int high){
    if(low>=high) return ;
    int Pi=partition(arr,low,high);
    quickSort (arr,low,Pi-1);
    quickSort(arr,Pi+1,high);
}

int main(){
    vector<int> arr = {3, 6, 8, 10, 1
        , 2, 1};
        quickSort(arr,0,arr.size()-1);
        cout << "Sorted array: ";
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
            }
    return 0;
}