#include<bits/stdc++.h>
using namespace std;
void minimize_coin(vector<int>coins,int amt,int *min_coins)
{
    int soln[amt+1];
    soln[0]=0;
    for (int i=1;i<=amt;i++)
    {
        soln[i]=INT_MAX;
        for(auto &coin:coins)
        {
            if(i-coin>-1 && soln[i-coin]+1<soln[i])
            {
                soln[i]=soln[i-coin]+1;
                min_coins[i]=coin;
            }   
        }
    }

}
int main(void)
{
    vector<int>coins{1,3,4};
    int total_sum=10;
    int min_coins[total_sum+1];
    minimize_coin(coins,total_sum,min_coins);
    while(total_sum>0)
    {
        cout<<min_coins[total_sum]<<" ";
        total_sum-=min_coins[total_sum];
    }
    cout<<endl;
}