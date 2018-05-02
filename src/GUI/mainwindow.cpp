/* Autori : Juraj Kula <xkulaj02>
 *          Michal Vasko <xvasko14>
 * Popis: Modul pre hlavné okno aplikácie
*/

#include "mainwindow.h"
#include "mainwindowtools.h"


MainWindow::MainWindow(std::string name, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    scheme(new Scheme(name))

{
    ui->setupUi(this);
    this->setWindowTitle(scheme->getName().data());
    QVBoxLayout *layout = new QVBoxLayout();
    QWidget *wrapper = new QWidget();

    // tvorba scena //
    scene = new GraphicsScene(this->scheme, this);

    //novy graphics view
    GraphicsView *view = new GraphicsView();
    view->setSceneRect(-300,-300, 300, 300);
    this->resize(600, 600);

    //zobrazenie sceny
    view->setScene(scene);

    mainWindowTools *tools = new mainWindowTools(scheme, scene);

    layout->setMenuBar(tools);
    layout->addWidget(view);

    wrapper->setLayout(layout);
    this->setCentralWidget(wrapper);
}

MainWindow::~MainWindow()
{
    delete ui;
}

Ui::MainWindow *MainWindow::getUI() {
    return this->ui;
}

QGraphicsScene *MainWindow::getScene()
{
    return this->scene;
}

Scheme *MainWindow::getScheme()
{
    return this->scheme;
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



void MainWindow::on_actionLoad_2_triggered()
{
        QString filename=QFileDialog::getOpenFileName(
                    this,
                    tr("Open File"),
                    "../example",
                    "ICP file (*.icp);;All Files(*)"
                    );

        //QMessageBox::information(this,tr("File Name"),filename);

        if (filename.isEmpty())
            return;

        QFile file(filename);
        Load l(&file);

        //TODO delete all
        this->close();
}


void MainWindow::on_actionSave_2_triggered()
{
    QString filter = "ICP file (*.icp)";
    QString filename=QFileDialog::getSaveFileName(
                this,
                tr("Save File"),
                "../example",
                filter
                );

    if (filename.isEmpty())
        return;

    if(!filename.endsWith(".icp"))
        filename += ".icp";

    QFile file(filename);
    Save s(this->scheme, this->scene, &file);
}

PortNode *MainWindow::getPortNodeByPortUniqueID(int id) {
    for (QGraphicsItem *item : this->scene->items()) {
        PortNode *p = qgraphicsitem_cast<PortNode *>(item);
        if(!p)
            continue;

        if (p->getLogicPort()->getUniqueID() == id)
            return p;
    }
    return nullptr;
}
