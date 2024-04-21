#include "LL.h"

void create_cat_ll(LL &ll) {
    
    Animal * temp_cat;
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

void create_dog_ll(LL &ll) {
    
    Animal * temp_dog;
    string temp_name, temp_sex, temp_age, temp_weight;

    fstream myfile;
    
    myfile.open("test_dog.txt", ios::in);
    
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
            temp_dog = new dog(temp_name, temp_sex, temp_age, stoi(temp_weight));
            // temp_cat->show_node();
            ll.add_node(temp_dog);
            // while(getline(X, temp, ',')) {
            //     cout<<temp<<endl;
            // }
        }
        myfile.close();
    }

}

void create_ll(LL &ll) {
    
    create_cat_ll(ll);
    create_dog_ll(ll);
}

void delete_cat_ll(LL &ll, Animal *n) {
    Animal *temp_cat = ll.c_hol;
    Animal *pre_cat = NULL;

    while (temp_cat != NULL) {
        if (temp_cat == n) {
            if (pre_cat == NULL) { // If n is the head of the linked list
                ll.c_hol = temp_cat->move_next();
                delete temp_cat;
                ll.d_size(); // Decrease size
                temp_cat = ll.c_hol;
            } else {
                pre_cat->set_next(temp_cat->move_next());
                delete temp_cat;
                ll.d_size(); // Decrease size
                temp_cat = pre_cat->move_next();
            }
            // Exit loop after deleting the node
            break;
        } else {
            pre_cat = temp_cat;
            temp_cat = temp_cat->move_next();
        }
    }
}


// void delete_cat_ll(LL &ll,Animal)
// {
//     Animal *temp_cat = ll.c_hol;
//     Animal *pre_cat = NULL;


//     if(temp_cat!=NULL && (temp_cat==))
//     {
//         if(temp_cat->move_next() != NULL) {
//             c_hol = temp_cat->move_next();
//             delete temp_cat;
//             size--;
//         }
//         return ;
//     }
//     while(temp_cat!=NULL && temp_cat->move_next() != NULL && (temp_cat!=n))
//     {
//         pre_cat = temp_cat;
//         temp_cat = temp_cat->move_next();
//     }
//     if(temp_cat==n && temp_cat->move_next() != NULL)
//     {
//         pre_cat->set_next(temp_cat->move_next());
//         delete temp_cat;
//         size--;
//     }
    
// }

void delete_ll(LL &ll){
    delete_cat_ll(ll,ll.c_hol);
    //delete_dog_ll(ll);
}

//delete until \n