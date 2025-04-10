// 10-April-2025 Random problem at GFG
// Problem link-https://www.geeksforgeeks.org/problems/tower-of-hanoi-1587115621/1?itm_source=geeksforgeeks&itm_medium=article&itm_campaign=practice_card


#include<iostream>
using namespace std;
// Function to move n disks from source to destination using auxiliary
int towerOfHanoi(int n,int from,int to,int aux){
    if(n==0) return 0;
    if(n==1) return 1;
    // Move n-1 disks from source to auxiliary, using destination as auxiliary
    int count=towerOfHanoi(n-1,from,aux,to);
    //Last wale disk ko move kar do
    count=count+1;
    //n-1 wale disk ko auxiliary se destination pe le jao
    count=count+towerOfHanoi(n-1,aux,to,from);
    return count;
}

int main(){
    int n=3; // Number of disks
    int from=1; // Source rod
    int to=3; // Destination rod
    int aux=2; // Auxiliary rod
    int moves = towerOfHanoi(n, from, to, aux);
    cout << "Number of moves required: " << moves << endl;
    cout << "The sequence of moves is as follows:" << endl;
    // Display the moves
    for (int i = 1; i <= moves; i++) {
        cout << "Move disk " << i << " from rod " << from << " to rod " << to << endl;
    }
    cout << "Total moves: " << moves << endl;
    return 0;
}