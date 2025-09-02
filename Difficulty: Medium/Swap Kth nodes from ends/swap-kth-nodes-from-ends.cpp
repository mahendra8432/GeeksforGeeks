/*
class Node {
  public:
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
    Node* swapKth(Node* head, int k) {
        // code here
        vector<int>ans;
        Node* curr=head;
        while(curr!=NULL){
            ans.push_back(curr->data);
            curr=curr->next;
        }
        int n=ans.size();
        if(n<k) return head;
        swap(ans[k-1],ans[n-k]);
        if(ans.size()==0) return NULL;
        curr=new Node(ans[0]);
        head=curr;
        for(int i=1;i<n;i++){
            curr->next=new Node(ans[i]);
            curr=curr->next;
        }
        return head;
    }

    
};