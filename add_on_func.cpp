#include<iostream>
#include<fstream>
#include<sstream>

int menu()
{
    int i;
    cout<<R"(Choose option :
    1. Adopt cat
    2. Adopt dog
    3. Donate
Enter menu : )";
    cin>>i;
    return i;
}

void guide(char c)
{
    int g;
    if(c=='c')
    {
        cout<<"---------------------"<<"\n";
        cout<<"| Guideline for cat |"<<"\n";
        cout<<"---------------------"<<"\n";

        fstream myfile;
        myfile.open("guideline_cat.txt", ios::in);
        if(myfile.is_open())
        {
            string line;
            while(getline(myfile, line))
            {
                cout<<line<<"\n";
            }
            myfile.close();
        }
    }
    else
    {
        cout<<"---------------------"<<"\n";
        cout<<"| Guideline for dog |"<<"\n";
        cout<<"---------------------"<<"\n";

        fstream myfile;
        myfile.open("guideline_dog.txt", ios::in);
        if(myfile.is_open())
        {
            string line;
            while(getline(myfile, line))
            {
                cout<<line<<"\n";
            }
            myfile.close();
        }
    }
}

void decide(char c)
{
    string name;
    char con;
    if(c=='c')
    {
        cout<<"\n";
        cout<<R"(Which cat do you want to adopt ? Enter name : )";
        cin>>name;
        cout<<"\n";
        guide('c');
        cout<<"Confirm (y/n) : ";
        cin>>con;
        if(con=='y' || con=='Y')
        {
            cout<<"Reserve cat done!"<<"\n"; //delete cat ที่จอง
        }
    }
    else
    {
        cout<<"\n";
        cout<<R"(Which dog do you want to adopt ? Enter name : )";
        cin>>name;
        cout<<"\n";
        guide('d'); 
        cout<<"Confirm (y/n) : ";
        cin>>con;
        if(con=='y' || con=='Y')
        {
            cout<<"Reserve dog done!"<<"\n"; //delete dog ที่จอง
        } 
    }
}