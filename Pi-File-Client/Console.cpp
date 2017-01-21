#include "Console.hpp"


//Initalize variables
const QString Console::prep = tr("> ");

//Constructor
Console::Console(QWidget * parent) :
	QPlainTextEdit(parent) { RUN_ONCE

    //Initalize the text
    setPlainText(imT = prep);

	//Connect signals and slots
    QObject::connect( this, SIGNAL( textChanged() ),
                      this, SLOT( textChangedSlot() ) );
}

//Destructor
Console::~Console() {
	RUN_ONCE
}


//Make top part of console read-only if needed
void Console::textChangedSlot() {

    //Fix imT if needed
    fixImmutableText();

    //Get the current text
    QString s = toPlainText();

    //Determine if a command was entered. If not, return
    int i; for(i = imT.size(); i < s.size(); i++)
        if (s[i] == '\n') break;
    if (i == s.size()) return;

    //If something was entered, update imT
    QStringRef ins( &s, imT.size(), i+1-imT.size());
    imT.append(ins);

    //Process the command ins
//    processCommand(ins);							 TODO: CHANGE

    //Add prep to the new line, and make it immutable
    s.insert(i+1, prep);
    imT.append(prep);
    setPlainText(s);

    //Move the cursor
    auto tmpC = textCursor();
    tmpC.setPosition(imT.size());
    setTextCursor(tmpC);
}

//If the immutable part was changed, fix it
void Console::fixImmutableText() {

    //Get the current text
    QString s = toPlainText();
    int k, i = 0;

    //Determine what remains unchanged
    for(; i < (int) imT.size(); i++)
        if (s[i] != imT[i]) break;

    //Return if nothing changed
    if (i == (int) imT.size()) return;

    //Remove un-necessary text.
    static const QString rm = tr("\n") + prep;
    if ((k = s.lastIndexOf(rm, s.size()-1)) >= i)
        s.remove(i, k+rm.size()-i);
    if ((k = s.lastIndexOf(tr("\n"), s.size()-1)) >= i)
        s.remove(i, k+1-i);

    //Create the string to insert
    QStringRef ins( &imT, i, (int)(imT.size()-i) );

    //Insert the rest of the string and update the console
    s.insert(i, ins);
    setPlainText(s);

    //Move the cursor
    auto tmpC = textCursor();
    tmpC.setPosition(s.size());
    setTextCursor(tmpC);
}

