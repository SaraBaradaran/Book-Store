#include "addcustomer.h"
#include "librarysystem.h"


AddCustomer::AddCustomer(LibrarySystem *libSystem):libsystem(libSystem)
{
    addcustomer_scene = new QGraphicsScene(0,0,800,500);
    back_btn = new QPushButton;
    add_btn = new QPushButton("Add Customer");
    name_led = new QLineEdit;
    no_lbl = new QLabel;
    gender_btn = new QComboBox;

    QPixmap pix1(":/background/bg2.jpg");
    addcustomer_scene->addPixmap(pix1.scaled (800,500,Qt::KeepAspectRatio));

    no_lbl->setAlignment(Qt::AlignCenter);

    name_led->setPlaceholderText("Customer's name");

    add_btn->setStyleSheet("background-color: rgb(0, 0, 255);color: white;font: 10pt Gorgia");
    gender_btn->setStyleSheet("background-color: white;font: 10pt Gorgia");
    name_led->setStyleSheet("background-color: white;font: 10pt Gorgia");
    back_btn->setStyleSheet("background-color: white; border-radius: 1px");
    no_lbl->setStyleSheet("background-color: white;color: black;font: 15pt Gorgia");

    addcustomer_scene->addWidget(back_btn);
    addcustomer_scene->addWidget(name_led);
    addcustomer_scene->addWidget(no_lbl);
    addcustomer_scene->addWidget(add_btn);
    addcustomer_scene->addWidget(gender_btn);

    back_btn->setGeometry(0,0,75,50);
    name_led->setGeometry(280,100,140,50);
    no_lbl->setGeometry(300,150,200,50);
    add_btn->setGeometry(350,200,100,50);
    gender_btn->setGeometry(450,130,100,20);

    QPixmap pixmap(":/back/back1");
    QIcon ButtonIcon(pixmap);
    back_btn->setIcon(ButtonIcon);
    back_btn->setIconSize(QSize(60,38));

    gender_btn->addItem("man");
    gender_btn->addItem("woman");

    no_lbl->setHidden(1);

    connect(back_btn,&QPushButton::clicked,this,&AddCustomer::GoBack);
    connect(add_btn,&QPushButton::clicked,this,&AddCustomer::AddNewCustomerToQueue);

}

void AddCustomer::GoBack()
{
    back_btn->setGeometry(0,0,75,50);
    name_led->setHidden(0);
    gender_btn->setHidden(0);
    add_btn->setHidden(0);
    no_lbl->setHidden(1);
    name_led->clear();
    libsystem->ChangeSceneToLibrarySystem();
}

void AddCustomer::AddNewCustomerToQueue()
{
    int no;

    if(name_led->text()!="")
    {
        back_btn->setGeometry(350,250,100,50);

        if(gender_btn->currentText() == "man")
            no = libsystem->AddCustomerToQueue(name_led->text(),"man");
        else
            no = libsystem->AddCustomerToQueue(name_led->text(),"woman");

        no_lbl->setText("Your turn is : " +QString::number(no));

        name_led->clear();
        no_lbl->setHidden(0);
        add_btn->setHidden(1);
        name_led->setHidden(1);
        gender_btn->setHidden(1);

    }
}

