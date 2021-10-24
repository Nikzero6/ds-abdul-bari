#include <iostream>
using namespace std;

//recursion
int sum(int n){
    if(n==0)
        return 0;
    else
        return sum(n-1)+n;
}

//loop
int Isum(int n){
    int s=0;
    
    for(int i=1; i<=n; i++){
        s += i;
    }

    return s;
}
//formula
int Fsum(int n){
    return (n*(n+1))/2;
}
int main(){
    int x=10;

    cout<<"recursion: "<<sum(x)<<endl;

    cout<<"loop: "<<Isum(x)<<endl;

    cout<<"formula: "<<Fsum(x)<<endl;

    return 0;
}