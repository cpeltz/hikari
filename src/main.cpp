#include "configuration.hpp"
#include "hikari.hpp"
#include "common.hpp"

const unsigned int VERSION_MAJOR = 0;
const unsigned int VERSION_MINOR = 1;
const unsigned int VERSION_PATCH = 0;

int main(int argc, char **argv) {
	Configuration::load(argc, argv);
	std::string action;
	bool success = Configuration::get("action", action);
	if( Configuration::is_set("version") ) {
		std::cout << VERSION_MAJOR << "." << VERSION_MINOR << "." << VERSION_PATCH << std::endl;
	} else if( success && !Configuration::is_set("help") ) {
		if( action == "create" ) {
			return Hikari::perform_create();
		} else if( action == "inject" ) {
			return Hikari::perform_inject();
		} else if( action == "search" ) {
			return Hikari::perform_search();
		} else if( action == "analyze" ) {
			return Hikari::perform_analyze();
		} else if( action == "list" ) {
			return Hikari::perform_list();
		} else {
			std::cout << "You have selected a unknown action." << std::endl;
			std::cout << "Possible actions are: create, inject, search, analyze and list." << std::endl;
		}
	} else {
		Configuration::print_description();
	}
//	Repository repo( "out/", "Teh Awesome Thing");
//	std::cout << repo.name() << " has the UUID " << repo.id().string() << std::endl;
//	repo.create();
//	repo.inject( "data/" );
	return 0;
}
