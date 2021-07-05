#pragma once
#include<string>
#include<mutex>
#include <stdio.h>
#include<vector>

class GenPasswords
{
public:
	GenPasswords();
	void Gen(std::vector<std::string>& retPasswords);
private:
	const std::string m_chars = "abcdefghijklmnopqrstuvwxyz0123456789";
    std::string m_genPass;
    const double m_totalPasswordsCount = pow(m_charCount, m_maxPasswordLength) + pow(m_charCount, 3) + pow(m_charCount, 2) + pow(m_charCount, 1);
    const size_t m_numberOfPass = 10000;
    const size_t m_charCount = 36;
	static const size_t m_maxSize = 30;
	const size_t m_maxPasswordLength = 4;	
	size_t m_generatedPasswordsCount = 0;
	int m_guessc[m_maxSize] = {};
};




