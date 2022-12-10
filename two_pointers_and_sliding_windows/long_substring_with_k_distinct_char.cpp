#include<bits/stdc++.h>
using namespace std;
//Time complexity:O(n)
void get_long_substring_with_k_distinct_char(string str,int k)
{
    int start=0,end=0;
    unordered_map<char,int>ch;
    for (int i=0,j=0;j<str.length();j++)
    {
        ch[str[j]]++;
        while(ch.size()>k)
        {    
            if (--ch[str[i]]==0)ch.erase(str[i]);
            i++;
        }
        if (end-start<j-i)
        {
            end=j;
            start=i;
        }
    }
    cout<<str.substr(start, end - start + 1)<<endl;

}
int main(void){
    string str="abcdbdcd";
    int k=3;
    get_long_substring_with_k_distinct_char(str,k);

}