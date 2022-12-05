#include<bits/stdc++.h>
using namespace std;
vector<bool>calculate_possible_options(vector<int>&weights,int W)
{
    vector<bool>possible(W+1);
    possible[0]=true;
    for(int k=0;k<weights.size();k++)
    {
        for(int w=W;w>=0;w--)
        {
            if (possible[w]==true)
               possible[w+weights[k]]=true;
        }
    }
    return possible;
}
int main(void){
        vector<int>weights{1,3,3,5};
        int W=12;
        vector<bool>possible_weights_formed=calculate_possible_options(weights,W);
        for (int i=0;i<possible_weights_formed.size()+1;i++)
        {
            if (possible_weights_formed[i]==true)
                cout<<i<<" ";
        }
        cout<<endl;
}
