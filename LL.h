#include"NODE.h"
#include"cat.h"
#include"dog.h"
class LL : public Animal {
private:
     Animal *hol = NULL;
     cat *c_hol = NULL;
     dog *d_hol = NULL;
     int size;
     friend void delete_cat_ll(LL &ll, Animal *n);
     friend void delete_dog_ll(LL &ll, Animal *n);
     friend void delete_ll(LL &ll);
public:
     void add_node(Animal*&);
     // void add_node(cat*&);
     // void add_node(dog*&);
     void show_all(char);
     // void delete_node(string name);
     // void delete_node(Animal*&);
     int d_size();
     Animal* get_hol() const { return hol; }
     int get_size() const { return size; }
     void set_hol(Animal *new_hol) { hol = new_hol; }
     void clear();
    
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

}

void LL::show_all(char a){
     
     Animal* t=hol;

     int i;

     for(i=0;i<size;i++){
          t->show_node();
          t = t->move_next();
     }
     
}

void LL::add_node(Animal *&A){

     hol->insert(A);
     hol=A;

     size++;

}

// void LL::delete_node(Animal *&n)
// {
//      Animal *temp = hol;
//      Animal *pre = NULL;

//      if(temp!=NULL && (temp==n))
//      {
//           if(temp->move_next() != NULL) {
//                hol = temp->move_next();
//                delete temp;
//                size--;
//           }
//           return ;
//      }
//      while(temp!=NULL && temp->move_next() != NULL && (temp!=n))
//      {
//           pre = temp;
//           temp = temp->move_next();
//      }
//      if(temp==n && temp->move_next() != NULL)
//      {
//           pre->set_next(temp->move_next());
//           delete temp;
//           size--;
//      }
    
// }
int LL::d_size()
{
     size--;
     return size;
}

// void LL::clear() {
//     Animal *current = hol;
//     Animal *nextNode;

//     while (current != NULL) {
//         nextNode = current->move_next();
//         delete current;
//         current = nextNode;
//     }

//     // กำหนด hol เป็น NULL เพื่อบ่งชี้ว่าลิงก์ลิสต์ว่างเปล่า
//     hol = NULL;
//     size = 0; // รีเซ็ตขนาดลิงก์ลิสต์เป็น 0
// }
