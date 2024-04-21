#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "LL.h"

using namespace std;

void delete_file(const string& filename, const string& name) {
    ifstream inFile(filename);

    if (!inFile.is_open()) {
        cout << "Error opening file." << endl;
        return;
    }

    ofstream outFile("temp.txt");

    string line;
    while (getline(inFile, line)) {
        size_t commaPos = line.find(',');

        if (commaPos != string::npos && line.substr(0, commaPos) != name) {
            outFile << line << endl;
        }
    }

    inFile.close();
    outFile.close();

    // Remove & rename
    remove(filename.c_str());
    rename("temp.txt", filename.c_str());
}

void delete_node(string name, LL& ll) {
    Animal *current = ll.get_hol();
    Animal *prev = NULL;

    while (current != NULL) {
        if (current->get_name() == name) {
            if (prev == NULL) {
                ll.set_hol(current->move_next());
            } else {
                prev->set_next(current->move_next());
            }
            delete current;
            ll.d_size();
            return;
        }
        prev = current;
        current = current->move_next();
    }
}
// int main() {
//     string name;
//     LL ll;

//     cin >> name;
//     delete_file("test_cat.txt", name);
//     delete_file("test_dog.txt", name);
//     delete_node(name,ll);

//     cout << name << "have been deleted from the files." << endl;

//     return 0;
// }
