#include <iostream>
using namespace std;

#include "./LinkedList.h"

/**
 * run following command for executing the program : 
 * g++ -. main.cpp -o program && ./program
 */

int main() {
    List<int> list;

    /***
     * @brief Adding Some Data Form A LinkedList
     */

    list.push_front(40);
    list.push_front(30);
    list.push_front(30);
    list.push_front(20);
    list.push_front(20);
    list.push_front(10);
    list.push_front(10);
    list.push_front(10);


    try {
        // 3. Call the function and store the result
        std::array<std::vector<int>, 2> deletedInfo = list.RemoveDuplicates();

        // 4. Process and display the results
        std::vector<int>& deletedValues = deletedInfo[0];
        std::vector<int>& deletedPositions = deletedInfo[1];

        std::cout << "\nDuplicates were removed." << std::endl;

        if (deletedValues.empty()) {
            std::cout << "No duplicates were found." << std::endl;
        } else {
            std::cout << "Deleted values and their positions:" << std::endl;
            for (size_t i = 0; i < deletedValues.size(); ++i) {
                std::cout << "-> Value: " << deletedValues[i]
                          << ", at position: " << deletedPositions[i] << std::endl;
            }
        }

    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}