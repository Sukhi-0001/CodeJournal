// i know we have to swap values but i wanted to try to swap nodes
// Definition for singly-linked list.
#include <cstddef>
#include <ctime>
#include <utility>
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  int get_size(ListNode *head) {
    int count = 1;
    while (head->next) {
      head = head->next;
      count++;
    }
    return count;
  }
  ListNode *swapNodes(ListNode *head, int k) {
    int n = get_size(head);
    if (n == 1)
      return head;
    ListNode *front = head, *back = head, *front_prev = NULL, *back_prev = NULL;
    int index = 1;
    while (index < k) {
      front_prev = front;
      front = front->next;
      index++;
    }
    index = 1;
    while (index < (n - k + 1)) {
      back_prev = back;
      back = back->next;
      index++;
    }

    if (front == back)
      return head;

    if (front_prev) {
      front_prev->next = back;
    } else {
      head = back;
    }
    if (back_prev) {
      back_prev->next = front;
    } else {
      head = front;
    }
    // cout<<front->val<<endl;

    // swap next pointers of both nodes
    std::swap(front->next, back->next);

    return head;
  }
};
