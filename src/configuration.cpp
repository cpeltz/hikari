#include "configuration.hpp"

void Configuration::load(int argc, char **argv) {
	po::options_description action_general("General options");
	action_general.add_options()
		("help", "prints help messages.")
		("version", "prints software version information.")
		("name", po::value< std::vector<std::string> >(), "Specifies the repositories to work upon by name")
		("base-directory", po::value< std::vector<std::string> >(), "Specifies the base directory of a repository, if no --name or --uuid is given")
		("uuid", po::value< std::vector<std::string> >(), "UUID of the repositories in which should be inserted. (Not with create).")
		;

	po::options_description action_search("Search options");
	action_search.add_options()
		("include-and", po::value< std::vector<std::string> >(), "1 to n Tags which a result should all have.")
		("exclude-and", po::value< std::vector<std::string> >(), "1 to n Tags which a result should all not have.")
		("include-or", po::value< std::vector<std::string> >(), "1 to n Tags which a result should have any one of.")
		("exclude-or", po::value< std::vector<std::string> >(), "1 to n Tags which a result shouldn't have any one of.")
		;

	po::options_description hidden("Hidden options");
	hidden.add_options()
		("action", po::value< std::string >(), "Specifies the action which should be performed.")
		;

	all.add(action_general).add(action_search).add(hidden);
	visible.add(action_general).add(action_search);
	po::positional_options_description pd; pd.add("action", 1);
	po::store( po::command_line_parser(argc, argv).options(all).positional(pd).run(), vm );
	po::notify( vm ); // do not need that yet but later maybe
	// Parse the commandline
	// read the config file
	// merge both
}

bool Configuration::is_set(const std::string& key) {
	if( vm.count( key ) ) {
		return true;
	}
	return false;
}

void Configuration::print_description() {
	std::cout << visible;
}

po::variables_map Configuration::vm;
po::options_description Configuration::visible("Allowed options"), Configuration::all("Allowed options");
