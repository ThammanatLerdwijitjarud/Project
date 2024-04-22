#include<iostream>
#include<fstream>
#include<sstream>
#include<iomanip>
#include"p_file.h"

int menu();
void guide(char c);
void decide(char c);
void bill(string p,string nani,string tel);
void doghome();

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
        doghome();
    }
}

void decide(LL & ll, char c)
{
    string name,person,contact;
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
            cout << "please enter your information"<<endl;
            cout << "Name : ";
            cin >> person;
            cout << "Phone number : ";
            cin >> contact;
            bill(person,name,contact);
            delete_node(name,ll);
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
            cout << "please enter your information"<<endl;
            cout << "Name : ";
            cin >> person;
            cout << "Phone number : ";
            cin >> contact;
            bill(person,name,contact);
            delete_node(name,ll);
            cout<<"Reserve dog done!"<<"\n"; //delete dog ที่จอง
        } 
    }
}

void bill(string p,string nani,string tel)
{
    
    cout <<" ____________________________________________________________________" << endl;
    cout <<"/\\                                                                   \\"<<endl;
    cout <<"\\_|        /\\          /\\          /\\          /\\          /\\        |"<<endl;
    cout <<"  |     /\\//\\\\/\\    /\\//\\\\/\\    /\\//\\\\/\\    /\\//\\\\/\\    /\\//\\\\/\\     |"<<endl;
    cout <<"  |  /\\//\\\\\\///\\\\/\\//\\\\\\///\\\\/\\//\\\\\\///\\\\/\\//\\\\\\///\\\\/\\//\\\\\\///\\\\/\\  |"<<endl;
    cout <<"  | //\\\\\\//\\/\\\\///\\\\\\//\\/\\\\///\\\\\\//\\/\\\\///\\\\\\//\\/\\\\///\\\\\\//\\/\\\\///\\\\ |"<<endl;
    cout <<"  | \\\\//\\/           ,                                          \\\\// |"<<endl;
    cout <<"  |  \\/          /\\^/'\\                                          \\/  |"<<endl;
    cout <<"  |  /\\         | \\/   |     ____________________                /\\  |"<<endl;
    cout <<"  | //\\\\        | |    |    ("<<setw(20)<<nani<<   ")              //\\\\ |"<<endl;
    cout <<"  | \\\\//        \\ \\    /    ( (=@.@=)  ₍˄·͈༝·͈˄₎◞ ̑̑))    _ _       \\\\// |"<<endl;
    cout <<"  |  \\/          '\\\\//'     ("<<setw(20)<<p<<   ")  _{ ' }_      \\/  |"<<endl;
    cout <<"  |  /\\            ||       ("<<setw(20)<<tel<<   ") { '.!.' }     /\\  |" <<endl;
    cout <<"  | //\\\\           ||       (____________________) ',_/Y\\_,'    //\\\\ |"<<endl;
    cout <<"  | \\\\//           ||  .                             {_,_}      \\\\// |"<<endl;
    cout <<"  |  \\/            ||  |\\            0                 |         \\/  |"<<endl;
    cout <<"  |  /\\        |\\  ||  | |                           (\\|  /)     /\\  |"<<endl;
    cout <<"  | //\\\\       | | || / /                             \\| //     //\\\\ |"<<endl;
    cout <<"  | \\\\//        \\ \\||/ /                               |//      \\\\// |"<<endl;
    cout <<"  |  \\/          '\\\\//'    \\   \\./   \\\\   \\./   \\  \\\\  |/  /     \\/  |"<<endl;
    cout <<"  |  /\\        ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^     /\\  |"<<endl;
    cout <<"  | //\\\\/\\                                                    /\\//\\\\ |"<<endl;
    cout <<"  | \\\\///\\\\/\\//\\\\\\///\\\\/\\//\\\\\\///\\\\/\\//\\\\\\///\\\\/\\//\\\\\\///\\\\/\\//\\\\\\// | "<<endl;
    cout <<"  |  \\/\\\\///\\\\\\//\\/\\\\///\\\\\\//\\/\\\\///\\\\\\//\\/\\\\///\\\\\\//\\/\\\\///\\\\\\//\\/  |"<<endl;
    cout <<"  |     \\/\\\\//\\/    \\/\\\\//\\/    \\/\\\\//\\/    \\/\\\\//\\/    \\/\\\\//\\/     |"<<endl;
    cout <<"  |        \\/          \\/          \\/          \\/          \\/        |"<<endl;
    cout <<"  |  ________________________________________________________________|__"<<endl;
    cout <<"  \\_/__________________________________________________________________/"<<endl;

}

void doghome() {
    cout << "                                 _            " << endl;
    cout << "                               ,/ \\,         " << endl;
    cout << "                             .//`_`\\\\,      " << endl;
    cout << "                           ,//`____-`\\\\,  " << endl;
    cout << "                       ,  //`[_POPPY_]`\\\\, " << endl;
    cout << "                      , //`=  ==  __-  _`\\\\," << endl;
    cout << "                      //|__=  __- == _  __|\\\\" << endl;
    cout << "                     `  |  __ .-----.  _  | ` " << endl;
    cout << "                        | - _/       \\-   |  " << endl;
    cout << "                        |__  | .-\"-. | __=|  " << endl;
    cout << "                        |  _=|/))  (\\|    |  " << endl;
    cout << "                        |-__ (/ . . \\) -__|  " << endl;
    cout << "                        |___ /`\\_Y_/`\\____|  " << endl;
    cout << "                            \\)8===8(/       " << endl;
}
