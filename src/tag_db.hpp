#ifndef HIKARI_TAG_DB
#define HIKARI_TAG_DB

/**
 * Entry in the TagDB.
 */
class Entity {
	/**
	 * The ID of the originating repository.
	 */
	uuid repo_id;
	/**
	 * The original filename before adding it to a repository.
	 * Saved mostly to support undo operations.
	 */
	fs::path oldname;
	/**
	 * The complete path to the file with filename.
	 */
	fs::path filepath;
	/**
	 * The list of all tags associated with this file.
	 * A Tag is a combination of 0 to n Groups and the real tag.
	 * It may look like this: "People:Family:Jessica". Tags may contain
	 * spaces.
	 */
	std::list< std::string > tags;

 public:
	Entity( uuid repo_id, fs::path oldname, fs::path filepath, std::list< std::string > tags );
	~Entity();
};

#endif
