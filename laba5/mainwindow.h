#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

private slots:
  void handleClick();

  void ResetCheks();

  void ResetResCheks();

  void on_dot_clicked();

  void on_changeSign_clicked();

  void on_ac_clicked();

  void on_inc_clicked();

  void on_result_clicked();

  void on_dec_clicked();

  void on_multipl_clicked();

  void on_division_clicked();

  void on_degree_clicked();

  void on_sqrt_2_clicked();

private:
  Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
