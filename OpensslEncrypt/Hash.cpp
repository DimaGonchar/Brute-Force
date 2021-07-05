#include"Hash.h"
#include<iostream>
#include <openssl/sha.h>
#include"WriteFile.h"

void CalculateHash(const std::vector<unsigned char>& data, std::vector<unsigned char>& hash)
{
	std::vector<unsigned char> hashTmp(SHA256_DIGEST_LENGTH);

	SHA256_CTX sha256;
	SHA256_Init(&sha256);
	SHA256_Update(&sha256, &data[0], data.size());
	SHA256_Final(&hashTmp[0], &sha256);

	hash.swap(hashTmp);
}

void ExtractHash(std::vector<unsigned char>& hashBuf, std::vector<unsigned char>& buf) {

	hashBuf.clear();
	for (size_t i = SHA256_DIGEST_LENGTH; i > 0; --i) {
		hashBuf.push_back(buf[buf.size() - i]);
	}
}

bool CompareHash(const std::string& filePath, std::vector<unsigned char>& sourceHash, std::vector<unsigned char>& decryptedText, const std::string& pass)
{
	std::vector<unsigned char> hash;
	CalculateHash(decryptedText, hash);
	if (hash == sourceHash) {
		WriteFile(filePath + "dec", decryptedText);
		std::cout << "Correct password is " << pass << std::endl;
		return  true;
	}
	return false;
}
