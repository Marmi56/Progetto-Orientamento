#include "csvviewwindow.h"
#include "ui_csvviewwindow.h"

#include <QCloseEvent>




CsvViewWindow::CsvViewWindow(QWidget *parent) : QWidget(parent), ui(new Ui::CsvViewWindow) {
    ui->setupUi(this);
    setWindowFlag(Qt::WindowCloseButtonHint, false);

}

CsvViewWindow::~CsvViewWindow() {
    delete ui;
}

void CsvViewWindow::loadData(const vector<CourseStudent> &data) {
    QStringList headers = {
        "Course Code", "Course Description", "Subject Code",
        "Subject Description", "Student ID", "Last Name", "First Name"
    };

    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(headers.size());
    ui->tableWidget->setHorizontalHeaderLabels(headers);
    ui->tableWidget->setRowCount(static_cast<int>(data.size()));

    for (int r = 0; r < data.size(); ++r) {
        const auto &cs = data[r];
        ui->tableWidget->setItem(r, 0, new QTableWidgetItem(QString::fromStdString(cs.courseCode)));
        ui->tableWidget->setItem(r, 1, new QTableWidgetItem(QString::fromStdString(cs.courseDescription)));
        ui->tableWidget->setItem(r, 2, new QTableWidgetItem(QString::fromStdString(cs.subjectCode)));
        ui->tableWidget->setItem(r, 3, new QTableWidgetItem(QString::fromStdString(cs.subjectDescription)));
        ui->tableWidget->setItem(r, 4, new QTableWidgetItem(QString::number(cs.studentId)));
        ui->tableWidget->setItem(r, 5, new QTableWidgetItem(QString::fromStdString(cs.studentLastName)));
        ui->tableWidget->setItem(r, 6, new QTableWidgetItem(QString::fromStdString(cs.studentFirstName)));
    }

    ui->tableWidget->resizeColumnsToContents();
}
