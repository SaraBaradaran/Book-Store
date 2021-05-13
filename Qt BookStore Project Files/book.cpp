#include "book.h"

Book::Book(QString name, QString author, QString year, QString price, QString number)
{
    this->name = name;
    this->author = author;
    this->year = year;
    this->price = price;
    this->number = number;

}

Book::Book(Book &book)
{
    this->name = book.name;
    this->author = book.author;
    this->year = book.year;
    this->price = book.price;
}

void Book::ReduceNumber()
{
    int i = number.toInt() - 1;
    number = QString::number(i);
}

void Book::IncreaseNumber()
{
    int i = number.toInt() + 1;
    number = QString::number(i);
}


