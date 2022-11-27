#include <bits/stdc++.h>
using namespace std;
void find_subset(vector<int>&s,vector<int>&mask,int sum,int target_sum,int index)
{
    if (sum>target_sum)
        return;
    if (sum==target_sum)
    {
        for (int i=0;i<s.size();i++)
        {
          if(mask[i]==1)
            cout<<s[i]<<" ";
        }
        cout<<endl;
        return;
    }
    for (int i=index;i<s.size();i++)
    {
        mask[i]=1;
        sum+=s[i];
        find_subset(s,mask,sum,target_sum,i+1);
        mask[i]=0;
        sum-=s[i];
    }
}
int main(void)
{
  vector<int>s{3,4,8,2,9,6,3};
  int target_sum=15;
  vector<int>mask(s.size(),0);
  find_subset(s,mask,0,target_sum,0);
  return 0;


}