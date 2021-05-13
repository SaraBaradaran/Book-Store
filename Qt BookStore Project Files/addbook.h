#ifndef ADDBOOK_H
#define ADDBOOK_H
#include <QLineEdit>
#include <QGraphicsScene>
#include <QPushButton>
#include <QLabel>

class LibrarySystem;

class AddBook: public QObject
{
    Q_OBJECT

    QGraphicsScene *addbook_scene;
    QLineEdit *name_led,*author_led,*year_led,*price_led,*number_led;
    QLabel *name_lbl,*author_lbl,*year_lbl,*price_lbl,*result_lbl;
    QPushButton *back_btn,*add_btn;
    LibrarySystem *libsystem;

public:
    AddBook(LibrarySystem*);
    void GoBack();
    void AddNewBookToLibrary();

    friend class LibrarySystem;
};

#endif // ADDBOOK_H
