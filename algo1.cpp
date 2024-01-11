#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>\n";
        return 1;
    }

    std::ifstream file(argv[1]);
    if (!file) {
        std::cerr << "Cannot open file " << argv[1] << "\n";
        return 1;
    }

    int vectorSize, mapSize, num;
    std::string key;
    std::vector<int> numbers;
    std::map<std::string, int> numMap;

    file >> vectorSize;
    while (vectorSize-- && file >> num) {
        numbers.push_back(num);
    }

    file >> mapSize;
    while (mapSize-- && file >> key >> num) {
        numMap[key] = num;
    }

    file.close();

    for (auto vec_it = numbers.begin(); vec_it != numbers.end(); ) {
        auto map_it = std::find_if(numMap.begin(), numMap.end(), 
            [vec_it](const auto& pair) { return pair.second == *vec_it; });

        map_it == numMap.end() ? vec_it = numbers.erase(vec_it) : ++vec_it;
    }

    for (auto map_it = numMap.begin(); map_it != numMap.end(); ) {
        std::find(numbers.begin(), numbers.end(), map_it->second) == numbers.end() ? 
            map_it = numMap.erase(map_it) : ++map_it;
    }

    for (auto num : numbers) {
        std::cout << num << " ";
    }
    std::cout << "\n";

    for (const auto& [key, value] : numMap) {
        std::cout << key << " " << value << " ";
    }
    std::cout << "\n";

    return 0;
}
