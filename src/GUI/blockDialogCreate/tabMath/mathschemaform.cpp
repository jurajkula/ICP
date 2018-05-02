/* Autori : Juraj Kula <xkulaj02>
 *          Michal Vasko <xvasko14>
 * Popis: Modul pre vzorcovú stránku
*/

#include "mathschemaform.h"


mathSchemaForm::mathSchemaForm(QVBoxLayout *layout, std::vector<mathSchemaForm *> *mathForms, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mathSchemaForm)
{
    ui->setupUi(this);
    this->setFixedSize(this->size());
    this->layout = layout;
    this->mathForms = mathForms;

    if (mathForms->size() == 0) {
        this->ui->destroySchema->hide();
    }

    QRegExp rx("[a-zA-Z][a-zA-z0-9]*");
    this->ui->mathOutput->setValidator(new QRegExpValidator(rx, this));
}

mathSchemaForm::~mathSchemaForm()
{
    delete ui;
}

void mathSchemaForm::showButton() {
    this->ui->destroySchema->show();
}

Ui::mathSchemaForm *mathSchemaForm::getUI() {
    return this->ui;
}

void mathSchemaForm::on_destroySchema_clicked()
{
    if (mathForms->size() == 1) {
        return;
    }

    for (unsigned int i = 0; i < mathForms->size(); i++) {
        if (this == mathForms->at(i)){
            mathForms->erase(mathForms->begin() + i);
        }
    }

    if (mathForms->size() == 1) {
        mathForms->back()->ui->destroySchema->hide();
    }

    layout->removeWidget(this);
    this->close();
}

void mathSchemaForm::on_mathSchema_editingFinished()
{
    if (checkMathSyntax(this->ui->mathSchema->text().toStdString() + "\n")) {
        this->ui->mathSchema->setStyleSheet("QLineEdit {color: black;}");
    }
    else {
        this->ui->mathSchema->setStyleSheet("QLineEdit {color: red;}");
    }
}
