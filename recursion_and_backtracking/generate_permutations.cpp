#include<iostream>
#include<vector>
using namespace std;
//recursion tree
//      [1,2,3]   i==0
//      /  |  \
//  [1,2,3] [2,1,3] [2,3,1]      i==1
//  /    \     /    \        /    \
//[1,2,3] [1,3,2] [2,1,3] [2,3,1] [3,1,2] [3,2,1] i==2 and backtrack and return to i=1
void generate_permutations(vector<int>&arr,int i)
{
    if(i==arr.size())
    {
        for(int j=0;j<arr.size();j++)
            cout<<arr[j]<<" ";
        cout<<endl;
    }
    else
    {
        for(int j=i;j<arr.size();j++)
        {
            swap(arr[i],arr[j]);
            generate_permutations(arr,i+1);
            swap(arr[i],arr[j]);
        }
    }

}
int main(void)
{
    vector<int>v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
     int x;
     cin>>x;
     v.push_back(x);

    }
    generate_permutations(v,0);
}