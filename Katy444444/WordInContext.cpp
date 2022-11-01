#include "WordInContext.h"
#include "SplitIntoWords.h"

void WordInContext::FindPermutations(std::string pref ,int n, int size)
{
    std::vector <std::string> prefs;
    std::string buf;
    if (size == 1)
    {

        for (int j = 0; j < n; j++)
        {
            prefs = SplitIntoWords(pref);
            for (int i = 0; i < prefs.size(); i++)
            {
                buf += leftWord + "\t" + prefs[i] + "\t" + rightWord + "\t";
            }
            buf += leftWord + "\t" + midWord[j] + "\t" + rightWord;

            permutations.push_back(buf);
            buf.clear();
        }
           

    }

    else

    {



        for (int i = 0; i < n; i++)
        {
            FindPermutations(pref + "\t" + midWord[i], n, size - 1);
        }


    }
   
}





int WordInContext::GetNUmberOfPermutations()
{
    return static_cast<int>(permutations.size()) - 1;
}

bool WordInContext::CompareContext(std::string word1, std::string word3)
{
    return leftWord == word1 && word3 == rightWord;
}

void WordInContext::AddPermutation(std::string word2)
{
    midWord.push_back(word2);
}

void WordInContext::FindPermutaionsAdapt()
{
    FindPermutations("", static_cast<int>(midWord.size()), static_cast<int>(midWord.size()));
}



void WordInContext::Show()
{
    if (midWord.size() < 2)
        return;
    for (int i = 0; i < permutations.size(); i++)
    {
        std::cout << permutations[i] << std::endl;
    }
    std::cout << "Permutation count = " << permutations.size() - 1 << std::endl;
}

std::vector<std::string> WordInContext::ReturnPermutations()
{
    std::vector <std::string> empty;
    if (midWord.size() < 2)
        return empty;
    return permutations;
}
