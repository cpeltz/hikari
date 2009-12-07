#ifndef HIKARI_CONFIGURATION
#define HIKARI_CONFIGURATION

#include <boost/program_options.hpp>
#include "common.hpp"

namespace po = boost::program_options;

class Configuration {
	static po::variables_map vm;
	static po::options_description visible, all;

	Configuration();
	Configuration(const Configuration&);

 public:
	static void load(int argc, char **argv);

	template<class T> static bool get(const std::string& key, T& value) {
		if( vm.count( key ) ) {
			value = vm[key].as< T >();
			return true;
		}
		return false;
	}


	static bool is_set(const std::string& key);

	static void print_description();
};

#endif
