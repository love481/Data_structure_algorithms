#include<bits/stdc++.h>
using namespace std;
void find_longest_increasing_subsequences(vector<int>&data){
    int arr[data.size()];
    for(int i=0;i<data.size();i++)
    {
        arr[i]=1;
        for(int k=0;k<i;k++)
        {
            if (data[k]<data[i])
            {
                arr[i]=max(arr[i],arr[k]+1);
            }
        }
    }
    int largest_value=*max_element(arr,arr+data.size());
    int index=find(arr,arr+data.size(),largest_value)-arr;
    cout<<"largest_length_of_subsequences is: "<<largest_value<<" and end at: "<<index<<endl;
}
int main(void)
{
    vector<int>data{6,2,5,1,7,8,9};
    find_longest_increasing_subsequences(data);

}