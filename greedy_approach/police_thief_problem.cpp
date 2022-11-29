#include <bits/stdc++.h>
using namespace std;
int catch_max_thief(vector<char>*seq,int max_dis)
{   vector<int> police,theif;
    int p=0,t=0,result=0;
     for (int i=0;i<seq->size();i++)
    {  
        if (seq->at(i) == 'P') police.push_back(i);
        else theif.push_back(i);
    }
    while(p<police.size() && t<theif.size())
    {
        if (abs(police[p]-theif[t])<=max_dis)
        {
            result++;
            p++;
            t++;

        }
        else if(police[p]<theif[t]) p++;
        else t++;
    }
    return result;


}
int main(void)
{
    vector<char>sequence{ 'P', 'T', 'P', 'T', 'T', 'P' };
    int max_dis=2;
    cout<<catch_max_thief(&sequence,max_dis)<<endl;
}
