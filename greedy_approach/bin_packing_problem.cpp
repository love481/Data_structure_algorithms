#include <bits/stdc++.h>
using namespace std;
void find_bins_required(vector<int>*weights,int capacity)
{
    sort(weights->begin(),weights->end());
    int result=0,bin_remainder[weights->size()];
    for (int i=weights->size()-1;i>=0;i--)
    {   int j=0;
        while(j<result)
        {
            if (bin_remainder[j]>=weights->at(i)) 
            {
                bin_remainder[j]=bin_remainder[j]-weights->at(i);
                break;
            }
            j++;
        }
        if (j==result)
        {
            bin_remainder[result]=capacity-weights->at(i);
            result++;
        }
    }
    cout<<result<<endl;

}
int main(void)
{
    vector<int>weights{2, 5, 4, 7, 1, 3, 8};
    int bin_capacity=10;
    find_bins_required(&weights,bin_capacity);

}