class dog : public Animal{
private:
    static int no_dog;
    // dog * d_next;
public:
    dog(string,string,string,int);
    int get_size_dog();
    void home();

    // dog * move_next();
    // void insert(dog*&);
    // void set_next(dog *);
};

int dog::no_dog=0;

dog::dog(string n,string g, string a ,int w) : Animal(n,g,a,w)
{
    no_dog++;
}

int dog::get_size_dog()
{
    return no_dog;
}

void dog::home() {
    cout << "                                 _            " << endl;
    cout << "                               ,/ \\,         " << endl;
    cout << "                             .//`_`\\\\,      " << endl;
    cout << "                           ,//`____-`\\\\,  " << endl;
    cout << "                       ,  //`[_POPPY_]`\\\\, " << endl;
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