/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
        prev = NULL;
    }
};

*/
class Solution {
public:
    Node *reverse(Node *head) {
        if (!head || !head->next) return head;
        Node *curr = head, *temp;
        while (curr) {
            temp = curr->next;
            curr->next = curr->prev;
            curr->prev = temp;
            if (!temp) return curr;
            curr = temp;
        }
        return head;
    }
};