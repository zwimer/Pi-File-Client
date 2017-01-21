#include <CommandHandler.hpp>


//Constructor
template<class T> Command<T>::Command {};

//Run the command
template<class T> Command<T>::execute() {

	//Cast this to it's subclass
	T * thisSub = static_cast<T*> (this); 
	Assert(thisSub, "Error, unable to cast Command<T>* to T*");

	//Run the command
	thisSub->execute();
}
