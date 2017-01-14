#include "Console.hpp"

//Constructor
Console::Console(QWidget * parent) :
	QPlainTextEdit(parent), numImmutable(0) { RUN_ONCE

	//Connect signals and slots
	QObject::connect( this, SIGNAL( cursorPositionChanged() ), 
                      this, SLOT( toggleReadOnlyEdit() ) );

}

//Destructor
Console::~Console() {
	RUN_ONCE
}

#include <QDebug>
//Make top part of console read-only if needed
void Console::toggleReadOnlyEdit() {
    if ((textCursor().position() < numImmutable) != isReadOnly())
        setReadOnly( ! isReadOnly() );

    qDebug() << "Hi";

}
