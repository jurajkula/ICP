#include "createblock.h"

createBlock::createBlock(Scheme *s, QGraphicsScene *scene, QPointF pos, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::createBlock)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
    this->scene = scene;
    this->pos = pos;
    this->scheme = s;

    QVBoxLayout *layout = new QVBoxLayout();
    QVBoxLayout *mathTabLayout = new QVBoxLayout();

    ui->scrollAreaWidgetContents->setLayout(layout);
    ui->scrollAreaWidgetContents_2->setLayout(mathTabLayout);

    // PORT TAB
    portToolBox *pTB = new portToolBox();
    portAddForm *pAF = new portAddForm(layout, &portPages, &portForms, pTB);

    portPage *w = new portPage(&portPages, pTB);
    portPages.push_back(w);

    pTB->addItem(w,"Port");
    layout->addWidget(pTB);
    layout->addWidget(pAF);

    // *********************************

    // MATH TAB
    mathAddSchemaForm *mAddForm = new mathAddSchemaForm(mathTabLayout, &mathForms);
    mathSchemaForm *mForm = new mathSchemaForm(mathTabLayout, &mathForms);

    mathForms.push_back(mForm);
    mathTabLayout->addWidget(mForm);

    mathTabLayout->addWidget(mAddForm);
    // *********************************
}

createBlock::~createBlock()
{
    delete ui;
}

void createBlock::accept() {}

void createBlock::setErrorMessage(std::string s) {
    this->ui->errorMessage->setText(QString::fromStdString(s));
}

void createBlock::on_buttonBox_accepted()
{
    for (portPage *page : portPages) {
        QComboBox *cBox = page->getPortForm()->GetUI()->io;
        port *p;
        if (cBox->currentText() == "Input")
            p = new port(INPUT);
        else
            p = new port (OUTPUT);

        for (portDataForm *data : page->getPortDataForms()) {
            if (data->GetUI()->name->text().isEmpty()) {
                p->clearData();
                this->setErrorMessage("Not correct data name");
                return;
            }

            p->addData(CreateData(data->GetUI()->name->text().toStdString(), data->GetUI()->value->text().toDouble()));
        }
        this->ports.push_back(p);
    }

    if (ports.empty()) {
        this->setErrorMessage("Not found any port!");
        return;
    }

    bool found = false;
    for (port *p : ports) {
        if (p->getStatus() == INPUT) {
            found = true;
            break;
        }
    }
    if (!found) {
        this->setErrorMessage("Not found any input port");
        this->ports.clear();
        return;
    }

    found = false;
    for (port *p : ports) {
        if (p->getStatus() == OUTPUT) {
            found = true;
            break;
        }
    }
    if (!found) {
        this->setErrorMessage("Not found any output port");
        this->ports.clear();
        return;
    }


    for (mathSchemaForm *mathForm : mathForms) {
        if (mathForm->getUI()->mathOutput->text().isEmpty()) {
            this->setErrorMessage("Not correct math schema output");
            return;
        }
        if (!checkMathSyntax(mathForm->getUI()->mathSchema->text().toStdString() + "\n")) {
            this->setErrorMessage("Not correct math schema");
            return;
        }

        // TODO check semantics

        rule r;
        r.output = mathForm->getUI()->mathOutput->text().toStdString();
        r.tokens = splitStringFormula(mathForm->getUI()->mathSchema->text().toStdString() + "\n");

        rules.push_back(r);
    }

    // Create block + create graphics represent of block + create gui of ports
    this->done(QDialog::Accepted);
}

void createBlock::on_buttonBox_rejected()
{
    this->close();
}
