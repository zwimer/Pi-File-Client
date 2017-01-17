#include "MainWindow.hpp"
#include "main.hpp"

#include <QApplication>


//A function used if an assert fails
void Err(const char *s) {
	std::cout << "Error " << s << std::endl;
	perror("Perror"); exit(EXIT_FAILURE);
}

//A function used to test assertions
void Assert(bool b, const char *s) { if (!b) Err(s); }


//The main function
int main(int argc, char *argv[]) {

	//Make the application
	QApplication a(argc, argv);
	MainWindow w;
	w.show();

	//Run the application
	return a.exec();
}
