#include <iostream>
using namespace std;

//pow function
double pow(int m, int n){
    int pow=1;
    
    if(n%2 != 0)
        pow=m;

    for(int i=1; i<=n/2; i++)
        pow *= (m*m);

    return pow;
}
//fact function
double fact(int n){
    int fact=1;
    for(int i=1; i<=n; i++){
        fact *= i;
    }
    return fact;
}
//test recursion
double test_e(int x, int n){
    if(n==0)
        return 1;
    else
        return pow(x, n)/fact(n) + test_e(x, n-1);
}
//----------------------------------------------------------------
//recursion
double e(int x, int n){
    static double p=1, f=1;
    double r;

    if(n==0)
        return 1;
    else {
        r = e(x, n-1);
        p *= x;
        f *= n;
        return r + p/f;
    }
}
//--------------------------------------------------------------------
//optimized loop (honour's method)
double Ie(int x, int n){
    double s=1;

    for(;n>0; n--){
        s = 1 + ((x*s)/n);
    }

    return s;
}
//optimized recursion (honour's method)
double Oe(int x, int n){
    static double s=1;

    if(n==0)
        return s;
   
    s = 1 + (x*s)/n;
    return Oe(x, n-1);
}
int main(){
    int x=0, n=0;

    cin>>x>>n;

    cout<<"e^"<<x<<" in "<<n<<" precision is: "<<Oe(x, n)<<endl;

    return 0;
}