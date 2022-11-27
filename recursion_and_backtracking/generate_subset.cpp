#include<iostream>
#include<vector>
using namespace std;
void generate_subset(vector<int> &arr, int index, vector<int> &subset)
{
    if(index==arr.size())
    {
        for(int i=0;i<subset.size();i++)
            cout<<subset[i]<<" ";
        cout<<endl;
        return;
    }
    subset.push_back(arr[index]);
    generate_subset(arr,index+1,subset);
    subset.pop_back();
    generate_subset(arr,index+1,subset);
}
int main()
{
    vector<int> arr={1,2,3,4};
    vector<int> subset;
    generate_subset(arr,0,subset);
    return 0;
}