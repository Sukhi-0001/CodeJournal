#include <cstddef>
#include <linked_list.h>
#include <climits>
#include <stdlib.h>
#include <iostream>
using namespace std;

/*
appends node to the linklist
*/
void Linked_list::insert(int data){
  if(head==NULL){
    head=new_node(data);
    return;
  }
  node* current=head;
  while (current->next) {
    current=current->next;
  }
  current->next=new_node(data);
}

void Linked_list::insert(int data,int pos){
  if(pos<1){
    cout<<"out of bounds positon"<<endl;
    return;
  }
  node* current=head;
  if(pos<=1){
    node* temp=new_node(data);
    temp->next=head;
    head=temp;
    return;
  }
  pos=pos-2;
  while (pos && current)
  {
    pos--;
    current=current->next;
  }
  if(current == NULL ){
    cout<<"out of bounds"<<endl;
    return;
  }
  node* temp=new_node(data);
  temp->next=current->next;
  current->next=temp;
}

int Linked_list::get_legth(){
  node* current=head;
  int count=0;
  while(current){
    current=current->next;
    count++;
  }
  return count;
}

int Linked_list::kth_node_from_end(int pos_from_back){
  // 2pointers approch
  node* kth_node=head,*front_node=head;
  if(pos_from_back<1){
    cout<<"out of bounds"<<endl;
    return INT_MIN;
  }

  while(pos_from_back){
    pos_from_back--;
    if(!front_node){
      cout<<"pos from back bigger than length"<<endl;
      return INT_MIN;
    }
    front_node=front_node->next;
  }
  while(front_node){
    front_node=front_node->next;
    kth_node=kth_node->next;
  }
  return kth_node->data;
}

/*
it returns node at pos
if no node is availbe at that pos it return INT_MIN
*/
int Linked_list::get_node(int pos){
  if(pos<1 || head==NULL)
    return INT_MIN;
  node *current=head;
  int count=1;
  while(count<pos){
    if(!current->next)
      return INT_MIN;
    current=current->next;
    count++;
  }

  return current->data;
}

void Linked_list::display_list(){
  cout<<"*****LIST*****"<<endl;
  node* current=head;
  while(current){
    cout<<current->data<<" -> ";
    current=current->next;
  }
  cout<<"NULL"<<endl;
  cout<<"*****END*****"<<endl;
}
