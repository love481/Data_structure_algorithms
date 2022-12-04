#include<bits/stdc++.h>
using namespace std;
#define N 5
int max_path(vector<vector<int>>&matrix)
{
    vector<vector<int>>mat(matrix.size()+1,vector<int>(matrix[0].size()+1));
    for (int i=1;i<=matrix.size();i++)
    {
        for(int j=1;j<=matrix[0].size();j++)
        {
            mat[i][j]=max(mat[i][j-1],mat[i-1][j])+matrix[i-1][j-1];            
        }
    }
    return mat[matrix.size()][matrix[0].size()];
}
int main(void)
{
    vector<vector<int>>matrix
    {
        {1, 2, 7, 1, 4},
        {3, 1, 2, 4, 5},
        {1, 2, 3, 6, 4},
        {2, -4, -1, 1, 4},
        {1, 1, 2, 5, 5},
    };
    cout<<max_path(matrix)<<endl;

}