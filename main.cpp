#include <iostream>
#include<cstdlib>
#include <fstream>
//#include"NODE.h"
#include"LL.h"
using namespace std;

int cout_line_in_file();
string read_name(int);
string read_gender(int);
//string read_age(int);

int main()
{
    LL L;
    int line = cout_line_in_file(),i,j;
    cat *c[line];
    string n,g;
    int a;
    for(i=0;i<line;i++)
    {
        n = read_name(i);
        g = read_gender(i);
        //a = read_age(i);
        c[i] = new cat(n,g,1,1);
        c[i]->show_node();
        //L.add_node(c[i]);
    }
    cout<< R"(Choose option
        1. Cat
        2. Dog
        3. Donate)"<<endl;
    // cat cat1("Garfield",'F',1,2);
    // cat1.show_node();
}