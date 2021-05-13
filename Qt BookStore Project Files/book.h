#ifndef BOOK_H
#define BOOK_H
#include <QString>

class Book
{

public:
    Book(QString name, QString author, QString publish_year, QString price, QString number = "1");
    Book(Book&);
    QString name;
    QString author;
    QString year;
    QString price;
    QString number;
    Book* next_book;

    void ReduceNumber();
    void IncreaseNumber();

};

#endif // BOOK_H
