#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

void removeConsecutiveNodeWithZeroSum(node** head){
    int sum = 0;
    node* curr = *head;
    node* prev = *head;
    if (head == NULL)
        return;
    while (curr != NULL){
        sum += curr->data;
        if (curr->data == 0){
            if (curr == *head){
                *head = curr->next;
                prev = *head;
            }else{
                prev->next = curr->next;
            }
        }else if (sum == 0){
            *head = curr->next;
            prev = *head;
        }else if (sum == (*head)->data){
            (*head)->next = curr->next;
            prev = *head;
        }else{
            prev = curr;
        }
        curr = curr->next;
    }
}

void insert(node* prev, int val){
    if (prev == NULL){
        cout << "Previous node cannot be NULL!" << endl;
        return;
    }

    node* new_node = new node();
    new_node->data = val;
    new_node->next = prev->next;
    prev->next = new_node;
}

void printList(node* Node){
    while(Node != NULL){
        cout << Node->data <<" ";
        Node = Node->next;
    }
    cout << endl;
}

int main(){
    int n;
    cin >> n;
    int val;
    node* head = NULL;
    head = new node();
    node* prev = head;
    for(int i = 0; i < n; i++){
        cin >> val;
        if (i == 0){
            head->data = val;
            head->next = NULL;
        }
        else{
            insert(prev, val);
            prev = prev->next;
        }
    }
    removeConsecutiveNodeWithZeroSum(&head);
    if (head == NULL){
        cout << "NULL" << endl;
    }else{
        printList(head);
    }
    
    return 0;
}  
