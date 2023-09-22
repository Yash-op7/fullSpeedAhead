#include <iostream>
#include <unordered_map>
#include <utility>

struct PairHash
{
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2> &p) const
    {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2;
    }
};

int main()
{
    std::unordered_map<std::pair<int, int>, int, PairHash> myMap;

    // Inserting values into the map
    myMap[std::make_pair(1, 2)] = 42;
    myMap[std::make_pair(3, 4)] = 56;

    // Accessing values
    std::cout << "Value at (1, 2): " << myMap[std::make_pair(1, 2)] << std::endl;

    return 0;
}
