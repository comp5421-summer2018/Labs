#ifndef LIST_H
#define LIST_H


class List
{
public:
    List();
    void AddNode(int addData);
    void DeleteNode(int delData);
    void PrintList();


private:

    struct node{
        node* next;
        int data;
    };

    typedef struct node* nodePtr;

    nodePtr head;
    nodePtr current;
    nodePtr temp;
};

#endif // LIST_H
