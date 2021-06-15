#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
// Start typing here
// This was a coding challenge for Bloomberg
/*
A Sorted Linked List is a singly linked list where elements are inserted in ascending order. Design the sorted linked list and implement the insert and print member methods. For the purposes of this question, we are only inserting **unique integer values */
using namespace std;
struct Node {
    int data;
    Node * next;
    Node(int d) {
        data = d;
        next = nullptr;
    }
};

class SortedLinkedList {
    private:
        Node * root;
    
    public:
        SortedLinkedList() {
            root = nullptr;
        }
        
        void insert(int newData) {
            Node * temp = this->root;
            Node * newNode = new Node(newData);
            
            if (temp == NULL) {
                // if this is the first item, replace "placeholder" node
                this->root = newNode;
                cout<<"Inserting first node\n";
                return;
            }

            while (temp) {
                // handle normal insertion case
                if (!temp->next) {
                    // There are no more nodes at the end of the list
                    // handle the end of the list insertion
                    temp->next = newNode;
                    cout<<"Inserting end node\n";
                    return;
                }
                
                int nextData = temp->next->data;
                
                if (newData == temp->data) {
                    return;
                }
                if (newData < temp->data) {
                    newNode->next = temp->next;
                    temp->next = newNode;
                    return;
                }
                if (newData > temp->data && newData < nextData) {
                    newNode->next = temp->next;
                    temp->next = newNode;
                    cout<<"Inserting new node\n";
                    return;
                }               
                
                temp = temp->next;
            }
        }
        
        void print() {
            Node * temp = this->root;
            cout<<"Printing"<<endl; 
            while (temp) {
                cout<<temp->data<<", ";
                temp = temp->next;
            }
            cout<<endl;
        }
};

int main()
{
    SortedLinkedList l;
    l.insert(8);
    l.insert(2);
    l.insert(5);
    l.insert(9);

    l.print();

    //should print out 2,5,8,9
    return 0;
}

//2,5,4,7,1 -> 1,2,4,5,7