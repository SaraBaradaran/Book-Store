#ifndef STACK_H
#define STACK_H

#include <QListWidgetItem>
#include <QListWidget>
#include <qdebug.h>
#include "book.h"

class Stack
{
    Book* top;
    int size;

public:
    Stack();
    void Push(Book*);
    void Pop();
    Book* Top();
    bool IsEmpty();
    void Print(QListWidget*);
    Book* Search(Book*);

};

#endif // STACK_H
