#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<satd::pair<int, int>, int> myMap;

    // Inserting key-value pairs into the map
    myMap[std::make_pair(1, 2)] = 42;
    myMap[std::make_pair(3, 4)] = 100;

    // Accessing values by key
    std::pair<int, int> key(1, 2);
    if (myMap.find(key) != myMap.end()) {
        std::cout << "Value for key " << key.first << ", " << key.second << ": " << myMap[key] << std::endl;
    } else {
        std::cout << "Key not found." << std::endl;
    }

    return 0;
}