#include <iostream>
#include<cstdlib>
#include <fstream>

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
    // cout<<"no_line="<<no_line<<endl;
    // cout<<"-----------------"<<endl;
    f.close();
    return no_line;
}

string read_name(int n)
{
    ifstream f;
    f.open("name_cat.txt");
    int i=0,l;
    l = cout_line_in_file();
    string line, name[l];
    while(getline(f,line))
    {
        name[i] = line;
        i++;
    }
    f.close();
    return name[n];
}

string read_gender(int n)
{
    ifstream f;
    f.open("gender_cat.txt");
    int i=0,l;
    l = cout_line_in_file();
    string line, gen[l];
    while(getline(f,line))
    {
        gen[i] = line;
        i++;
    }
    f.close();
    return gen[n];
}

// string read_age(int n)
// {
//     ifstream f;
//     f.open("age_cat.txt");
//     int i=0,l;
//     l = cout_line_in_file();
//     string age[l];
//     string line;
//     while(getline(f,line))
//     {
//         age[i] = line;
//         i++;
//     }
//     f.close();
//     return age[n];

// }