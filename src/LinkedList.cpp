/**
 * @file        LinkedList.cpp
 * @description implements the LinkedList class.
 * @course      2. A.
 * @assignment  Assignment 2.
 * @date        2024-12-06.
 * @author      Mustafa Masri.
 */

#include "../include/LinkedList.hpp"
#include <iostream>
#include <iomanip>
using namespace std;

//I wanted to use the <algorithm> library to use min function but i didn't know if it's allowed or not
//so I created my own function.
//I am very smart.
int min(int a, int b) {
    return (a < b) ? a : b;
}

LinkedList::LinkedList() {
    head = nullptr;
    current = nullptr;
    size = 0;
}

LinkedList::~LinkedList() {
    Node* temp = head;
    while (temp != nullptr) {
        Node* next = temp->getNext();
        delete temp;
        temp = next;
    }
}

void LinkedList::addNode(const string& data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
        current = head;
    } else {
        Node* temp = head;
        while (temp->getNext() != nullptr) {
            temp = temp->getNext();
        }
        temp->setNext(newNode);
    }
    size++;
}

//this part... THIS PART... THIS PART... THIS PART.. AAAAAAAAA
void LinkedList::displayNodes() {
    if (!head) {
        cout << "\nNo tree nodes to display.\n";
        return;
    }

    const int BOX_WIDTH = 10;
    const int PADDING = 2;
    const string BORDER(BOX_WIDTH, '-');
    const string SPACE(PADDING, ' ');

    //calculate current page
    Node* temp = head;
    int currentPos = 0;
    while (temp && temp != current) {
        currentPos++;
        temp = temp->getNext();
    }

    int startPos = (currentPos / 10) * 10;
    Node* displayStart = head;
    for (int i = 0; i < startPos && displayStart; i++) {
        displayStart = displayStart->getNext();
    }

    cout << "\nDisplaying nodes " << startPos + 1 
         << " to " << min(startPos + 10, size) 
         << " (Total: " << size << ")\n\n";

    //top border
    temp = displayStart;
    for (int i = 0; i < 10 && temp; i++) {
        cout << "+" << BORDER << "+";
        if (temp->getNext() && i < 9) cout << SPACE;
        temp = temp->getNext();
    }
    cout << endl;

    //current address
    temp = displayStart;
    for (int i = 0; i < 10 && temp; i++) {
        cout << "| " << setw(8) << hex << temp << dec << " |";
        if (temp->getNext() && i < 9) cout << SPACE;
        temp = temp->getNext();
    }
    cout << endl;

    //tree value after calculating
    temp = displayStart;
    for (int i = 0; i < 10 && temp; i++) {
        cout << "| " << setw(8) << left << temp->getTreeValue() << " |";
        if (temp->getNext() && i < 9) cout << SPACE;
        temp = temp->getNext();
    }
    cout << endl;

    //next pointer
    temp = displayStart;
    for (int i = 0; i < 10 && temp; i++) {
        cout << "| ";
        if (temp->getNext()) {
            cout << setw(8) << hex << temp->getNext() << dec;
        } else {
            cout << setw(8) << "NULL";
        }
        cout << " |";
        if (temp->getNext() && i < 9) cout << SPACE;
        temp = temp->getNext();
    }
    cout << endl;

    //bottom border
    temp = displayStart;
    for (int i = 0; i < 10 && temp; i++) {
        cout << "+" << BORDER << "+";
        if (temp->getNext() && i < 9) cout << SPACE;
        temp = temp->getNext();
    }
    cout << endl;

    //current marker
    temp = displayStart;
    for (int i = 0; i < 10 && temp; i++) {
        if (temp == current) {
            cout << string((BOX_WIDTH/2) + 1, ' ') << "^" << string((BOX_WIDTH/2), ' ');
        } else {
            cout << string(BOX_WIDTH + 2, ' ');
        }
        if (temp->getNext() && i < 9) cout << SPACE;
        temp = temp->getNext();
    }
    cout << endl;

    if (current) {
        cout << "\nCurrent Tree Structure:\n\n";
        current->displayTree();
    }
}


void LinkedList::moveNext() {
    if (current && current->getNext()) {
        current = current->getNext();
    }
}

void LinkedList::movePrev() {
    if (current != head) {
        Node* temp = head;
        while (temp->getNext() != current && temp->getNext() != nullptr) {
            temp = temp->getNext();
        }
        current = temp;
    }
}

void LinkedList::deleteCurrentNode() {
    if (!current) return;

    //for deleting head node
    if (current == head) {
        head = current->getNext();
        delete current;
        current = head;
        size--;
    } else {
        //find the previous node
        Node* prev = head;
        while (prev && prev->getNext() != current) {
            prev = prev->getNext();
        }

        if (prev) {
            prev->setNext(current->getNext());
            delete current;
            current = prev->getNext() ? prev->getNext() : prev;
            size--;
        }
    }

    //if you delete all nodes
    if (head == nullptr) {
        current = nullptr;
    }
}

Node* LinkedList::getCurrentNode() const {
    return current;
}