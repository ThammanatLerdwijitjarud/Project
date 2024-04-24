class dog : public Animal{
private:
    static int no_dog;
    // dog * d_next;
public:
    dog(string,string,string,int,string);
    int get_size_dog();

    // dog * move_next();
    // void insert(dog*&);
    // void set_next(dog *);
};

int dog::no_dog=0;

dog::dog(string n,string g, string a ,int w, string c) : Animal(n,g,a,w,c)
{
    no_dog++;
}

int dog::get_size_dog()
{
    return no_dog;
}

// dog* dog::move_next()
// {
//     return d_next;
// }

// void dog::insert(dog*& x) {
//     x->d_next=this;
// }

// void dog::set_next(dog *n) {
//     this->d_next=n;
// }