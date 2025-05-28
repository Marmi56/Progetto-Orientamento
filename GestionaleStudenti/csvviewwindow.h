#ifndef CSVVIEWWINDOW_H
#define CSVVIEWWINDOW_H

#include "mainwindow.h"

#include <QWidget>
#include <vector>
#include <QTableWidgetItem>

namespace Ui {
class CsvViewWindow;
}

class CsvViewWindow : public QWidget
{
    Q_OBJECT

public:
    explicit CsvViewWindow(QWidget *parent = nullptr);
    ~CsvViewWindow();

    void loadData(const vector<CourseStudent> &data);

private:
    Ui::CsvViewWindow *ui;
};

#endif // CSVVIEWWINDOW_H
