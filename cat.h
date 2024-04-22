class cat : public Animal{
private :
    static int no_cat;
    // cat * c_next;
public:
    cat(string,string,string,int,string);
    int get_size_cat();
    void home();

    // cat * move_next();
    // void insert(cat*&);
    // void set_next(cat *);
};

int cat::no_cat=0;

cat::cat(string n,string g, string a ,int w, string c) : Animal(n,g,a,w,c) {
    no_cat++;
}

int cat::get_size_cat()
{
    return no_cat;
}

void cat::home() {
    cout << "                                 _            " << endl;
    cout << "                               ,/ \\,         " << endl;
    cout << "                             .//`_`\\\\,      " << endl;
    cout << "                           ,//`____-`\\\\,  " << endl;
    cout << "                       ,  //`[_KITTY_]`\\\\, " << endl;
    cout << "                      , //`=  ==  __-  _`\\\\," << endl;
    cout << "                      //|__=  __- == _  __|\\\\" << endl;
    cout << "                     `  |  __ .-----.  _  | ` " << endl;
    cout << "                        | - _/       \\-   |  " << endl;
    cout << "                        |__  | .-\"-. | __=|  " << endl;
    cout << "                        |  _=|/))  (\\|    |  " << endl;
    cout << "                        |-__ (/ . . \\) -__|  " << endl;
    cout << "                        |___ /`\\_Y_/`\\____|  " << endl;
    cout << "                            \\)8===8(/       " << endl;
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

