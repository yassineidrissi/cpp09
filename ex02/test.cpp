#include <vector>
#include <iostream>

int main() {
    // Example vector of vector of ints
    std::vector<std::vector<int> > vec;
    std::vector<int> temp1;
    temp1.push_back(1);
    temp1.push_back(2);
    temp1.push_back(3);
    vec.push_back(temp1);

    std::vector<int> temp2;
    temp2.push_back(4);
    temp2.push_back(5);
    temp2.push_back(6);
    vec.push_back(temp2);

    std::vector<int> temp3;
    temp3.push_back(7);
    temp3.push_back(8);
    temp3.push_back(9);
    vec.push_back(temp3);
    // Indices of the elements you want to merge
    int indexFrom = 1; // Assuming you want to merge from this index...
    int indexTo = 0; // ...into this index.

    // Check if indices are valid
    if(indexFrom < vec.size() && indexTo < vec.size() && indexFrom != indexTo) {
        // Append all values from vec[indexFrom] to vec[indexTo]
        vec[indexTo].insert(vec[indexTo].end(), vec[indexFrom].begin(), vec[indexFrom].end());

        // Optional: Remove the source element if no longer needed
        vec.erase(vec.begin() + indexFrom);
    } else {
        std::cout << "Invalid indices provided." << std::endl;
    }

    // Output the result for demonstration
    for(int i = 0; i < vec.size(); ++i) {
        std::cout << "indice " << i << std::endl;
        for(int j = 0; j < vec[i].size(); ++j) {
            std::cout << vec[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
