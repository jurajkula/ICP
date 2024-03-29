/* Autori : Juraj Kula <xkulaj02>
 *          Michal Vasko <xvasko14>
 * Popis: Modul pre port stránku
*/

#include "portpage.h"

portPage::portPage(std::vector<portPage *> *portPages, portToolBox *b, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::portPage)
{
    ui->setupUi(this);

    QVBoxLayout *l = new QVBoxLayout();
    this->setLayout(l);
    this->box = b;
    this->portPages = portPages;

    portAddDataForm *pADF = new portAddDataForm(l, &portDataForms);

    pF = new portForm(b, this);

    l->addWidget(pF);

    portDataForm *pDF = new portDataForm(l, &portDataForms);
    l->addWidget(pDF);
    l->addWidget(pADF);
    portDataForms.push_back(pDF);

    QObject::connect(pF->GetUI()->pushButton, SIGNAL(clicked()), this, SLOT(destroy_page()));
}

portPage::portPage(std::vector<portPage *> *portPages, portToolBox *b, port *p, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::portPage)
{
    ui->setupUi(this);

    QVBoxLayout *l = new QVBoxLayout();
    this->setLayout(l);
    this->box = b;
    this->portPages = portPages;

    portAddDataForm *pADF = new portAddDataForm(l, &portDataForms);

    pF = new portForm(b, this);
    pF->GetUI()->io->setCurrentIndex(p->getStatus());
    l->addWidget(pF);

    portDataForm *pDF;

    for(pData *d : p->getData()) {
        pDF = new portDataForm(l, &portDataForms);
        pDF->GetUI()->name->setText(QString::fromStdString(d->name));
        pDF->GetUI()->value->setText(QString::number(d->value));
        l->addWidget(pDF);
    }

    l->addWidget(pADF);
    portDataForms.push_back(pDF);

    QObject::connect(pF->GetUI()->pushButton, SIGNAL(clicked()), this, SLOT(destroy_page()));
}


void portPage::destroy_page() {

    for (unsigned int i = 0; i < portPages->size(); i++) {
        if (this == portPages->at(i)){
            portPages->erase(portPages->begin() + i);
        }
    }

    box->removeItem(box->indexOf(this));
    this->close();

}

portPage::~portPage()
{
    delete ui;
}

std::vector<portDataForm *> portPage::getPortDataForms(){
    return this->portDataForms;
}

Ui::portPage * portPage::getUi() {
    return this->ui;
}

portForm * portPage::getPortForm() {
    return this->pF;
}
