#include <QCoreApplication>
#include "helloworld.h"


int main(int argc, char **argv)
{
    QCoreApplication app(argc, argv);
    HelloWorld hello;
    app.exec();
}
