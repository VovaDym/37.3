//
// Created by lebed on 21.01.2023.
//

#ifndef INC_37_3_REMCONTRMAINWINDOW_H
#define INC_37_3_REMCONTRMAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>


class RemContrMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    QLabel* resultShow = nullptr;
    RemContrMainWindow(QWidget* parent = nullptr): QMainWindow(parent){}

    void numberToString (int n, int v)
    {
        QString nStr = QString::number(n);
        QString vStr = QString::number(v);
        resultShow->setText("ch:" + nStr + '\n' + "vol:" + vStr);
    }

public slots:
    void slotNumbers()
    {
        QPushButton* buttonNumbers = dynamic_cast<QPushButton*>(sender());
        n = buttonNumbers->text().toInt();
        numberToString(n,v);
    };

    void slotOperators()
    {
        QPushButton* buttonOperators = dynamic_cast<QPushButton*>(sender());
        opr = buttonOperators->text();
        if(opr == "ch+")
        {
            n++;
            if(n > 9)
            {
                n = 0;
                numberToString(n,v);
            }
            else
            {
                numberToString(n,v);
            }
        }
        else if(opr == "ch-")
        {
            n--;
            if(n < 0)
            {
                n = 9;
                numberToString(n,v);
            }
            else
            {
                numberToString(n,v);
            }
        }
        else if(opr == "vol+")
        {
            v += 10;
            if(v > 100)
            {
                v = 100;
                numberToString(n,v);
            }
            else
            {
                numberToString(n,v);
            }
        }
        else if(opr == "vol-")
        {
            v -= 10;
            if(v < 0)
            {
                v = 0;
                numberToString(n,v);
            }
            else
            {
                numberToString(n,v);
            }
        }
    };
private:
    QString opr;
    int n = 0;
    int v = 0;
};

#endif //INC_37_3_REMCONTRMAINWINDOW_H
