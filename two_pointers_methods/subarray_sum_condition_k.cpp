#include<bits/stdc++.h>
using namespace std;
//Time complexity:O(n)
int get_subarray_sum_greater_than_k(vector<int>&arr,int k)
{
    int start=0,end=0,sum=arr[start],count=0;
    while(start<arr.size() && end<arr.size())
    {
        if (sum<=k)
        {
            end++;
            if (end<arr.size())sum+=arr[end];
        }
        else{
            count+=arr.size()-end;
            sum-=arr[start];
            start++;
        }
    }
    return count;

}
int get_subarray_sum_less_than_equal_k(vector<int>&arr,int k)
{
    int start=0,end=0,sum=arr[start],count=0;
    while(start<arr.size() && end<arr.size())
    {
        if (sum<=k)
        {
            end++;
            if (start<=end)
                count+=end-start;
            if (end<arr.size())sum+=arr[end];
        }
        else{
            sum-=arr[start];
            start++;
        }
    }
    return count;

}
int main(void){
    vector<int>arr{ 1, 11, 2, 3, 15 };
    int k=9;
    int x=get_subarray_sum_greater_than_k(arr,k);
    int y=get_subarray_sum_less_than_equal_k(arr,k);
    cout<<x<<" + "<<y<<" = "<<int(arr.size()*(arr.size()+1)/2)<<endl;

}