#include <iostream>
using namespace std;

template<class T>

class Array{
    private:
        T *A;
        int length;
        int size;
    public:
        Array(){
            size=10;
            length = 0;
            A = new T[size];
        }
        Array(int sz){
            size = sz;
            length = 0;
            A = new T[size];
        }
        ~Array(){
            delete []A;
        }
        //functions
        void display();
        void insert(int index, T x);
        T Delete(int index);
};

template<class T>
void Array<T>::display(){
    for(int i=0; i<length; i++)
        cout<<A[i]<<" ";

    cout<<endl<<endl;
}

template<class T>
void Array<T>::insert(int index, T x){
    for(int i=length; i>index; i++)
        A[i] = A[i-1];
    A[index] = x;
    length++;
}

template<class T>
T Array<T>::Delete(int index){
    int x = A[index];
    
    for(int i=index; i<length-1; i++)
        A[i] = A[i+1];
    length--;

    return x;
}

int main(){

    cout<<"int array"<<endl;

    Array<int> arr(5);
    arr.insert(0, 5);
    arr.insert(1, 15);
    arr.insert(2, 20);
    arr.insert(3, 25);
    arr.display();
    arr.Delete(2);
    arr.display();

    cout<<"char array"<<endl;

    Array<char> chr(5);
    chr.insert(0, 'a');
    chr.insert(1, 'c');
    chr.insert(2, 'f');
    chr.insert(3, 'v');
    chr.insert(4, 'h');
    chr.display();
    chr.Delete(3);
    chr.display();

    cout<<"float array"<<endl;

    Array<float> flt(5);
    flt.insert(0, 1.25);
    flt.insert(1, 2.25);
    flt.insert(2, 5.25);
    flt.insert(3, 8.69);
    flt.display();
    flt.Delete(1);
    flt.display();

    return 0;
}