#ifndef HIKARI_HIKARI
#define HIKARI_HIKARI

#include "common.hpp"
#include "configuration.hpp"
#include "repository.hpp"

class Hikari {
 public:
	static int perform_create() {}
	static int perform_inject() {}
	static int perform_search() {}
	static int perform_analyze() {}
	static int perform_list() {}
};

#endif
