#include <iostream>
#include <fstream>
#include <vector>
#include "food_data.h"
using namespace std;

class Food {
public:
    void set(string setName, string setCategory, string setDecription, string setAvailable);
    void print();
    void printAvailable();
private:
    bool isAvailable();
    string name;
    string category;
    string description;
    string available;
};

void Food::set(string setName, string setCategory, string setDescription, string setAvailable) {
    name = setName;
    category = setCategory;
    description = setDescription;
    available = setAvailable;
}

void Food::print() {
    cout << name << " (" << category << ") -- " << description << endl;
}

void Food::printAvailable() {
    if (isAvailable()) {
        cout << name << " (" << category << ") -- " << description << endl;
    }
}

bool Food::isAvailable() {
    return (available == "Available");
}


void parseFoodLine(ifstream &foodFS, string &category, string &name, string &description, string &available);

int main() {
    ifstream foodFS;
    string filename;
    string name, category, description, available;
    Food foodItem;
    vector<Food> menu;

    cout << "Enter the name of the file: ";
    // cin >> filename;
    filename = "module9/food.txt";

    foodFS.open(filename);
    if (!foodFS.is_open()) {
        cout << "Error opening file" << endl;
        return 1;
    }

    parseFoodLine(foodFS, category, name, description, available);

    while(foodFS) {
        Food foodItem;
        foodItem.set(name, category, description, available);
        menu.push_back(foodItem);

        parseFoodLine(foodFS, category, name, description, available);
    }

    foodFS.close();

    
    for (int i = 0; i < menu.size(); i++) {
        menu[i].printAvailable();
    }

    return 0;
}

void parseFoodLine(ifstream &foodFS, string &category, string &name, string &description, string &available)
{
    getline(foodFS, category, '\t');    // read until tab character
    getline(foodFS, name, '\t');        // read until tab character
    getline(foodFS, description, '\t'); // read until tab character
    getline(foodFS, available);         // read until end of line
}