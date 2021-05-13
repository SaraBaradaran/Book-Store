#include "showbook.h"
#include "librarysystem.h"

ShowBook::ShowBook(LibrarySystem *LibSystem):LibSystem(LibSystem),CurrentCustomer(0)
{

    ShowBookScene = new QGraphicsScene(0,0,800,500);
    back_btn = new QPushButton;
    add_btn = new QPushButton("Add to ShoppingBag");

    MoreInfo_lbl = new QLabel;
    Typs_lbl = new QLabel;
    Nums_lbl = new QLabel;

    BookList = new QListWidget;
    ShoppingBagList = new QListWidget;

    BookFile = new QFile("BookFile.txt");

    QPixmap pix1(":/background/bg6.jpg");
    ShowBookScene->addPixmap(pix1.scaled (800,500,Qt::KeepAspectRatio));


    MoreInfo_lbl->setHidden(1);
    add_btn->setHidden(1);
    ShoppingBagList->setHidden(1);

    Typs_lbl->setAlignment(Qt::AlignCenter);
    Nums_lbl->setAlignment(Qt::AlignCenter);

    back_btn->setStyleSheet("background-color: white");
    add_btn->setStyleSheet("background-color: rgb(85, 0, 255);color: white;font: 10pt Gorgia");
    Typs_lbl->setStyleSheet("background-color: rgb(0, 229, 229);color: black;font: 10pt Gorgia");
    Nums_lbl->setStyleSheet("background-color: rgb(0, 229, 229);color: black;font: 10pt Gorgia");
    MoreInfo_lbl->setStyleSheet("background-color: rgb(224, 193, 255);color: black;font: 10pt Gorgia");

    back_btn->setGeometry(20,15,75,50);
    add_btn->setGeometry(470,320,150,50);
    BookList->setGeometry(100,50,300,205);
    ShoppingBagList->setGeometry(100,270,300,155);
    MoreInfo_lbl->setGeometry(420,150,250,150);
    Typs_lbl->setGeometry(680,15,100,50);
    Nums_lbl->setGeometry(680,85,100,50);

    ShowBookScene->addWidget(add_btn);
    ShowBookScene->addWidget(back_btn);
    ShowBookScene->addWidget(BookList);
    ShowBookScene->addWidget(Typs_lbl);
    ShowBookScene->addWidget(Nums_lbl);
    ShowBookScene->addWidget(MoreInfo_lbl);
    ShowBookScene->addWidget(ShoppingBagList);

    QPixmap pixmap(":/back/back1");
    QIcon ButtonIcon(pixmap);
    back_btn->setIcon(ButtonIcon);
    back_btn->setIconSize(QSize(60,38));

    window = new QWidget;
    window->setWindowTitle("Customer's Name");
    Layout = new QGridLayout;
    CustomerName_lbl = new QLabel("Customer's Name:");
    ErrorName_lbl = new QLabel;
    CustomerName_led = new QLineEdit;
    Login_btn = new QPushButton("Login");
    GetTurn_btn = new QPushButton("Signup");
    Layout->addWidget(CustomerName_lbl,0,0);
    Layout->addWidget(CustomerName_led,0,1);
    Layout->addWidget(ErrorName_lbl,1,0,2,2);
    Layout->addWidget(GetTurn_btn,4,0,1,2);
    Layout->addWidget(Login_btn,3,0,1,2);
    window->setLayout(Layout);
    window->setFixedSize(320,200);

    window->setStyleSheet("background-color: rgb(224, 193, 255);color: black;font: 10pt Gorgia");
    Login_btn->setStyleSheet("background-color: rgb(0, 229, 229);color: black;font: 10pt Gorgia");
    GetTurn_btn->setStyleSheet("background-color: rgb(0, 229, 229);color: black;font: 10pt Gorgia");

    connect(back_btn,&QPushButton::clicked,this,&ShowBook::GoBack);
    connect(BookList,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(ShowMoreInformation(QListWidgetItem*)));
    connect(add_btn,&QPushButton::clicked,this,&ShowBook::AddBookToShophingBag);
    connect(Login_btn,&QPushButton::clicked,this,&ShowBook::LoginToSelectBook);
    connect(GetTurn_btn,&QPushButton::clicked,this,&ShowBook::GetTurn);

}

ShowBook::~ShowBook()
{
    window->close();
}

void ShowBook::GoBack()
{
    CurrentCustomer = 0;
    ErrorName_lbl->clear();
    CustomerName_led->clear();
    add_btn->setHidden(1);
    MoreInfo_lbl->setHidden(1);
    ShoppingBagList->setHidden(1);
    LibSystem->ChangeSceneToLibrarySystem();
}

void ShowBook::SetType_NumbersLabel(int types, int nums)
{
    Typs_lbl->setText("Types : " + QString::number(types));
    Nums_lbl->setText("Numbers : " + QString::number(nums));
}


void ShowBook::ShowMoreInformation(QListWidgetItem* item)
{

    add_btn->setHidden(0);
    MoreInfo_lbl->setHidden(0);
    QString name, year, txt=item->text();
    int f=1;
    for(int i=0;txt[i]!=')';i++)
    {
        if(txt[i] == ' ' && txt[i+1] == ' ')
            f=2;
        if(f == 1)
            name+=txt[i];
        else if(!f)
        {
            if(txt[i]>='0' && txt[i]<='9')
                year+=txt[i];
        }
        if(txt[i]=='(')
            f=0;
    }
    CurrentBook = LibSystem->SearchInLibrary(name,year);
    MoreInfo_lbl->setAlignment(Qt::AlignCenter);
    MoreInfo_lbl->setText("  name = " + name + "\n\n  author = " + CurrentBook->author + "\n\n  publish year = " + year + "\n\n  price = " + CurrentBook->price + "\n\n  available number = " + CurrentBook->number);

}

void ShowBook::AddBookToShophingBag()
{
    if(Nums_lbl->text() != "Numbers : 0")
    {
        if(CurrentCustomer == 0)
        {
            window->show();
        }
        else
        {
            CurrentCustomer->AddBookToShopphingBag(CurrentBook);
            LibSystem->DeleteBookFromLibrary(CurrentBook->name,CurrentBook->year);
            CurrentCustomer->PrintShoppingBag(ShoppingBagList);
        }
        add_btn->setHidden(1);
        MoreInfo_lbl->setHidden(1);
    }
    else
        qDebug() << "no book exist";

}

void ShowBook::LoginToSelectBook()
{
    if(CustomerName_led->text() != "" && CurrentBook!=0)
    {
        CurrentCustomer = LibSystem->SearchInQueue(CustomerName_led->text());
        if(CurrentCustomer)
        {
            ErrorName_lbl->clear();
            CurrentCustomer->AddBookToShopphingBag(CurrentBook);
            LibSystem->DeleteBookFromLibrary(CurrentBook->name,CurrentBook->year);
            CurrentCustomer->PrintShoppingBag(ShoppingBagList);
            CustomerName_led->clear();
            window->close();
            ShoppingBagList->setHidden(0);
        }
        else
        {
            ErrorName_lbl->setText("name could not be found please Enter again \nor press Signup if you have not yet register ");
        }
    }
}

void ShowBook::GetTurn()
{
    ErrorName_lbl->clear();
    CustomerName_led->clear();
    window->close();
    LibSystem->ChangeSceneToAddCustomer();
}
