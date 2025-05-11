#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_mainwin.h"
#include <QPushButton>
#include <vector>
#include <QAction>
#include <QMouseEvent>
#include <QFile>
#include <QTextStream>

using namespace std;

class paihang
{
public:
    QString name=" ";
    int time2=9999;
};

class boombutton : public QPushButton
{
public:
    boombutton(QWidget* parent = nullptr);
    int con = 0;//0未排查,1已排查,2已标记
    void mousePressEvent(QMouseEvent*);
};



class mainwin : public QMainWindow
{
    Q_OBJECT

public:
    mainwin(QWidget *parent = nullptr);
    ~mainwin();
    
    
    int  hang;
    int  lie;
    int  boom;
    int notboom;
    int time66;

    QVector<paihang> paihang;

    void createboard();
    void  boomset();
    void  sweep(int,int);
    void reveal();
    void range();

     vector<vector<int>> boomse;
     
     QVector<boombutton*> buttons;

     

private:
    Ui::mainwinClass ui;

private slots:
    void on_eaaction_triggered();
    void on_restart_triggered();
    void on_noaction_triggered();
    void on_haaction_triggered();
    void on_savebutton_clicked();
public slots:
    void  onbuttonclicked(int,int );
    
};


