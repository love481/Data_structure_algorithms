#include<iostream>
using namespace std;
#define SIZE 10
//Time Complexity: O(NlogN)
template<class T>void heapify(T *arr, int n, int i);
template<class T>void heap_sort(T *arr, int n);
int main()
{
    float arr[SIZE]={5,13,3,7,8,8,3,6,15,9};
    heap_sort(arr,SIZE);
    for(int i=0;i<SIZE;i++)
        cout<<*(arr+i)<<" ";
    return 0;
}
template<class T>
void heap_sort(T *arr, int n)
{
    for(int i=n/2-1;i>=0;i--)
        heapify(arr,n,i);
    for(int i=n-1;i>=0;i--)
    {
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }
}
template<class T>
void heapify(T *arr, int n, int i)
{
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;
    if(l<n && *(arr+l)>*(arr+largest))
        largest=l;
    if(r<n && *(arr+r)>*(arr+largest))
        largest=r;
    if(largest!=i)
    {
        swap(*(arr+i),*(arr+largest));
        heapify(arr,n,largest);
    }
}

