#include"NODE.h"
#include"cat.h"
#include"dog.h"

class LL : public Animal {
private:
     Animal *hol = NULL;
     int size;
     friend void delete_cat_ll(LL &ll, Animal *n);
     friend void delete_dog_ll(LL &ll, Animal *n);
     friend void delete_ll(LL &ll);
public:
     void add_node(Animal*&);
     void show_all();
     int d_size();
     Animal* get_hol() const;
     int get_size() const;
     void set_hol(Animal *new_hol) { hol = new_hol; }
     void selection();
     void sort_name();
    
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
     cout<<"---------------------------------------"<<"\n"<<"\n";
     
}

void LL::add_node(Animal *&A){

     hol->insert(A);
     hol=A;

     size++;

}

int LL::d_size()
{
     size--;
     return size;
}

Animal* LL::get_hol() const { 
     return hol; 
}
     
int LL::get_size() const { 
     return size; 
}

void LL::selection() {
     Animal * hol_temp = hol;
     Animal * temp, * temp2 = new Animal, *max_age_node;
     int max_age;
     while (hol_temp != NULL) {
          temp = hol_temp->move_next();
          max_age = hol_temp->get_age2();
          max_age_node = hol_temp;
          while (temp != NULL) {
               if (temp->get_age2() < max_age) {
                    max_age = temp->get_age2();
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

void LL::sort_name() {
     Animal * hol_temp = hol;
     Animal * temp, * temp2 = new Animal, *max_name;
     string max;
     while (hol_temp != NULL) {
          temp = hol_temp->move_next();
          max = hol_temp->get_name();
          max_name = hol_temp;
          while (temp != NULL) {
               if (temp->get_name() > max) {
                    max = temp->get_name();
                    max_name = temp;
               }
               if(temp->move_next()==NULL) {
                    break;
               }
               temp = temp->move_next();
          }

          temp2->add_value(hol_temp);
          hol_temp->add_value(max_name);
          max_name->add_value(temp2);

          hol_temp = hol_temp->move_next();
     }
}

