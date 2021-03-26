#include<bits/stdc++.h>
using namespace std;

/*

At a popular bar, each customer has a set of favorite drinks, and will happily accept any drink among this set. For example, in the following situation, customer 0 will be satisfied with drinks 0, 1, 3, or 6.

preferences = {
    0: [0, 1, 3, 6],
    1: [1, 4, 7],
    2: [2, 4, 7, 5],
    3: [3, 2, 5],
    4: [5, 8]
}
A lazy bartender working at this bar is trying to reduce his effort by limiting the drink recipes he must memorize. Given a dictionary input such as the one above, return the fewest number of drinks he must learn in order to satisfy all customers.

For the input above, the answer would be 2, as drinks 1 and 5 will satisfy everyone.

*/

//WIP
int minimum_drinks(unordered_map<int,vector<int>> input)
{
    unordered_set<int> drinks;

    for(auto map_itr = input.begin();map_itr != input.end();++map_itr)
    {
        for(auto vec_itr = map_itr->second.begin();vec_itr != map_itr->second.end();++vec_itr)
        {
            if(drinks.find(*vec_itr) == drinks.end())
                drinks.insert(*vec_itr);
        }
    }
    // for(auto set_itr = drinks.begin();set_itr != drinks.end();++set_itr)
        // cout<<*set_itr;
    map<int,vector<int>> drink;
    
    for(auto map_itr = input.begin();map_itr != input.end();++map_itr)
    {
        for(auto vec_itr = map_itr->second.begin();vec_itr != map_itr->second.end();++vec_itr)
        {
            drink[*vec_itr].push_back(map_itr->first);
        }
    }

    // Make a new hashmap, this will be pointing to drinks to customers
    // from this new hashmap will create a new hashset and compare with the length of new hashset with input size, increase count 
    
    return 0;
}


int main()
{
    unordered_map<int,vector<int>> data = 
    {
        {0,{0,1,3,6}},
        {1,{1,4,7}},
        {2,{2,4,7,5}},
        {3,{3,2,5}},
        {4,{5,8}}
    };

    for(auto map_itr = data.begin();map_itr != data.end();++map_itr)
    {
        cout<<map_itr->first<<"->\t";
        for(auto vec_itr = map_itr->second.begin();vec_itr != map_itr->second.end();++vec_itr)
        {
            cout<<*vec_itr<<" ";
        }
        cout<<"\n";
    }
    cout<<"\n";
    int z = minimum_drinks(data);

	return 0;
}