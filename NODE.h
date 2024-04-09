#include <iostream>
#include <string>
using namespace std;

class Animal {
    private:
        string name, color, gender, age;
        int weight;
        Animal* next;
    public:
        // string find_color(string); //use sorting
        // string set_color(string);
        // string get_color();
        Animal(string = "TBD", string = "TBD", string = "1 years old", int = 5);
        string get_name();
        string get_gender();
        string get_age();
        int get_weight();
        void show_node();
        Animal* move_next();
        void insert(Animal*&);
        void set_next(Animal *);
        void delete_node();
};

Animal::Animal(string n, string g, string a, int w)
{
    name = n;
    gender = g;
    age = a;
    weight = w;
}

string Animal::get_name()
{
    return name;
}

string Animal::get_gender()
{
    return gender;
}

string Animal::get_age()
{
    return age;
}

int Animal::get_weight()
{
    return weight;
}

void Animal::show_node()
{   
    cout<<"-------------------------"<<endl;
    cout<<"Name : "<<get_name()<<endl;
    cout<<"Gender : "<<get_gender()<<endl;
    cout<<"Age : "<<get_age()<<endl;
    cout<<"Weight : "<<get_weight()<<" kg"<<endl;
}

void Animal::insert(Animal*& x) {
    x->next=this;
}

Animal* Animal::move_next()
{
    return next;
}

void Animal::set_next(Animal *n) {
    this->next=n;
}

