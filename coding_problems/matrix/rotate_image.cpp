#include<bits/stdc++.h>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void rotate_image(vector<vector<int>> &image)
{

    for(int i = 0; i<image.size();i++)
    {
        for(int j = i; j<image[i].size();j++)
        {
            swap(image[i][j],image[j][i]);
        }
    }
    for(int i = 0; i<image.size();i++)
    {
        for(int j = 0; j<(image[i].size())/2;j++)
        {
            // if(j == 0 || j == image[i].size())
                swap(image[i][j],image[j][i]);
        }
    }



}


int main()
{
    vector<vector<int>> image = {
                                    {1,2,3},
                                    {4,5,6},
                                    {7,8,9}
                                };
    rotate_image(image);
    for(int i = 0; i<image.size();i++)
    {
        for(int j = 0; j<image[i].size();j++)
        {
            cout<<image[i][j];
        }
        cout<<"\n";
    }
	return 0;
}

