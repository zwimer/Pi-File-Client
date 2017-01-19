#ifndef CONSOLE_HPP
#define CONSOLE_HPP

#include "main.hpp"

#include <QPlainTextEdit>
#include <QStringRef>

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

private slots:
	
	//Turn on or off read only mode as needed
    void textChangedSlot();

private:

     //If the immutable part was changed, fix it
    void fixImmutableText();

    //Process a line of input
    void processCommand(const QStringRef& s);

    //The immutable text of the console
    QString imT;

    //Prepend to each line
    static const QString prep;
};
#endif

