#include <bits/stdc++.h>
// Definition for a Node.
class Node {
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

class Solution {
public:
  Node *copyRandomList(Node *head) {
    Node *current = head;
    if (!head)
      return head;

    while (current) {
      Node *new_node = new Node(current->val);
      new_node->next = current->next;
      current->next = new_node;
      current = new_node->next;
    }

    current = head;
    Node *new_head = current->next;
    while (current) {
      Node *new_node = current->next;
      Node *next_current = new_node->next;
      // set random pointer
      if (current->random)
        new_node->random = current->random->next;
      current = next_current;
    }
    current = head;
    while (current) {
      Node *new_node = current->next;
      Node *next_current = new_node->next;
      current->next = next_current;
      if (next_current)
        new_node->next = next_current->next;
      current = next_current;
    }

    return new_head;
  }
};
