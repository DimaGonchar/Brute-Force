#pragma once
#include<string>
#include<vector>

void PasswordToKey(std::string& password);
bool DecryptAes(const std::vector<unsigned char>& encryptedText, std::vector<unsigned char>& decryptedText);