//TODO delete this file
#include "Command.hpp"
#include <iostream>
#include <stdlib.h>

//TODO move this to command.cpp
//TODO use default initalizer
std::map<std::string, void (*) (const std::string&)> CommandMap::m = {{"Test", nullptr}};

struct a { static void execute(const std::string&) { std::cout << "a" << std::endl; } };
ADD_COMMAND(a);

using namespace CommandMap;
int main() {

	m["a"]("");

	return 0;
}
