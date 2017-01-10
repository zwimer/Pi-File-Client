#include "MainWindow.hpp"
#include "ui_mainwindow.h"
#include "main.hpp"

#include <QVBoxLayout>
#include <QHBoxLayout>

//Constructor
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) { RUN_ONCE

    //Set up the ui
    ui->setupUi(this);

    //Define local variables
    QWidget * subC = new QWidget(ui->centralWidget);
    QSplitter * subS = new QSplitter(ui->centralWidget);
    QSplitter * main = new QSplitter(ui->centralWidget);
    QVBoxLayout * subL = new QVBoxLayout(ui->centralWidget);
    QHBoxLayout * layout = new QHBoxLayout(ui->centralWidget);

    //Define orientations
    subS->setOrientation(Qt::Vertical);
    main->setOrientation(Qt::Horizontal);

    //Add lists to the right splitter
    subS->addWidget(ui->listWidget);
    subS->addWidget(ui->listWidget_2);

    //Put the splitter into a widget
    subL->addWidget(subS);
    subC->setLayout(subL);

    //Add the text interface and split
    //widget made above to the main splitter
    main->addWidget(ui->plainTextEdit);
    main->addWidget(subC);

    //Make this centralWidget's layout
    layout->addWidget(main);
    ui->centralWidget->setLayout(layout);
}

//Destructor
MainWindow::~MainWindow() {
    delete ui;
}
