#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>

// Include any necessary libraries here.

using namespace std;

int main() {
    string filename;
    ifstream nationalParksFS;
    string photoName;
    string annotationName;
    vector<string> photoNames;
    vector<string> annotationNames;
    int underscoreIndex;
    
    cout << "Enter the name of the file: ";
    cin >> filename;
    nationalParksFS.open(filename);

    if (!nationalParksFS.is_open()) {
        cout << "Error opening file." << endl;
        return 1;
    }

    while(nationalParksFS) {
        getline(nationalParksFS, photoName);
        if (!nationalParksFS.fail()) {
            photoNames.push_back(photoName);
        }
    }

    nationalParksFS.close();

    for (int i = 0; i < photoNames.size(); i++) {
        cout << photoNames.at(i) << endl;

        underscoreIndex = photoNames.at(i).find("_");
        annotationName = photoNames.at(i).substr(0, underscoreIndex) + "_info.txt";
        annotationNames.push_back(annotationName);
    }

    // cout << "Annotation names:\n" << endl;

    for (int i = 0; i < annotationNames.size(); i++) {
        cout << annotationNames.at(i) << endl;
    }

   return 0;
}
