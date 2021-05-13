#include "getfactor.h"
#include "librarysystem.h"

GetFactor::GetFactor(LibrarySystem* libsystem):libsystem(libsystem),ManTurn(0)
{
    getfactor_scene = new QGraphicsScene(0,0,800,500);

    factor_txt = new QTextEdit;
    factor_txt->setReadOnly(1);

    back_btn = new QPushButton;
    Calculate_btn = new QPushButton("Calculate Next Factor");

    QPixmap pix1(":/background/bg6.jpg");
    getfactor_scene->addPixmap(pix1.scaled (800,500,Qt::KeepAspectRatio));

    factor_txt->setStyleSheet("background-color: white;font: 12pt Gorgia");
    back_btn->setStyleSheet("background-color: white");
    Calculate_btn->setStyleSheet("background-color: rgb(0, 0, 255);color: white;font: 10pt Gorgia");

    getfactor_scene->addWidget(factor_txt);
    getfactor_scene->addWidget(back_btn);
    getfactor_scene->addWidget(Calculate_btn);

    Calculate_btn->setGeometry(325,420,150,50);
    factor_txt->setGeometry(200,100,400,300);
    back_btn->setGeometry(20,15,75,50);

    QPixmap pixmap(":/back/back1");
    QIcon ButtonIcon(pixmap);
    back_btn->setIcon(ButtonIcon);
    back_btn->setIconSize(QSize(60,38));

    connect(back_btn,&QPushButton::clicked,this,&GetFactor::GoBack);
    connect(Calculate_btn,&QPushButton::clicked,this,&GetFactor::CalculateNextFactor);
}

void GetFactor::GoBack()
{
    factor_txt->clear();
    libsystem->ChangeSceneToLibrarySystem();
}

void GetFactor::CalculateNextFactor()
{
    Customer *current;
    factor_txt->clear();

    if(ManTurn)
    {
        current = libsystem->GetFirstCustomerInfo("man");
        if(current == 0)
        {
            qDebug() << "menQueue is finished";
            current = libsystem->GetFirstCustomerInfo("woman");
        }
        if(current == 0)
        {
            qDebug() << "womenQueue is finished";
            factor_txt->setText("<b>There is not any Customers<b>");
        }
        else
        {
            long int sum = 0;
            Book* temp = current->shoppingbag->Top();
            factor_txt->setText("Customer's Name : " + current->name);
            factor_txt->append(+"\nbook\t\tprice\t\tnumbers\n" );
            factor_txt->append("--------------------------------------------------\n");
            for(; temp; temp = temp->next_book)
            {
                sum += (temp->price.toLong() * temp->number.toInt());
                factor_txt->append(temp->name + "\t\t"+ temp->price + "\t\t"+ temp->number +"\n" );
            }

            factor_txt->append("--------------------------------------------------\n");
            factor_txt->append(" SUM = " + QString::number(sum));
        }

    }
    else
    {
       current = libsystem->GetFirstCustomerInfo("woman");
       if(current == 0)
       {
           qDebug() << "womenQueue is finished";
           current = libsystem->GetFirstCustomerInfo("man");
       }
       if(current == 0)
       {
           qDebug() << "menQueue is finished";
           factor_txt->setText("<b>There is not any Customers<b>");
       }
       else
       {
           long int sum = 0;
           Book* temp = current->shoppingbag->Top();
           factor_txt->setText("Customer's Name : " + current->name);
           factor_txt->append(+"\nbook\t\tprice\t\tnumbers\n" );
           factor_txt->append("--------------------------------------------------\n");
           for(; temp; temp = temp->next_book)
           {
               sum += (temp->price.toLong() * temp->number.toInt());
               factor_txt->append(temp->name + "\t\t"+ temp->price + "\t\t"+ temp->number +"\n" );
           }

           factor_txt->append("--------------------------------------------------\n");
           factor_txt->append(" SUM = " + QString::number(sum));
       }

    }

    ManTurn = !ManTurn;
}
