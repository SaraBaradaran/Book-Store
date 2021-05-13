#ifndef ADDCUSTOMER_H
#define ADDCUSTOMER_H
#include <QLineEdit>
#include <QGraphicsScene>
#include <QPushButton>
#include <QLabel>
#include <QObject>
#include <QRadioButton>
#include <QGroupBox>
#include <QComboBox>


class LibrarySystem;

class AddCustomer: public QObject
{
    Q_OBJECT


    QGraphicsScene *addcustomer_scene;
    QLineEdit *name_led;
    QComboBox* gender_btn;
    QLabel *no_lbl;
    QPushButton *back_btn,*add_btn;
    LibrarySystem *libsystem;

public:

    AddCustomer(LibrarySystem*);
    void GoBack();
    void AddNewCustomerToQueue();

    friend class LibrarySystem;
};

#endif // ADDCUSTOMER_H
