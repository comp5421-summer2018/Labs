#include "List.h"
#include<iostream>
using namespace std;

List::List()
{
    head = nullptr;

    current = nullptr;

    temp = nullptr;
}

void List::AddNode(int addData)
{
    nodePtr n = new node;

    n->data = addData;

    n->next = nullptr;

    if (head != nullptr)
    {
        current = head;

        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = n;


    }
    else
        head = n;
}

void List::DeleteNode(int delData)
{
    nodePtr delPtr = nullptr;

    temp = head;

    current = head;

    while (current != nullptr && current->data != delData)
    {
        temp = current;
        current = current->next;
    }

    if (current == nullptr)
    {
        cout << delData << " was not in the list\n";

        delete delPtr;
    }

    else{
        delPtr = current;

        current = current->next;

        temp->next = current;

        delete delPtr;

        cout << delData << " was deleted\n";
    }



}

void List::PrintList()
{
    current = head;

    while (current != nullptr)
    {
        cout << current->data << endl;
        current = current->next;
    }
}
