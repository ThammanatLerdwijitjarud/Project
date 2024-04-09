#include <iostream>
#include<cstdlib>
#include <fstream>
#include"LL.h"
// #include"cat.h"
// #include"dog.h"
using namespace std;

int cout_line_in_file();
string read_name(const string& ,int);
string read_gender(const string&, int);
string read_age(const string&, int);
int read_weight(const string&, int);

int main()
{
    LL L_cat;
    int line = cout_line_in_file(),i,j;
    cat *c[line];
    string n,g,a;
    int w,option;
    cout<< R"(Choose option
    1. Cat
    2. Dog
    3. Donate)"<<endl;;
    cout<<"Enter number : ";
    cin>>option;
    if(option==1)
    {
        for(i=0;i<line;i++)
        {
            n = read_name("name_cat.txt",i);
            g = read_gender("gender_cat.txt",i);
            a = read_age("age_cat.txt",i);
            w = read_weight("weight_cat.txt",i);
            c[i] = new cat(n,g,a,w);
            c[i]->show_node();
            //L_cat.add_node(c[i]);
        }
    }
}