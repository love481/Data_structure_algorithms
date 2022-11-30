#include <bits/stdc++.h>
using namespace std;
void find_changes(vector<int>*coins,int amt)
{
    sort(coins->begin(),coins->end());
    vector<int>get_changes;
    for (int i=coins->size()-1;i>=0;i--)
    {
        while(amt>=coins->at(i))
        {
          amt=amt-coins->at(i);
          get_changes.push_back(coins->at(i));
        }
    }
    for(auto i:get_changes)
    {
        cout<<i<<" ";
    }
    cout<<endl;

}
int main(void)
{
    vector<int>coins{1,2,5,10,20,50,100,500,1000};
    int target_amt=600;
    find_changes(&coins,target_amt);

}