#include<iostream>
#include<vector>
using namespace std;
void merge(vector<int>& arr,int l,int m,int r){
    int n1=m-l+1;
    int n2=r-m;
    int L[n1];
    int R[n2];
    int k=l;
    //fill l
    for(int i=0;i<n1;i++){
        L[i]=arr[k];
        k++;
    }
    //fill r
    for(int i=0;i<n2;i++){
        R[i]=arr[k];
        k++;
    }
    int i=0,j=0;
    k=l;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        } else{
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=R[j];
        j++;
        k++;
    }
}
void mergeSort(vector<int>& arr,int l,int r){
    if(l>=r) return ;
    int m=(l+r)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}
int main(){
    vector<int> arr={5,2,8,1,9,3,7,
        6,4};   
        mergeSort(arr,0,arr.size()-1);
        for(int i=0;i<arr.size();i++){
            cout<<arr[i]<<" ";
            }
    return 0;
}