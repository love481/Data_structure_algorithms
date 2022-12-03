#include<bits/stdc++.h>
using namespace std;
int minimize_coin(vector<int>coins,int amt,int *min_coins)
{
    int soln[amt+1];
    soln[0]=0;
    int total_no_sol[amt+1];
    memset(total_no_sol,0,sizeof total_no_sol);
    total_no_sol[0]=1;
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
            if(i-coin>-1)
                total_no_sol[i]+=total_no_sol[i-coin];
        }
    }
    return total_no_sol[amt];

}
int main(void)
{
    vector<int>coins{1,3,4};
    int total_sum=10;
    int min_coins[total_sum+1];
    int max_soln=minimize_coin(coins,total_sum,min_coins);
    cout<<"optimal_solutions is: ";
    while(total_sum>0)
    {
        cout<<min_coins[total_sum]<<" ";
        total_sum-=min_coins[total_sum];
    }
    cout<<endl;
    cout<<"max_no_of_solutions: "<<max_soln;
    cout<<endl;
}