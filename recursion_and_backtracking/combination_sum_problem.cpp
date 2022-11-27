#include <bits/stdc++.h>
using namespace std;
void find_subset(vector<int>&s,vector<int>&subset,int sum,int target_sum,int index)
{
    if (sum>target_sum || index>=s.size())
        return;
    if (sum==target_sum)
    {
        for (auto x:subset)
            cout<<x<<" ";
        cout<<endl;
        return;
    }
        subset.push_back(s[index]);
        sum+=s[index];
        find_subset(s,subset,sum,target_sum,index);
        subset.pop_back();
        sum-=s[index];
        find_subset(s,subset,sum,target_sum,index+1);
}
int main(void)
{
  vector<int>s{3,4,2,5};
  int target_sum=15;
  vector<int>subset;
  find_subset(s,subset,0,target_sum,0);
  return 0;
}