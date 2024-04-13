#include "linked_list.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

Linked_List::Linked_List() {
    this->length = 0;
    this->head = NULL;
}

int Linked_List::get_length() {
    return this->length; //returns length
}

void Linked_List::print() {
    Node* current = head;
    while(current->next_node != NULL) { 
        cout << current->value << " "; 
        current = current->next_node; 
    };
    cout << current->value << endl;
}

void Linked_List::clear() {
    Node* new_head = this->head;
    Node* current = new_head; 
    Node* temp; 
    while(current != NULL) {
        temp = current->next_node;
        delete current;
        current = temp;
    }
    this->length = 0;
}

void Linked_List::push_front(int value) {
    Node* beginning = new Node;
    beginning->next_node = head; 
    beginning->value = value;
    head = beginning;
    this->length += 1;
}

void Linked_List::push_back(int value) {
    Node* ending = new Node;
    ending->value = value;
    ending->next_node = NULL;
    Node* last = head;
    do { 
        last = last->next_node;
    } while(last->next_node != NULL);
    last->next_node = ending;
    this->length += 1;
}

void Linked_List::insert(int value, int index) {
    Node* inserting = new Node;
    Node* hold = this->head;
    int count = 0;

    if (index > this->length) {
        delete inserting;
        return;
    } 
    else if(this->length == index) {
        push_back(value);
    } 
    else if(index == 0) {
        push_front(value);
    }
    else {
        do {
            count += 1;
            hold = hold->next_node;
        } while (count != (index - 1));
        inserting->value = value;
        inserting->next_node = hold->next_node;
        hold->next_node = inserting;
        this->length += 1;
    }
    delete inserting;
}
