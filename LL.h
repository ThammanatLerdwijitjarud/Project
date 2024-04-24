#include"NODE.h"
#include"cat.h"
#include"dog.h"

void swap(Animal *& n1, Animal *& n2);

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
     void show_all();
     int d_size();
     Animal* get_hol() const { return hol; }
     int get_size() const { return size; }
     void set_hol(Animal *new_hol) { hol = new_hol; }
     void clear();
     void selection();
    
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

void LL::show_all(){
     
     Animal* t=hol;

     int i;

     for(i=0;i<size;i++){
          t->show_node();
          t = t->move_next();
     }
     cout<<"-------------------------"<<"\n"<<"\n";
     
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

// void LL::selection() {
//      Animal * hol_temp = hol;
//      Animal * temp;
//      while (hol_temp != NULL) {
//           temp = hol_temp->move_next();
//           while (temp != NULL) {
//                if (hol_temp->get_age() < temp->get_age()) {
//                     swap(hol_temp, temp);
//                }
//                temp = temp->move_next();
//           }
//           hol_temp = hol_temp->move_next();
//      }

//      cout << "test\n";
//      show_all();
// }


// ??????????????????????
void LL::selection() {
     Animal * hol_temp = hol;
     Animal * temp, * temp2 = new Animal, *max_age_node;
     int max_age;
     while (hol_temp != NULL) {
          temp = hol_temp->move_next();
          max_age = stoi(hol_temp->get_age2());
          max_age_node = hol_temp;
          while (temp != NULL) {
               if (stoi(temp->get_age2()) > max_age) {
                    // cout <<"get ";
                    max_age = stoi(temp->get_age2());
                    max_age_node = temp;
               }
               if(temp->move_next()==NULL) {
                    break;
               }
               temp = temp->move_next();
          }

          temp2->add_value(hol_temp);
          hol_temp->add_value(max_age_node);
          max_age_node->add_value(temp2);

          hol_temp = hol_temp->move_next();
     }
}

