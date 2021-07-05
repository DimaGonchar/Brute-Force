#pragma once
#include<vector>
#include<string>

void CalculateHash(const std::vector<unsigned char>& data, std::vector<unsigned char>& hash);
void ExtractHash(std::vector<unsigned char>& hashBuf, std::vector<unsigned char>& buf);
bool CompareHash(const std::string& filePath, std::vector<unsigned char>& sourceHash,
	std::vector<unsigned char>& decryptedText, const std::string& pass);