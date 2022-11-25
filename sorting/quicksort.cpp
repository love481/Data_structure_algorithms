#include<iostream>
using namespace std;
#define SIZE 10
//Time Complexity: O(NlogN)
//based on divide and conquer approach (recursive)
//first of all first element is treated as pivot and then all element greater than
//pivot from last indices to first indices are swapped with with the counting indices to keep track of
//larger elements on the right side of pivot and smaller elements on the left side of pivot
template<class T>int partition(T *arr, int l, int r);
template<class T>void quick_sort(T *arr, int l, int r);
template<class T>void swap(T *a, T *b)
{
    T temp=*a;
    *a=*b;
    *b=temp;
}
int main()
{
    float arr[SIZE]={5,13,3,7,8,8,3,6,15,9};
    quick_sort(arr,0,SIZE-1);
    for(int i=0;i<SIZE;i++)
        cout<<*(arr+i)<<" ";
    return 0;
}
template<class T>void quick_sort(T *arr, int l, int r)
{
    if(l<r)
    {
        int p=partition(arr,l,r);
        quick_sort(arr,l,p-1);
        quick_sort(arr,p+1,r);
    }
}
template<class T> int partition(T *arr, int l, int r)
{
    T pivot=*(arr+l);
    int i=r+1;
    for(int j=r;j>l;j--)
    {
        if(*(arr+j)>=pivot) swap(arr+(--i),arr+j);
    }
    swap(arr+i-1,arr+l);
    return i-1;
}