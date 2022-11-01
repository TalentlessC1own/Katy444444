#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "VectorEqual.h"
class WordInContext 
{
private:
	std::string leftWord;
	std::vector<std::string> midWord;
	std::string rightWord;
	std::vector <std::string> permutations;

public:
	WordInContext(std::string word1, std::string word2, std::string word3)
		: leftWord(word1), rightWord(word3)
	{
		midWord.push_back(word2);
	}

	void FindPermutations(std::string pref,int n, int size);
	int GetNUmberOfPermutations();

	bool  CompareContext(std::string word1, std::string word3);

	void AddPermutation(std::string word2);

	void FindPermutaionsAdapt();

	void Show();

	std::vector <std::string> ReturnPermutations();
	
	~WordInContext () = default;

};

