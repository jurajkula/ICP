#include "mainwindowtools.h"

mainWindowTools::mainWindowTools(Scheme *scheme, QGraphicsScene *scene, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainWindowTools)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
    this->scene = scene;
    this->scheme = scheme;

    QHBoxLayout *layout = new QHBoxLayout();

    QPushButton *run = new QPushButton("RUN");
    QPushButton *debug = new QPushButton("DEBUG");
    QPushButton *next = new QPushButton("NEXT");
    QPushButton *stop = new QPushButton("STOP");

    run->setMinimumHeight(this->height() - 5);
    debug->setMinimumHeight(this->height() - 5);
    next->setMinimumHeight(this->height() - 5);
    stop->setMinimumHeight(this->height() - 5);


    layout->addWidget(run);
    layout->addWidget(debug);
    layout->addWidget(next);
    layout->addWidget(stop);

    this->setLayout(layout);

    QObject::connect(run, SIGNAL(clicked()), this, SLOT(RUN_clicked()));
    QObject::connect(debug, SIGNAL(clicked()), this, SLOT(DEBUG_clicked()));
    QObject::connect(next, SIGNAL(clicked()), this, SLOT(NEXT_clicked()));
    QObject::connect(stop, SIGNAL(clicked()), this, SLOT(STOP_clicked()));
}

mainWindowTools::~mainWindowTools()
{
    delete ui;
}

QPushButton *mainWindowTools::getRun()
{
    return this->run;
}

QPushButton *mainWindowTools::getDebug()
{
    return this->debug;
}

QPushButton *mainWindowTools::getNext()
{
    return this->next;
}

QPushButton *mainWindowTools::getStop()
{
    return this->stop;
}

void mainWindowTools::RUN_clicked() {
    qDebug("RUN");
    scheme->compute();
}

void mainWindowTools::DEBUG_clicked() {
    qDebug("DEBUG");
}

void mainWindowTools::NEXT_clicked() {
    qDebug("NEXT");
}

void mainWindowTools::STOP_clicked() {
    qDebug("STOP");
}
