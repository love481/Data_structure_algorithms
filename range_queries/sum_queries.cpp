#include<bits/stdc++.h>
using namespace std;
//Time complexity:O(n^2)+m < naive (m*k^2) for large m such that k<=n
void computer_recWindow_sum( vector<vector<int>>&data,int k,vector<vector<int>>input_rect_corner)
{
    for(int i=0;i<data.size();i++)
    {
    for(int j=0;j<data[0].size();j++){
        if (i==0 && j==0)data[0][0]=data[0][0];
        else if(i==0 && j>0)data[0][j]+=data[0][j-1];
        else if(j==0 && i>0)data[i][0]+=data[i-1][0];
        else data[i][j]+=data[i-1][j]+data[i][j-1]-data[i-1][j-1];
        cout<<data[i][j]<<"  ";
    }
     cout<<endl;
    }
    int x,y,value;
    for (int i=0;i<input_rect_corner.size();i++)
    {   x=input_rect_corner[i][0];
        y=input_rect_corner[i][1];
        if (x==0 && y==0)
          value=data[x+k-1][y+k-1];
        else if (x==0 && y>0)
          value=data[x+k-1][y+k-1]-data[x+k-1][y-1];
        else if (y==0 && x>0)
          value=data[x+k-1][y+k-1]-data[x-1][y+k-1];
        else
          value=data[x+k-1][y+k-1]+data[x-1][y-1]-data[x+k-1][y-1]-data[x-1][y+k-1];
        cout<<x<<" "<<y<<" "<<value<<endl;

    }
}
int main(void)
{
    vector<vector<int>>data{
        {1,1,1,1,1,1},
        {1,1,1,0,5,1},
        {1,1,0,1,1,1},
        {1,0,1,5,0,1},
        {1,1,1,0,1,1},
        {1,1,0,1,3,0}
    };
    int window_size=3;
    vector<vector<int>>input_rect_corner{
        {0,0},
        {1,2},
        {2,2}
    };
    computer_recWindow_sum(data,window_size,input_rect_corner);


}