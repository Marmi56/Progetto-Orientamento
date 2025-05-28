#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "addstudentwindow.h"



#include <QMainWindow>
#include <vector>
#include <QStringList>
#include <functional>
#include <QTableWidgetItem>

using namespace std;
class CsvViewWindow; // dichiarazione anticipata


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

struct CourseStudent {
    string courseCode;
    string courseDescription;
    string subjectCode;
    string subjectDescription;
    int studentId;
    string studentLastName;
    string studentFirstName;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_loadCSVButton_clicked();


    void on_clearButton_clicked();

    void on_searchSurnameButton_clicked();

    void on_searchIdButton_clicked();

    void on_courseCodeButton_clicked();

    void on_courseSearchButton_clicked();

    void on_studentPerCourseButton_clicked();

    void on_subjectPerCourseButton_clicked();

    void on_subjectSearchButton_clicked();

    void on_saveButton_clicked();

    void on_addStudentButton_clicked();

    void onStudentDataReceived(int id, QString firstName, QString lastName, QString subjectCode, QString courseCode);

    void closeEvent(QCloseEvent *event);


private:
    Ui::MainWindow *ui;
    AddStudentWindow *addStudentWindow;
    CsvViewWindow *csvViewWindow = nullptr;

    vector<CourseStudent> m_data;

    //funzioni per csvviwewindow.cpp, preparazione tabella
    bool loadCSV(const QString &filePath, vector<CourseStudent> &out);

    void prepareTable(const vector<CourseStudent> &data,
                      const QStringList &headers,
                      function<QList<QTableWidgetItem*>(const CourseStudent&)> rowBuilder);

    //output
    void printStudent(CourseStudent student);
    void printStudents(vector<CourseStudent> students);
    void printStudentInfo(CourseStudent student);
    void printStudentsInfo(vector<CourseStudent> students);

    //PUNTO 6
    void studentPerCourse(vector<CourseStudent> data);

    //PUNTO 7
    void subjectPerCourse(vector<CourseStudent> data);

    //PUNTO 8
    void searchSubjectByString(vector<CourseStudent> data, string keyword);

    //PUNTO 9
    bool addNewStudent(vector<CourseStudent>& data, int id, string firstName, string lastName, string subjectCodeInput, string courseCodeInput);

    QList<QTableWidgetItem*> buildFullRow(const CourseStudent &cs);
    QList<QTableWidgetItem*> buildNameSurnameIdRow(const CourseStudent &cs);
};




//PROTOTIPI

//gestione file
bool loadCSV(string filePath, vector<CourseStudent>& load);                                                                                  //PUNTO 2
bool uploadCSV(string filePath, vector<CourseStudent> upload);                                                                              //PUNTO 10

//funzionalita'
string trim(string s);
string toLower(string s);
string toUpper(string s);
vector<CourseStudent> deleteMultipleId(vector<CourseStudent> data);


//ricerca
vector<int> searchByStudentId(vector<CourseStudent> data, int id);                                                                          //PUNTO 3.1
vector<int> searchByLastName(vector<CourseStudent> data, string lastName);                                                                  //PUNTO 3.2
vector<CourseStudent> getStudentsByCourseCode(vector<CourseStudent> data, string courseCode);                                               //PUNTO 4
vector<CourseStudent> searchByCourseCode(vector<CourseStudent> data, string courseCodeInput);                                               //PUNTO 5




#endif // MAINWINDOW_H



