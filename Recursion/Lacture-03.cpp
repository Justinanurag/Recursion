//Sum of first N natural number
/*
// method 01
#include<iostream>
using namespace std;
int main(){
    int n;
  cout<<"Enter Number: "<<endl;
  cin>>n;
  int sum=n*(n+1)/2;
  cout<<"Sum of first "<<n<<" natural number is: "<<sum<<endl;
    return 0;
}*/

/*
// Method 02
#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter Number: "<<endl;
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++){
        sum=sum+i;
    }
    cout<<"Sum of first "<<n<<" natural number is: "<<sum<<endl;
    return 0;
}*/

/*
// Now using recursion
// parameterize way
#include<iostream>
using namespace std;
void function(int i,int sum){
    if(i<1){
        cout<<"sum of natural number is: "<<sum<<endl;
    }
    else{
        function(i-1,sum+i);
    }

}
int main(){
    int n;
    cout<<"Enter Number: ";
    cin>>n;
    function(n,0);

    return 0;
}*/
/*
//function recursion call
#include<iostream>
using namespace std;
int function(int n){
    if(n==0){
        return 0;
    }
    else{
        return n + function(n-1);
    }

}
int main(){
    int n;
    cout<<"Enter Number: ";
    cin>>n;
    cout<<function(n)<<endl;
        
}*/

//Factorial of a number using recursion
#include<iostream>
using namespace std;
int fact(int n){
    if(n==0){
        return 1;
    }
    else{
        return n*fact(n-1);
    }
}
int main(){
    int n;
    cout<<"Enter Number: ";
    cin>>n;
    cout<<fact(n)<<endl;
    return 0;
}