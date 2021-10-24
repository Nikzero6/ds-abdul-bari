#include <iostream>
using namespace std;

void print_duplicates(int A[], int n){

    int last_duplicate = -1;
    for(int i=0; i<n; i++){
        if(A[i] == A[i+1] && A[i] != last_duplicate){
            cout<<A[i]<<" ";
            last_duplicate = A[i];
        }
    }
}

void print_and_count_duplicates(int B[], int n){

    for(int i=0; i<n; i++){
        if(B[i] == B[i+1]){
            int j = i+1;
            while(B[j] == B[i])j++;
            cout<<B[i]<<" repeats "<<j-i<<" times"<<endl;
            i = j-1;
        }
    }
}

void Hashing_duplicates(int A[], int n, int max){

    int H[max+1];
    for(int i=0; i<=max; i++)
        H[i] = 0;

    for(int i=0; i<n; i++){
        H[A[i]]++;
    }

    for(int i=0; i<=max; i++){
        if(H[i]>1)
            cout<<i<<" repeats "<<H[i]<<" times"<<endl;
    }
}

void duplicates_unsorted(int A[], int n){

    for(int i=0; i<n; i++){
        int count=1;
        if(A[i] != -1){
            for(int j=i+1; j<n; j++){
                if(A[j] == A[i]){
                    count++;
                    A[j] = -1;
                }
            }
            if(count>1)
                cout<<A[i]<<" repeats "<<count<<" times"<<endl;
        }
    }
}

int main(){

    //print duplicates in sorted array
    // int size;
    // cin>>size;
    // int A[size];
    // for(int i=0; i<size; i++)
    //     cin>>A[i];

    // print_duplicates(A, size);

    //find + count duplicates in sorted array
    // int n;
    // cin>>n;
    // int B[n];
    // for(int i=0; i<n; i++)
    //     cin>>B[i];

    // print_and_count_duplicates(B, n);

    //find + count duplicates in sorted array using Hash Table
    // int n, max;
    // cin>>n>>max;
    // int C[n];
    // for(int i=0; i<n; i++)
    //     cin>>C[i];

    // Hashing_duplicates(C, n, max);

    //find + count duplicates in unsorted array: O(n^2)
    // int n;
    // cin>>n;
    // int D[n];
    // for(int i=0; i<n; i++)
    //     cin>>D[i];

    // duplicates_unsorted(D, n);

    //find + count duplicates in unsorted array using Hashing Table: O(n)
    int n, max;
    cin>>n>>max;
    int E[n];
    for(int i=0; i<n; i++)
        cin>>E[i];

    Hashing_duplicates(E, n, max);

    return 0;
}