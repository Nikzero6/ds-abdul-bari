#include <iostream>
using namespace std;

int single_missing(int A[], int h){
    int s = (h*(h+1))/2;
    int sum =0;

    for(int i=0; A[i] != h; i++)
        sum += A[i];
    sum += h;

    return s-sum;
}

int missing_Ap(int B[], int l, int h, int n){

    int diff = l-0;
    for(int i=0; i<n; i++){
        if(B[i]-i != diff){
            return diff+i;
            break;
        }
    }

    return -1;
}

void multiple_missing(int C[], int l, int h, int n){

    int diff = l-0;
    cout<<endl;
    for(int i=0; i<n; i++){
        if(C[i]-i != diff){
            while(diff<C[i]-i){
                cout<<diff+i<<" ";
                diff++;
            }
        }
    }
}
int main(){

    //single missing element in sorted array of natural nos.
    // int size;
    // cin>>size;
    // int h;
    // cin>>h;
    // int A[size];
    // for(int i=0; i<size; i++)
    //     cin>>A[i];

    // cout<<endl<<single_missing(A, h)<<endl;

    //single missing in sorted and any AP type sequence
    // int low, high, n;
    // cin>>low>>high>>n;

    // int B[n];
    // for(int i=0; i<n; i++)
    //     cin>>B[i];

    // cout<<endl<<missing_Ap(B, low, high, n)<<endl;

    //multiple missing elements in Ap
    int l, hi, no;
    cin>>l>>hi>>no;
    int C[no];
    for(int i=0; i<no; i++){
        cin>>C[i];
    }
    multiple_missing(C, l, hi, no);

    return 0;
}