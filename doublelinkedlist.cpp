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