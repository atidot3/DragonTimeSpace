#include "DBTaSLTool.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DBTaSLTool w;
    w.show();
    return a.exec();
}
