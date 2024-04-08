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

string read_name(const string &filename,int n)
{
    ifstream f;
    f.open(filename);
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

string read_gender(const string &filename, int n)
{
    ifstream f;
    f.open(filename);
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

string read_age(const string &filename,int n)
{
    ifstream f;
    f.open(filename);
    int i=0,l;
    l = cout_line_in_file();
    string age[l], line;
    while(getline(f,line))
    {
        age[i] = line;
        i++;
    }
    f.close();
    return age[n];

}

int read_weight(const string &filename,int n)
{
    ifstream f;
    f.open(filename);
    int i,l;
    l = cout_line_in_file();
    int w;
    for(i=0;i<=n;i++)
    {
        f>>w;
    }
    f.close();
    return w;
}