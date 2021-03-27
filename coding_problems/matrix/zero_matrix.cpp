#include<bits/stdc++.h>
using namespace std;
void set_zero(vector<vector<int>> &matrix,vector<pair<int,int>> &zeros_positions) {
    for(int i = 0;i<zeros_positions.size();i++)
    {
        for(int j = 0;j<matrix.size();j++)
        {
            matrix[zeros_positions[i].first][j] = 0;
        }
    }

    for(int i = 0; i<zeros_positions.size();i++)
    {
        for(int j = 0;j<matrix.size();j++)
        {
            matrix[j][zeros_positions[i].second] = 0;
        }
    }
}
void zero_matrix(vector<vector<int>> &matrix) {
    vector<pair<int,int>> zeros_positions;
    for(int i = 0; i<matrix.size();i++)
    {
        for(int j = 0; j<matrix[i].size();j++)
        {
            if(matrix[i][j] == 0 )
            zeros_positions.push_back(make_pair(i,j));
        }
    }
    set_zero(matrix,zeros_positions);
}

int main()
{
    vector<vector<int>> matrix = {
                                    {1,0,3},
                                    {4,5,6},
                                    {7,8,9}
                                };
    zero_matrix(matrix);
    for(int i = 0; i<matrix.size();i++)
    {
        for(int j = 0; j<matrix[i].size();j++)
        {
            cout<<matrix[i][j];
        }
        cout<<"\n";
    }
	return 0;
}

