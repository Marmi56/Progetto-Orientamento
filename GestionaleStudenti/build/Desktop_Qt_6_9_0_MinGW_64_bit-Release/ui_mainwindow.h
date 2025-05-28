/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFrame *serches;
    QPushButton *searchIdButton;
    QPushButton *searchSurnameButton;
    QLineEdit *SearchSurnameId;
    QPushButton *loadCSVButton;
    QPlainTextEdit *outputConsole;
    QPushButton *clearButton;
    QFrame *line;
    QPlainTextEdit *errorConsole;
    QTextEdit *textEdit;
    QTextEdit *textEdit_2;
    QFrame *StudentSubscribed;
    QPushButton *courseCodeButton;
    QLineEdit *courseCodeSearch;
    QTextEdit *textEdit_3;
    QFrame *CourseInfo;
    QPushButton *courseSearchButton;
    QLineEdit *courseInfoSearch;
    QTextEdit *textEdit_4;
    QFrame *Stats;
    QPushButton *studentPerCourseButton;
    QPushButton *subjectPerCourseButton;
    QPushButton *saveButton;
    QPushButton *addStudentButton;
    QTextEdit *textEdit_5;
    QFrame *SearchSubject;
    QPushButton *subjectSearchButton;
    QLineEdit *subjectSearch;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1188, 649);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(1188, 649));
        MainWindow->setMaximumSize(QSize(1188, 649));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        serches = new QFrame(centralwidget);
        serches->setObjectName("serches");
        serches->setGeometry(QRect(30, 50, 471, 101));
        serches->setFrameShape(QFrame::Shape::StyledPanel);
        serches->setFrameShadow(QFrame::Shadow::Raised);
        searchIdButton = new QPushButton(serches);
        searchIdButton->setObjectName("searchIdButton");
        searchIdButton->setGeometry(QRect(60, 60, 111, 24));
        searchSurnameButton = new QPushButton(serches);
        searchSurnameButton->setObjectName("searchSurnameButton");
        searchSurnameButton->setGeometry(QRect(270, 60, 111, 24));
        SearchSurnameId = new QLineEdit(serches);
        SearchSurnameId->setObjectName("SearchSurnameId");
        SearchSurnameId->setGeometry(QRect(10, 20, 421, 31));
        loadCSVButton = new QPushButton(centralwidget);
        loadCSVButton->setObjectName("loadCSVButton");
        loadCSVButton->setGeometry(QRect(570, 30, 80, 24));
        outputConsole = new QPlainTextEdit(centralwidget);
        outputConsole->setObjectName("outputConsole");
        outputConsole->setGeometry(QRect(570, 70, 571, 401));
        outputConsole->setReadOnly(true);
        clearButton = new QPushButton(centralwidget);
        clearButton->setObjectName("clearButton");
        clearButton->setGeometry(QRect(1060, 30, 80, 24));
        line = new QFrame(centralwidget);
        line->setObjectName("line");
        line->setGeometry(QRect(520, 30, 16, 501));
        line->setFrameShape(QFrame::Shape::VLine);
        line->setFrameShadow(QFrame::Shadow::Sunken);
        errorConsole = new QPlainTextEdit(centralwidget);
        errorConsole->setObjectName("errorConsole");
        errorConsole->setGeometry(QRect(570, 520, 571, 70));
        errorConsole->setReadOnly(true);
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(30, 20, 251, 31));
        textEdit->setMouseTracking(false);
        textEdit->setAcceptDrops(false);
        textEdit->setReadOnly(true);
        textEdit_2 = new QTextEdit(centralwidget);
        textEdit_2->setObjectName("textEdit_2");
        textEdit_2->setGeometry(QRect(570, 490, 211, 31));
        textEdit_2->setMouseTracking(false);
        textEdit_2->setAcceptDrops(false);
        textEdit_2->setReadOnly(true);
        StudentSubscribed = new QFrame(centralwidget);
        StudentSubscribed->setObjectName("StudentSubscribed");
        StudentSubscribed->setGeometry(QRect(30, 210, 471, 51));
        StudentSubscribed->setFrameShape(QFrame::Shape::StyledPanel);
        StudentSubscribed->setFrameShadow(QFrame::Shadow::Raised);
        courseCodeButton = new QPushButton(StudentSubscribed);
        courseCodeButton->setObjectName("courseCodeButton");
        courseCodeButton->setGeometry(QRect(350, 20, 91, 24));
        courseCodeSearch = new QLineEdit(StudentSubscribed);
        courseCodeSearch->setObjectName("courseCodeSearch");
        courseCodeSearch->setGeometry(QRect(10, 10, 301, 31));
        textEdit_3 = new QTextEdit(centralwidget);
        textEdit_3->setObjectName("textEdit_3");
        textEdit_3->setGeometry(QRect(30, 180, 251, 31));
        textEdit_3->setMouseTracking(false);
        textEdit_3->setAcceptDrops(false);
        textEdit_3->setReadOnly(true);
        CourseInfo = new QFrame(centralwidget);
        CourseInfo->setObjectName("CourseInfo");
        CourseInfo->setGeometry(QRect(30, 330, 471, 51));
        CourseInfo->setFrameShape(QFrame::Shape::StyledPanel);
        CourseInfo->setFrameShadow(QFrame::Shadow::Raised);
        courseSearchButton = new QPushButton(CourseInfo);
        courseSearchButton->setObjectName("courseSearchButton");
        courseSearchButton->setGeometry(QRect(350, 20, 91, 24));
        courseInfoSearch = new QLineEdit(CourseInfo);
        courseInfoSearch->setObjectName("courseInfoSearch");
        courseInfoSearch->setGeometry(QRect(10, 10, 301, 31));
        textEdit_4 = new QTextEdit(centralwidget);
        textEdit_4->setObjectName("textEdit_4");
        textEdit_4->setGeometry(QRect(30, 300, 251, 31));
        textEdit_4->setMouseTracking(false);
        textEdit_4->setAcceptDrops(false);
        textEdit_4->setReadOnly(true);
        Stats = new QFrame(centralwidget);
        Stats->setObjectName("Stats");
        Stats->setGeometry(QRect(30, 550, 471, 41));
        Stats->setFrameShape(QFrame::Shape::StyledPanel);
        Stats->setFrameShadow(QFrame::Shadow::Raised);
        studentPerCourseButton = new QPushButton(Stats);
        studentPerCourseButton->setObjectName("studentPerCourseButton");
        studentPerCourseButton->setGeometry(QRect(40, 10, 121, 24));
        subjectPerCourseButton = new QPushButton(Stats);
        subjectPerCourseButton->setObjectName("subjectPerCourseButton");
        subjectPerCourseButton->setGeometry(QRect(280, 10, 151, 24));
        saveButton = new QPushButton(centralwidget);
        saveButton->setObjectName("saveButton");
        saveButton->setGeometry(QRect(1050, 480, 80, 24));
        addStudentButton = new QPushButton(centralwidget);
        addStudentButton->setObjectName("addStudentButton");
        addStudentButton->setGeometry(QRect(680, 30, 80, 24));
        textEdit_5 = new QTextEdit(centralwidget);
        textEdit_5->setObjectName("textEdit_5");
        textEdit_5->setGeometry(QRect(30, 420, 251, 31));
        textEdit_5->setMouseTracking(false);
        textEdit_5->setAcceptDrops(false);
        textEdit_5->setReadOnly(true);
        SearchSubject = new QFrame(centralwidget);
        SearchSubject->setObjectName("SearchSubject");
        SearchSubject->setGeometry(QRect(30, 450, 471, 51));
        SearchSubject->setFrameShape(QFrame::Shape::StyledPanel);
        SearchSubject->setFrameShadow(QFrame::Shadow::Raised);
        subjectSearchButton = new QPushButton(SearchSubject);
        subjectSearchButton->setObjectName("subjectSearchButton");
        subjectSearchButton->setGeometry(QRect(350, 20, 91, 24));
        subjectSearch = new QLineEdit(SearchSubject);
        subjectSearch->setObjectName("subjectSearch");
        subjectSearch->setGeometry(QRect(10, 10, 301, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1188, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        searchIdButton->setText(QCoreApplication::translate("MainWindow", "Id", nullptr));
        searchSurnameButton->setText(QCoreApplication::translate("MainWindow", "Surname", nullptr));
#if QT_CONFIG(whatsthis)
        SearchSurnameId->setWhatsThis(QCoreApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(whatsthis)
        SearchSurnameId->setText(QString());
        SearchSurnameId->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter ID or Surname", nullptr));
        loadCSVButton->setText(QCoreApplication::translate("MainWindow", "Load CSV", nullptr));
        clearButton->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        textEdit->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:700;\">Attended Courses</span></p></body></html>", nullptr));
        textEdit_2->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:700;\">ERRORS:</span></p></body></html>", nullptr));
        courseCodeButton->setText(QCoreApplication::translate("MainWindow", "Search course", nullptr));
        courseCodeSearch->setText(QString());
        courseCodeSearch->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter Course Code", nullptr));
        textEdit_3->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:700;\">Students subscribed at course</span></p></body></html>", nullptr));
        courseSearchButton->setText(QCoreApplication::translate("MainWindow", "Search course", nullptr));
        courseInfoSearch->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter Course Code", nullptr));
        textEdit_4->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:700;\">Course Info</span></p></body></html>", nullptr));
        studentPerCourseButton->setText(QCoreApplication::translate("MainWindow", "Student per Course", nullptr));
        subjectPerCourseButton->setText(QCoreApplication::translate("MainWindow", "Subject per Course", nullptr));
        saveButton->setText(QCoreApplication::translate("MainWindow", "Save CSV", nullptr));
        addStudentButton->setText(QCoreApplication::translate("MainWindow", "add Student", nullptr));
        textEdit_5->setHtml(QCoreApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:700;\">Search subject by string</span></p></body></html>", nullptr));
        subjectSearchButton->setText(QCoreApplication::translate("MainWindow", "Search subject", nullptr));
        subjectSearch->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter text", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
