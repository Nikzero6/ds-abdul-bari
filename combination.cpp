#include <iostream>
using namespace std;

int fact(int n){

    if(n==0)
        return 1;

    return fact(n-1)*n;
}
//formula based
int C(int n, int r){

    int a = fact(n);
    int b = fact(n-r);
    int c = fact(r);

    return a/(b*c);
}
//recursive - based on pascal triangle
int rC(int n, int r){

    if(r==0 || n==r)
        return 1;
    
    return rC(n-1, r-1)+rC(n-1, r);
}
//driver code
int main(){

    int n,r;

    cin>>n>>r;

    cout<<rC(n, r);

    return 0;
}