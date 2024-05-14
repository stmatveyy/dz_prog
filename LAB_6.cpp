
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

void writeVectorToFile(const std::vector<int>& vec, const std::string& filename) {
    std::ofstream file(filename);
    for (int value : vec) {
        file << value << " ";
    }
    file.close();
}

std::vector<int> readVectorFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::vector<int> vec;
    int value;
    while (file >> value) {
        vec.push_back(value);
    }
    file.close();
    return vec;
}

void reverseVector(std::vector<int>& vec) {
    std::reverse(vec.begin(), vec.end());
}

int findMinimalElement(const std::vector<int>& vec) {
    return *std::min_element(vec.begin(), vec.end());
}

void discardEvenElements(std::vector<int>& vec) {
    vec.erase(std::remove_if(vec.begin(), vec.end(), [](int i) {return i % 2 == 0; }), vec.end());
}

void sortVectorAscending(std::vector<int>& vec) {
    std::sort(vec.begin(), vec.end());
}

void insertInOrder(std::vector<int>& vec, int value) {
    auto it = std::lower_bound(vec.begin(), vec.end(), value);
    vec.insert(it, value);
}

int findElementIndex(const std::vector<int>& vec, int value) {
    auto it = std::find(vec.begin(), vec.end(), value);
    if (it != vec.end()) {
        return std::distance(vec.begin(), it);
    }
    return -1; 
}

void removeDuplicates(std::vector<int>& vec) {
    std::sort(vec.begin(), vec.end());
    vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
}

void Show(std::vector<int>& vec) {
    for (int value : vec) {
        std::cout << value << " ";
    }
}
int main()
{
    std::vector<int> vector = { 1,2,3,4,5,6,7 };
    writeVectorToFile(vector, "Vec.txt");
    
    std::vector<int> vec_from_file = readVectorFromFile("Vec.txt");
    std::cout << "Vector from file: " << std::endl;

    Show(vec_from_file);

    reverseVector(vector);
    std::cout << "\n\nReversed vector: " << std::endl;
    Show(vector);

    std::cout << "\n\nMinimal element in vector: " << findMinimalElement(vector) << std::endl;

    discardEvenElements(vector);
    std::cout << "\n\nVector without even elements: " << std::endl;
    Show(vector);

    sortVectorAscending(vector);
    std::cout << "\n\nVector sorted ascending: " << std::endl;
    Show(vector);

    vector = { 1,2,3,400,400,600,700,700,700 };
    insertInOrder(vector, 50);
    std::cout << "\n\nInserted 50 in the vector:" << std::endl;
    Show(vector);

    std::cout << "\n\nIndex of 50 in a vector: " << findElementIndex(vector, 50);

    removeDuplicates(vector);
    std::cout << "\n\nVector without duplicates:" << std::endl;
    Show(vector);
    std::cout << "\n\n" << std::endl;
}

