#include <iostream>
using namespace std;

//recursion
int fact(int n){
    if(n==0)
        return 1;
    else
        return fact(n-1)*n;
}
//loop
int Ifact(int n){
    int fact=1;
    for(int i=1; i<=n; i++){
        fact *= i;
    }
    return fact;
}
int main(){
    int x=5;

    cout<<"recursion: "<<fact(x)<<endl;
    cout<<"loop: "<<Ifact(x)<<endl;
}