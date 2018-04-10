#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>
#include "form.h"
#include <QMessageBox>
#include <QDebug>
#include <QToolBar>
#include <QGraphicsItem>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <graphics.h>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // tvorba scena //
    scene = new GraphicsScene(this);
    //novy graphics view
    QGraphicsView *view = new QGraphicsView(this);
    view->setSceneRect(-300,-300, 300, 300);
    this->resize(600, 600);

    //zobrazenie sceny
    view->setScene(scene);

    //tvorba stvroca
    QBrush redBrush(Qt::red);
    QPen blackpen(Qt::black);
    blackpen.setWidth(1);
    rectangle = scene->addRect(10,10,100,100,blackpen,redBrush);
    rectangle->setFlag(QGraphicsItem::ItemIsMovable);

 this->setCentralWidget(view);
}

MainWindow::~MainWindow()
{
    delete ui;
}


//vypnutie hry
void MainWindow::on_actionQuit_2_triggered()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this,"Quit","Do you want to quit the game?",
                          QMessageBox::Yes | QMessageBox::No);
   if(reply == QMessageBox::Yes) {
   QApplication::quit();
   }
   else {
   qDebug() << "No is clicked";
   }
}

//tutorial
void MainWindow::on_actionTutorial_triggered()
{
    QMessageBox::about(this,"Tutorial","Program ktory sa zaobera skladanim blokovych schem");
}
