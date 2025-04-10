#include<iostream>
using namespace std;
void swapNumber(int &a, int &b) {
	/*Method 01 using third variable
	int temp=a;
	a=b;
	b=temp;*/

	//method 02 using two variable
	/*a=a+b;
	b=a-b;
	a=a-b;*/
	//Method 03 using XOR bitwwise operator
	a=a^b;
	b=a^b;
	a=a^b;
}

int main() {
    int a=5,b=10;
    swapNumber(a,b);
    cout<<"After swapping a="<<a<<" b="<<b;
    return 0;
}