#include "Console.hpp"

#include <QStringRef>

//Initalize variables
const QString Console::prep = tr("> ");

//Constructor
Console::Console(QWidget * parent) : QPlainTextEdit(parent) {

    //Initalize the text
    immutablePart = prep + tr("Dasdasdas\n> asdfadsfd\n> ");
    setPlainText(immutablePart);

	//Connect signals and slots
    QObject::connect( this, SIGNAL( textChanged() ),
	                  this, SLOT( toggleReadOnlyEdit() ) );
}

//Destructor
Console::~Console() {}


//If the immutable part was changed, fix it
void Console::fixImmutablePart() {

    //Get the current text
    QString s = toPlainText();
    int k, i = 0;

    //Determine what remains unchanged
    for(; i < (int) immutablePart.size(); i++)
        if (s[i] != immutablePart[i]) break;

    //Return if nothing changed
    if (i == (int) immutablePart.size()) return;

    //Remove un-necessary text.
    static const QString rm = tr("\n") + prep;
    if ((k = s.lastIndexOf(rm, s.size()-1)) >= i)
        s.remove(i, k+rm.size()-i);
    if ((k = s.lastIndexOf(tr("\n"), s.size()-1)) >= i)
        s.remove(k-1, k+1-i);

    //Create the string to insert
    QStringRef ins( &immutablePart, i, (int)(immutablePart.size()-i) );

    //Insert the rest of the string and update the console
    s.insert(i, ins);
    setPlainText(s);

    //Move the cursor
    auto tmpC = textCursor();
    tmpC.setPosition(immutablePart.size());
    setTextCursor(tmpC);
}

//Make top part of console read-only if needed
void Console::toggleReadOnlyEdit() {

    //Fix immutablePart if needed
    fixImmutablePart();

    //For efficiency
    static const QString cmp = tr("\n") + prep;
    QString a = toPlainText();
}
