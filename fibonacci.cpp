#include <iostream>
using namespace std;

//recursion
int fib(int n){
    if(n<=1)
        return n;

    return fib(n-2)+fib(n-1);
}
//loop
int Ifib(int n){
    int a=0, b=1, s=0;

    if(n<=1)
        return n;

    for(int i=2; i<=n; i++){
        s=a+b;
        a=b;
        b=s;
    }

    return s;
}
//optimized recursion
int F[100];//global variable

int Ofib(int n){

    if(n<=1)
    {
        F[n]=n;
        return n;
    }
    else
    {
        if(F[n-2]==-1)
            F[n-2]=Ofib(n-2);

        if(F[n-1]==-1)
            F[n-1]=Ofib(n-1);

        return F[n-2]+F[n-1];
    }
}
//driver code
int main(){
    int x;

    cin>>x;

    for(int i=0; i<100; i++)
        F[i]=-1;
        
    cout<<Ofib(x);

    return 0;
}