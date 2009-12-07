#ifndef HIKARI_REPOSITORY
#define HIKARI_REPOSITORY

#include "common.hpp"

// C++ Wrapper for the OSSP UUID library used in Repository
#include <ossp/uuid++.hh>

/**
 * A repository is a file and directory tree that is used to save
 * the files with hashes as their names in specific sub-directories.
 */
class Repository {
	/**
	 * Path to repository, with directory name of the repository,
	 * as the repository name and the actual directory do not
	 * have to be the same.
	 */
	fs::path path_to_repository;
	/**
	 * The unique ID for this repository.
	 */
	uuid repo_id;
	/**
	 * The display name of this particular repository.
	 */
	std::string repo_name;

 public:
	Repository( const fs::path& path, const std::string& name );

	/**
	 * Used to create a repository object from a string.
	 */
	Repository( const std::string& repo_line );

	fs::path path();

	uuid id();

	std::string name();

	void name( const std::string& new_name );

	Repository& create();

	Repository& inject( const fs::path& base_directory );
};

#endif
