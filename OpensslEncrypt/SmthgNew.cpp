//#include "SmthgNew.h"
//#include<iostream>
//#include "openssl/evp.h"
//#include <openssl/aes.h>
//#include "openssl/sha.h"
//#include "openssl/md5.h"
//
//unsigned char key[EVP_MAX_KEY_LENGTH];
//unsigned char iv[EVP_MAX_IV_LENGTH];

//void ReadFile(const std::string& filePath, std::vector<unsigned char>& buf)
//{
//	std::basic_fstream<unsigned char> fileStream(filePath, std::ios::binary | std::fstream::in);
//
//	if (!fileStream.is_open())
//	{
//		throw std::runtime_error("Can not open file " + filePath);
//	}
//
//	buf.clear();
//	buf.insert(buf.begin(), std::istreambuf_iterator<unsigned char>(fileStream), std::istreambuf_iterator<unsigned char>());
//
//	fileStream.close();
//}

//void WriteFile(const std::string& filePath, const std::vector<unsigned char>& buf)
//{
//	std::basic_ofstream<unsigned char> fileStream(filePath, std::ios::binary);
//	fileStream.write(&buf[0], buf.size());
//	fileStream.close();
//}

//void PasswordToKey(std::string& password)
//{
//	OpenSSL_add_all_digests();
//	const EVP_MD* dgst = EVP_get_digestbyname("md5");
//	if (!dgst)
//	{
//		throw std::runtime_error("no such digest");
//	}
//
//	const unsigned char* salt = NULL;
//	if (!EVP_BytesToKey(EVP_aes_128_cbc(), EVP_md5(), salt,
//		reinterpret_cast<unsigned char*>(&password[0]),
//		password.size(), 1, key, iv))
//	{
//		throw std::runtime_error("EVP_BytesToKey failed");
//	}
//}
//
//bool DecryptAes(const std::vector<unsigned char>& encryptedText, std::vector<unsigned char>& decryptedText)
//{
//	EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
//
//	/* Create and initialise the context */
//	if (!(ctx = EVP_CIPHER_CTX_new()))
//	{
//		throw std::runtime_error("DecryptInit error");
//	}
//	if (1 != EVP_DecryptInit_ex(ctx, EVP_aes_128_cbc(), NULL, key, iv)) {
//		return false;
//	}
//	std::vector<unsigned char>decryptedTextBuf(encryptedText.size() + AES_BLOCK_SIZE);
//	int decryptedTextSize = 0;  //decryptedTextBuf.size();
//	if (1 != EVP_DecryptUpdate(ctx, &decryptedTextBuf[0], &decryptedTextSize, &encryptedText[0], encryptedText.size())) {
//		return false;
//	}
//	int lastPartLen = 0;
//
//	if (1 != EVP_DecryptFinal_ex(ctx, &decryptedTextBuf[0] + decryptedTextSize, &lastPartLen)) {
//		return false;
//	}
//	decryptedTextSize += lastPartLen;
//	decryptedTextBuf.erase(decryptedTextBuf.begin() + decryptedTextSize, decryptedTextBuf.end());
//	decryptedText.swap(decryptedTextBuf);
//	EVP_CIPHER_CTX_free(ctx);
//	return true;
//
//}
//void CalculateHash(const std::vector<unsigned char>& data, std::vector<unsigned char>& hash)
//{
//	std::vector<unsigned char> hashTmp(SHA256_DIGEST_LENGTH);
//
//	SHA256_CTX sha256;
//	SHA256_Init(&sha256);
//	SHA256_Update(&sha256, &data[0], data.size());
//	SHA256_Final(&hashTmp[0], &sha256);
//
//	hash.swap(hashTmp);
//}
//
//void ExtractHash(std::vector<unsigned char>& hashBuf, std::vector<unsigned char>& buf) {
//
//	hashBuf.clear();
//	for (size_t i = SHA256_DIGEST_LENGTH; i > 0; --i) {
//		hashBuf.push_back(buf[buf.size() - i]);
//	}
//}
//
//bool CompareHash(const std::string& filePath, std::vector<unsigned char>& sourceHash, 
//	             std::vector<unsigned char>& decryptedText, const std::string& pass)
//{
//	std::vector<unsigned char> hash;
//	CalculateHash(decryptedText,hash);
//	if (hash == sourceHash) {
//		WriteFile(filePath + "dec", decryptedText);
//		std::cout << "Correct password is " << pass << std::endl;
//		return  true;
//	}
//	return false;
//}
