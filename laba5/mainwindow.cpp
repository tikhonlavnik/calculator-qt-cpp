#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  //digits
  connect(ui->pushButton_0,SIGNAL(clicked()),this,SLOT(handleClick()));
  connect(ui->pushButton_1,SIGNAL(clicked()),this,SLOT(handleClick()));
  connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(handleClick()));
  connect(ui->pushButton_3,SIGNAL(clicked()),this,SLOT(handleClick()));
  connect(ui->pushButton_4,SIGNAL(clicked()),this,SLOT(handleClick()));
  connect(ui->pushButton_5,SIGNAL(clicked()),this,SLOT(handleClick()));
  connect(ui->pushButton_6,SIGNAL(clicked()),this,SLOT(handleClick()));
  connect(ui->pushButton_7,SIGNAL(clicked()),this,SLOT(handleClick()));
  connect(ui->pushButton_8,SIGNAL(clicked()),this,SLOT(handleClick()));
  connect(ui->pushButton_9,SIGNAL(clicked()),this,SLOT(handleClick()));
}

MainWindow::~MainWindow()
{
  delete ui;
}

bool checked = false;
bool checked_dot = false;
bool checked_oper = false;
double a,b;
QString oper;

void MainWindow::handleClick()
{
  if (!checked) {
      QPushButton *button = (QPushButton *)sender();
      double digit = (ui->res_label->text() + button->text()).toDouble();
      QString str_digit = QString::number(digit, 'g', 10);
      ui->res_label->setText(str_digit);
      a = digit;
  } else {
      QPushButton *button2 = (QPushButton *)sender();
      double digit2 = (ui->res_label->text() + button2->text()).toDouble();
      QString str_digit2 = QString::number(digit2, 'g', 10);
      ui->res_label->setText(str_digit2);
      b = digit2;
  }
}



void MainWindow::on_dot_clicked()
{
  if(!checked_dot) {
      ui->res_label->setText(ui->res_label->text() + '.');
  }
  checked_dot = true;
}


void MainWindow::on_changeSign_clicked()
{
  if (!checked) {
      a = a*(-1);
      QString a_str = QString::number(a, 'g', 10);
      ui->res_label->setText(a_str);
  } else {
      b = b*(-1);
      QString b_str = QString::number(b, 'g', 10);
      ui->res_label->setText(b_str);
  }
}


void MainWindow::on_ac_clicked()
{
    a = 0;
    b = 0;
    checked = false;
    checked_dot = false;
    checked_oper = false;
    ui->res_label->setText("");
}

void MainWindow::ResetCheks() {
    ui->res_label->setText("");
    checked = true;
    checked_dot = false;
    checked_oper = true;
}

void MainWindow::ResetResCheks(){
    checked = false;
    checked_dot = false;
    checked_oper = false;
    oper = "";
}

void MainWindow::on_inc_clicked()
{
    if(!checked_oper)
    {
        ResetCheks();
        oper = "+";
        ui->inc->setStyleSheet("QPushButton { background-color: rgb(205, 133, 0);border: 1px solid black }\n");
    }
}
void MainWindow::on_dec_clicked()
{
    if(!checked_oper)
    {
        ResetCheks();
        oper = "-";
        ui->dec->setStyleSheet("QPushButton { background-color: rgb(205, 133, 0);border: 1px solid black }\n");
    }
}

void MainWindow::on_multipl_clicked()
{
    if(!checked_oper)
    {
        ResetCheks();
        oper = "*";
        ui->multipl->setStyleSheet("QPushButton { background-color: rgb(205, 133, 0);border: 1px solid black }\n");
    }
}

void MainWindow::on_division_clicked()
{
    if(!checked_oper)
    {
        ResetCheks();
        oper = "/";
        ui->division->setStyleSheet("QPushButton { background-color: rgb(205, 133, 0);border: 1px solid black }\n");
    }
}

void MainWindow::on_sqrt_2_clicked()
{
    if(!checked_oper)
    {
        ResetCheks();
        oper = "sqrt";
        double z = sqrt(a);
        QString z_str = QString::number(z, 'g', 10);
        ui->res_label->setText(z_str);
        a = z;
        b = 0;
        ResetResCheks();
    }
}

void MainWindow::on_degree_clicked()
{
    if(!checked_oper)
    {
        ResetCheks();
        oper = "**";
        ui->degree->setStyleSheet("QPushButton { background-color: rgb(205, 133, 0);border: 1px solid black }\n");
    }
}

void MainWindow::on_result_clicked()
{
  ui->inc->setStyleSheet("QPushButton {background-color: rgb(255, 165, 0);border: 1px solid black; }\n");
  ui->dec->setStyleSheet("QPushButton {background-color: rgb(255, 165, 0);border: 1px solid black; }\n");
  ui->multipl->setStyleSheet("QPushButton {background-color: rgb(255, 165, 0);border: 1px solid black;}\n");
  ui->division->setStyleSheet("QPushButton {background-color: rgb(255, 165, 0);border: 1px solid black;}\n");
  ui->degree->setStyleSheet("QPushButton {background-color: rgb(255, 165, 0);border: 1px solid black; }\n");
  if(oper == "+") {
      double z = a+b;
      QString z_str = QString::number(z, 'g', 10);
      ui->res_label->setText(z_str);
      a = z;
      b = 0;
      ResetResCheks();
   }
  if(oper == "-") {
      double z = a-b;
      QString z_str = QString::number(z, 'g', 10);
      ui->res_label->setText(z_str);
      a = z;
      b = 0;
      ResetResCheks();
   }
   if(oper == "*") {
      double z = a*b;
      QString z_str = QString::number(z, 'g', 10);
      ui->res_label->setText(z_str);
      a = z;
      b = 0;
      ResetResCheks();
   }
   if(oper == "/") {
      double z = a/b;
      QString z_str = QString::number(z, 'g', 10);
      ui->res_label->setText(z_str);
      a = z;
      b = 0;
      ResetResCheks();
   }
   if(oper == "**") {
      double z = a;
      for (int i = 0; i < b-1; i++) {
          a *= z;
      }
      QString z_str = QString::number(a, 'g', 10);
      ui->res_label->setText(z_str);
      b = 0;
      ResetResCheks();
   }
}










