#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

class Node
{
public:
    int no;
    Node *next;
    Node *prev;
};

class DoublyLinkedList
{
    Node *START;

public:
    DoublyLinkedList()
    {
        START = NULL;
    }

    void addnode()
    {
        int n;
        cout << "Enter the roll number of the student: ";
        cin >> n;

        // Step 1: Allocate memory for new node
        Node *newnode = new Node();

        // Step 2: Assign value to the data field
        newnode->no = n;

        // Step 3: Insert at beginning if list is empty or first element
        if (START == NULL || n <= START->no)
        {
            if (START != NULL && n == START->no)
            {
                cout << "Duplicate roll numbers not allowed" << endl;
                return;
                            }
            newnode->next = START;
            if (START != NULL)
                START->prev = newnode;
            newnode->prev = NULL;
            START = newnode;
            return;
        }

        // Step 4: Traverse to find position for insertion
        Node *current = START;
        while (current->next != NULL && current->next->no < n)
            current = current->next;

        if (current->next != NULL && current->next->no == n)
        {
            cout << "Duplicate roll numbers not allowed" << endl;
            return;
        }

        newnode->next = current->next;
        if (current->next != NULL)
            current->next->prev = newnode;

        newnode->prev = current;
        current->next = newnode;
    }
