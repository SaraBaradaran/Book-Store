#ifndef GETFACTOR_H
#define GETFACTOR_H

#include <QGraphicsScene>
#include <QLabel>
#include <QPushButton>
#include <QTextEdit>

class LibrarySystem;

class GetFactor: public QObject
{
    Q_OBJECT

    QGraphicsScene *getfactor_scene;
    LibrarySystem *libsystem;
    QTextEdit *factor_txt;
    QPushButton *back_btn, *Calculate_btn;
    bool ManTurn;

public:
    GetFactor(LibrarySystem*);
    void GoBack();
    void CalculateNextFactor();


    friend class LibrarySystem;
};

#endif // GETFACTOR_H
