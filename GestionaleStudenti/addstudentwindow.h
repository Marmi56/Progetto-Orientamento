#ifndef ADDSTUDENTWINDOW_H
#define ADDSTUDENTWINDOW_H

#include <QWidget>

namespace Ui {
class AddStudentWindow;
}

class AddStudentWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AddStudentWindow(QWidget *parent = nullptr);
    ~AddStudentWindow();

signals:
    void studentDataReady(int id, QString firstName, QString lastName, QString subjectCode, QString courseCode);

private slots:
    void on_addStudentFinalButton_clicked();

private:
    Ui::AddStudentWindow *ui;
};

#endif // ADDSTUDENTWINDOW_H
