#ifndef PREMFEN_H
#define PREMFEN_H

#include <QHBoxLayout>
#include <QFormLayout>
#include <QVBoxLayout>

#include <QWidget>
#include <QPushButton>
#include <QGroupBox>
#include <QLineEdit>
#include <QTextEdit>
#include <QCheckBox>
#include <QDateEdit>
#include <QMessageBox>


class premFen : public QWidget
{
    Q_OBJECT

public:
    premFen();
    ~premFen();

private slots:
    void afficherResultat();

private:
    QLineEdit *nom;
    QLineEdit *parent;
    QCheckBox *headerProtect;
    QCheckBox *constructeur;
    QCheckBox *destructeur;
    QLineEdit *auteur;
    QDateEdit *date;
    QTextEdit *texte;
    QPushButton *generer;
    QPushButton *quitter;
};
#endif // PREMFEN_H
