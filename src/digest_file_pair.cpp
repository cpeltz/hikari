#include "digest_file_pair.hpp"

DigestFilePair::DigestFilePair( const DigestFilePair& rhs ) {
	this->_digest = rhs._digest;
	this->_file = rhs._file;
}

DigestFilePair::DigestFilePair( const fs::path file ) {
	this->calculate( file );
}

DigestFilePair::DigestFilePair() { }

void DigestFilePair::calculate( const fs::path file ) {
	fs::ifstream file_stream( file );
	CryptoPP::FileSource fsource( file_stream, true );
	CryptoPP::SHA512 sha;
	byte digest[sha.DigestSize()];
	byte *data = new byte[ fsource.MaxRetrievable() ];
	size_t size = fsource.Get( data, fsource.MaxRetrievable() );
	sha.CalculateDigest( digest, data, size );
	std::stringstream ss;
	for(int i = 0; i < sha.DigestSize(); i++)
		ss << std::hex << std::setw(2) << std::setfill('0') << (int) digest[i];
	delete[] data;
	_digest = ss.str();
	_file = file;
}

std::string DigestFilePair::digest() const {
	return this->_digest;
}

fs::path DigestFilePair::file() const {
	return this->_file;
}
