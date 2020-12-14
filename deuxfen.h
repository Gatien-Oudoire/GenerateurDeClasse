#ifndef DEUXFEN_H
#define DEUXFEN_H

#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QTextEdit>
#include <QPushButton>

class deuxFen : public QWidget
{

public:
    deuxFen();
    void ajouterTexte(QString a);

private:
    QTextEdit *texte;
    QPushButton *fermer;


};

#endif // DEUXFEN_H
