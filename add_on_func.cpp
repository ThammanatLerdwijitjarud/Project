#include<iostream>
#include<fstream>
#include<sstream>
#include<iomanip>
#include"p_file.h"

int menu();
void guide(LL & ll, char c);
void decide(LL & ll, char c);
void bill(string p,string nani,string tel);
void sort_color(LL &ll);
int check_word(const string& name, const string& filename);
int check_word(string n,LL &ll);

int menu()
{
    int i;
    cout<<R"(Choose option :
    1. Adopt cat
    2. Adopt dog
    3. Donate
Enter menu : )";
    cin>>i;
    while(i<1 ||i>3) 
    { 
        cout<<"Please enter only 1-3: ";
        cin>>i;
    }
    return i;
}


void guide(LL &ll,char c)
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
        ll.home();
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
        ll.home();
    }
}

void decide(LL & ll, char c)
{
    string name,person,contact;
    char con;
    int check = 0;
    if(c=='c')
    {
        // cat_select(); ปริ้นรูป
        sort_color(ll);
        do{
            cout<<"Which cat do you want to adopt ? Enter name : ";
            cin>>name;
            check = check_word(name,ll);
            if(check==0)
            {
                cout << "not found please enter again"<< endl;            
            }
        } while(check==0);
            guide(ll,'c');
            cout<<"Confirm (y/n) : ";
            cin>>con;
            if(con=='y' || con=='Y')
            {
                cout << "please enter your information"<<endl;
                cout << "Name : ";
                cin >> person;
                cout << "Phone number (0823456789) : ";
                cin >> contact;
                bill(person,name,contact);
                delete_node(name,ll);
                delete_file("test_cat.txt",name);
                cout<<"Reserve cat done!"<<"\n";
            }
    }
    else
    {
        // dog_select(); ปริ้นรูป
        sort_color(ll);
        do{
            cout<<"Which dog do you want to adopt ? Enter name : ";
            cin>>name;
            check = check_word(name,ll);
            if(check==0)
            {
                cout << "not found please enter again" << endl;            
            }
        }while(check==0);
        guide(ll,'d');
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
            delete_file("test_dog.txt",name);
            cout<<"Reserve dog done!"<<"\n"; //delete dog ที่จอง
        }
    }
}

int check_word(string n,LL &ll)
{
    Animal *a = ll.get_hol();
    int check=0;

    while(a!=NULL)
    {
        if(n==a->get_name())
        {
            check = 1; //เจอ
        }
        a = a->move_next();     
    }
    // cout<<"check = "<<check<<"\n";
    return check;
}


void bill(string p,string nani,string tel)
{
    cout<<"bill1"<<endl;
    
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
    cout <<"  |  /\\            ||       (Tel."<<setw(16)<<tel<<   ") { '.!.' }     /\\  |" <<endl;
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

void sort_color(LL &ll)
{
    Animal *a = ll.get_hol();
    int i,flag=0;
    string col;
    cout<< "Which color do you want ? : ";
    cin>>col;

    while(a!=NULL)
    {
        if(col==a->get_color())
        {
            a->show_node();
            flag++;
            // cout<<"sort-c1"<<endl;
        }
        // cout<<"sort-c2"<<endl;
        a = a->move_next();  
        
    }
    if(flag==0)
    {
        cout<<"We don't have that color, please enter color again."<<endl;
        sort_color(ll);
    }
    
}

