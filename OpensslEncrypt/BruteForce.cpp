#include "BruteForce.h"
#include"Hash.h"
#include"Decryption.h"
#include"GenPass.h"
#include<iostream>

void BruteForce(std::string& filePath, const std::vector<unsigned char>& chipherText,
	            std::vector<unsigned char>& hash,std::vector<std::string>* passwords,
	            GenPasswords* genPass, bool* status)
{
  	while (*status!=true)
	{
		genPass->Gen(*passwords);
		
		for (auto& i : *passwords)
		{
          	PasswordToKey(i);
			 std::vector<unsigned char> decryptedText;
			if (DecryptAes(chipherText, decryptedText) == true)
			{
				if (CompareHash(filePath, hash, decryptedText, i) == true)
				{
					*status = true;
					 break;
				}
			}
		}
	}
}
