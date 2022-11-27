#include<iostream>
#include<vector>
#define N 8
using namespace std;
bool queen_is_safe(vector<vector<int>>&chess,int r,int c)
{
    for (int i=0;i<r;i++)
    {
       if (chess[i][c]==1) return false;
    }
    for(int i=r-1,j=c-1;i>=0 && j>=0;i--,j--)
    {
        if (chess[i][j]==1) return false;
    }
     for(int i=r-1,j=c+1;i>=0 && j<N;i--,j++)
    {
        if (chess[i][j]==1) return false;
    }
    return true;
}
void find_solution(vector<vector<int>>&chess,int row)
{
    if(row==N)
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
                cout<<chess[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
    }
    else
    {
        for (int c=0;c<N;c++)
        {
            if (queen_is_safe(chess,row,c))
            {
                chess[row][c]=1;
                find_solution(chess,row+1);
                chess[row][c]=0;
            }
        }
         
    }
}
int main(void)
{
    vector<vector<int>>chess(N,vector<int>(N,0));
    find_solution(chess,0);
    return 0;
}