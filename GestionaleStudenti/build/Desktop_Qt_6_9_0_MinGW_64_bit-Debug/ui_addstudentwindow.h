/********************************************************************************
** Form generated from reading UI file 'addstudentwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSTUDENTWINDOW_H
#define UI_ADDSTUDENTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddStudentWindow
{
public:
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit_id;
    QLineEdit *lineEdit_firstName;
    QLineEdit *lineEdit_lastName;
    QLineEdit *lineEdit_subjectCode;
    QLineEdit *lineEdit_courseCode;
    QPushButton *addStudentFinalButton;

    void setupUi(QWidget *AddStudentWindow)
    {
        if (AddStudentWindow->objectName().isEmpty())
            AddStudentWindow->setObjectName("AddStudentWindow");
        AddStudentWindow->resize(400, 250);
        verticalLayout = new QVBoxLayout(AddStudentWindow);
        verticalLayout->setObjectName("verticalLayout");
        lineEdit_id = new QLineEdit(AddStudentWindow);
        lineEdit_id->setObjectName("lineEdit_id");

        verticalLayout->addWidget(lineEdit_id);

        lineEdit_firstName = new QLineEdit(AddStudentWindow);
        lineEdit_firstName->setObjectName("lineEdit_firstName");

        verticalLayout->addWidget(lineEdit_firstName);

        lineEdit_lastName = new QLineEdit(AddStudentWindow);
        lineEdit_lastName->setObjectName("lineEdit_lastName");

        verticalLayout->addWidget(lineEdit_lastName);

        lineEdit_subjectCode = new QLineEdit(AddStudentWindow);
        lineEdit_subjectCode->setObjectName("lineEdit_subjectCode");

        verticalLayout->addWidget(lineEdit_subjectCode);

        lineEdit_courseCode = new QLineEdit(AddStudentWindow);
        lineEdit_courseCode->setObjectName("lineEdit_courseCode");

        verticalLayout->addWidget(lineEdit_courseCode);

        addStudentFinalButton = new QPushButton(AddStudentWindow);
        addStudentFinalButton->setObjectName("addStudentFinalButton");

        verticalLayout->addWidget(addStudentFinalButton);


        retranslateUi(AddStudentWindow);

        QMetaObject::connectSlotsByName(AddStudentWindow);
    } // setupUi

    void retranslateUi(QWidget *AddStudentWindow)
    {
        AddStudentWindow->setWindowTitle(QCoreApplication::translate("AddStudentWindow", "Aggiungi Studente", nullptr));
        lineEdit_id->setPlaceholderText(QCoreApplication::translate("AddStudentWindow", "ID studente", nullptr));
        lineEdit_firstName->setPlaceholderText(QCoreApplication::translate("AddStudentWindow", "Nome", nullptr));
        lineEdit_lastName->setPlaceholderText(QCoreApplication::translate("AddStudentWindow", "Cognome", nullptr));
        lineEdit_subjectCode->setPlaceholderText(QCoreApplication::translate("AddStudentWindow", "Codice Materia", nullptr));
        lineEdit_courseCode->setPlaceholderText(QCoreApplication::translate("AddStudentWindow", "Codice Corso", nullptr));
        addStudentFinalButton->setText(QCoreApplication::translate("AddStudentWindow", "Aggiungi Studente", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddStudentWindow: public Ui_AddStudentWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSTUDENTWINDOW_H
