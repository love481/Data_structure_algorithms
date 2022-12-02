#include <bits/stdc++.h>
using namespace std;
int find_changes(vector<int>&coins,int amt,int* values)
{
    if(amt<0) return 10000;
    if (amt==0) return 0;
    if (values[amt]!=0) return values[amt];
    int max_coin=10000;
    for (auto c:coins)
    {
        max_coin=min(max_coin,find_changes(coins,amt-c,values)+1);
    }
    values[amt]=max_coin;
    return max_coin;
}
int main(void)
{
    vector<int>coins{1,3,4};
    int target_amt=10;
    int values[target_amt+1];
    memset(values,0,sizeof values);
    cout<<find_changes(coins,target_amt,values)<<endl;

}