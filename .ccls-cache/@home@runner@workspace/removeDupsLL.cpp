
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Node {
public:
  int data;
  Node *next;
  Node(int d) {
    data = d;
    next = nullptr;
  }
};

void removeDuplicates(Node *head) {
  Node *curr = head;
  Node *prev = nullptr;
  unordered_set<int> seen;

  while (curr != nullptr) {
    if (seen.find(curr->data) != seen.end()) {
      prev->next = curr->next;
    } else {
      seen.insert(curr->data);
    }
    prev = curr;
    curr = curr->next;
  }
}

void printList(Node *head) {
  Node *curr = head;
  while (curr != nullptr) {
    cout << curr->data << " ";
    curr = curr->next;
  }
  cout << endl;
}

int main() {
  // Write C++ code here
  Node *head = new Node(12);
  head->next = new Node(11);
  head->next->next = new Node(12);
  head->next->next->next = new Node(21);
  head->next->next->next->next = new Node(41);
  head->next->next->next->next->next = new Node(43);
  head->next->next->next->next->next->next = new Node(21);
  printList(head);
  removeDuplicates(head);
  printList(head);

  return 0;
}