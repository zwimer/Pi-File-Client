#ifndef CONSOLE_HPP
#define CONSOLE_HPP

#include "main.hpp"

#include <QPlainTextEdit>

//A class that transforms a
//QPlainTextEdit into a console
class Console : public QPlainTextEdit {
	Q_OBJECT
public:

	//Constructor
	Console()=delete;
	Console(QWidget * parent);
	
	//Destructor
	~Console();

public slots:
	
	//Turn on or off read only mode as needed
	void toggleReadOnlyEdit();

private:

	//Representation
	int numImmutable;
};
#endif

