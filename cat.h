class cat : public Animal{
private :
    static int no_cat;
public:
    cat(string,string,string,int,string);
    int get_size_cat();

};

int cat::no_cat=0;

cat::cat(string n,string g, string a ,int w, string c) : Animal(n,g,a,w,c) {
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

