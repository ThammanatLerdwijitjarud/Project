#include "NODE.h"
class LL{
private:
    Animal *hol;
    int size;
public:
    void add_node(Animal *&);
    void show_all();
    void delete_node(Animal *&);
    
    ~LL();
    LL();
};

LL::LL()
{
    hol = NULL;
    size=0;
}

LL::~LL(){
     int i;
     Animal *temp;
     Animal *t=hol;
     for(i=0;i<size;i++) //แก้
     {
          temp=t;
          t=t->move_next();
          delete temp;
     }
     size=0;   
}

void LL::show_all(){
     Animal* t=hol;
     int i;
     for(i=0;i<size;i++){
        t->show_node();
        t=t->move_next();
     }
     cout<<"--------------------------"<<endl;
     
}
void LL::add_node(Animal *&A){

        hol->insert(A);
        hol=A;

        size++;

 }

void LL::delete_node(Animal *&n)
{
     Animal *temp = hol;
     Animal *pre = NULL;

     if(temp!=NULL && (temp==n))
     {
          if(temp->move_next() != NULL) {
               hol = temp->move_next();
               delete temp;
               size--;
          }
          return ;
     }
     while(temp!=NULL && temp->move_next() != NULL && (temp!=n))
     {
          pre = temp;
          temp = temp->move_next();
     }
     if(temp==n && temp->move_next() != NULL)
     {
          pre->set_next(temp->move_next());
          delete temp;
          size--;
     }
    
}