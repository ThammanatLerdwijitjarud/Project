#include "LL.h"

void create_cat_ll(LL &ll) {
    
    cat * temp_cat;
    string temp_name, temp_sex, temp_age, temp_weight;

    fstream myfile;
    
    myfile.open("test_cat.txt", ios::in);
    
    if(myfile.is_open()) {
        string line;
        while(getline(myfile, line)) {
            stringstream X(line);
            getline(X, temp_name, ','); 
            // cout<<temp_name<<endl;           
            getline(X, temp_sex, ',');
            // cout<<temp_sex<<endl;
            getline(X, temp_age, ',');
            // cout<<temp_age<<endl;
            getline(X, temp_weight, '\n');
            // cout<<temp_weight<<endl;
            temp_cat = new cat(temp_name, temp_sex, temp_age, stoi(temp_weight));
            // temp_cat->show_node();
            ll.add_node(temp_cat);
            // while(getline(X, temp, ',')) {
            //     cout<<temp<<endl;
            // }
        }
        myfile.close();
    }

}