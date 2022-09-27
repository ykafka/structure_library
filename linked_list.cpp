//WIP

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
    newNode->next = (*head);
    newNode->prev = NULL;
    (*head) = newNode;
}

//add value to end
void append(struct Node** head, int node_data) {
    struct Node *newNode = new Node;
    struct Node *last = *head;
    newNode->value = node_data;
    newNode->next = NULL;
    //if head/list is null then add new node as head
    if (*head = NULL) {
        *head = newNode;
        return;
    }
    //iterating to last available space
    while (last->next != NULL) {
        last = last->next;
        last->next = newNode;
        newNode->prev = last;
        return;
    }
}

//add value after another specified value
void insertAfter(struct Node* prev_node, int node_data) {
    struct Node* newNode = new Node;
    newNode->value = node_data;
    newNode->next = prev_node->next;
    newNode->prev = prev_node;
    prev_node->next = newNode;
}

void deleteNode(struct Node **head, int node_val) {
    struct Node *temp = *head;
    while (temp->next != NULL) {
        if (temp->value == node_val) {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            temp->prev = NULL;
            temp->next = NULL;
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
    display(&head);
}
