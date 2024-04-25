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
    cout<<"-------------------------"<<endl;
    cout<<"        __"<<"    Name   : "<<get_name()<<endl;
    cout<<"   (___()'`;"<<"  Gender : "<<get_gender()<<endl;
    cout<<"   /,    /`"<<"   Age    : "<<get_age()<<endl;
    cout<<"   \\\\'--\\\\"<<"    Weight : "<<get_weight()<<" kg"<<endl;
    cout<<"              Color  : "<<get_color()<<endl;
}