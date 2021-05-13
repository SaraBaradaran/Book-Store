#include "stack.h"

Stack::Stack():top(0),size(0)
{
}

void Stack::Push(Book *newbook)
{
    Book* result = Search(newbook);
    if(!result)
    {
        Book *temp = new Book(*newbook);
        temp->number = "1";
        temp->next_book = top;
        top = temp;
        size++;
        qDebug()<< temp->name;
    }
    else
    {
        result->IncreaseNumber();
    }
}

void Stack::Pop()
{
    Book *temp;
    temp = top;
    top = top->next_book;
    delete(temp);
    size--;
}

Book *Stack::Top()
{
    return top;
}

bool Stack::IsEmpty()
{
    if(size)
        return 0;
    return 1;
}

void Stack::Print(QListWidget *list)
{
    list->clear();
    Book *temp = top;

    for(int i = 0 ;i < size; i++)
    {

        QListWidgetItem* bookitem = new QListWidgetItem(temp->name + "   ( " + temp->year + " )" +"   number = "+temp->number);
        list->addItem(bookitem);

        if(i%2)
            bookitem->setBackgroundColor(QColor::fromRgb(85, 0, 255));
        else
            bookitem->setBackgroundColor(QColor::fromRgb(159, 3, 255));

        bookitem->setTextColor(QColor::fromRgb(255, 255, 255));
        bookitem->setSizeHint(QSize(0,50));

        temp = temp->next_book;
    }
}

Book* Stack::Search(Book *book)
{
    Book *temp = top;

    for(int i=0; i<size; i++)
    {
        if(temp->name == book->name && temp->year == book->year)
            return temp;
        temp = temp->next_book;
    }
    return 0;
}
