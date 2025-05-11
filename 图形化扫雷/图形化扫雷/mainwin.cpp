#include "mainwin.h"

mainwin::mainwin(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    srand((unsigned int)time(NULL));
    ui.charlabel->hide();
    ui.namelabel->hide();
    ui.nameedit->hide();
    ui.savebutton->hide();
    /*connect(ui.eaaction, &QAction::triggered, this, &mainwin::on_eaaction_triggered);*/
    //函数名特殊，导致自动连接
}

mainwin::~mainwin()
{}

boombutton::boombutton(QWidget* parent ):QPushButton(parent)
{
    setText(" ");
}



void  mainwin::createboard()
{
    qDeleteAll(buttons);
    buttons.clear();
    ui.timelabel->hide();
    ui.charlabel->hide();
    ui.namelabel->hide();
    ui.nameedit->hide();
    ui.nameedit->clear();
    ui.timelabel->clear();
    ui.savebutton->hide();

    ui.tiplabel->setText("sweep boom");
   

    for (int m = 1;m <= hang;m++)
    {
        for (int n = 1;n <= lie;n++)
        {
            int x = 390 - (double(lie) / 2) * 30 + (n - 1) * 30;
            int y = 300 + m * 30;
           boombutton* button = new boombutton(this);
            button->setGeometry(x,y, 30, 30);
            button->show();
           
            buttons.append(button);
            connect(button, &boombutton::clicked, [this, m, n]() {onbuttonclicked(m,n);});
            
        }
    }


}

void mainwin::boomset()
{
    boomse.clear();
    boomse.shrink_to_fit();
    boomse.resize(hang + 2, vector<int>(lie + 2, 0));
    int count = boom;
    
    while (count)
    {
        int x = rand() % hang + 1;
        int y = rand() % lie + 1;
        if (boomse[x][y] == 0)
        {
            boomse[x][y] = 1;
            count--;
        }
    }
    ui.countlabel->setText(QString::number(hang*lie-notboom));
    time66 = (unsigned int)time(NULL);
}

void mainwin::sweep(int x,int y)
{
    int k = (x - 1) * lie + y - 1;
   
    if (x == 0 || y == 0||x==hang+1||y==lie+1)
        return;
    if (buttons[k]->con == 1)
        return;
    int num = 0;
    for (int m = x - 1;m <= x + 1;m++)
    {
        for (int n = y - 1;n <= y + 1;n++)
        {        
                if (boomse[m][n] == 1)
                    num++;
        }
    }
    buttons[k]->setText(QString::number(num));
    buttons[k]->con = 1;
    notboom--;
    

    if (num != 0)
        return;
    sweep(x - 1, y - 1);
    sweep(x - 1, y);
    sweep(x - 1, y + 1);
    sweep(x, y - 1);
    sweep(x, y + 1);
    sweep(x + 1, y - 1);
    sweep(x + 1, y);
    sweep(x + 1, y + 1);

}

void mainwin::on_eaaction_triggered()
{
    
    hang = 3;
    lie = 3;
    boom = 1;
    notboom = 8;
    createboard();
    boomset();
}

void mainwin::on_noaction_triggered()
{
    hang = 6;
    lie = 6;
    boom = 5;
    notboom = 31;
    createboard();
    boomset();
}

void mainwin::on_haaction_triggered()
{
    hang = 8;
    lie = 12;
    boom = 10;
    notboom = 86;
    createboard();
    boomset();

}

void mainwin::on_restart_triggered()
{
    switch (hang)
    {
    case 3:
        notboom = 8;
        break;
    case 6:
        notboom = 31;
        break;
    case 8:
        notboom = 86;
        break;
    }
    createboard();
    boomset();
}


void mainwin::onbuttonclicked(int m,int n)
{
  
    int k = (m - 1) * lie + n - 1;
    if (buttons[k]->con == 1 || buttons[k]->con == 2)
        return;
    if (boomse[m][n] == 1)
    {
        ui.tiplabel->setText("boom ");

        
        reveal();

            
    }
    
    else
    {
        sweep(m, n);
        if (notboom == 0)
        {
            ui.tiplabel->setText("victory");
         
            time66= (unsigned int)time(NULL)-time66;
            ui.timelabel->setText(QString::number(time66));
            ui.timelabel->show();
            ui.charlabel->show();
            ui.namelabel->show();
            ui.nameedit->show();
            ui.savebutton->show();
            
        }
        
    }
}

void boombutton::mousePressEvent(QMouseEvent* k)
{
    if (k->button() == Qt::RightButton)
    {
        if (con == 1)
            return;
        if (con == 0)
        {
            setText("*");
            con = 2;
        }
        else if (con == 2)
        {
            setText(" ");
            con = 0;
        }
    }
    else
    {
        QPushButton::mousePressEvent(k);
    }
}

void mainwin::reveal()
{
    for (int i = 0;i < hang * lie;i++)
    {
        if (buttons[i]->con == 1)
            continue;
        if (boomse[i / lie + 1][i % lie + 1] == 0)
            sweep(i / lie + 1, i % lie + 1);
        else
            buttons[i]->setText("B");
    }
}

void mainwin::range()
{
    
    int paiming=0;
    QString username = ui.nameedit->text();
    paihang.resize(5);

    QString timeee;
    QString filename;
    switch (hang) 
    {
    case 3: filename = "33range.txt"; break;
    case 6: filename = "66range.txt"; break;
    case 8: filename = "99range.txt"; break;
    }
    QFile inFile(filename);
    
    inFile.open(QIODevice::ReadOnly | QIODevice::Text);
     
    QTextStream inbang(&inFile);

   

    for (int i = 1;i <= 5;i++)  //读取排行榜，并判断用户排名
    {
       
        inbang >> paihang[i - 1].name >> timeee;
        paihang[i - 1].time2 = timeee.toInt();
       
        if (time66 < paihang[i - 1].time2 && paiming == 0)
        {
           
            paiming = i;
            
        }
    }
    inFile.close();



    if (paiming == 0) //未进入排行榜直接结束
        return;
    
    for (int i = 4;i >= paiming;i--) //进入排行榜，为用户提供位置
    {
        paihang[i] = paihang[i - 1];
    }
    paihang[paiming - 1].name = username;  //写入用户数据
    paihang[paiming - 1].time2 = time66;
    
    QFile outFile(filename);
    outFile.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream outbang(&outFile);
    
    for (int i = 1;i <= 5;i++)   //将新数据写入文件
    {
        
        outbang << paihang[i - 1].name << "    " << paihang[i - 1].time2 <<"\n";
        
    }
    outFile.close();
}

void mainwin::on_savebutton_clicked()
{
    range();
}