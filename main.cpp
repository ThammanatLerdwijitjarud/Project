#include <iostream>
#include<cstdlib>
#include <fstream>
//#include"NODE.h"
#include"LL.h"
using namespace std;

int cout_line_in_file();
string read_name(int);
string read_gender(int);
string read_age(int);
int read_weight(int);

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
            n = read_name(i);
            g = read_gender(i);
            a = read_age(i);
            w = read_weight(i);
            c[i] = new cat(n,g,a,w);
            c[i]->show_node();
            //L_cat.add_node(c[i]);
        }
    }
}