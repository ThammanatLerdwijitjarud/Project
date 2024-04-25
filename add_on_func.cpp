#include<iostream>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<exception>
#include"p_file.h"

using namespace std;

#define RED_TEXT "\033[31m"
#define GREEN_TEXT "\033[32m"
#define YELLOW_TEXT "\033[33m"
#define BLUE_TEXT "\033[34m"
#define MAGENTA_TEXT "\033[35m"
#define CYAN_TEXT "\033[36m"
#define WHITE_TEXT "\033[37m"
// ANSI escape code for changing text color to default
#define DEFAULT_COLOR "\033[0m"

int menu();
void Choose_sort(LL &ll);
void guide(LL & ll, char c);
void decide(LL & ll, char c);
void bill(string p,string nani,string tel);
void sort_color(LL &ll);
int check_word(const string& name, const string& filename);
int check_word(string n,LL &ll);
void selection_sort(LL &ll, char c);
void welcome();
void option();
void doghome();
void cathome();
void cat_select();
void dog_select();

class Not_number: public exception
{
	public:
	 const char* what() const throw()
	{
		cin.clear();
		cin.ignore(50,'\n');
		return "Invalid";
	}
}notnum;


int menu()
{
    int flag=0,no;
    string i="TBD";
    welcome();
    option();
    while(flag==0)
    {
        do {
            cout<<"What do you want to do ? : ";
            cin>>i;
            cout<<"Please enter only number 1-3"<<endl;
        }while(i.length()>1);
        if(i[0] > '0' && i[0] < '4') {
            flag = 1;
        }
    }
    system("clear");
    no = stoi(i);
    if(no==1)
    {
        cout<<"---------------------"<<"\n";
        cout<<"|     Adopt cat     |"<<"\n";
        cout<<"---------------------"<<"\n";
    }
    else if(no==2)
    {
        cout<<"---------------------"<<"\n";
        cout<<"|     Adopt dog     |"<<"\n";
        cout<<"---------------------"<<"\n";
    }
    else
    {
        cout<<"---------------------"<<"\n";
        cout<<"|       Donate      |"<<"\n";
        cout<<"---------------------"<<"\n";
    }
    return no;
}

void Choose_sort(LL &ll)
{
    int choice,flag=0;
    while(flag==0)
    {
        try {
            cout<< "Sort by..."<<endl;
            cout<< "1. Sort by Color"<< "\n"<<"2. Age (min to max)\n"<<"3. Choose!"<<endl;
            cout<< "You choose : ";
            cin>>choice;
            if(cin.fail()) {
                throw notnum;
            }
            while(choice<1 ||choice>3) { 
                cout<<"Please enter only 1 or 3: ";
                cin>>choice;
                if(cin.fail()) {
                    throw notnum;
                }
            }
            flag=1;
        }
        catch(exception &e) {
            cout<<e.what()<<endl;
        }
    }
    if(choice==1) {
        system("clear");
        cout << "Sorting by Color\n\n";
        sort_color(ll);
    }
    else if(choice == 2) {
        system("clear");
        cout << "Sorting by age\n\n";
        ll.selection();
        ll.show_all();
    }
    else {
        return;        
    }
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
        cathome();
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

bool check_phone(const string& phoneNumber) {
    if (phoneNumber.length() != 12) {
        return false;
    }
    for (char c : phoneNumber) {
        if (!isdigit(c) && c != '-') {
            return false;
        }
    }
    return true;
}


void decide(LL & ll, char c)
{
    string name,person,phone;
    char con;
    int check = 0;
    if(c=='c')
    {
        // cat_select(); ปริ้นรูป
        // sort_color(ll);
        do{
            cout<<"Which cat do you want to adopt ? \nEnter name : ";
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
                // cout << "Phone number (0823456789) : ";
                // cin >> contact;

                //check phone number
                bool validPhoneNumber = false;
                while (!validPhoneNumber) {
                    cout << "Phone number (XXX-XXX-XXXX): ";
                    cin>>phone;

                    validPhoneNumber = check_phone(phone);
                    if (!validPhoneNumber) {
                        cout << "Invalid phone number. Please enter a valid phone number (XXX-XXX-XXXX)." << endl;
                    }
                }
                
                bill(person,name,phone);
                delete_node(name,ll);
                delete_file("test_cat.txt",name);
                cout<<"Reserve cat done!"<<"\n";
            }
    }
    else
    {
        // dog_select(); ปริ้นรูป
        // sort_color(ll);
        do{
            cout<<"Which dog do you want to adopt ? \nEnter name : ";
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

            bool validPhoneNumber = false;
            while (!validPhoneNumber) {
                cout << "Phone number (XXX-XXX-XXXX): ";
                cin>>phone;

                validPhoneNumber = check_phone(phone);
                if (!validPhoneNumber) {
                    cout << "Invalid phone number. Please enter a valid phone number (XXX-XXX-XXXX)." << endl;
                }
            }

            bill(person,name,phone);
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
        }
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
    
    std::cout<<DEFAULT_COLOR <<" ____________________________________________________________________" << endl;
    cout <<"/\\                                                                   \\"<<endl;
    cout <<"\\_|        "<<BLUE_TEXT<<"/\\          /\\          /\\          /\\          /\\        "<<DEFAULT_COLOR<<"|"<<endl;
    cout <<"  |     "<<BLUE_TEXT<<"/\\//\\\\/\\    /\\//\\\\/\\    /\\//\\\\/\\    /\\//\\\\/\\    /\\//\\\\/\\     "<<DEFAULT_COLOR<<"|"<<endl;
    cout <<"  |  "<<CYAN_TEXT<<"/\\//\\\\\\///\\\\/\\//\\\\\\///\\\\/\\//\\\\\\///\\\\/\\//\\\\\\///\\\\/\\//\\\\\\///\\\\/\\  "<<DEFAULT_COLOR<<"|"<<endl;
    cout <<"  | "<<MAGENTA_TEXT<<"//\\\\\\//\\/\\\\///\\\\\\//\\/\\\\///\\\\\\//\\/\\\\///\\\\\\//\\/\\\\///\\\\\\//\\/\\\\///\\\\ "<<DEFAULT_COLOR<<"|"<<endl;
    cout <<"  | "<<MAGENTA_TEXT<<"\\\\//\\/           "<<RED_TEXT<<",                                          "<<MAGENTA_TEXT<<"\\\\// "<<DEFAULT_COLOR<<"|"<<endl;
    cout <<"  |  "<<MAGENTA_TEXT<<"\\/          "<<RED_TEXT<<"/\\^/'\\"<<DEFAULT_COLOR<<"                                          "<<MAGENTA_TEXT<<"\\/  "<<DEFAULT_COLOR<<"|"<<endl;
    cout <<"  |  "<<MAGENTA_TEXT<<"/\\         "<<RED_TEXT<<"| \\/   |"<<DEFAULT_COLOR<<"     ____________________                "<<MAGENTA_TEXT<<"/\\  "<<DEFAULT_COLOR<<"|"<<endl;
    cout <<"  | "<<MAGENTA_TEXT<<"//\\\\        "<<RED_TEXT<<"| |    |"<<DEFAULT_COLOR<<"    ("<<setw(20)<<nani<<   ")              "<<MAGENTA_TEXT<<"//\\\\ "<<DEFAULT_COLOR<<"|"<<endl;
    cout <<"  | "<<MAGENTA_TEXT<<"\\\\//        "<<RED_TEXT<<"\\ \\    /"<<DEFAULT_COLOR<<"    ( (=@.@=)  ₍˄·͈༝·͈˄₎◞ ̑̑))    "<<RED_TEXT<<"_ _       "<<MAGENTA_TEXT<<"\\\\// "<<DEFAULT_COLOR<<"|"<<endl;
    cout <<"  |  "<<MAGENTA_TEXT<<"\\/          "<<RED_TEXT<<"'\\\\//'"<<DEFAULT_COLOR<<"     ("<<setw(20)<<p<<   ")  "<<RED_TEXT<<"_{ ' }_      "<<MAGENTA_TEXT<<"\\/  "<<DEFAULT_COLOR<<"|"<<endl;
    cout <<"  |  "<<MAGENTA_TEXT<<"/\\            "<<DEFAULT_COLOR<<"||       (Tel."<<setw(16)<<tel<<   ") "<<RED_TEXT<<"{ '.!.' }     "<<MAGENTA_TEXT<<"/\\  "<<DEFAULT_COLOR<<"|" <<endl;
    cout <<"  | "<<MAGENTA_TEXT<<"//\\\\           "<<DEFAULT_COLOR<<"||       (____________________) "<<RED_TEXT<<"',_/Y\\_,'    "<<MAGENTA_TEXT<<"//\\\\ "<<DEFAULT_COLOR<<"|"<<endl;
    cout <<"  | "<<MAGENTA_TEXT<<"\\\\//           "<<DEFAULT_COLOR<<"||  "<<GREEN_TEXT<<"."<<DEFAULT_COLOR<<"                             "<<RED_TEXT<<"{_,_}      "<<MAGENTA_TEXT<<"\\\\// "<<DEFAULT_COLOR<<"|"<<endl;
    cout <<"  |  "<<MAGENTA_TEXT<<"\\/            "<<DEFAULT_COLOR<<"||  "<<GREEN_TEXT<<"|\\"<<DEFAULT_COLOR<<"                              "<<DEFAULT_COLOR<<"|         "<<MAGENTA_TEXT<<"\\/  "<<DEFAULT_COLOR<<"|"<<endl;
    cout <<"  |  "<<MAGENTA_TEXT<<"/\\        "<<GREEN_TEXT<<"|\\  "<<DEFAULT_COLOR<<"||  "<<GREEN_TEXT<<"| |                           "<<GREEN_TEXT<<"(\\"<<DEFAULT_COLOR<<"|"<<GREEN_TEXT<<"  /)     "<<MAGENTA_TEXT<<"/\\  "<<DEFAULT_COLOR<<"|"<<endl;
    cout <<"  | "<<MAGENTA_TEXT<<"//\\\\       "<<GREEN_TEXT<<"| | "<<DEFAULT_COLOR<<"|| "<<GREEN_TEXT<<"/ /                            "<<GREEN_TEXT<<" \\"<<DEFAULT_COLOR<<"|"<<GREEN_TEXT<<" //     "<<MAGENTA_TEXT<<"//\\\\ "<<DEFAULT_COLOR<<"|"<<endl;
    cout <<"  | "<<MAGENTA_TEXT<<"\\\\//        "<<GREEN_TEXT<<"\\ \\"<<DEFAULT_COLOR<<"||"<<GREEN_TEXT<<"/ /                               "<<DEFAULT_COLOR<<"|"<<GREEN_TEXT<<"//      "<<MAGENTA_TEXT<<"\\\\// "<<DEFAULT_COLOR<<"|"<<endl;
    cout <<"  |  "<<MAGENTA_TEXT<<"\\/          "<<GREEN_TEXT<<"'\\\\//'    \\   \\./   \\\\   \\./   \\  \\\\  |"<<GREEN_TEXT<<"/  /     "<<MAGENTA_TEXT<<"\\/  "<<DEFAULT_COLOR<<"|"<<endl;
    cout <<"  |  "<<MAGENTA_TEXT<<"/\\        "<<GREEN_TEXT<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^     "<<MAGENTA_TEXT<<"/\\  "<<DEFAULT_COLOR<<"|"<<endl;
    cout <<"  | "<<MAGENTA_TEXT<<"//\\\\/\\                                                    "<<MAGENTA_TEXT<<"/\\//\\\\ "<<DEFAULT_COLOR<<"|"<<endl;
    cout <<"  | "<<MAGENTA_TEXT<<"\\\\///\\\\/\\//\\\\\\///\\\\/\\//\\\\\\///\\\\/\\//\\\\\\///\\\\/\\//\\\\\\///\\\\/\\//\\\\\\// "<<DEFAULT_COLOR<<"| "<<endl;
    cout <<"  |  "<<CYAN_TEXT<<"\\/\\\\///\\\\\\//\\/\\\\///\\\\\\//\\/\\\\///\\\\\\//\\/\\\\///\\\\\\//\\/\\\\///\\\\\\//\\/  "<<DEFAULT_COLOR<<"|"<<endl;
    cout <<"  |     "<<BLUE_TEXT<<"\\/\\\\//\\/    \\/\\\\//\\/    \\/\\\\//\\/    \\/\\\\//\\/    \\/\\\\//\\/     "<<DEFAULT_COLOR<<"|"<<endl;
    cout <<"  |        "<<BLUE_TEXT<<"\\/          \\/          \\/          \\/          \\/        "<<DEFAULT_COLOR<<"|"<<endl;
    cout <<"  |  ________________________________________________________________|__"<<endl;
    cout <<"  \\_/__________________________________________________________________/"<<DEFAULT_COLOR<<endl<<std::endl;

}

void welcome()
{
    string word;
    std::cout<<YELLOW_TEXT << "                              /\\__/\\" << endl;
    cout << "                           ry'• w • 'ヽっ " << endl;
    cout << "                          '!          i" << endl;
    cout << "                             >c__c_,.ノ " << endl; 
    std::cout <<DEFAULT_COLOR<< "                           _"<<YELLOW_TEXT<<"   (                   " << endl;
    std::cout <<DEFAULT_COLOR<< "             __      _____| | __"<<YELLOW_TEXT")"<<DEFAULT_COLOR<<" ___  _ __ ___   ___ " << endl;
    cout << "             \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\" << endl;
    cout << "              \\ V  V /  __/ | (__ (_) | | | | | |  __/" << endl;
    cout << "               \\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|\\___|          _ " << endl;
    std::cout<<YELLOW_TEXT << "                        /\\_/\\  (                               "<<DEFAULT_COLOR<<"| |_ ___ " << endl;
    std::cout<<YELLOW_TEXT << "                      ('• w • づ                               "<<DEFAULT_COLOR<<"| __/ _ \\" << endl;
    std::cout<<YELLOW_TEXT<< "                       o    ,ノ                                "<<DEFAULT_COLOR<<"| || (_) |" << endl;
    std::cout<<YELLOW_TEXT<< "                        O_.ノ                                   "<<DEFAULT_COLOR<<"\\__\\___/" << endl;
    std::cout<<YELLOW_TEXT<< "                         (ノ       "<<DEFAULT_COLOR<<"  "<<"                                    "<<YELLOW_TEXT<<" __    __" << endl;
    std::cout <<DEFAULT_COLOR<< "           _   _  ___  _   _  ____   __  __ _____ _____        __      "<<YELLOW_TEXT<<"o-''))_____\\\\" << endl;
    std::cout <<DEFAULT_COLOR<< "          | | | |/ _ \\| \\ | |/ ___| |  \\/  | ____/ _ \\ \\      / /     "<<YELLOW_TEXT<<"''--__/ * * * )" << endl;
    std::cout <<DEFAULT_COLOR<< "          | |_| | | | |  \\| | |  _  | |\\/| |  _|| | | \\ \\ /\\ / /        "<<YELLOW_TEXT<<"c_c__/-c____/" << endl;
    std::cout <<DEFAULT_COLOR<< "          |  _  | |_| | |\\  | |_| | | |  | | |__| |_| |\\ V  V /" << endl;
    std::cout <<DEFAULT_COLOR<< "          |_| |_|\\___/|_| \\_|\\____| |_|  |_|_____\\___/  \\_/\\_/          " << endl << endl;
    std::cout <<DEFAULT_COLOR<<"                                                          _"<<endl;
    std::cout<<YELLOW_TEXT<< "                       ___  ___                    "<<DEFAULT_COLOR<<" _ __ | | __ _  ___ ___ " << endl;
    std::cout<<YELLOW_TEXT<< "                      /   ヽ    \\                  "<<DEFAULT_COLOR<<"| '_ \\| |/ _` |/ __/ _ \\" << endl;
    std::cout<<YELLOW_TEXT<< "                    く  レ|    ^ヽ zZz             "<<DEFAULT_COLOR<<"| |_) | | (_| | (_|  __/" << endl;
    std::cout<<YELLOW_TEXT<< "                      \\_ _ ノヽ   )|               "<<DEFAULT_COLOR<<"| .__/|_|\\__,_|\\___\\___|" << endl;
    std::cout<<YELLOW_TEXT<< "                      (_と_-ノくニノ               "<<DEFAULT_COLOR<<"|_| " << DEFAULT_COLOR <<endl;
    cout<< "" << endl<<endl;

   cout<<"Please enter to go to the next page.";
    cin.clear();
    cin.ignore(500,'\n');
    system("clear");
}

void dog_select()
{
    std::cout<<YELLOW_TEXT<<endl;
    cout<<"                              /~~~\\"<<endl;
    cout<<"                             /  .. \\"<<endl;
    cout<<"                            (_,\\  |_)"<<endl;
    cout<<"                           /   \\@/    /^^^\\"<<endl;
    cout<<"    _     /)---(\\   _     /      \\   / . . \\"<<endl;
    cout<<"    \\\\   (/ . . \\)  \\\\   /  `    |   V\\ Y /V"<<endl;
    cout<<"     \\\\__)-\\(*)/      \\\\/  \\   | _\\    / - \\"<<endl;
    cout<<"     \\_       (_       \\   /__'|| \\\\_  |    \\"<<endl;
    cout<<"     (___/-(____)       \\_____)|_).\\_).||(__V"<<DEFAULT_COLOR<<endl;
}

void cat_select()
{
    std::cout<<YELLOW_TEXT<<endl;
    cout<<"                     ⟁ ,,⟁ ⟁ ,,⟁"<<endl;
    cout<<"                 ⟁ (' •w• )(•w• ') ⟁ ⟁"<<endl;
    cout<<"                (' •w)   U)(つとノ(w • ' )"<<endl;
    cout<<"                | U (    '•)(•'   )  とノ"<<endl;
    cout<<"                 u-u(|     )(    ノ u-u"<<endl;
    cout<<"                     'u-u'.  'u-u'"<<DEFAULT_COLOR<<endl;
    cout<<endl;
}

void cathome()
{
    
    std::cout<<DEFAULT_COLOR<<"       /\\_/\\"<<endl;
    cout<<"      (  •w•)"<<endl;
    std::cout<<RED_TEXT<<"  ____"<<DEFAULT_COLOR<<"|  つ/("<<RED_TEXT<<"________"<<endl;
    cout<<" /_______"<<DEFAULT_COLOR<<"ヒ-("<<RED_TEXT<<"_______/|"<<endl;
    cout<<"|__________________|/"<<DEFAULT_COLOR<<endl<<endl;
}

void doghome() {
    std::cout<<RED_TEXT << "                                 _            " << endl;
    cout << "                               ,/ \\,         " << endl;
    cout << "                             .//`_`\\\\,      " << endl;
    cout << "                           ,//`____-`\\\\,  " << endl;
    cout << "                       ,  //`[_"<<DEFAULT_COLOR<<"POPPY"<<RED_TEXT<<"_]`\\\\, " << endl;
    cout << "                      , //`=  ==  __-  _`\\\\," << endl;
    cout << "                      //|__=  __- == _  __|\\\\" << endl;
    cout << "                     `  |  __ .-----.  _  | ` " << endl;
    cout << "                        | - _/       \\-   |  " << endl;
    cout << "                        |__  | "<<DEFAULT_COLOR<<".-\"-. "<<RED_TEXT<<"| __=|  " << endl;
    cout << "                        |  _=|"<<DEFAULT_COLOR<<"/))  (\\"<<RED_TEXT<<"|    |  " << endl;
    cout << "                        |-__ "<<DEFAULT_COLOR<<"(/ . . \\) "<<RED_TEXT<<"-__|  " << endl;
    cout << "                        |___ "<<DEFAULT_COLOR<<"/`\\_Y_/`\\"<<RED_TEXT<<"____|  " << endl;
    std::cout<<DEFAULT_COLOR << "                             \\)8===8(/       " << DEFAULT_COLOR<<endl;
}

void option()
{

    std::cout<<DEFAULT_COLOR<<"  ____ _                                       _   _ "<<endl;
    cout<<" / ___| |__   ___   ___  ___  ___   ___  _ __ | |_(_) ___  _ __     "<<endl;
    cout<<"| |   | '_ \\ / _ \\ / _ \\/ __|/ _ \\ / _ \\| '_ \\| __| |/ _ \\| '_ \\  "<<endl;
    cout<<"| |___| | | | (_) | (_) \\__ \\  __/| (_) | |_) | |_| | (_) | | | |"<<endl;
    cout<<" \\____|_| |_|\\___/ \\___/|___/\\___| \\___/| .__/ \\__|_|\\___/|_| |_| "<<endl;
    cout<<"                                        |_| "<<endl<<endl;
    std::cout<<BLUE_TEXT<<" _        _       _             _               _               ____         _       _             _          _"<<endl;
    cout<<"/ |      / \\   __| | ___  _ __ | |_    ___ __ _| |_            |___ \\       / \\   __| | ___  _ __ | |_     __| | ___   __ _     "<<endl;
    cout<<"| |     / _ \\ / _` |/ _ \\| '_ \\| __|  / __/ _` | __|             __) |     / _ \\ / _` |/ _ \\| '_ \\| __|   / _` |/ _ \\ / _` |   "<<endl;
    cout<<"| |_   / ___ \\ (_| | (_) | |_) | |_  | (_| (_| | |_             / __/ _   / ___ \\ (_| | (_) | |_) | |_   | (_| | (_) | (_| |"<<endl;
    cout<<"|_(_) /_/   \\_\\__,_|\\___/| .__/ \\__|  \\___\\__,_|\\__|           |_____(_) /_/   \\_\\__,_|\\___/| .__/ \\__|   \\__,_|\\___/ \\__, |   "<<endl;
    cout<<"                         |_|                                                                |_|                       |___/  "<<endl;
    cout<<"                                                              "<<endl;
    std::cout<<DEFAULT_COLOR"                                                                                          ___"<<endl;
    cout<<"                   /\\__/\\                                                              __/_  '.  .-\"\"\"-."<<endl;
    cout<<"                  (' •w•)づ__/\\                                                        \\_,' | \\-'  /   )'-')"<<endl;
    cout<<"                  (っ  / ( •w•=)                                                          "") '""    \\  (('"""<<endl;
    cout<<"                  し--J  (nn ノ)  pat pat                                                ___Y  ,    .'7 /|"<<endl;
    cout<<"                                                                                        (_,___/...-' (_/_/ "<<endl;
    std::cout<<BLUE_TEXT"                                       _____    ____                    _   "<<endl;
    cout<<"                                      |___ /   |  _ \\  ___  _ __   __ _| |_ ___ "<<endl;
    cout<<"                                        |_ \\   | | | |/ _ \\| '_ \\ / _` | __/ _ \\"<<endl;
    cout<<"                                       ___) |  | |_| | (_) | | | | (_| | ||  __/"<<endl;
    cout<<"                                      |____(_) |____/ \\___/|_| |_|\\__,_|\\__\\___|"<<endl;
    cout<<""<<endl;
    std::cout<<DEFAULT_COLOR<<"                                                                v"<<endl;
    cout<<"                                                  ___     .--,  |"<<endl;
    cout<<"                                                 |   |   (('')) /"<<endl;
    cout<<"                                                 |___|___ /  \\/ "<<endl;
    cout<<"                                                         /____\\"<<endl;
    cout<<"                                                          _/ \\_"<<DEFAULT_COLOR<<endl;
}


