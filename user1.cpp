#include "user1.h"
#include "./ui_user1.h"
#include <QMessageBox>
#include "manager1.h"
#include "Algorithm_getKey.h"
#include "Algorithm_getPoint.h"
#include "isPrime.h"
#include "EnCode.h"
#include "DeCode.h"
int user1::k;
user1::user1(QWidget* parent) :
	QWidget(parent),
	ui(new Ui::user1)
{
	ui->setupUi(this);
}

user1::~user1()
{
	delete ui;
}
void user1::u_receiveform()
{
	
	this->show();
}

void user1::buttonclicked()
{
	this->hide();
	emit usertof();
}

void user1::getpublickey()
{
	
	QString pri_key = ui->private_key->text();
	if (pri_key == "")
	{
		QMessageBox::StandardButton result = QMessageBox::critical(this, "error", "请输入私钥");
	}
	else
	{
		int px = 283;
		int py = 315;
		int ra = pri_key.toInt();//私钥
		int p = 503;
		int a = 4;
		int b = 1;
		EnCode ec;
		k = 123;
		string message = ui->plaintext->toPlainText().toStdString();
		vector<int> encoded_message;
		vector<string> output_message;
		encoded_message = ec.encode(message, p, a, b, px, py, k, ra);
		string x, y;
		output_message.push_back("0");
		output_message.push_back("x");
		for (int i = 2; i < encoded_message.size(); i += 4)
		{
			x = ec.DecStrToHexStr(to_string(encoded_message[i]));
			output_message.push_back(x);
			output_message.push_back("G");
			y = ec.DecStrToHexStr(to_string(encoded_message[i + 1]));
			output_message.push_back(y);
			output_message.push_back("G");
		}
		string o_m;
		for (auto str : output_message)
		{
			o_m += str;
		}

		ui->ciphertext->setPlainText("");
		if (1)
		{
			ui->ciphertext->setPlainText(QString::fromStdString(o_m));
		}
		else
		{
			QMessageBox::StandardButton result = QMessageBox::critical(this, "error", "G的阶不是素数，请选择其他的点 ");
		}
	}
}

void user1::on_pushButton_3_clicked()
{
	this->hide();
	emit usertom();
}


