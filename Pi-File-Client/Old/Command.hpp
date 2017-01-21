#ifndef COMMAND_HANDLER_HPP
#define COMMAND_HANDLER_HPP


//A class that command sub-classes
class Cmd {};

//The command class
template<class T> class Command : public Cmd {
public:

	//Constructor
	Command();

	//Run the command
	void execute();

};


//--------------------Template-Meta--------------------


//Call this inside a command
//constructor to make it usable
#define ADD_COMMAND(T)					\
	CommandNamespace_##T {				\
	static RegisterCommand<T> a(#T);	\
}

//A super class of Type2Type
template<class T> struct AType {};

//A class that holds another, 
//but does not instantiate it
template<class T> struct Type2Type : public AType {
	typedef T value;
	T getType();
};

//A class whose sole purpose is to create a
//map of commands to the names of each command
class RegisterCommand {
public:

	//Call to register your command
	RegisterCommand(const std::string s);

	//Make a command of type s
	Cmd * cmdMap(const std::string& s);

private:	


	//Obviously this won't work as Type2Type has many types.
	//Find out how to do this with a tuple

	//A map of command names to command types
	static std::map<std::string, AType> commandMap;
};

//Call to register your command
template<class T> RegisterCommand<T>::RegisterCommand(const std::string s) {
	commandMap[s] = Type2Type<T>();
}

//Make a command of type s
template<class T> Cmd * RegisterCommand<T>::cmdMap(const std::string& s) {
	return new commandMap[s]::value();
}

#endif
