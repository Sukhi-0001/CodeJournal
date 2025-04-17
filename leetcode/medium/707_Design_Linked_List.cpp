#include <bits/stdc++.h>
#include <cstddef>
class Node {
public:
  Node *prev;
  int val;
  Node *next;

  Node(int val) {
    this->val = val;
    prev = NULL;
    next = NULL;
  }
  Node(Node *prev, int val, Node *next) {
    this->prev = prev;
    this->val = val;
    this->next = next;
  }
};

class MyLinkedList {
  Node *head;
  int size;

public:
  MyLinkedList() {
    head = NULL;
    size = 0;
  }

  int get(int index) {
    int count = 0;
    Node *current = head;
    while (current) {
      if (count == index)
        return current->val;
      current = current->next;
      count++;
    }
    return -1;
  }

  void addAtHead(int val) {
    head = new Node(NULL, val, head);
    size++;
  }

  void addAtTail(int val) {
    if (head == NULL) {
      addAtHead(val);
      return;
    }
    Node *current = head;
    while (current->next) {
      current = current->next;
    }
    current->next = new Node(current, val, NULL);
    size++;
  }

  void addAtIndex(int index, int val) {
    if (index < 0 || index > size)
      return;
    if (index == 0) {
      addAtHead(val);
      return;
    }
    if (index == size) {
      addAtTail(val);
      return;
    }
    Node *current = head;
    while (--index) {
      current = current->next;
    }
    current->next = new Node(current, val, current->next);
    size++;
  }

  void deleteAtIndex(int index) {
    if (index < 0 || index >= size)
      return;
    size--;
    if (index == 0) {
      Node *temp = head;
      head = head->next;
      delete temp;
      return;
    }
    Node *current = head;
    while (--index) {
      current = current->next;
    }
    Node *temp = current->next;
    current->next = current->next->next;
    delete temp;
    if (current->next) {
      current->next->prev = current;
    }

    return;
  }
}

;
