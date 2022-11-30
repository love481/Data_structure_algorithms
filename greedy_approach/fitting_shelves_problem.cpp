#include <bits/stdc++.h>
using namespace std;
void find_best_fit(int wall,int m,int n)
{
    int max_x=wall/m,max_y=0,min_space=wall%m,rem;
    int x=max_x,y=max_y;
    while(wall>=n)
    { y+=1;
      wall=wall-n;
      x=wall/m;
      rem=wall%m;
      if (rem<=min_space)
      {
        min_space=rem;
        max_x=x;
        max_y=y;
      }

    }
    cout<<max_x<<" "<<max_y<<" "<<min_space<<endl;
}
int main(void)
{
    int wall,m,n;
    cin>>wall>>m>>n;
    find_best_fit(wall,m,n);
}