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

    QListWidgetItem* bookitem;

public:
    Stack();
    void Push(Book*);
    void Pop();
    Book* Top();
    bool IsEmpty();
    void Print(QListWidget*);

};

#endif // STACK_H
