#include<iostream>
#include<chrono>
#include<vector>
#include<thread>
#include"BruteForce.h"
#include"ReadFile.h"
#include"Hash.h"
#include"GenPass.h"

bool status = false;

int main()
{
	auto startTime = std::chrono::high_resolution_clock::now();
	//auto res=std::thread::hardware_concurrency();
	std::ios_base::sync_with_stdio(false);
	std::cerr.imbue(std::locale(""));  // get pretty local formatting for numeric values
	std::string filePath;
	std::cout << "Enter file path:";
	std::cin >> filePath;

	std::vector<unsigned char> chipherText;
	ReadFile(filePath, chipherText);

	std::vector<unsigned char> hash;
	ExtractHash(hash, chipherText);
	chipherText.resize(chipherText.size() - hash.size());

	std::vector<std::string> firstThreadContainer;
	std::vector<std::string> secondThreadContainer;
	std::vector<std::string> thirdThreadContainer;
	std::vector<std::string> fourthThreadContainer;
	
	GenPasswords getPass;

	std::thread first(BruteForce, std::ref(filePath), std::ref(chipherText),
		std::ref(hash), &firstThreadContainer, &getPass, &status);

	std::thread second(BruteForce, std::ref(filePath), std::ref(chipherText),
		std::ref(hash), &secondThreadContainer, &getPass, &status);

	std::thread third(BruteForce, std::ref(filePath), std::ref(chipherText),
		std::ref(hash), &thirdThreadContainer, &getPass, &status);

	std::thread four(BruteForce, std::ref(filePath), std::ref(chipherText),
		std::ref(hash), &fourthThreadContainer, &getPass, &status);

	first.join();
	second.join();
	third.join();
	four.join();
	
	auto finishTime = std::chrono::high_resolution_clock::now();
	std::chrono::duration<float>duration = finishTime - startTime;
	std::cout << duration.count();
}
