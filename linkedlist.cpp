//============================================================================
// Name         : Polynomial Calculator 
// Author       : Sadaf Habib
// Version      : 1.0
// Date Created : 23-09-2023
// Date Modified: 
// Description  : Linked List class used for Polynomial Calculagtor
//============================================================================

#include "linkedlist.h"

// Constructor to create an empty linked list
LinkedList::LinkedList() {
    head = nullptr; // Initialize the head pointer to nullptr for an empty list
}

// Method to insert a new term (node) into the linked list while maintaining order
void LinkedList::insert(int coef, int expo) {
    Node* newNode = new Node(coef, expo); // Create a new node with the given coefficient and exponent

    // Check if the list is empty or the new node's exponent is greater than the head's exponent
    if (head == nullptr || expo > head->expo) {
        newNode->next = head; // Set the new node's next pointer to the current head
        head = newNode; // Update the head to the new node
    } else {
        Node* current = head;

        // Traverse the list to find the correct position to insert the new node
        while (current->next != nullptr && current->next->expo >= expo) {
            current = current->next;
        }

        newNode->next = current->next; // Set the new node's next pointer to the next node
        current->next = newNode; // Update the current node's next pointer to the new node
    }
}

// Method to print the linked list in the specified format
void LinkedList::print(ostream& os) const {
    Node* current = head;

    // Traverse the list and print each term in the specified format
    while (current != nullptr) {
        os << current->coef << "x^" << current->expo;

        if (current->next != nullptr) {
            os << " + "; // Add a plus sign if there are more terms
        }

        current = current->next;
    }

    os << endl; // Add a newline at the end of the printed list
}

// Method to remove all nodes in the linked list
void LinkedList::removeAll() {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next; // Move the head to the next node
        delete temp; // Delete the current node
    }
}

// Destructor to clean up all nodes in the linked list
LinkedList::~LinkedList() {
    removeAll(); // Call the removeAll method to delete all nodes
}
