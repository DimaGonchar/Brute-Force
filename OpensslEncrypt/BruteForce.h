#pragma once
#include<string>
#include<vector>

void BruteForce(std::string& filePath, const std::vector<unsigned char>& chipherText, 
	            std::vector<unsigned char>& hash, std::vector<std::string>* passwords, 
	            class GenPasswords*genPass, bool* status);
	          