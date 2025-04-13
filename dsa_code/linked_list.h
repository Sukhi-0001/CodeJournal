#pragma once

#include <cstddef>
class node{
  public:
  node* next;
  int data;
};


class Linked_list
{
private:
  node* head;
  node* new_node(int data,node* ptr){
    node* temp=new node;
    temp->data=data;
    temp->next=ptr;
    return temp;
  }

node* new_node(int data){
    node* temp=new node;
    temp->data=data;
    temp->next=NULL;
    return temp;
  }

public:
  Linked_list(/* args */){
    head=NULL;
  }
  ~Linked_list(){
    head=NULL;
  }

  void insert(int data);
  void insert(int data,int pos);
  void add(int data,int pos);
  int get_legth();
  int kth_node_from_end(int pos_from_back);


  int get_node(int pos);
  void display_list();
};

