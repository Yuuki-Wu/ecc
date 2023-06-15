#pragma once
#ifndef USER1_H
#define USER1_H

#include <QtWidgets/QWidget>

namespace Ui {
    class user1;
}

class user1 : public QWidget
{
    Q_OBJECT

public:
    explicit user1(QWidget* parent = nullptr);
    ~user1();
public:
    static int k;
private slots:
    void on_pushButton_3_clicked(); 
    void u_receiveform();
    void buttonclicked();
    void getpublickey();
signals:
    void usertom();
    void usertof();
private:
    Ui::user1* ui;
};

#endif // USER1_H
