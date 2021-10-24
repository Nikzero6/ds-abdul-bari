#include <iostream>
using namespace std;

//recursion
int pow(int m, int n){

    if(n==0)
        return 1;
    else
        return m*pow(m, n-1);
}
//recursion optimized
int Opow(int m , int n){
    if(n==0)
        return 1;
    else if(n%2 == 0)
        return pow(m*m, n/2);
    else
        return m*pow(m*m, (n-1)/2);
}
//loop
int Ipow(int m, int n){
    int pow=1;
    
    if(n%2 != 0)
        pow=m;

    for(int i=1; i<=n/2; i++)
        pow *= (m*m);

    return pow;
}
int main(){
    int m,n;

    cin>>m>>n;

    cout<<"recursion: "<<pow(m,n)<<endl;
    cout<<"optimized recursion: "<<Opow(m,n)<<endl;
    cout<<"loop: "<<Ipow(m,n)<<endl;

    return 0;
}