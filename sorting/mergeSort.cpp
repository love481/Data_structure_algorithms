#include<iostream>
using namespace std;
#define SIZE 10
//Time Complexity: O(NlogN)
//based on divide and conquer approach (recursive)
template<class T>void merge_sort(T *arr, int l, int r);
template<class T>void merge(T *arr, int l, int m, int r);
int main()
{
    float arr[SIZE]={5,13,3,7,8,0,3,6,7.0,9};
    merge_sort(arr,0,SIZE-1);
    for(int i=0;i<SIZE;i++)
        cout<<*(arr+i)<<" ";
    return 0;
}
template<class T>
void merge_sort(T *arr, int l, int r)
{
    if(l<r)
    {
        int m=l+(r-l)/2;
        merge_sort(arr,l,m);
        merge_sort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}
template<class T>
void merge(T *arr, int l, int m, int r)
{
    int i, j, k, n1 = m - l + 1, n2 =  r - m;
    T *L=new T[n1];
    T *R=new T[n2];
    for (i = 0; i < n1; i++)
        *(L+i) = *(arr + l + i);
    for (j = 0; j < n2; j++)
        *(R+j) = *(arr + m + 1+ j);
    i = 0,j=0,k=l;
    while (i < n1 && j < n2)
    {
        if (*(L+i) <= *(R+j)) *(arr+(k++)) =  *(L+(i++));
        else *(arr+(k++)) = *(R+(j++));
    }
    while (i < n1) *(arr+(k++)) = *(L+(i++));
    while (j < n2) *(arr+(k++)) = *(R+(j++));
}