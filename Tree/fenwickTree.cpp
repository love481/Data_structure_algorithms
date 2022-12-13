#include<bits/stdc++.h>
using namespace std;
int get_sum(vector<int>&data,int index)
{
    int sum=0;
    index++;
    while(index>0)
    {
        sum+=data[index];
        index-=index&(-index);
    }
    return sum;
}
void insert_value(vector<int>&data,int index,int value)
{
    index++;
    while(index<=data.size()-1)
    {
        data[index]+=value;
        index+=index&(-index);

    }
}
vector<int> build_Binary_index_tree(vector<int>&data)
{
    vector<int>tree(data.size()+1,0);
    for(int i=0;i<data.size();i++)
    {
        insert_value(tree,i,data[i]);
    }
    return tree;
}
int main(void)
{
    vector<int>data{1,2,3,4,5,6,7,8};
    vector<vector<int>>index_range{
        {0,2},
        {1,5},
        {0,7}
    };
    vector<int>tree=build_Binary_index_tree(data);
    for (auto d:index_range)
    {
        cout<<d[0]<<" "<<d[1]<<" "<<get_sum(tree,d[1])-get_sum(tree,d[0]-1)<<endl;

    }

}