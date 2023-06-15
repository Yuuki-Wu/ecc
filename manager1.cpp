#include "manager1.h"
#include "./ui_manager1.h"
#include "QtWidgets/QMessageBox"
#include "isPrime.h"
#include "Algorithm_getPoint.h"
#include "DeCode.h"
#include "user1.h"
#include "EnCode.h"
#include "Algorithm_getKey.h"
manager1::manager1(QWidget* parent) :
	QWidget(parent),
	ui(new Ui::manager1)
{
	ui->setupUi(this);

}

manager1::~manager1()
{
	delete ui;
}
void manager1::isuseful()
{
	if (ui->ciphertext->toPlainText() == "" || ui->private_key->text() == "")
	{

	}
	else
	{
		int p = 503;
		int a = 4;
		int b = 1;
		int Gx = 283;
		int Gy = 315;
		DeCode dc;
		EnCode ec;
		user1 u;
		Algorithm_getKey agk;
		QString str = ui->ciphertext->toPlainText();
		QString ra = ui->private_key->text();
		if (ra.toInt() < 10)
		{
			vector<string> hexm = dc.format(str.toStdString());
			vector<int> decm = dc.HexStrToDecStr(hexm);
			vector<int> kG;
			vector<int> encoded_message;
			kG = agk.algorithm_getKey(p, a, Gx, Gy, Gx, Gy, u.k);
			int pt = 0;
			vector<int> PmkPa;
			vector<string> message;
			for (int i = 0; i < decm.size(); i += 2)
			{
				PmkPa.push_back(decm[i]);
				PmkPa.push_back(decm[i + 1]);
			}
			qDebug() << PmkPa[0];
			message = dc.decode(p, a, kG, PmkPa, ra.toInt());
			string mes;
			for (auto m : message)
			{
				mes += m;
			}
			ui->message->setPlainText(QString::fromStdString(mes));
		}
		else
		{
			QMessageBox::StandardButton result = QMessageBox::critical(this, "error", "您输入的密钥过大，精度无法控制，请输入-10e10~10范围内的整数");
		}
	}
}
void manager1::m_receiveuser()
{

	this->show();
}

void manager1::onclicked()
{
	this->hide();
	emit showuser1();
}

void manager1::m_receiveform()
{

	this->show();
}





