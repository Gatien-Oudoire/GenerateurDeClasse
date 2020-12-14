#include "premfen.h"
#include "deuxfen.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    premFen fen1;
    fen1.show();
    return app.exec();
}
