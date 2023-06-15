#include "manager1.h"
#include "user1.h"
#include <QtWidgets/QApplication>
#include <iostream>
int main(int argc, char *argv[]){

    QApplication a(argc, argv);
    manager1 ma;
    user1 u;
    u.show();
    qDebug() << "show";
    QObject::connect(&u, SIGNAL(usertom()), &ma, SLOT(m_receiveuser()));
    return a.exec();
}

