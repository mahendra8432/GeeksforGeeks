/*
class Node {
public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
public:
    Node* mergeSort(Node* head) {
        if (!head || !head->next) return head;

        Node* slow = head;
        Node* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        Node* rightHalf = slow->next;
        slow->next = nullptr;

        Node* left = mergeSort(head);
        Node* right = mergeSort(rightHalf);

        return merge(left, right);
    }
    
    Node* merge(Node* a, Node* b) {
        if (!a) return b;
        if (!b) return a;

        if (a->data <= b->data) {
            a->next = merge(a->next, b);
            return a;
        } else {
            b->next = merge(a, b->next);
            return b;
        }
    }
};
