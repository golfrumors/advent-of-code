#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <numeric>
#include <functional>

using namespace std;

struct plusSecond {
    template <typename T1, typename T2>
        inline T1 operator()(T1 t1, const T2 &t2) const {
            return t1 + t2.second;
        }
};

template <typename Map, typename Key, typename Value>
Value accumulate_range(const Map & map, const Key & key, Value init){
    typedef typename Map::const_iterator MapIterator;
    typedef typename Map::value_type value_type;

    std::pair<MapIterator, MapIterator> range = map.equal_range(key);

    return std::accumulate(range.first, range.second, init, plusSecond());
}

map<string, int> readFile(string fileName) {
    map<string, int> result;
    ifstream file(fileName);
    string key;
    int value;
    while (file >> key >> value){
        result.insert(pair<string, int>(key, value));
    }
    
    return result;
}

int main(){
    map<string, int> m = readFile("input.txt");
   
    int sumForward = accumulate_range(m, "forward", 0);
    int sumUp = accumulate_range(m, "up", 0);
    int sumDown = accumulate_range(m, "down", 0);

    cout << "Sum of forward " << sumForward << endl;
    cout << "Sum of up " << sumUp << endl;
    cout << "Sum of down " << sumDown << endl;

    sumDown -= sumUp;

    int finalVec = sumForward * sumUp;

    cout << "Final vec (multiplied): " << finalVec << endl;

    return 0;
}
