#pragma once
#ifndef MANAGER1_H
#define MANAGER1_H
#include <QtWidgets/QWidget>

namespace Ui {
    class manager1;
}

class manager1 : public QWidget
{
    Q_OBJECT

public:
    explicit manager1(QWidget* parent = nullptr);
    ~manager1();
public:
private slots:
    void onclicked();
    void isuseful();
    void m_receiveuser();
    void m_receiveform();
signals:
    void showuser1();
    void managertof();
private:
    Ui::manager1* ui;
};

#endif // MANAGER1_H
