/*
    Name: <Jonathan Nelson>
    Date: <09/09/2021>
    Desc: Lab 3, Finding and fixing errors in code
*/
#include <iostream>

using namespace std;

struct node_t{
    int data;
    node_t* next;
};

// Adds the value on the end of the linked list starting from node.
void push_back(int value, node_t* node){
    if(node == NULL) return;
    // Walk to end
    while(node->next){
        node = node->next;
    }
    // put a node on the end
    node->next = new node_t;
    node->next->data = value;
    node->next->next = NULL;
}

// Prints the linked list starting from node.
void print(node_t* node){
    // Walk the list and print
    node_t* temp = node;
    temp->data = node->data;
    temp->next = node->next;
    temp = node;
    while(temp->next){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data;
    cout << endl;
}

// Add value to every element of the linked list.
void add(node_t* node, int value){
    while(node->next){
        node->data += value;
        node = node->next;
    }
    node->data += value;
    node = node->next;
}

// Returns a new linked list, based on one starting with node, but in the reverse
// order.
node_t* reverse(node_t* node){
    if(node == NULL) return node;
    // Walk down the good linked list
    node_t* last = NULL;
    
    while(node->next){
        node_t* temp = new node_t;
        temp->data = node->data;
        temp->next = last;
        node = node->next;
        last = temp;
    }
        node_t* temp = new node_t;
        temp->data = node->data;
        temp->next = last;
        last = temp;
    return last;
}

void freeMem(node_t* node){
    node_t* temp = new node_t;
    temp = node;
    while(node->next){
    node = node->next;
    delete temp;
	temp = node;
    }
    delete node;
    node = NULL;
}

int main(){
    node_t* head = new node_t;
    head->data = 1;
    head->next = NULL;
    
    push_back(2, head);
    push_back(3, head);
    push_back(4, head);
    
    cout << "Should be 1 2 3 4 = ";
    print(head);
    
    add(head, 10);

    cout << "Should be 11 12 13 14 = ";
    print(head);
    
    node_t* rev = reverse(head);
    cout << "Should be 14 13 12 11 = ";
    print(rev);
    
    // Return the memory from the linked lists
    freeMem(head);
    head = NULL;
    freeMem(rev);
    rev = NULL;
}