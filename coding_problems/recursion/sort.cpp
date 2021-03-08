#include<bits/stdc++.h>
using namespace std;


void insert(vector<int> &val, int temp)
{
    if(val.size() == 0||temp>=val[val.size()-1]) {
        val.push_back(temp);
        return;
    }
    int value = val[val.size() -1]; val.pop_back();
    insert(val,temp);
    val.push_back(value);


}

void sort(vector<int> &input)
{
    if(input.size() == 1)
        return;
    int val = input[input.size()-1]; input.pop_back();
    sort(input);
    insert(input,val);
    return;
    

}

int main()
{
    vector<int> val {1,2,0,4,6,5};
    for(int i =0;i< val.size();i++)
        cout<<val[i];
    cout<<"\n";
    sort(val);
    for(int i =0;i< val.size();i++)
        cout<<val[i];
	return 0;
}