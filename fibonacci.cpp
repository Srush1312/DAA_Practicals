#include <iostream>
using namespace std;

int fibo_recur(int n) {
    if(n<=1) {
        return n;
    }

    return(fibo_recur(n-1)+fibo_recur(n-2));
}

int fib_iterative(int n){
    int a=0;
    int b=1,c;

    while(n>1) {
        c=a+b;
        a=b;
        b=c;
        n--;
    }
    return b;
}

int main() {
    int n;
    cout<<"Enter the number for fibonacci series: ";
    cin>>n;

    int ans;
    ans=fibo_recur(n);
    
    cout<<"Recursive fibonacci: "<<ans;
    cout<<endl;
    ans=fib_iterative(n);
    
    cout<<"Iterative fibonacci: "<<ans;
}
