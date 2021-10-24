#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Array{
    int *A;
    int size;
    int length;
};

void display(struct Array *arr){

    printf("\n");

    for(int i=0; i<arr->length; i++)
        printf("%d ", arr->A[i]);
}

void append(struct Array *arr, int x){

    arr->A[arr->length++] = x;
}

void insert(struct Array *arr, int index, int x){
    
    for(int i=arr->length; i>index; i--)
        arr->A[i] = arr->A[i-1];

    arr->A[index] = x;
    arr->length++;
}

int deletion(struct Array *arr, int index){

    int x = arr->A[index];

    for(int i=index; i<arr->length-1; i++)
        arr->A[i] = arr->A[i+1];

    arr->length--;

    return x;
}

int linearSearch(struct Array arr, int key){

    for(int i=0; i<arr.length; i++)
        if(key == arr.A[i])
            return i;

    return -1;
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
int impLinearSearch(struct Array *arr, int key){

    for(int i=0; i<arr->length; i++)
    {
        if(key == arr->A[i])
        {
            //transposition
            swap(&arr->A[i-1], &arr->A[i]);
            return i-1;

            //move to head
            // arr->A[0] = arr->A[i];
            // return 0;
        }
    }

    return -1;
}

int BinarySearch(struct Array arr, int key){

    int l=0, h=arr.length;

    while(l<=h){

        int mid = (l+h)/2;

        if(key == arr.A[mid])
            return mid;
        else if(key < arr.A[mid])
            h = mid-1;
        else
            l = mid+1;
    }
    return -1;
}

int get(struct Array arr, int index){

    if(index>=0 && index<arr.length)
        return arr.A[index];

    return -1;
}

void set(struct Array *arr, int index, int x){

    if(index>=0 && index<arr->length)
        arr->A[index] = x;
}

int Max(struct Array arr){

    int maximum = arr.A[0];

    for(int i=1; i<arr.length; i++)
        if(arr.A[i] > maximum)
            maximum = arr.A[i];

    return maximum;
}

int Min(struct Array arr){

    int minimum = arr.A[0];

    for(int i=1; i<arr.length; i++)
        if(arr.A[i] < minimum)
            minimum = arr.A[i];

    return minimum;
}

int sum(struct Array arr){

    int total = arr.A[0];

    for(int i=1; i<arr.length; i++)
        total += arr.A[i];

    return total;
}

float avg(struct Array arr){

    return (float)sum(arr)/arr.length;
}

void reverse_space(struct Array *arr){

    int *B = (int *)malloc(arr->length*sizeof(int));

    for(int i=arr->length-1, j=0; i>=0; i--, j++)
        B[j] = arr->A[i];
    
    for(int i=0; i<arr->length; i++)
        arr->A[i] = B[i];
}

void reverse_swap(struct Array *arr){

    for(int i=0, j=arr->length-1; i<j; i++, j--)
        swap(&arr->A[i], &arr->A[j]);
}

void left_shift(struct  Array *arr){

    for(int i=0; i<arr->length-1; i++)
        arr->A[i] = arr->A[i+1];

    arr->length--;
}

void left_rotate(struct Array *arr){

    int first = arr->A[0];

    for(int i=0; i<arr->length-1; i++)
        arr->A[i] = arr->A[i+1];
    
    arr->A[arr->length-1] = first;
}

void insert_in_sorted(struct Array *arr, int x){

    int i = arr->length-1;

    while(arr->A[i] > x){

        arr->A[i+1] = arr->A[i];
        i--; 
    }
    arr->A[i+1] = x;
    arr->length++;
}

bool is_sorted(struct Array *arr){

    for(int i=0; i<arr->length-1; i++)
        if(arr->A[i] > arr->A[i+1]) return false;
    
    return true;
}

void shift_neg_left(struct Array *arr){
    
    int i=0, j=arr->length-1;

    while(i<j){

        while(arr->A[i]<0){i++;}
        while(arr->A[j]>=0){j--;}

        if(i<j)
            swap(&arr->A[i], &arr->A[j]);
    }
}

void merge(struct Array *arr1, struct Array *arr2, struct Array *arr3){

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

void Union(struct Array *arr1, struct Array *arr2, struct Array *arr3){

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

void Intersection(struct Array *arr1, struct Array *arr2, struct Array *arr3){

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

void Difference(struct Array *arr1, struct Array *arr2, struct Array *arr3){

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
    
    // //decleration
    // struct Array arr;
    
    // //initialization
    // arr.size = 10;
    // arr.A = (int *)malloc(arr.size*(sizeof(int)));

    // printf("enter the no. elements you want to enter: \n");
    // scanf("%d", &arr.length);

    // printf("Enter the elements:\n");
    
    // for(int i=0; i<arr.length; i++)
    //     scanf("%d", &arr.A[i]);

    // //printing
    // display(&arr);

    // //Appending
    // append(&arr, 50);
    // display(&arr);

    // //insert
    // insert(&arr, 2, 16);
    // display(&arr);

    // //delete
    // printf("\n%d", deletion(&arr, 5));
    // display(&arr);

    // //linearsearch
    // printf("\n%d", linearSearch(arr, 20));

    // //improved linear search
    // printf("\n%d", impLinearSearch(&arr, 20));
    // display(&arr);

    // //binary search
    // printf("\n%d", BinarySearch(arr, 25));

    // //get element
    // printf("\n%d", get(arr, 2));

    // //set element
    // set(&arr, 5, 60);
    // display(&arr);

    // //max element
    // printf("\n%d", Max(arr));

    // //min element
    // printf("\n%d", Min(arr));

    // //sum
    // printf("\n%d", sum(arr));

    // //avg
    // printf("\n%f", avg(arr));

    // //reverse space
    // reverse_space(&arr);
    // display(&arr);

    // //reverse swap
    // reverse_swap(&arr);
    // display(&arr);

    // //left shift
    // left_shift(&arr);
    // display(&arr);

    // //left rotate
    // left_rotate(&arr);
    // display(&arr);

    // //insert in sorted
    // insert_in_sorted(&arr, 22);
    // display(&arr);

    // //check sorted
    // printf("\n%d", is_sorted(&arr));

    // //shift -ve to left
    // arr.A[1] = -2;
    // arr.A[5] = -10;
    // arr.A[6] = -20;
    // arr.A[7] = 50;
    // arr.length = 8;

    // shift_neg_left(&arr);
    // display(&arr);

    //merge arrays
    struct Array arr1;
    int A[5] = {3, 8, 16, 20, 25};
    int B[5] = {4, 10, 12, 22, 23};
    arr1.A = A;
    arr1.length = 5;
    arr1.size = 5;
    struct Array arr2;
    arr2.A = B;
    arr2.length = 5;
    arr2.size = 5;

    struct Array arr3;
    merge(&arr1, &arr2, &arr3);
    display(&arr3);

    //union arrays
    int C[5] = {3, 6, 16, 20, 25};
    int D[5] = {6, 10, 20, 22, 23};
    arr1.A = C;
    arr1.length = 5;
    arr1.size = 5;
   
    arr2.A = D;
    arr2.length = 5;
    arr2.size = 5;

    Union(&arr1, &arr2, &arr3);
    display(&arr3);
    
    //Intersection
    Intersection(&arr1, &arr2, &arr3);
    display(&arr3);

    //difference
    Difference(&arr1, &arr2, &arr3);
    display(&arr3);

    return 0;
}