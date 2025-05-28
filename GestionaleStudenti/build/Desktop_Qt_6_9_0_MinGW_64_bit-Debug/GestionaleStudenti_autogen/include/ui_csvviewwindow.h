/********************************************************************************
** Form generated from reading UI file 'csvviewwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CSVVIEWWINDOW_H
#define UI_CSVVIEWWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CsvViewWindow
{
public:
    QTableWidget *tableWidget;

    void setupUi(QWidget *CsvViewWindow)
    {
        if (CsvViewWindow->objectName().isEmpty())
            CsvViewWindow->setObjectName("CsvViewWindow");
        CsvViewWindow->resize(902, 571);
        tableWidget = new QTableWidget(CsvViewWindow);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setGeometry(QRect(0, 10, 891, 211));

        retranslateUi(CsvViewWindow);

        QMetaObject::connectSlotsByName(CsvViewWindow);
    } // setupUi

    void retranslateUi(QWidget *CsvViewWindow)
    {
        CsvViewWindow->setWindowTitle(QCoreApplication::translate("CsvViewWindow", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CsvViewWindow: public Ui_CsvViewWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CSVVIEWWINDOW_H
