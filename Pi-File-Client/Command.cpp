#include "Command.hpp"
#include "main.hpp"

//The map that links command names to their execution functions
std::map<std::string, void (*) (const std::string&)> CommandMap::m;

//The list made at compile time that is what m is defined from
Node * CommandMap::staticBuiltM = nullptr;

//A class used to create a primative tree
Node::Node(const std::string s, execType t, Node * n) : key(s), value(t), next(n) {}

//Build m from staticBuiltM
void CommandMap::buildMap() { RUN_ONCE 
	
	//For readability
	Node * & ctm = CommandMap::staticBuiltM;	

	//While there are still items in ctm
	for(Node * tmp = ctm; ctm; ctm = tmp) {

		//Add the item to the m
		m[ctm->key] = ctm->value;
			
		//Prevent leaks
		tmp = ctm->next;
		delete ctm;
	}
}
