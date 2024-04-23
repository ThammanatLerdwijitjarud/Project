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
void welcome();
void option();
void doghome();
void cathome();
void cat_select();
void dog_select();


int menu()
{
    int i;
    //option();
    cout <<"1 cat 2dog 3 donate "<<endl;
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

void welcome()
{
    string word;
    cout << "" << endl;
    cout << "" << endl;
    cout << "" << endl;
    cout << "                              /\\__/\\" << endl;
    cout << "                           ry'• w • 'ヽっ " << endl;
    cout << "                          '!          i" << endl;
    cout << "                             >c__c_,.ノ " << endl; 
    cout << "                           _   (                   " << endl;
    cout << "             __      _____| | __) ___  _ __ ___   ___ " << endl;
    cout << "             \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\" << endl;
    cout << "              \\ V  V /  __/ | (__ (_) | | | | | |  __/" << endl;
    cout << "               \\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|\\___|          _ " << endl;
    cout << "                        /\\_/\\  (                               | |_ ___ " << endl;
    cout << "                      ('• w • づ                               | __/ _ \\" << endl;
    cout << "                       o    ,ノ                                | || (_) |" << endl;
    cout << "                        O_.ノ                                   \\__\\___/" << endl;
    cout << "                         (ノ           _ _   _                   __    __" << endl;
    cout << "           _ __   __ ___      _____(_) |_(_)_   _____           o-''))_____\\\\" << endl;
    cout << "          | '_ \\ / _` \\ \\ /\\ / / __| | __| \\ \\ / / _ \\        ''--__/ * * * )" << endl;
    cout << "          | |_) | (_| |\\ V  V /\\__ \\ | |_| |\\ V /  __/        c_c__/-c____/" << endl;
    cout << "          | .__/ \\__,_| \\_/\\_/ |___/_|\\__|_| \\_/ \\___|" << endl;
    cout << "          |_|                                            _               " << endl;
    cout << "                       ___  ___                    _ __ | | __ _  ___ ___ " << endl;
    cout << "                      /   ヽ    \\                  | '_ \\| |/ _` |/ __/ _ \\" << endl;
    cout << "                    く  レ|    ^ヽ zZz             | |_) | | (_| | (_|  __/" << endl;
    cout << "                      \\_ _ ノヽ   )|               | .__/|_|\\__,_|\\___\\___|" << endl;
    cout << "                      (_と_-ノくニノ               |_| " << endl;
    cout << "" << endl;
    cout << "plese enter any word for next page" << endl;
    cin >> word;
}

void dog_select()
{
    cout<<endl;
    cout<<"     _     /)---(\\          /~~~\\"<<endl;
    cout<<"     \\\\   (/ . . \\)        /  .. \\"<<endl;
    cout<<"      \\\\__)-\\(*)/         (_,\\  |_)"<<endl;
    cout<<"      \\_       (_         /   \\@/    /^^^\\"<<endl;
    cout<<"      (___/-(____) _     /      \\   / . . \\"<<endl;
    cout<<"                   \\\\   /  `    |   V\\ Y /V"<<endl;
    cout<<"                    \\\\/  \\   | _\\    / - \\"<<endl;
    cout<<"                     \\   /__'|| \\\\_  |    \\"<<endl;
    cout<<"                      \\_____)|_).\\_).||(__V"<<endl;
}

void cat_select()
{
    cout<<endl;
    cout<<"                     ⟁ ,,⟁ ⟁ ,,⟁"<<endl;
    cout<<"                 ⟁ (' •w• )(•w• ') ⟁ ⟁"<<endl;
    cout<<"                (' •w)   U)(つとノ(w • ' )"<<endl;
    cout<<"                | U (    '•)(•'   )  とノ"<<endl;
    cout<<"                 u-u(|     )(    ノ u-u"<<endl;
    cout<<"                     'u-u'.  'u-u'"<<endl;
    cout<<""<<endl;
}

void cathome()
{
    
    cout<<"      /\\_/\\"<<endl;
    cout<<"     (  •w•)"<<endl;
    cout<<" ____|  つ/(________"<<endl;
    cout<<"/_______ヒ-(_______/"<<endl;
    cout<<"__________________"<<endl;
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
    cout << "                             \\)8===8(/       " << endl;
}

void option()
{
    cout<<"  ____ _ "<<endl;
    cout<<" / ___| |__   ___   ___  ___  ___   ___  _ __ | |_(_) ___  _ __     "<<endl;
    cout<<"| |   | '_ \\ / _ \\ / _ \\/ __|/ _ \\ / _ \\| '_ \\| __| |/ _ \\| '_ \\  "<<endl;
    cout<<"| |___| | | | (_) | (_) \\__ \\  __/| (_) | |_) | |_| | (_) | | | |"<<endl;
    cout<<" \\____|_| |_|\\___/ \\___/|___/\\___| \\___/| .__/ \\__|_|\\___/|_| |_| "<<endl;
    cout<<"                                        |_| "<<endl<<endl;
    cout<<" _        _       _             _               _               ____         _       _             _          _"<<endl;
    cout<<"/ |      / \\   __| | ___  _ __ | |_    ___ __ _| |_            |___ \\       / \\   __| | ___  _ __ | |_     __| | ___   __ _     "<<endl;
    cout<<"| |     / _ \\ / _` |/ _ \\| '_ \\| __|  / __/ _` | __|             __) |     / _ \\ / _` |/ _ \\| '_ \\| __|   / _` |/ _ \\ / _` |   "<<endl;
    cout<<"| |_   / ___ \\ (_| | (_) | |_) | |_  | (_| (_| | |_             / __/ _   / ___ \\ (_| | (_) | |_) | |_   | (_| | (_) | (_| |"<<endl;
    cout<<"|_(_) /_/   \\_\\__,_|\\___/| .__/ \\__|  \\___\\__,_|\\__|           |_____(_) /_/   \\_\\__,_|\\___/| .__/ \\__|   \\__,_|\\___/ \\__, |   "<<endl;
    cout<<"                         |_|                                                                |_|                       |___/  "<<endl;
    cout<<"                                                              "<<endl;
    cout<<"                                                                                          ___"<<endl;
    cout<<"                   /\\__/\\                                                              __/_  '.  .-\"\"\"-."<<endl;
    cout<<"                  (' •w•)づ__/\\                                                        \\_,' | \\-'  /   )'-')"<<endl;
    cout<<"                  (っ  / ( •w•=)                                                          "") '""    \\  (('"""<<endl;
    cout<<"                  し--J  (nn ノ)  pat pat                                                ___Y  ,    .'7 /|"<<endl;
    cout<<"                                                                                        (_,___/...-' (_/_/ "<<endl;
    cout<<"                                       _____    ____                    _   "<<endl;
    cout<<"                                      |___ /   |  _ \\  ___  _ __   __ _| |_ ___ "<<endl;
    cout<<"                                        |_ \\   | | | |/ _ \\| '_ \\ / _` | __/ _ \\"<<endl;
    cout<<"                                       ___) |  | |_| | (_) | | | | (_| | ||  __/"<<endl;
    cout<<"                                      |____(_) |____/ \\___/|_| |_|\\__,_|\\__\\___|"<<endl;
    cout<<""<<endl;
    cout<<"                                                                v"<<endl;
    cout<<"                                                  ___     .--,  |"<<endl;
    cout<<"                                                 |   |   (('')) /"<<endl;
    cout<<"                                                 |___|___ /  \\/ "<<endl;
    cout<<"                                                         /____\\"<<endl;
    cout<<"                                                          _/ \\_"<<endl;
}


