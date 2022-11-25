#include<iostream>
using namespace std;
//Time Complexity: O(N**2)
//first find the largest and place it on last position and then find the second largest and place it on second last position and so on.
template<class T>void bubbleSort(T a[],int n)
{
    int i,j;
    T temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
}
int main()
{
    int a[10],n,i;
    cout<<"Enter the number of elements:"<<endl;
    cin>>n;
    cout<<"Enter the elements:"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    bubbleSort(a,n);
    cout<<"Sorted array is:"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    return 0;
}