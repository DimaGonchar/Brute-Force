#include <iostream>
#include <chrono>
#include <vector>
#include <thread>
#include "BruteForce.h"
#include "ReadFile.h"
#include "Hash.h"
#include "GenPass.h"
#include <openssl/evp.h>

int main()
{
	auto startTime = std::chrono::high_resolution_clock::now();
	bool status = false;

	std::ios_base::sync_with_stdio(false);
	std::cerr.imbue(std::locale(""));  // get pretty local formatting for numeric values

	std::string filePath;
    std::vector<unsigned char> encryptedText;
	for (;;)
	{
		std::cout << "Enter file path:";
		std::cin >> filePath;
		if (ReadFile(filePath, encryptedText))
		{
		  break;
		}
	}

	std::vector<unsigned char> hash;
	ExtractHash(hash, encryptedText);
	encryptedText.resize(encryptedText.size() - hash.size());

	std::vector<std::string> firstThreadContainer;
	std::vector<std::string> secondThreadContainer;
	std::vector<std::string> thirdThreadContainer;
	std::vector<std::string> fourthThreadContainer;

	GenPasswords getPass;

	OpenSSL_add_all_digests();


	std::thread first(BruteForce, std::ref(filePath), std::ref(encryptedText),
		std::ref(hash), &firstThreadContainer, &getPass, &status);

	std::thread second(BruteForce, std::ref(filePath), std::ref(encryptedText),
		std::ref(hash), &secondThreadContainer, &getPass, &status);

	std::thread third(BruteForce, std::ref(filePath), std::ref(encryptedText),
		std::ref(hash), &thirdThreadContainer, &getPass, &status);

	std::thread fourth(BruteForce, std::ref(filePath), std::ref(encryptedText),
		std::ref(hash), &fourthThreadContainer, &getPass, &status);

	first.join();
	second.join();
	third.join();
	fourth.join();
	auto finishTime = std::chrono::high_resolution_clock::now();
	std::chrono::duration<float>duration = finishTime - startTime;
	std::cout << duration.count();
}
