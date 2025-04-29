#pragma once

#include <QtWidgets/QWidget>
#include "ui_QtWidgetsApplication.h"

class QtWidgetsApplication : public QWidget
{
    Q_OBJECT

public:
    QtWidgetsApplication(QWidget *parent = nullptr);
    ~QtWidgetsApplication();

private:
    Ui::QtWidgetsApplicationClass ui;
    QString count;

private slots:
    void b1_clicked();
    void b2_clicked();
    void b3_clicked();
    void b4_clicked();
    void b5_clicked();
    void b6_clicked();
    void b7_clicked();
    void b8_clicked();
    void b9_clicked();
    void b0_clicked();
    void brkuo_clicked();
    void blkuo_clicked();
    void bjia_clicked();
    void bjian_clicked();
    void bcheng_clicked();
    void bchu_clicked();
    void bpoint_clicked();

    void bdeng_clicked();
    void bclear_clicked();
    void back_clicked();

};
