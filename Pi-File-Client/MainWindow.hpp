#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QSplitter>


//Forward declarations
class Console;

//Auto-generated
namespace Ui {
	class MainWindow;
}

//The main window
class MainWindow : public QMainWindow{
	Q_OBJECT
public:

	//Constructor: prevent implicit conversion
	explicit MainWindow(QWidget *parent = 0);

	//Destructor
	~MainWindow();

private:

	//Representation
	Ui::MainWindow *ui;
	Console * con;

};

#endif // MAINWINDOW_HPP
