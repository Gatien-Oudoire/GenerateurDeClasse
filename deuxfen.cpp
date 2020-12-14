#include "deuxfen.h"


deuxFen::deuxFen()
{
    QVBoxLayout *mainLayout = new QVBoxLayout;
    this->texte = new  QTextEdit(QString(""));
    this->fermer = new QPushButton(QString("Fermer"));
    this->texte->setReadOnly(true);
    mainLayout->addWidget(texte);
    mainLayout->addWidget(this->fermer);
    this->setWindowTitle(QString("Résultat"));
    this->setMinimumSize(QSize(300,500));
    this->setLayout(mainLayout);

    connect(this->fermer, SIGNAL(clicked()), this, SLOT(close()));
}

void deuxFen::ajouterTexte(QString a)
{
    this->texte->append(a);
}
