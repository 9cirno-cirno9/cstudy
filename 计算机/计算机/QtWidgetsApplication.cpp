#include "QtWidgetsApplication.h"

QtWidgetsApplication::QtWidgetsApplication(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    this->setWindowTitle("calloc");


    connect(ui.b1, &QPushButton::clicked, this, &QtWidgetsApplication::b1_clicked);
    connect(ui.b2, &QPushButton::clicked, this, &QtWidgetsApplication::b2_clicked);
    connect(ui.b3, &QPushButton::clicked, this, &QtWidgetsApplication::b3_clicked);
    connect(ui.b4, &QPushButton::clicked, this, &QtWidgetsApplication::b4_clicked);
    connect(ui.b5, &QPushButton::clicked, this, &QtWidgetsApplication::b5_clicked);
    connect(ui.b6, &QPushButton::clicked, this, &QtWidgetsApplication::b6_clicked);
    connect(ui.b7, &QPushButton::clicked, this, &QtWidgetsApplication::b7_clicked);
    connect(ui.b8, &QPushButton::clicked, this, &QtWidgetsApplication::b8_clicked);
    connect(ui.b9, &QPushButton::clicked, this, &QtWidgetsApplication::b9_clicked);
    connect(ui.b0, &QPushButton::clicked, this, &QtWidgetsApplication::b0_clicked);
    connect(ui.brkuo, &QPushButton::clicked, this, &QtWidgetsApplication::brkuo_clicked);
    connect(ui.blkuo, &QPushButton::clicked, this, &QtWidgetsApplication::blkuo_clicked);
    connect(ui.bjia, &QPushButton::clicked, this, &QtWidgetsApplication::bjia_clicked);
    connect(ui.bjian, &QPushButton::clicked, this, &QtWidgetsApplication::bjian_clicked);
    connect(ui.bcheng, &QPushButton::clicked, this, &QtWidgetsApplication::bcheng_clicked);
    connect(ui.bchu, &QPushButton::clicked, this, &QtWidgetsApplication::bchu_clicked);
    connect(ui.bpoint, &QPushButton::clicked, this, &QtWidgetsApplication::bpoint_clicked);
    
    connect(ui.bdeng, &QPushButton::clicked, this, &QtWidgetsApplication::bdeng_clicked);
    connect(ui.bclear, &QPushButton::clicked, this, &QtWidgetsApplication::bclear_clicked);
    connect(ui.back, &QPushButton::clicked, this, &QtWidgetsApplication::back_clicked);


}

QtWidgetsApplication::~QtWidgetsApplication()
{}

void QtWidgetsApplication::b1_clicked()
{
    count += '1';
    ui.print->setText(count);
}

void QtWidgetsApplication::b2_clicked()
{
    count += '2';
    ui.print->setText(count);
}

void QtWidgetsApplication::b3_clicked()
{
    count += '3';
    ui.print->setText(count);
}

void QtWidgetsApplication::b4_clicked()
{
    count += '4';
    ui.print->setText(count);
}

void QtWidgetsApplication::b5_clicked()
{
    count += '5';
    ui.print->setText(count);
}

void QtWidgetsApplication::b6_clicked()
{
    count += '6';
    ui.print->setText(count);
}

void QtWidgetsApplication::b7_clicked()
{
    count += '7';
    ui.print->setText(count);
}

void QtWidgetsApplication::b8_clicked()
{
    count += '8';
    ui.print->setText(count);
}

void QtWidgetsApplication::b9_clicked()
{
    count += '9';
    ui.print->setText(count);
}

void QtWidgetsApplication::b0_clicked()
{
    count += '0';
    ui.print->setText(count);
}

void QtWidgetsApplication::brkuo_clicked()
{
    count += ')';
    ui.print->setText(count);
}

void QtWidgetsApplication::blkuo_clicked()
{
    count += '(';
    ui.print->setText(count);
}

void QtWidgetsApplication::bjia_clicked()
{
    count += '+';
    ui.print->setText(count);
}

void QtWidgetsApplication::bjian_clicked()
{
    count += '-';
    ui.print->setText(count);
}

void QtWidgetsApplication::bcheng_clicked()
{
    count += '*';
    ui.print->setText(count);
}

void QtWidgetsApplication::bchu_clicked()
{
    count += '/';
    ui.print->setText(count);
}

void QtWidgetsApplication::bpoint_clicked()
{
    count += '.';
    ui.print->setText(count);
}



void QtWidgetsApplication::bdeng_clicked()
{
    count += '=';
    ui.print->setText(count);
}

void QtWidgetsApplication::bclear_clicked()
{
    count.clear();
    ui.print->clear();
}

void QtWidgetsApplication::back_clicked()
{
    count.chop(1);
    ui.print->setText(count);
}