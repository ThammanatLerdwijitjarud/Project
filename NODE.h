#include <iostream>
#include <string>
using namespace std;

class Animal {
    private:
        string name, color, gender, age;
        int weight;
        Animal* next = NULL;
    public:
        Animal(string = "TBD", string = "TBD", string = "1 years old", int = 5, string = "Col");
        string get_name();
        string get_gender();
        string get_age();
        int get_age2();
        string get_color();
        float get_weight();
        Animal* move_next();
        void insert(Animal*&);
        void set_next(Animal *);
        void add_value(Animal *);

        virtual void show_node();
};


Animal::Animal(string n, string g, string a, int w, string c) {
    name = n;
    gender = g;
    age = a;
    weight = w;
    color = c;
}

string Animal::get_name() {
    return name;
}

string Animal::get_gender() {
    return gender;
}

string Animal::get_age() {
    return age;
}

int Animal::get_age2() {

    int L = age.length();
    string temp;

    for (char c:age) {
        if (c >= '0' && c <='9') {
            temp += c;
        }
    }
    if(age[L-6] == 'h') {
        return (stoi(temp));
    }
    else {
        return (stoi(temp) * 12);
    }

}

float Animal::get_weight() {
    return weight;
}

string Animal::get_color() {
    return color;
}

void Animal::show_node() {   
    cout << "Something wrong!\n";
}

void Animal::insert(Animal*& x) {
    // this->next = x;
    // cout<<"change insert"<<"\n";
    x->next=this;
}

Animal* Animal::move_next() {
    return next;
}

void Animal::set_next(Animal *n) {
    this->next=n;
}

void Animal::add_value(Animal * n1) {
    this->name = n1->name;
    this->color = n1->color;
    this->gender = n1->gender;
    this->age = n1->age;
    this->weight = n1->weight;
}
