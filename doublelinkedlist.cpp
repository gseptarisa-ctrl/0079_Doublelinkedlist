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

    void deletenode()
    {
        if (START == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        int rollno;
        cout << "Enter the roll number of the student whose record is to be deleted: ";
        cin >> rollno;

        Node *current = START;

        while (current != NULL && current->no != rollno)
            current = current->next;

        if (current == NULL)
        {
            cout << "Record not found" << endl;
            return;
        }

        if (current == START)
        {
            START = current->next;
            if (START != NULL)
                START->prev = NULL;
        }
        else
        {
            if (current->next != NULL)
                current->next->prev = current->prev;

            if (current->prev != NULL)
                current->prev->next = current->next;
        }

        delete current;
        cout << "Record with roll number " << rollno << " deleted" << endl;
    }

    void traverse()
    {
        if (START == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node *currentnode = START;
        cout << "Records in ascending order of roll number are:\n";
        while (currentnode != NULL)
        {
            cout << currentnode->no << " ";
            currentnode = currentnode->next;
        }
    }

    void revtraverse()
    {
        if (START == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node *currentnode = START;
        while (currentnode->next != NULL)
            currentnode = currentnode->next;

        cout << "Records in descending order of roll number are:\n";
        while (currentnode != NULL)
        {
            cout << currentnode->no << " ";
            currentnode = currentnode->prev;
        }
    }

    void searchData()
    {
        if (START == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        int rollno;
        cout << "Enter the roll number to be searched: ";
        cin >> rollno;

        Node *current = START;
        while (current != NULL && current->no != rollno)
            current = current->next;

        if (current == NULL)
            cout << "Record not found" << endl;
        else
            cout << "Record found" << endl;
    }
};

int main()
{
    DoublyLinkedList list;
    char choice;

    do
    {
        cout << "\n1: Add Record\n";
        cout << "2: Delete Record\n";
        cout << "3: Traverse (Ascending)\n";
        cout << "4: Traverse (Descending)\n";
        cout << "5: Search Record\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case '1':
            list.addnode();
            break;
        case '2':
            list.deletenode();
            break;
        case '3':
            list.traverse();
            break;
        case '4':
            list.revtraverse();
            break;
        case '5':
            list.search();
            break;
        default:
            cout << "Invalid option" << endl;
        }