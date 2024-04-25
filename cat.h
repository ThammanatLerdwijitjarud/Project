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
    int box_width = 50;

    // Print the top border of the box
    std::cout << "+-------------------------------------------------+" << std::endl;

    // Print each line of cat information within the box
    std::cout << "|    ^~^  ,      Name   : " << std::setw(box_width - 26) << std::left << get_name() << "|" << std::endl;
    std::cout << "|   ('Y') )      Gender : " << std::setw(box_width - 26) << std::left << get_gender() << "|" << std::endl;
    std::cout << "|   /   \\/       Age    : " << std::setw(box_width - 26) << std::left << get_age() << "|" << std::endl;
    std::cout << "|  (\\|||/)       Weight : " << setw(2)<<setfill(' ')<<get_weight() << " kg                   |" << std::endl;
    std::cout << "|                Color  : " << std::setw(box_width - 26) << std::left << get_color() << "|" << std::endl;
}


