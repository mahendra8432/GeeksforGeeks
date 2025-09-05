
/*
delete n nodes after m nodes
  The input list will have at least one element
  Node is defined as

struct Node {
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* linkdelete(Node* head, int n, int m) {
        // code here MAhendra
        Node* temp =  head ;
        int keep = m , skip = n; 
        while(temp->next){
            if(--keep>0) temp = temp->next;     // keep m nodes
            else if(skip-->0){                  //keep pointing mth node to next next node for n times
                temp->next = temp->next->next;
            }
            else{
                temp = temp->next ;             //move to next node after skipping n nodes and reset the keep skip counter
                keep = m;
                skip = n;
            }
        }
        return head;
    }
};