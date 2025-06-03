#include <vector>
#include <string>
#include <iostream>

using namespace std;

// TODO: Write function to create and output all permutations of the list of names.
void PrintAllPermutations(const vector<string> &permList, const vector<string> &nameList) {
    if (nameList.empty()) {
        cout << permList.at(0);
        for (int i = 1; i < permList.size(); i++) {
            cout << ", " << permList.at(i);
        }
        cout << endl;
        return;
    }

    string tempName;
    vector<string> newNameList = nameList;
    vector<string> newPermList = permList;
    
    for (int i = 0; i < newNameList.size(); i++) {
        tempName = nameList.at(i);
        newNameList.erase(newNameList.begin() + i);
        newPermList.push_back(tempName);
        
        PrintAllPermutations(newPermList, newNameList);

        newPermList.pop_back();
        newNameList.insert(newNameList.begin() +i, tempName);
    }



}

int main() {
   vector<string> nameList;
   vector<string> permList;
   string name;

   // TODO: Read a list of names into nameList; stop when -1 is read. Then call recursive function.
   cin >> name;
   while (name != "-1") {
      nameList.push_back(name);
      cin >> name;
   }
   PrintAllPermutations(permList, nameList);
   
   return 0;
}