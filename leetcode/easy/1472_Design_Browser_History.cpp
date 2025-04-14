#include <bits/stdc++.h>
#include <string>
using namespace std;
class Node {
public:
  Node *prev;
  string val;
  Node *next;
  Node();
  Node(string val) {
    this->val = val;
    prev = NULL;
    next = NULL;
  }

  Node(Node *prev, string val, Node *next) {
    this->prev = prev;
    this->val = val;
    this->next = next;
  }
};
class BrowserHistory {
  Node *head = NULL;

public:
  BrowserHistory(string homepage) { head = new Node(homepage); }

  void visit(string url) {
    Node *temp = new Node(NULL, url, head);
    head->prev = temp;
    head = temp;
  }

  string back(int steps) {
    while (steps-- && head->next) {
      head = head->next;
    }
    return head->val;
  }

  string forward(int steps) {
    while (steps-- && head->prev) {
      head = head->prev;
    }
    return head->val;
  }
};
