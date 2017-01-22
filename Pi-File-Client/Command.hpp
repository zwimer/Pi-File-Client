#ifndef COMMAND_HPP
#define COMMAND_HPP

#include <string>
#include <map>


//-------------------------For the user-------------------------


/* How to make a command: 
 * 
 * 1) Create a class representing your command.
 *
 * 2) Said class must define: static void execute(const std::string&);
 *
 * 3) In the class' cpp file run ADD_COMMAND(<Your class>), replacing
 *    <Your class> with the name of your class (without quotes)
 *
 */

//Call this inside a command's cpp file
//to register the command as a usable command
#define ADD_COMMAND(T)                              \
namespace CommandNamespace {                        \
    static RegisterCommand<class T> reg##T(#T);     \
}


//----------------------For CommandHandler----------------------


//For clarity
typedef void (*execType) (const std::string&);

//A class used to create a primative tree
struct Node {

	//Constructor
	Node() = delete;
	Node(const std::string, execType, Node*);

	//Representation
	const std::string key;
	execType value;
	Node * next;
};

//Protect the global namespace
namespace CommandMap {

	/* The reason staticBuiltM exists instead of just having
	 * m be built statically is because m must be initalized
	 * with a constructor, which occurs in the dynamic phase
	 * of non-local variable initalization. This means it's
	 * construction occurs at the same time it's population
	 * does. Since elements of this phase are created in an
	 * arbiturary order, it is possible an element may be 
	 * added to m before m is constructed. Thus we used
	 * staticBuiltM which is initalized earlier and build
	 * m from that early on in main.cpp 
	 */

	//The map that links command names to their execution functions
	extern std::map<std::string, execType> m;

	//Has zero initialization (before static initalization)
	//m is build using the data stored in this
	extern Node * staticBuiltM;

	//A function called once to build m
	void buildMap();
};


//-------------------Used to register commands-------------------


//Used to verify that T contains
//a function with the name execute
template<class T> class hasExecute {

	//Make two sized different types
	class ItExists { char d[2]; };
	typedef char ItDoesNotExist;

	//Use SFINAE to determine if U::execute exists
	template<class U> static ItExists test( decltype(U::execute)* );	
	template<class U> static ItDoesNotExist test( ... );

public:

	//Prevent instantiation
	hasExecute()=delete;

	//True if T::execute exists, false otherwise
	enum { legalCommand = sizeof(test<T>(nullptr)) == sizeof(ItExists) };
};


//Used to register commands
template<class T> class RegisterCommand {
public:

	//Constructor	
	RegisterCommand(const std::string s) {

		//Check usage
		static_assert( hasExecute<T>::legalCommand,
		               "T doesn't contain a public static function named execute" );

		//Register the command
		CommandMap::staticBuiltM = new Node(s, &T::execute, CommandMap::staticBuiltM);
	}
};

#endif
