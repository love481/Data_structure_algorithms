#include<iostream>
using namespace std;
#define SIZE 10
//Time Complexity: O(N**2)
void insertion_sort(int *arr)
{
    int i,j,key;
    for(i=1;i<SIZE;i++)
    {
        key=*(arr+i);
        j=i-1;
        while(j>=0 && *(arr+j)>key)
        {
            *(arr+j+1)=*(arr+j);
            j--;
        }
        *(arr+j+1)=key;
    }
}
int main()
{
    int arr[SIZE]={5,13,3,7,8,8,3,6,15,9};
    insertion_sort(arr);
    for(int i=0;i<SIZE;i++)
        cout<<*(arr+i)<<" ";
    return 0;
}