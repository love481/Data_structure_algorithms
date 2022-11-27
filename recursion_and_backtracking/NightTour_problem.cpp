#include<iostream>
#include<vector>
#define N 8
using namespace std;
int row[N] = {2, 1, -1, -2, -2, -1, 1, 2 };
int col[N] = {1, 2, 2, 1, -1, -2, -2, -1 };
bool Night_is_safe(vector<vector<int>>&chess,int r,int c)
{
    return (r>=0 && c>=0 && r<N && c<N && chess[r][c]==-1);
}
void find_solution(vector<vector<int>>&chess,int r,int c,int moves)
{
    if(moves==N*N)
    {
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
                cout<<chess[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
        return;
    }
    else
    {   int x,y;
        for (int j=0;j<N;j++)
        {
            x=r+row[j]; y=c+col[j];
            if (Night_is_safe(chess,x,y))
            { 
                chess[x][y]=moves+1;
                find_solution(chess,x,y,moves+1);
                chess[x][y]=-1;
            }
        }
    }
}
int main(void)
{
    vector<vector<int>>chess(N,vector<int>(N,-1));
    chess[0][0]=0;
    find_solution(chess,0,0,1);
    return 0;
}