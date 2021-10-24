#include <iostream>
using namespace std;

//global variables
//test hanoi
int * test_hanoi(int A[], int n){
    static int i=n-1, j=-1, k=-1;
    
    int *B = new int[n];
    int *C = new int[n];
    
    for(int i=0; i<n; i++)
    {
        C[i]=0;
        B[i]=0;
    }

    while(k!=n-1 && j!=n-1){
    if(k==-1)
    {
        C[k+1]=A[i];
        k++;
        i--;
    }

    if(j==-1)
    {
        B[j+1]=A[i];
        j++;
        i--;
    }

    int s=0;

    while(B[j]>C[s] && j!=-1 && k!=-1)
    {
        B[j+1]=C[s];
        j++;
        s++;
        k--;
    }

    s=0;

    while(C[k]>B[s] && k!=-1 && j!=-1)
    {
        C[k+1]=B[s];
        k++;
        s++;
        j--;
    }
    }
    if(j==n-1)
        return B;
    else
        return C;
}

//driver code
int main(){

    int n=8;
    cin>>n;

    int A[n];

    for(int i=0; i<n; i++)
        cin>>A[i];

    int *C = test_hanoi(A, n);

    for(int i=0; i<n; i++)
        cout<<C[i]<<" ";

    return 0;
}