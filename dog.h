class dog : public Animal{
private:
    static int no_dog;
public:
    dog(string,string,string,int,string);
    int get_size_dog();
    void show_node();
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

void dog::show_node()
{   
    int box_width = 50;

    cout<<"+-------------------------------------------------+" << endl;

    cout<<"|          __"<<"    Name   : "<< setw(box_width - 26) << left << get_name() << "|" << endl;
    cout<<"|     (___()'`;"<<"  Gender : "<< setw(box_width - 26) << left << get_gender() << "|" <<endl;
    cout<<"|     /,    /`"<<"   Age    : "<< setw(box_width - 26) << left << get_age() << "|" <<endl;
    cout<<"|     \\\\'--\\\\"<<"    Weight : "<< setw(2)<<setfill(' ')<<get_weight() << " kg                   |" << endl;
    cout<<"|                Color  : "<< setw(box_width - 26) << left << get_color() << "|" << endl;
}
