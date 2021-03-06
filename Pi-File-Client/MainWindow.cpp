#include "MainWindow.hpp"
#include "ui_mainwindow.h"
#include "Console.hpp"
#include "main.hpp"

#include <QVBoxLayout>
#include <QHBoxLayout>

//Constructor
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), 
	ui(new Ui::MainWindow), con(new Console(parent)) { RUN_ONCE

	//Set up the ui
	ui->setupUi(this);

	//Initalize the console
	con->setObjectName(QStringLiteral("QplainTextEdit"));
	con->setGeometry(QRect(10, 10, 361, 481));

	//Define local variables
	QVBoxLayout * subL = new QVBoxLayout;
	QHBoxLayout * layout = new QHBoxLayout;
	QWidget * subC = new QWidget(ui->centralWidget);
	QSplitter * subS = new QSplitter(ui->centralWidget);
	QSplitter * main = new QSplitter(ui->centralWidget);

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
	main->addWidget(con);
	main->addWidget(subC);

	//Make this centralWidget's layout
	layout->addWidget(main);
	ui->centralWidget->setLayout(layout);
}

//Destructor
MainWindow::~MainWindow() { RUN_ONCE
	delete ui;
}


void MainWindow::processCommand(const QStringRef& s) {


    //TODO

}
