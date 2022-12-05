#include<bits/stdc++.h>
using namespace std;
#define N 5
int max_path(vector<vector<int>>&matrix)
{
    for (int i=1;i<matrix.size();i++)
    {
        matrix[i][0]+=matrix[i-1][0];
    }
     for (int i=1;i<matrix[0].size();i++)
    {
        matrix[0][i]+=matrix[0][i-1];
    }
    for (int i=1;i<matrix.size();i++)
    {
        for(int j=1;j<matrix[0].size();j++)
        {
            matrix[i][j]=max(matrix[i][j-1],matrix[i-1][j])+matrix[i][j];            
        }
    }
    return matrix[matrix.size()-1][matrix[0].size()-1];
}
int main(void)
{
    vector<vector<int>>matrix
    {
        {3, 7, 9, 2, 7},
        {9, 8, 3, 5, 5},
        {1, 7, 9, 8, 6},
        {3, 8, 6, 4, 9},
        {6, 3, 9, 7, 8}
    };
    cout<<max_path(matrix)<<endl;

}