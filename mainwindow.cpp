#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<bits/stdc++.h>
#include<QPixmap>
#include<QLabel>
#include<QMessageBox>
using namespace std;
MainWindow::MainWindow(QWidget *parent) :
		QMainWindow(parent), ui(new Ui::MainWindow) {
	ui->setupUi(this);
	first = -1;
	second = -1;
	OrderedData.push_back(
			"C:/Users/pc/Documents/TowerOfHanoi/images/untitled4.png");
	OrderedData.push_back(
			"C:/Users/pc/Documents/TowerOfHanoi/images/untitled3.png");
	OrderedData.push_back(
			"C:/Users/pc/Documents/TowerOfHanoi/images/untitled2.png");
	OrderedData.push_back(
			"C:/Users/pc/Documents/TowerOfHanoi/images/untitled5.png");

}
char* StringtoChArray(string& s) {
	char* s2 = new char[s.size() + 1];
	for (int i = 0; i < (int) s.size(); i++) {
		s2[i] = s[i];
	}
	s2[s.size()] = '\0';
	return s2;
}

bool MainWindow::isWon() {
	if ((int) C.size() != Difficulty)
		return false;
	for (int i = 0; i < Difficulty; i++) {
		if (C[i] != OrderedData[i])
			return false;
	}
	return true;
}

bool MainWindow::IsSmaller(string s1, string s2) {
	int index1, index2;
	for (int i = 0; i < (int) OrderedData.size(); i++) {
		if (OrderedData[i] == s1)
			index1 = i;
	}
	for (int i = 0; i < (int) OrderedData.size(); i++) {
		if (OrderedData[i] == s2)
			index2 = i;
	}
	return index1 > index2;
}
bool MainWindow::isValid() {
	string s1, s2;
	if (first == 1)
		s1 = A.back();
	if (first == 2)
		s1 = B.back();
	if (first == 3)
		s1 = C.back();
	if (second == 1) {
		if (A.size() == 0)
			return true;
		s2 = A.back();
	}
	if (second == 2) {
		if (B.size() == 0)
			return true;
		s2 = B.back();
	}
	if (second == 3) {
		if (C.size() == 0)
			return true;
		s2 = C.back();
	}
	return IsSmaller(s1, s2);
}
void MainWindow::UpdateGUI() {
	if (A.size() >= 2)
		ui->label3->setPixmap(QPixmap(StringtoChArray(A[1])));
	else
		ui->label3->setPixmap(QPixmap(""));
	if (A.size() >= 3)
		ui->label2->setPixmap(QPixmap(StringtoChArray(A[2])));
	else
		ui->label2->setPixmap(QPixmap(""));
	if (A.size() >= 4)
		ui->label1->setPixmap(QPixmap(StringtoChArray(A[3])));
	else
		ui->label1->setPixmap(QPixmap(""));
	if (A.size() >= 1)
		ui->label4->setPixmap(QPixmap(StringtoChArray(A[0])));
	else
		ui->label4->setPixmap(QPixmap(""));
	if (B.size() >= 2)
		ui->label3_2->setPixmap(QPixmap(StringtoChArray(B[1])));
	else
		ui->label3_2->setPixmap(QPixmap(""));
	if (B.size() >= 3)
		ui->label2_2->setPixmap(QPixmap(StringtoChArray(B[2])));
	else
		ui->label2_2->setPixmap(QPixmap(""));
	if (B.size() >= 4)
		ui->label1_2->setPixmap(QPixmap(StringtoChArray(B[3])));
	else
		ui->label1_2->setPixmap(QPixmap(""));
	if (B.size() >= 1)
		ui->label4_2->setPixmap(QPixmap(StringtoChArray(B[0])));
	else
		ui->label4_2->setPixmap(QPixmap(""));
	if (C.size() >= 2)
		ui->label3_3->setPixmap(QPixmap(StringtoChArray(C[1])));
	else
		ui->label3_3->setPixmap(QPixmap(""));
	if (C.size() >= 3)
		ui->label2_3->setPixmap(QPixmap(StringtoChArray(C[2])));
	else
		ui->label2_3->setPixmap(QPixmap(""));
	if (C.size() >= 4)
		ui->label1_3->setPixmap(QPixmap(StringtoChArray(C[3])));
	else
		ui->label1_3->setPixmap(QPixmap(""));
	if (C.size() >= 1)
		ui->label4_3->setPixmap(QPixmap(StringtoChArray(C[0])));
	else
		ui->label4_3->setPixmap(QPixmap(""));
}
MainWindow::~MainWindow() {
	delete ui;
}

void MainWindow::CheckChanges() {
	if (first == second) {
		first = -1;
		second = -1;
	}
	if (first != -1 && second != -1) {

		if (first == 1) {
			if (A.size() == 0) {
				QMessageBox::information(this, "Print", "Invalid");
				first = -1;
				second = -1;
				return;
			}
			if (!isValid()) {

				QMessageBox::information(this, "Print", "Invalid");
				first = -1;
				second = -1;
				return;

			}
			RemovedElement = A.back();
			A.pop_back();
		} else if (first == 2) {
			if (B.size() == 0) {
				QMessageBox::information(this, "Print", "Invalid");
				first = -1;
				second = -1;
				return;
			}
			if (!isValid()) {

				QMessageBox::information(this, "Print", "Invalid");
				first = -1;
				second = -1;
				return;

			}
			RemovedElement = B.back();

			B.pop_back();
		} else if (first == 3) {
			if (C.size() == 0) {
				QMessageBox::information(this, "Print", "Invalid");
				first = -1;
				second = -1;
				return;
			}
			if (!isValid()) {

				QMessageBox::information(this, "Print", "Invalid");
				first = -1;
				second = -1;
				return;

			}
			RemovedElement = C.back();

			C.pop_back();
		}
		if (second == 1) {
			A.push_back(RemovedElement);
		} else if (second == 2) {
			B.push_back(RemovedElement);
		} else if (second == 3) {
			C.push_back(RemovedElement);
		}
		UpdateGUI();
		if (isWon()) {
			QMessageBox::information(this, "Print", "You Won \nCongratulation");
			first = -1;
			second = -1;
			return;
		}
		first = -1;
		second = -1;
	}
}

void MainWindow::on_pushButton_clicked() {
	if (first == -1)
		first = 1;
	else if (second == -1)
		second = 1;
	CheckChanges();
}

void MainWindow::on_pushButton_2_clicked() {
	if (first == -1)
		first = 2;
	else if (second == -1)
		second = 2;
	CheckChanges();
}

void MainWindow::on_pushButton_3_clicked() {
	if (first == -1)
		first = 3;
	else if (second == -1)
		second = 3;
	CheckChanges();
}

void MainWindow::on_pushButton_4_clicked() {
	first = -1;
	second = -1;
}

void MainWindow::on_action1_triggered() {
	A.clear();
	B.clear();
	C.clear();
	A.push_back("C:/Users/pc/Documents/TowerOfHanoi/images/untitled4.png");
	Difficulty = 1;
	UpdateGUI();
}

void MainWindow::on_action2_triggered() {
	A.clear();
	B.clear();
	C.clear();
	A.push_back("C:/Users/pc/Documents/TowerOfHanoi/images/untitled4.png");
	A.push_back("C:/Users/pc/Documents/TowerOfHanoi/images/untitled3.png");
	Difficulty = 2;
	UpdateGUI();
}

void MainWindow::on_action3_triggered() {
	A.clear();
	B.clear();
	C.clear();
	A.push_back("C:/Users/pc/Documents/TowerOfHanoi/images/untitled4.png");
	A.push_back("C:/Users/pc/Documents/TowerOfHanoi/images/untitled3.png");
	A.push_back("C:/Users/pc/Documents/TowerOfHanoi/images/untitled2.png");
	Difficulty = 3;
	UpdateGUI();
}

void MainWindow::on_action4_triggered() {
	A.clear();
	B.clear();
	C.clear();
	A.push_back("C:/Users/pc/Documents/TowerOfHanoi/images/untitled4.png");
	A.push_back("C:/Users/pc/Documents/TowerOfHanoi/images/untitled3.png");
	A.push_back("C:/Users/pc/Documents/TowerOfHanoi/images/untitled2.png");
	A.push_back("C:/Users/pc/Documents/TowerOfHanoi/images/untitled5.png");
	Difficulty = 4;
	UpdateGUI();
}
