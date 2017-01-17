#include "Console.hpp"

//Constructor
Console::Console(QWidget * parent) :
	QPlainTextEdit(parent), numImmutable(0) {

	//Connect signals and slots
	QObject::connect( this, SIGNAL( cursorPositionChanged() ),
	                  this, SLOT( toggleReadOnlyEdit() ) );

}

//Destructor
Console::~Console() {}

//Make top part of console read-only if needed
void Console::toggleReadOnlyEdit() {



	//TODO: delete !!!!!!!!!!!!!!!!
		//Currently makes only last line edit-able
	auto a = toPlainText();
	int i; for(i = a.size()-1; i != 0; i--) if (a[i]=='\n') break;
	numImmutable = i ? i+1 : 0;


	//Toggle read-only if needed
	if ((textCursor().position() < numImmutable) != isReadOnly())
		setReadOnly( ! isReadOnly() );
}
