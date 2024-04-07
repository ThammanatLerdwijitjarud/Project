#include <iostream>
#include<cstdlib>
#include <fstream>
#include"NODE.h"
#include"LL.h"
using namespace std;

int cout_line_in_file()
{
    ifstream f;
    f.open("name_cat.txt");
    string line;
    int no_line=0;
    while(getline(f,line))
    {
        no_line++;
    }
    cout<<"no_line="<<no_line<<endl;
    f.close();
    return no_line;
}


int main()
{
    LL L;
    int line = cout_line_in_file(),i,j;
    cat *c[line];
    // for(i=0;i<line<i++)
    // {
    //     c[i] = new cat()
    // }
    cout<< R"(Choose option
        1. Cat
        2. Dog
        3. Donate)"<<endl;
    // cat cat1("Garfield",'F',1,2);
    // cat1.show_node();
}