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

    //If the immutable part was changed, fix it
    void fixImmutablePart();

	//Representation
    QString immutablePart;

    //Prepend to each line
    static const QString prep;
};
#endif

