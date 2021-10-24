#include <iostream>
using namespace std;

class Array{

    private:
        int *A;
        int size;
        int length;
        void swap(int *x, int *y);
    public:
        Array(){            //conor
            size = 10;
            length = 0;
            A = new int[size];
        }
        Array(int sz){      //parameterized conor
            size = sz;
            length = 0;
            A = new int[size];
        }
        ~Array(){           //deor
            delete []A;
        }
        //functions
        void set_array(int a[]);
        void set_length(int l);
        void display();
        void append(int x);
        void insert(int index, int x);
        int deletion(int index);
        int linearSearch(int key);
        int impLinearSearch(int key);
        int BinarySearch(int key);
        int get(int index);
        void set(int index, int x);
        int Max();
        int Min();
        int sum();
        float avg();
        void reverse_space();
        void reverse_swap();
        void left_shift();
        void left_rotate();
        void insert_in_sorted(int x);
        bool is_sorted();
        void shift_neg_left();
        void merge(Array *arr1, Array *arr2, Array *arr3);
        void Union(Array *arr1, Array *arr2, Array *arr3);
        void Intersection(Array *arr1, Array *arr2, Array *arr3);
        void Difference(Array *arr1, Array *arr2, Array *arr3);
};

void Array::set_array(int a[]){
    A = a;
}
void Array::set_length(int l){
    length = l;
}
void Array::display(){

    cout<<"\n";

    for(int i=0; i<length; i++)
        cout<<A[i]<<" ";
}

void Array::append(int x){

    A[length++] = x;
}

void Array::insert(int index, int x){
    
    for(int i=length; i>index; i--)
        A[i] = A[i-1];

    A[index] = x;
    length++;
}

int Array::deletion(int index){

    int x = A[index];

    for(int i=index; i<length-1; i++)
        A[i] = A[i+1];

    length--;

    return x;
}

int Array::linearSearch(int key){

    for(int i=0; i<length; i++)
        if(key == A[i])
            return i;

    return -1;
}

void Array::swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int Array::impLinearSearch(int key){

    for(int i=0; i<length; i++)
    {
        if(key == A[i])
        {
            //transposition
            swap(&A[i-1],&A[i]);
            return i-1;

            //move to head
            // A[0] = A[i];
            // return 0;
        }
    }

    return -1;
}

int Array::BinarySearch(int key){

    int l=0, h=length;

    while(l<=h){

        int mid = (l+h)/2;

        if(key == A[mid])
            return mid;
        else if(key < A[mid])
            h = mid-1;
        else
            l = mid+1;
    }
    return -1;
}

int Array::get(int index){

    if(index>=0 && index<length)
        return A[index];

    return -1;
}

void Array::set(int index, int x){

    if(index>=0 && index<length)
        A[index] = x;
}

int Array::Max(){

    int maximum = A[0];

    for(int i=1; i<length; i++)
        if(A[i] > maximum)
            maximum = A[i];

    return maximum;
}

int Array::Min(){

    int minimum = A[0];

    for(int i=1; i<length; i++)
        if(A[i] < minimum)
            minimum = A[i];

    return minimum;
}

int Array::sum(){

    int total = A[0];

    for(int i=1; i<length; i++)
        total += A[i];

    return total;
}

float Array::avg(){

    return (float)sum()/length;
}

void Array::reverse_space(){

    int *B = new int[length];

    for(int i=length-1, j=0; i>=0; i--, j++)
        B[j] = A[i];
    
    for(int i=0; i<length; i++)
        A[i] = B[i];
}

void Array::reverse_swap(){

    for(int i=0, j=length-1; i<j; i++, j--)
        swap(&A[i], &A[j]);
}

void Array::left_shift(){

    for(int i=0; i<length-1; i++)
        A[i] = A[i+1];

    length--;
}

void Array::left_rotate(){

    int first = A[0];

    for(int i=0; i<length-1; i++)
        A[i] = A[i+1];
    
    A[length-1] = first;
}

void Array::insert_in_sorted(int x){

    int i = length-1;

    while(A[i] > x){

        A[i+1] = A[i];
        i--; 
    }
    A[i+1] = x;
    length++;
}

bool Array::is_sorted(){

    for(int i=0; i<length-1; i++)
        if(A[i] > A[i+1]) return false;
    
    return true;
}

void Array::shift_neg_left(){
    
    int i=0, j=length-1;

    while(i<j){

        while(A[i]<0){i++;}
        while(A[j]>=0){j--;}

        if(i<j)
            swap(&A[i], &A[j]);
    }
}

void Array::merge(Array *arr1, Array *arr2, Array *arr3){

    int i=0, j=0, k=0;

    while(i<arr1->length && j<arr2->length){

        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else
            arr3->A[k++] = arr2->A[j++];
    }
    for(; i<arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    for(; j<arr2->length; j++)
        arr3->A[k++] = arr2->A[j];   

    arr3->length = arr1->length+arr2->length;
    arr3->size = arr1->size+arr2->size;
}

void Array::Union(Array *arr1, Array *arr2, Array *arr3){

    int i=0, j=0, k=0;

    while(i<arr1->length && j<arr2->length){

        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if(arr1->A[i]>arr2->A[j])
            arr3->A[k++] = arr2->A[j++];
        else
        {
            arr3->A[k++] = arr2->A[j++];
            i++;
        }
    }
    for(; i<arr1->length; i++)
        arr3->A[k++] = arr1->A[i];
    for(; j<arr2->length; j++)
        arr3->A[k++] = arr2->A[j];   

    arr3->length = k;
    arr3->size = arr1->size+arr2->size;
}

void Array::Intersection(Array *arr1, Array *arr2, Array *arr3){

    int i=0, j=0, k=0;

    while(i<arr1->length && j<arr2->length){

        if(arr1->A[i]<arr2->A[j])
            i++;
        else if(arr1->A[i]>arr2->A[j])
            j++;
        else
        {
            arr3->A[k++] = arr2->A[j++];
            i++;
        }
    }
    
    arr3->length = k;
    arr3->size = arr1->size+arr2->size;
}

void Array::Difference(Array *arr1, Array *arr2, Array *arr3){

    int i=0, j=0, k=0;

    while(i<arr1->length && j<arr2->length){

        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++] = arr1->A[i++];
        else if(arr1->A[i]>arr2->A[j])
            j++;
        else
        {
            j++;
            i++;
        }
    }
    for(; i<arr1->length; i++)
        arr3->A[k++] = arr1->A[i];

    arr3->length = k;
    arr3->size = arr1->size+arr2->size;
}

int main(){
    
    //decleration
    Array arr;

    cout<<"enter the no. elements you want to enter: \n";
    int l;
    cin>>l;

    cout<<"Enter the elements:\n";
    
    for(int i=0; i<l; i++){
        int input;
        cin>>input;
        arr.append(input);
    }

    //printing
    arr.display();

    //Appending
    arr.append(50);
    arr.display();

    //insert
    arr.insert(2, 16);
    arr.display();

    //delete
    cout<<"\n"<<arr.deletion(5);
    arr.display();

    //linearsearch
    cout<<"\n"<<arr.linearSearch(20);

    //improved linear search
    cout<<"\n"<<arr.impLinearSearch(20);
    arr.display();

    //binary search
    cout<<"\n"<<arr.BinarySearch(25);

    //get element
    cout<<"\n"<<arr.get(2);

    //set element
    arr.set(5, 60);
    arr.display();

    //max element
    cout<<"\n"<<arr.Max();

    //min element
    cout<<"\n"<<arr.Min();

    //sum
    cout<<"\n"<<arr.sum();

    //avg
    cout<<"\n"<<arr.avg();

    //reverse space
    arr.reverse_space();
    arr.display();

    //reverse swap
    arr.reverse_swap();
    arr.display();

    //left shift
    arr.left_shift();
    arr.display();

    //left rotate
    arr.left_rotate();
    arr.display();

    //insert in sorted
    arr.insert_in_sorted(22);
    arr.display();

    //check sorted
    cout<<"\n"<<arr.is_sorted();

    //shift -ve to left
    // arr.A[1] = -2;
    // arr.A[5] = -10;
    // arr.A[6] = -20;
    // arr.A[7] = 50;
    // arr.length = 8;

    // arr.shift_neg_left();
    // arr.display();

    //merge arrays
    Array arr1;
    int A[5] = {3, 8, 16, 20, 25};
    int B[5] = {4, 10, 12, 22, 23};
    arr1.set_array(A);
    arr1.set_length(5);
    Array arr2;
    arr2.set_array(B);
    arr2.set_length(5);

    Array arr3;
    arr3.merge(&arr1, &arr2, &arr3);
    arr3.display();

    //union arrays
    int C[5] = {3, 6, 16, 20, 25};
    int D[5] = {6, 10, 20, 22, 23};
    arr1.set_array(C);
    arr1.set_length(5);
   
    arr2.set_array(D);
    arr2.set_length(5);

    arr3.Union(&arr1, &arr2, &arr3);
    arr3.display();
    
    //Intersection
    arr3.Intersection(&arr1, &arr2, &arr3);
    arr3.display();

    //difference
    arr3.Difference(&arr1, &arr2, &arr3);
    arr3.display();

    return 0;
}