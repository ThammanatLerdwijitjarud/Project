#include<iostream>
#include<fstream>
#include<sstream>
#include "p_file.h"
using namespace std;

int main () {

    LL L_cat;

    create_cat_ll(L_cat);

    cout << "done" << endl;

    L_cat.show_all('c');

    cout << "done2" << endl;

    return 0;
}