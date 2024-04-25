class cat : public Animal{
private :
    static int no_cat;
public:
    cat(string,string,string,int,string);
    int get_size_cat();
    void show_node();

};

int cat::no_cat=0;

cat::cat(string n,string g, string a ,int w, string c) : Animal(n,g,a,w,c) {
    no_cat++;
}

int cat::get_size_cat()
{
    return no_cat;
}

void cat::show_node()
{   
    cout<<"-------------------------"<<endl;
    cout<<"  ^~^  ,"<<"   Name   : "<<get_name()<<endl;
    cout<<" ('Y') )"<<"   Gender : "<<get_gender()<<endl;
    cout<<" /   \\/ "<<"   Age    : "<<get_age()<<endl;
    cout<<"(\\|||/)"<<"    Weight : "<<get_weight()<<" kg"<<endl;
    cout<<"           Color  : "<<get_color()<<endl;
}
