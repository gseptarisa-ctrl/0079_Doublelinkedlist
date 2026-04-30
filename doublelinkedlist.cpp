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
