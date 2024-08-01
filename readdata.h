#ifndef READDATA_H
#define READDATA_H
#include <QWidget>
#include <QPushButton>
#include <QString>
#include <QStringList>
#include <QDebug>
#include "mainwindow.h";
#include <QApplication>
#include <QWidget>
#include <QApplication>
#include <QWidget>
#include <QResizeEvent>
#include <QLabel>
#include <QPixmap>
#include <QProcess>
#include "kompilator.h"
#include "reqw.h"
#include "reqwaest.h"
#include <QVBoxLayout>
#include <QScrollBar>
#include <QScrollArea>
#include <QComboBox>
QT_BEGIN_NAMESPACE
namespace Ui { class Read; }
QT_END_NAMESPACE
class Read: public QMainWindow
{
Q_OBJECT
public:
    Read(QString speek="settings.o",QWidget *parent = 0);
    ~Read();
    QLabel *label;
    Ui::MainWindow *ui;
private slots:
    void readfrom();
    void displayFileContent(const QString &filename);
    void onButton1Clicked();
private:
    QString data1;
    QString choose;
    QComboBox* box;
    QPushButton *savetotxt;
};

#endif // READDATA_H
