#include<bits/stdc++.h>
using namespace std;
bool calculate_possible_options(vector<int>&weights,int W,int k)
{
    
    if (W==0 && k==0)return true;
    if (W!=0 && k==0)return false;
    return calculate_possible_options(weights,W-weights[k-1],k-1)|calculate_possible_options(weights,W,k-1);
}
int main(void){
        vector<int>weights{1,3,3,5};
        int W=12;
        for(int x=0;x<=W;x++)
        {   int k=weights.size();
            bool value=calculate_possible_options(weights,x,k);
            if (value==true)
                cout<<x<<" ";
        }
        cout<<endl;
}
