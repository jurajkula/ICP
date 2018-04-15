#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    scheme(new Scheme(""))

{
    ui->setupUi(this);
    this->setWindowTitle(scheme->getName().data());

    // tvorba scena //
    scene = new GraphicsScene(this->scheme, this);

    //novy graphics view
    QGraphicsView *view = new QGraphicsView(this);
    view->setSceneRect(-300,-300, 300, 300);
    this->resize(600, 600);

    //zobrazenie sceny
    view->setScene(scene);


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
