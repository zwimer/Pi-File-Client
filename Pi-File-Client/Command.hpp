#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <string>
#include <map>

//--------------------For the user--------------------


//Call this inside a command
//constructor to make it usable
#define ADD_COMMAND(T)					\
	CommandNamespace_##T {				\
	static RegisterCommand<T> a(#T);	\
}


//-----------------For CommandHandler-----------------


//Protect the global namespace
namespace CommandMap {

	//The map that links command names to their execution functions
	std::map<std::string, void (*) (const std::string&)> m;
};


//--------------Used to register commands--------------


//Used to verify that T contains
//a function with the name execute
template<class T> class hasExecute {
public:

	//Prevent instantiation
	hasExecute()=delete;

protected:
	
	//True if T::execute exists, false otherwise
	enum { legalCommand = sizeof(test<T>(nullptr)) == sizeof(ItExists) };

private:

	//Make two sized different types
	class ItExists { char d[2]; }
	typedef char ItDoesNotExist;

	//Use SFINAE to determine if U::execute exists
	template<class U> static ItExists test( decltype(U::execute)* );	
	template<class U> static ItDoesNotExist test( ... );
}



//Used to register commands
template<class T> class RegisterCommand : hasExecute<T> {
public:

	//Constructor	
	RegisterCommand(const std::string s) {

		//Check usage
		static_assert( legalCommand,
		               "T doesn't contain a static function named execute" );

		//Register the command
		commandMap[s] = &T::execute;
	}
};

#endif
