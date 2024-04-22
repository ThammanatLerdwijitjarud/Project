class cat : public Animal{
private :
    static int no_cat;
    // cat * c_next;
public:
    cat(string,string,string,int);
    int get_size_cat();
    void home();

    // cat * move_next();
    // void insert(cat*&);
    // void set_next(cat *);
};

int cat::no_cat=0;

cat::cat(string n,string g, string a ,int w) : Animal(n,g,a,w) {
    no_cat++;
}

int cat::get_size_cat()
{
    return no_cat;
}

// cat* cat::move_next()
// {
//     return c_next;
// }

// void cat::insert(cat*& x) {
//     x->c_next=this;
// }

// void cat::set_next(cat *n) {
//     this->c_next=n;
// }