#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "csvviewwindow.h"
#include "addstudentwindow.h"


#include <QCloseEvent>
#include <QFileDialog>
#include <QString>
#include <QDir>
#include <fstream>
#include <vector>
#include <iostream>
#include <cstring>
#include <unordered_set>
#include <set>
#include <map>
#include <algorithm>
#include <QMainWindow>
#include <QTableWidgetItem>
#include <functional>
#include <QDebug>
#include <QFileDialog>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

//FUNZIONI
bool loadCSV(string filePath, vector<CourseStudent>& load) {
    //intestazione
    vector<string> HEAD = {
        "codice_corso", "descrizione_corso", "codice_materia",
        "descrizione_materia", "matricola_studente",
        "cognome_studente", "nome_studente"
    };

    //PARTE 1: APERTURA FILE
    ifstream File(filePath);

    if (!File) {
        return false;
    }



    //PARTE 2: CONTROLLO HEADER
    vector<string> headers(7);

    for (int i = 0; i < 7; i++) {

        if (i < 6) {
            getline(File, headers[i], ',');
        }
        else {
            getline(File, headers[i]);
        }

        headers[i] = toLower(trim(headers[i]));

    }


    for (int i = 0; i < 7; i++) {
        if (headers[i] != HEAD[i]) { //non trovato
            return false;
        }
    }



    //PARTE 3:  INPUT Dati

    string a; //stringa di appoggio
    while (getline(File, a, ',')) {   //ciclo fino a fine file
        CourseStudent sudent;
        // 0: courseCode -> minuscolo
        sudent.courseCode = toLower(trim(a));

        // 1: courseDescription
        getline(File, a, ',');
        sudent.courseDescription = toLower(trim(a));

        // 2: subjectCode
        getline(File, a, ',');
        sudent.subjectCode = toLower(trim(a));

        // 3: subjectDescription
        getline(File, a, ',');
        sudent.subjectDescription = toLower(trim(a));

        // 4: studentId
        getline(File, a, ',');
        a = trim(a);
        sudent.studentId = stoi(a);

        // 5: studentLastName
        getline(File, a, ',');
        sudent.studentLastName = toLower(trim(a));

        // 6: studentFirstName
        getline(File, a);
        sudent.studentFirstName = toLower(trim(a));


        //insert of student in vector
        load.push_back(sudent);
    }

    File.close();
    return true;
}


//PUNTO 10
bool uploadCSV(string filePath, vector<CourseStudent> upload) {
    //intestazione
    vector<string> HEAD = {
        "codice_corso", "descrizione_corso", "codice_materia",
        "descrizione_materia", "matricola_studente",
        "cognome_studente", "nome_studente"
    };

    //apertura file
    ofstream File (filePath);


    if (!File) {
        return false;
    }

    //output intestazione
    for (int i = 0; i < HEAD.size()-1; i++) {
        File << HEAD[i]<<",";
    }
    File<<HEAD[HEAD.size()-1]<<endl;

    //output dati
    for (int i = 0; i < upload.size(); i++) {
        File << upload[i].courseCode << ","
            << upload[i].courseDescription << ","
            << upload[i].subjectCode << ","
            << upload[i].subjectDescription << ","
            << upload[i].studentId << ","
            << upload[i].studentLastName << ","
            << upload[i].studentFirstName << endl;
    }

    File.close();
    return true;
}


string trim(string s) {
    int start = 0;
    while (start < (int)s.size() && (s[start] == ' ' || s[start] == '\t')) {
        start++;
    }
    int end = (int)s.size() - 1;
    while (end >= start && (s[end] == ' ' || s[end] == '\t')) {
        end--;
    }
    if (end < start) return "";
    return s.substr(start, end - start + 1);
}



string toLower(string s) {
    string result = s;

    for (int i = 0; i < result.size(); ++i) {
        result[i] = tolower(result[i]);
    }
    return result;
}

string toUpper(string s) {
    string result = s;

    for (int i = 0; i < result.size(); ++i) {
        result[i] = toupper(result[i]);
    }
    return result;
}


//dato un vettore con duplicati di codice_matricola ritorna il vettore eliminando i duplicati
vector<CourseStudent> deleteMultipleId(vector<CourseStudent> data) {
    vector<CourseStudent> students;
    unordered_set<int> seenIds;  // tiene traccia degli ID giÃ  trovati

    for (int i = 0; i < data.size(); i++) {
        int currentId = data[i].studentId;

        if (seenIds.find(currentId) == seenIds.end()) {     //se non trova ritorna l'ultimo elemento del set -> elemento nuovo e va aggiunto
            students.push_back(data[i]);      // Aggiunge lo studente se ID non giÃ  visto
            seenIds.insert(currentId);        // Segna l'ID come visto
        }
    }

    return students;
}

void MainWindow::printStudent(CourseStudent student) {
    QString line = QString::fromStdString(student.courseCode) + " | "
                   + QString::fromStdString(student.courseDescription) + " | "
                   + QString::fromStdString(student.subjectCode) + " | "
                   + QString::fromStdString(student.subjectDescription) + " | "
                   + QString::number(student.studentId) + " | "
                   + QString::fromStdString(student.studentLastName) + " | "
                   + QString::fromStdString(student.studentFirstName);

    ui->outputConsole->appendPlainText(line);
}



// Funzione per stampare gli studenti iscritti con i dati separati da "|"
void MainWindow::printStudents(vector<CourseStudent> students) {
    for (const CourseStudent student : students) {
        printStudent(student);
    }
}

void MainWindow::printStudentInfo(CourseStudent student) {
    QString line = QString::number(student.studentId) + " | "
                   + QString::fromStdString(student.studentLastName) + " | "
                   + QString::fromStdString(student.studentFirstName);

    ui->outputConsole->appendPlainText(line);
}

void MainWindow::printStudentsInfo(vector<CourseStudent> students) {
    for (const CourseStudent student : students) {
        printStudentInfo(student);
    }
}

//PUNTO 3.1
vector<int> searchByStudentId(vector<CourseStudent> data, int id) {
    vector<int> positions;

    for (int i = 0; i < data.size(); i++) {
        if (data[i].studentId == id) {
            positions.push_back(i);
        }
    }
    return positions;
}

//PUNTO 3.2
vector<int> searchByLastName(vector<CourseStudent> data, string lastName) {
    vector<int> positions;

    for (int i = 0; i < data.size(); i++) {
        if (data[i].studentLastName == lastName) {
            positions.push_back(i);
        }
    }
    return positions;
}

//PUNTO 4
//visualizzare sudente: nome | cognome | codice_studente
vector<CourseStudent> getStudentsByCourseCode(vector<CourseStudent> data, string courseCode) {
    vector <CourseStudent> students;

    courseCode = toLower(trim(courseCode));

    students = searchByCourseCode(data, courseCode);

    students = deleteMultipleId(students);

    return students;
}



//PUNTO 5
vector<CourseStudent> searchByCourseCode(vector<CourseStudent> data, string courseCodeInput) {
    vector <CourseStudent> students;

    courseCodeInput = toLower(trim(courseCodeInput));

    for (int i = 0; i < data.size(); i++) {
        if (data[i].courseCode == courseCodeInput) {
            students.push_back(data[i]);
        }
    }

    return students;
}

//PUNTO 6


void MainWindow::studentPerCourse(vector<CourseStudent> data) {
    // Mappa: courseCode -> set di studentId unici
    map<string, set<int>> courseStudents;

    for (const auto &entry : data) {
        courseStudents[entry.courseCode].insert(entry.studentId);
    }

    ui->outputConsole->appendPlainText("---- Studenti per Corso ----");

    for (const auto &pair : courseStudents) {
        QString line = "Corso " + QString::fromStdString(pair.first)
        + ": " + QString::number(pair.second.size()) + " studente/i";
        ui->outputConsole->appendPlainText(line);
    }

    ui->outputConsole->appendPlainText(""); // Riga vuota finale
}




//PUNTO 7
// stampare il numero di materie per corso

void MainWindow::subjectPerCourse(vector<CourseStudent> data) {
    // Mappa: courseCode -> insieme di materie (uniche)
    map<string, set<string>> courseStudents;

    for (const auto &entry : data) {
        courseStudents[entry.courseCode].insert(entry.subjectCode);
    }

    ui->outputConsole->appendPlainText("---- Materie per Corso ----");

    for (const auto &pair : courseStudents) {
        QString line = "Corso " + QString::fromStdString(pair.first)
        + ": " + QString::number(pair.second.size()) + " materie";
        ui->outputConsole->appendPlainText(line);
    }

    ui->outputConsole->appendPlainText(""); // Riga vuota finale
}




//PUNTO 8

void MainWindow::searchSubjectByString(vector<CourseStudent> data, string keyword) {
    keyword = toLower(trim(keyword));
    set<string> duplicated;
    bool found = false;

    for (const auto &entry : data) {
        const string &subject = entry.subjectDescription;

        if (subject.find(keyword) != string::npos) {
            if (duplicated.count(subject) == 0) {
                ui->outputConsole->appendPlainText(QString::fromStdString(subject));
                duplicated.insert(subject);
                found = true;
            }
        }
    }

    if (!found) {
        QString message = "Nessuna materia trovata contenente: " + QString::fromStdString(keyword);
        ui->errorConsole->appendPlainText(message);
    }
}



//PUNTO 9

bool MainWindow::addNewStudent(vector<CourseStudent>& data, int id, string firstName, string lastName, string subjectCodeInput, string courseCodeInput) {
    string subjectCode = toLower(trim(subjectCodeInput));
    string courseCode = toLower(trim(courseCodeInput));
    firstName = toLower(firstName);
    lastName = toLower(lastName);

    CourseStudent newStudent;
    bool found = false;

    for (const auto &entry : data) {
        if (toLower(trim(entry.subjectCode)) == subjectCode &&
            toLower(trim(entry.courseCode)) == courseCode) {

            newStudent.courseCode = entry.courseCode;
            newStudent.courseDescription = entry.courseDescription;
            newStudent.subjectCode = entry.subjectCode;
            newStudent.subjectDescription = entry.subjectDescription;
            newStudent.studentId = id;
            newStudent.studentFirstName = toLower(trim(firstName));
            newStudent.studentLastName = toLower(trim(lastName));

            data.push_back(newStudent);
            ui->outputConsole->appendPlainText("New Student added:");
            printStudent(newStudent);
            ui->outputConsole->appendPlainText("");

            found = true;
            break;  //risparmia runtime :)
        }
    }

    if (!found) {
        ui->errorConsole->appendPlainText("Error: subject/course not found. New student not added.");
    }

    return found;
}





void MainWindow::onStudentDataReceived(int id, QString firstName, QString lastName, QString subjectCode, QString courseCode) {
    if (addNewStudent(m_data, id,
                      firstName.toStdString(),
                      lastName.toStdString(),
                      subjectCode.toStdString(),
                      courseCode.toStdString()))
    {
        // Ricarica CsvViewWindow se esiste
        if (csvViewWindow) {
            csvViewWindow->loadData(m_data);  // ricarica con i nuovi dati
        }
    }
}





void MainWindow::on_addStudentButton_clicked() {
    if (m_data.empty()) {
        ui->errorConsole->appendPlainText("Load a CSV file before!");
    }
    else {
        addStudentWindow = new AddStudentWindow();
        connect(addStudentWindow, &AddStudentWindow::studentDataReady,
                this, &MainWindow::onStudentDataReceived);
        addStudentWindow->show();
    }

}





void MainWindow::closeEvent(QCloseEvent *event) {
    if (csvViewWindow && csvViewWindow->isVisible()) {
        csvViewWindow->hide();  // evita blocchi
        csvViewWindow->deleteLater();
    }

    if (addStudentWindow && addStudentWindow->isVisible()) {
        addStudentWindow->hide();
        addStudentWindow->deleteLater();
    }

    event->accept();
}




void MainWindow::on_loadCSVButton_clicked() {
    QString fileName = QFileDialog::getOpenFileName(this, "Apri CSV", QDir::homePath(), "CSV files (*.csv)");
    if (!fileName.isEmpty()) {
        m_data.clear();
        if (!::loadCSV(fileName.toStdString(), m_data)) {
            ui->errorConsole->appendPlainText("An error occured while trying to load the CSV file!");
        }
        else {
            if (!csvViewWindow) {
                csvViewWindow = new CsvViewWindow();
            }

            csvViewWindow->loadData(m_data);
            csvViewWindow->show();
        }


    }


}



bool MainWindow::loadCSV(const QString &filePath, vector<CourseStudent> &out) {
    return ::loadCSV(filePath.toStdString(), out);
}


QList<QTableWidgetItem*> MainWindow::buildFullRow(const CourseStudent &cs) {
    return {
        new QTableWidgetItem(QString::fromStdString(cs.courseCode)),
        new QTableWidgetItem(QString::fromStdString(cs.courseDescription)),
        new QTableWidgetItem(QString::fromStdString(cs.subjectCode)),
        new QTableWidgetItem(QString::fromStdString(cs.subjectDescription)),
        new QTableWidgetItem(QString::number(cs.studentId)),
        new QTableWidgetItem(QString::fromStdString(cs.studentLastName)),
        new QTableWidgetItem(QString::fromStdString(cs.studentFirstName))
    };
}

QList<QTableWidgetItem*> MainWindow::buildNameSurnameIdRow(const CourseStudent &cs) {
    return {
        new QTableWidgetItem(QString::number(cs.studentId)),
        new QTableWidgetItem(QString::fromStdString(cs.studentLastName)),
        new QTableWidgetItem(QString::fromStdString(cs.studentFirstName))
    };
}

void MainWindow::on_clearButton_clicked() {
    ui->outputConsole->clear();
    ui->errorConsole->clear();
}


void MainWindow::on_searchSurnameButton_clicked() {

    if (m_data.empty()) {
        ui->errorConsole->appendPlainText("Load a CSV file before!");
    }
    else {
        string str = ui->SearchSurnameId->text().toStdString();
        if (str.empty()) {
            ui->errorConsole->appendPlainText("Put a Surname before!");
        }
        else {
            str = toLower(str);

            vector <int> pos = searchByLastName(m_data, str);

            if(pos.empty()) {
                ui->errorConsole->appendPlainText("No student found!");
            }
            else {
                str = "---- Result Search by Surname '" + str + "' ----";
                QString a = QString::fromStdString(str);
                ui->outputConsole->appendPlainText(a);

                for (int i = 0; i < pos.size(); i++) {
                    printStudent(m_data[pos[i]]);
                }
                ui->outputConsole->appendPlainText("");
            }
        }


    }
}


void MainWindow::on_searchIdButton_clicked() {
    string str = ui->SearchSurnameId->text().toStdString();

    if (m_data.empty()) {
        ui->errorConsole->appendPlainText("Load a CSV file before!");
    }
    else if (str.empty()) {
        ui->errorConsole->appendPlainText("Put an ID before!");
    }
    else {
        int search = stoi(str);
        vector <int> pos = searchByStudentId(m_data, search);

        if(pos.empty()) {
            ui->errorConsole->appendPlainText("No student found!");
        }
        else {
            str = "---- Result Search by ID '" + str + "' ----";
            QString a = QString::fromStdString(str);
            ui->outputConsole->appendPlainText(a);

            for (int i = 0; i < pos.size(); i++) {
                printStudent(m_data[pos[i]]);
            }
            ui->outputConsole->appendPlainText("");
        }

    }
}


void MainWindow::on_courseCodeButton_clicked() {


    if (m_data.empty()) {
        ui->errorConsole->appendPlainText("Load a CSV file before!");
    }
    else {
        string str = ui->courseCodeSearch->text().toStdString();
        if (str.empty()) {
            ui->errorConsole->appendPlainText("Insert a course code before!");
        }
        else {
            str = toLower(trim(str));

            vector<CourseStudent> s = getStudentsByCourseCode(m_data, str);

            if (s.empty()) {
                ui->errorConsole->appendPlainText("No course found for: " + QString::fromStdString(str));
            }
            else {
                QString header = "---- Result Search by Course Code '" + QString::fromStdString(str) + "' ----";
                ui->outputConsole->appendPlainText(header);
                printStudentsInfo(s);
                ui->outputConsole->appendPlainText("");
            }
        }
    }

}



void MainWindow::on_courseSearchButton_clicked() {

    if (m_data.empty()) {
        ui->errorConsole->appendPlainText("Load a CSV file before!");
    }
    else {
        string str = ui->courseInfoSearch->text().toStdString();
        if (str.empty()) {
            ui->errorConsole->appendPlainText("Insert a course code before!");
        }
        else {
            vector <CourseStudent> s = searchByCourseCode(m_data, str);
            if (s.empty()) {
                ui->errorConsole->appendPlainText("No Course found!");
            }
            else {
                str = "---- Result Search by Course Code '" + str + "' ----";
                QString a = QString::fromStdString(str);
                ui->outputConsole->appendPlainText(a);
                printStudents(s);
                ui->outputConsole->appendPlainText("");
            }
        }
    }
}


void MainWindow::on_studentPerCourseButton_clicked() {
    if (m_data.empty()) {
        ui->errorConsole->appendPlainText("Load a CSV file before!");
    }
    else {
        studentPerCourse(m_data);
        ui->outputConsole->appendPlainText("");
    }

}


void MainWindow::on_subjectPerCourseButton_clicked() {
    if (m_data.empty()) {
        ui->errorConsole->appendPlainText("Load a CSV file before!");
    }
    else {
        subjectPerCourse(m_data);
        ui->outputConsole->appendPlainText("");
    }

}


void MainWindow::on_subjectSearchButton_clicked() {
    string str = ui->subjectSearch->text().toStdString();
    if (m_data.empty()) {
        ui->errorConsole->appendPlainText("Load a CSV file before!");
    }
    else if (str.empty()) {
        ui->errorConsole->appendPlainText("Put text before!");
    }
    else {
        searchSubjectByString(m_data, str);
        ui->outputConsole->appendPlainText("");
    }


}





void MainWindow::on_saveButton_clicked() {

    if (m_data.empty()) {
        ui->errorConsole->appendPlainText("Load a CSV file before!");
    }
    else {
        QString fileName = QFileDialog::getSaveFileName(this, "Salva CSV", QDir::homePath(), "CSV files (*.csv)");
        if (!fileName.isEmpty()) {
            string path = fileName.toStdString();

            if (!uploadCSV(path, m_data)) {
                ui->errorConsole->appendPlainText("An Error occured while trying to save the CSV file.");
            } else {
                ui->outputConsole->appendPlainText("File Saved. The CSV file was saved correctly.");
                ui->outputConsole->appendPlainText("");
            }
        }
    }
}


