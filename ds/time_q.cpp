#include <iostream>
#include <string>
#include <utility>
#include <random>
using namespace std;

inline long long getNow() {
    using namespace std::chrono;
    auto now = system_clock::now();
    auto duration = now.time_since_epoch();
    auto timestamp = duration_cast<nanoseconds>(duration).count();          // works for milliseconds, fails in nanoseconds & micro
    return timestamp;
}

pair<string, int> generateRandomPair(size_t stringLength, int maxRange) {
    const string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

    // Set up random number generators
    random_device rd;
    mt19937 rng(rd());
    uniform_int_distribution<> charDist(0, characters.size() - 1);
    uniform_int_distribution<> intDist(1, maxRange);

    // Generate random string
    string randomStr;
    for (size_t i = 0; i < stringLength; ++i) {
        randomStr += characters[charDist(rng)];
    }

    // Generate random integer
    int randomInt = intDist(rng);

    cout<< "making " << randomStr << " " << randomInt << " at " <<  getNow() << endl;
    return make_pair(randomStr, randomInt);
}

void consumeRandomPair(const pair<string, int>& randomPair) {
    const string& randomStr = randomPair.first;
    int randomInt = randomPair.second;

    cout << "Consumed pair: (" << randomStr << ", " << randomInt << ")" << " at " << getNow() << endl;

}



struct val{
    string       s;
    bool         b;
    long long    i;
    long long    j;
};

class DataStructure{
    vector<val> values;         // optimize to a size, vector resize optimize

public:
    DataStructure(){
        gc();
    }
    void consumer(pair<string,int> input){
        values.push_back({input.first,false,input.second,getNow()+input.second});
    }
    void producer(){
        while(values.size()){
            int sz = values.size();
            for(int i=0;i<sz;i++){
                if(values[i].j-getNow()<=0){
                    values[i].b=true;
                    consumeRandomPair({values[i].s,static_cast<int>(values[i].i)});
                }
            }
            gc();
        }
        cout<<"all values empty";
    }

private:
    void gc(){
        values.erase(remove_if(values.begin(), values.end(),
            [](const val& v) {
                return v.b == true; // Remove elements where b is true
            }), values.end());

    }
};

// g++ -std=c++17 time_q.cpp; ./a.out
int main(){

    DataStructure data;

    for (int i = 0; i < 10; ++i) {
        auto randomPair = generateRandomPair(10, 100);
        data.consumer(randomPair);
    }

    data.producer();

    return 0;
}
