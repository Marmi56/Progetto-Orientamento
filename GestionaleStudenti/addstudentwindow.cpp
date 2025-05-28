#include "addstudentwindow.h"
#include "ui_addstudentwindow.h"

AddStudentWindow::AddStudentWindow(QWidget *parent) : QWidget(parent), ui(new Ui::AddStudentWindow) {
    ui->setupUi(this);
}

AddStudentWindow::~AddStudentWindow() {
    delete ui;
}

void AddStudentWindow::on_addStudentFinalButton_clicked() {
    int id = ui->lineEdit_id->text().toInt();
    QString firstName = ui->lineEdit_firstName->text();
    QString lastName = ui->lineEdit_lastName->text();
    QString subjectCode = ui->lineEdit_subjectCode->text();
    QString courseCode = ui->lineEdit_courseCode->text();

    emit studentDataReady(id, firstName, lastName, subjectCode, courseCode);
    close();
}
