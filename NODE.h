#include <iostream>
#include <string>
using namespace std;

class Animal {
    private:
        string name, color, gender, age;
        int weight;
        Animal* next;
    public:
        Animal(string = "TBD", string = "TBD", string = "1 years old", int = 5, string = "Col");
        string get_name();
        string get_gender();
        string get_age();
        string get_color();
        int get_weight();
        void show_node();
        Animal* move_next();
        void insert(Animal*&);
        void set_next(Animal *);

        Animal *merge(Animal *a, Animal *b);
        Animal *mid_point(Animal *head);
        Animal* merge_sort(Animal *head);
};


Animal::Animal(string n, string g, string a, int w, string c)
{
    name = n;
    gender = g;
    age = a;
    weight = w;
    color = c;
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

string Animal::get_color()
{
    return color;
}

void Animal::show_node()
{   
    cout<<"-------------------------"<<endl;
    cout<<"Name : "<<get_name()<<endl;
    cout<<"Gender : "<<get_gender()<<endl;
    cout<<"Age : "<<get_age()<<endl;
    cout<<"Weight : "<<get_weight()<<" kg"<<endl;
    cout<<"Color : "<<get_color()<<endl;
}

void Animal::insert(Animal*& x) {
    // this->next = x;
    // cout<<"change insert"<<"\n";
    x->next=this;
}

Animal* Animal::move_next()
{
    return next;
}

void Animal::set_next(Animal *n) {
    this->next=n;
}

Animal * Animal::merge(Animal *a, Animal *b) {
    // base case
    if(a == NULL)
        return b;
    if(b == NULL)
        return a;
 
    // recursive case
    // take a head pointer
    Animal *c;
 
    if(a->name < b->name)
    {
        c = a;
        c->next = merge(a->next, b);
    }
    else
    {
        c = b;
        c->next = merge(a, b->next);
    }
 
    return c;
}
Animal * Animal::mid_point(Animal *head) {
    // base case
    if(head == NULL || head->next == NULL)
        return head;
 
    // recursive case
    Animal *fast = head;
    Animal *slow = head;
 
    while(fast != NULL && fast->next != NULL)
    {
        fast = fast->next;
 
        if(fast->next == NULL)
            break;
 
        fast = fast->next;
        slow = slow->next;
    }
 
    return slow;
}
Animal * Animal::merge_sort(Animal *head) {
     // base case
    if(head == NULL || head->next == NULL)
        return head;
 
    // recursive case
    // Step 1: divide the linked list into
    // two equal linked lists
    Animal *mid = mid_point(head);
    Animal *a = head;
    Animal *b = mid->next;
 
    mid->next = NULL;
 
    // Step 2: recursively sort the smaller
    // linked lists
    a = merge_sort(a);
    b = merge_sort(b);
 
    // Step 3: merge the sorted linked lists
    Animal *c = merge(a, b);
 
    return c;
}