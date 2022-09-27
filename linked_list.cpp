#include <iostream>
using namespace std;

struct Node {
    int value;
    struct Node *prev;
    struct Node *next;
};

//add value to beginning
void push(struct Node** head, int node_data) { 
    struct Node *newNode = new Node;
    newNode->value = node_data;
    newNode->next = *head;
    newNode->prev = NULL;
    *head = newNode;
}

//add value to end
void append(struct Node** head, int node_data) {
    struct Node *newNode = new Node;
    struct Node *last = *head; //for iterating
    newNode->value = node_data;
    newNode->next = NULL;
    //if head/list is null then add new node as head
    if (*head == NULL) {
        *head = newNode;
        return;
    } else {
        //iterating to last available space
        while (last != NULL) {
            last->next = newNode;
            newNode->prev = last;
            return;
       }
    }
}


void deleteNode(struct Node **head, int node_val) {
    struct Node *temp = *head;
    if (temp->value == node_val) { //if the node_val is the head
        temp->next->prev == NULL;
        temp->next == NULL;
    } else {
        while (temp != NULL) {
            if (temp->value == node_val) {
                temp->prev->next = temp->next;
                if (temp->next != NULL) {
                    temp->next->prev = temp->prev;
                }
                temp->prev = NULL;
                temp->next = NULL;
                return;
            }
            temp = temp->next;
        }
    }
}

//...display...
void display(struct Node** head) {
    struct Node *last = (*head);
    while (last != NULL) {
        cout << last->value << " ";
        last = last->next;
    }
}

int main() {
    struct Node* head = NULL;
    append(&head, 20);
    append(&head, 23);
    append(&head, 33);
    deleteNode(&head, 23);
    display(&head);
}
