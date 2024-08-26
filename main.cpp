#include <iostream>
#include <map>
#include <fstream>
#include <string>

class ItemTracker {
private:
    std::map<std::string, int> itemFrequencies;

    // Loads items from the input file and stores them in the map
    void loadItems() {
        std::ifstream inputFile("CS210_Project_Three_Input_File.txt");
        std::string item;
        while (inputFile >> item) {
            itemFrequencies[item]++;
        }
        inputFile.close();
    }

    // Automatically creates the frequency.dat file at the start of the program
    void createDataFile() {
        std::ofstream outputFile("frequency.dat");
        for (const auto& entry : itemFrequencies) {
            outputFile << entry.first << " " << entry.second << std::endl;
        }
        outputFile.close();
    }

public:
    // Constructor that loads items and creates the data file
    ItemTracker() {
        loadItems();
        createDataFile();
    }

    // Function to show frequency of a specific item
    void showFrequency(const std::string& item) {
        if (itemFrequencies.find(item) != itemFrequencies.end()) {
            std::cout << item << ": " << itemFrequencies[item] << std::endl;
        } else {
            std::cout << item << " not found." << std::endl;
        }
    }

    // Function to print overall frequency of all items
    void printOverallFrequency() {
        for (const auto& entry : itemFrequencies) {
            std::cout << entry.first << ": " << entry.second << std::endl;
        }
    }

    // Function to print a histogram of item frequencies
    void printHistogram() {
        for (const auto& entry : itemFrequencies) {
            std::cout << entry.first << " ";
            for (int i = 0; i < entry.second; i++) {
                std::cout << "*";
            }
            std::cout << std::endl;
        }
    }

    // Function to exit the program
    void exitProgram() {
        std::cout << "Exiting program..." << std::endl;
    }
};

// Function to display the menu options
void showMenu() {
    std::cout << "Menu Options:\n";
    std::cout << "1. Show frequency of a specific item\n";
    std::cout << "2. Show overall frequency of all items\n";
    std::cout << "3. Show histogram of all items\n";
    std::cout << "4. Exit\n";
}

// Main function handling user input and menu navigation
int main() {
    ItemTracker tracker;
    int choice;
    std::string item;

    do {
        showMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                std::cout << "Enter item name: ";
                std::cin >> item;
                tracker.showFrequency(item);
                break;
            case 2:
                tracker.printOverallFrequency();
                break;
            case 3:
                tracker.printHistogram();
                break;
            case 4:
                tracker.exitProgram();
                break;
            default:
                std::cout << "Invalid choice, please try again." << std::endl;
        }
    } while (choice != 4);

    return 0;
}
