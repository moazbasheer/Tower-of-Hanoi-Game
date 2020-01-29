#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<vector>
#include<QLabel>
using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    int first=-1;
    int second=-1;
    int Difficulty;
    string RemovedElement;
    vector<string> A;
    vector<string> B;
    vector<string> C;
    vector<string> OrderedData;
    string firstString;
    string secondString;

    QPixmap pic;
    QPixmap pic1;
    QPixmap pic2;
    QPixmap pic3;
    bool IsSmaller(string s1,string s2);
    bool isWon();
    bool isValid();
    void CheckChanges();
    void UpdateGUI();

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_action3_triggered();

    void on_action4_triggered();

    void on_action2_triggered();

    void on_action1_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
