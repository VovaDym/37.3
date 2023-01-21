#include <QApplication>
#include <QPushButton>
#include "remContrMainWindow.h"
#include "./ui_remoteController.h"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    RemContrMainWindow window(nullptr);
    Ui::MainWindow remoteController;
    remoteController.setupUi(&window);
    window.resultShow = remoteController.resultShow;
    window.resize(240, 680);
    window.show();
    return QApplication::exec();
}
