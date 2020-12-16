#include "premfen.h"
#include "deuxfen.h"
#include "ui_premfen.h"

premFen::premFen() : QWidget()

{
    QVBoxLayout *mainLayout = new QVBoxLayout();
    this->setWindowTitle("Générateur de classes C++");
    this->setWindowIcon(QIcon("logo.svg"));

    // Principal
    QGroupBox *boxInfos = new QGroupBox("Principal");
    this->nom = new QLineEdit;
    this->parent = new QLineEdit;
    QFormLayout *layoutInfos = new QFormLayout;
    layoutInfos->addRow("Nom:", nom);
    layoutInfos->addRow("Classe mère", parent);
    boxInfos->setLayout(layoutInfos);

    // Options
    QGroupBox *boxOptions = new QGroupBox("Options");
    QVBoxLayout *layoutOptions = new QVBoxLayout;
    this->headerProtect = new QCheckBox(QString("Protéger le header contre les inclusions multiples"));
    this->headerProtect->setChecked(true);
    this->constructeur = new QCheckBox(QString("Générer un constructeur par défaut"));
    this->destructeur = new QCheckBox(QString("Générer un destructeur par défaut"));
    layoutOptions->addWidget(headerProtect);
    layoutOptions->addWidget(constructeur);
    layoutOptions->addWidget(destructeur);
    boxOptions->setLayout(layoutOptions);

    // Commentaires
    QGroupBox *boxCommentaires = new QGroupBox("Commentaires");
    QFormLayout *layoutCommentaires = new QFormLayout();
    this->auteur = new QLineEdit();
    this->date = new QDateEdit();
    date->setDate(QDate::currentDate());
    this->texte = new QTextEdit();
    layoutCommentaires->addRow("Auteur:", auteur);
    layoutCommentaires->addRow("Date:", date);
    layoutCommentaires->addRow("Role de la classe:", texte);
    boxCommentaires->setLayout(layoutCommentaires);
    boxCommentaires->setCheckable(true);
    boxCommentaires->setChecked(false);

    // Bouttons
    QHBoxLayout *layoutBouttons = new QHBoxLayout;
    this->generer = new QPushButton(QString("Générer !"));
    this->quitter = new QPushButton(QString("Quitter"));
    layoutBouttons->addWidget(generer);
    layoutBouttons->addWidget(quitter);

    // Fenetre
    mainLayout->addWidget(boxInfos);
    mainLayout->addWidget(boxOptions);
    mainLayout->addWidget(boxCommentaires);
    mainLayout->addLayout(layoutBouttons);
    this->setLayout(mainLayout);
    this->setMinimumSize(QSize(700,600));

    // Slots et signaux
    connect(this->quitter, SIGNAL(clicked()), qApp, SLOT(quit()));
    connect(this->generer, SIGNAL(clicked()), this, SLOT(afficherResultat()));

}

void premFen::afficherResultat()
{
    if (this->nom->text().isEmpty())
    {
        QMessageBox::critical(this, QString("Erreur: taille de nom"), QString("Vous devez au minimum donner un nom à votre classe"));
        return;
    }
    QString resultat;
    deuxFen *fen2 = new deuxFen();
    if (this->headerProtect->isChecked())
    {
        resultat = "#ifndef " + this->nom->text() + "_H";
        fen2->ajouterTexte(resultat);
        resultat = "#define " + this->nom->text() + "_H";
        fen2->ajouterTexte(resultat);
    }
    if (this->boxCommentaires->isChecked())
    {
        fen2->ajouterTexte("/*"),
        fen2->ajouterTexte(this->date->text());
        resultat = "Auteur: ";
        if (this->auteur->text().isEmpty())
        {
            resultat += "Anonyme";
        }
        else {
            resultat += this->auteur->text();
        }
        fen2->ajouterTexte(resultat);
        if (!this->texte->toPlainText().isEmpty())
        {
            fen2->ajouterTexte(QString("Description:"));
            fen2->ajouterTexte(this->texte->toPlainText());
        }
        fen2->ajouterTexte("*/");
    }
    if (this->parent->text().isEmpty())
    {
    resultat = "class " + this->nom->text();
    }
    else
    {
        resultat = "class " + this->nom->text() + ": public " + this->parent->text();
    }
    fen2->ajouterTexte(resultat);
    fen2->ajouterTexte("{");
    fen2->ajouterTexte("public:");
    if (this->constructeur->isChecked())
    {
    resultat = "    " + this->nom->text() + "();";
    fen2->ajouterTexte(resultat);
    }
    if (this->destructeur->isChecked())
    {
    resultat = "    ~" + this->nom->text() + "();";
    fen2->ajouterTexte(resultat);
    }
    fen2->ajouterTexte("");
    fen2->ajouterTexte("protected:");
    fen2->ajouterTexte("");
    fen2->ajouterTexte("private:");
    fen2->ajouterTexte("}");

    fen2->ajouterTexte(QString(" "));
    if (this->headerProtect->isChecked())
        fen2->ajouterTexte(QString("#endif"));
    fen2->show();

}

premFen::~premFen(){}
