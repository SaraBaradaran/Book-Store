#ifndef SHOWBOOK_H
#define SHOWBOOK_H
#include <QListWidget>
#include <QListWidgetItem>
#include <QPushButton>
#include <QGraphicsScene>
#include <QFile>
#include <QTextStream>
#include <qdebug.h>
#include <QLabel>
#include <QLineEdit>
#include <QWidget>
#include <QGridLayout>
#include <QMessageBox>
#include "customer.h"

class LibrarySystem;


class ShowBook: public QObject
{
    Q_OBJECT

    QGraphicsScene *ShowBookScene;
    QListWidget *BookList,*ShoppingBagList;
    QListWidgetItem *item;
    QPushButton *back_btn,*add_btn;
    QFile *BookFile;
    QLabel *MoreInfo_lbl,*Typs_lbl,*Nums_lbl;
    QLineEdit *CustomerName_led;
    QWidget *window;
    QGridLayout *Layout;
    QLabel *CustomerName_lbl,*ErrorName_lbl;
    QPushButton *Login_btn,*GetTurn_btn;
    LibrarySystem *LibSystem;
    Book *CurrentBook;
    Customer* CurrentCustomer;


public :
    ShowBook(LibrarySystem*);
    ~ShowBook();
    void ReadBooksFromFile();
    void SetType_NumbersLabel(int,int);
    void AddBookToShophingBag();
    void LoginToSelectBook();
    void GetTurn();
    void GoBack();

public slots:
    void ShowMoreInformation(QListWidgetItem*);


    friend class LibrarySystem;


};

#endif // SHOWBOOK_H
