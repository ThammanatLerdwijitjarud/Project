#include "NODE.h"
#include"cat.h"
#include"dog.h"
class LL : public Animal {
private:
    Animal *hol = NULL;
    cat *c_hol = NULL;
    dog *d_hol = NULL;
    int size;
public:
    void add_node(Animal*&);
//     void add_node(cat*&);
//     void add_node(dog*&);
    void show_all(char);
    void delete_node(Animal*&);
    
    ~LL();
    LL();
};

LL::LL()
{
    hol = NULL;
    size=0;
}

LL::~LL(){

     Animal * temp;

     while(hol != NULL) {
          temp = hol;
          hol = hol->move_next();
          delete temp;
     }

     // int i;
     // Animal *temp;
     // Animal *t=hol;
     // while(t != NULL)
     // {
     //      temp = t;
     //      t = t->move_next();
     //      delete temp;
     // }
     // cat *c_temp;
     // cat *c_t = c_hol;
     // while(c_t != NULL)
     // {
     //      // cout << "a" << endl;
     //      c_temp = c_t;
     //      // c_temp->show_node();
     //      c_t = c_t->move_next();
     //      delete c_temp;
     // }
     // dog *d_temp;
     // dog *d_t = d_hol;
     // while(d_t!=NULL)
     // {
     //      d_temp = d_t;
     //      d_t = d_t->move_next();
     //      delete d_temp;
     // }
     // size=0;   
}

void LL::show_all(char a){
     
     Animal* t=hol;

     int i;

     for(i=0;i<size;i++){
          t->show_node();
          t = t->move_next();
     }

     // if(a=='c')
     // {
     //      cat* t = c_hol;
     //      int i;
     //      for(i=0;i<size;i++){
     //           t->show_node();
     //           t=t->move_next();
     //      }
     //      //cout<<"--------------------------"<<endl;
     // }
     // else
     // {
     //      dog* t = d_hol;
     //      int i;
     //      for(i=0;i<size;i++){
     //           t->show_node();
     //           t=t->move_next();
     //      }
     //      //cout<<"--------------------------"<<endl;
     // }
     
}

void LL::add_node(Animal *&A){

     hol->insert(A);
     hol=A;

     size++;

}

// void LL::add_node(cat *&A){

//           c_hol->insert(A);
//           c_hol=A;

//        size++;

// }
// void LL::add_node(dog *&A){

//           d_hol->insert(A);
//           d_hol=A;

//        size++;

// }

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