#include "CppUnitTest.h"
#include "..\Katy444444\FindSameContextWords.h"
#include "..\Katy444444\FindSameContextWords.cpp"
#include "..\Katy444444\WordInContext.cpp"
#include "..\Katy444444\WordInContext.h"
#include "..\Katy444444\Check.h"
#include "..\Katy444444\Check.cpp"
#include "..\Katy444444\CheckFileOutput.h"
#include "..\Katy444444\CheckFileOutput.cpp"
#include "..\Katy444444\SplitIntoWords.h"
#include "..\Katy444444\SplitIntoWords.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	private: 
		std::vector<std::string> answ = { "q\tw\tq\tq\tw\tq", "q\tw\tq\tq\te\tq", "q\te\tq\tq\tw\tq", "q\te\tq\tq\te\tq"};
		std::vector <std::shared_ptr<WordInContext>> contextCase;
		std::vector <std::string> words = { "q","w","q","e","q"};
	public:
		
		TEST_METHOD(TestMethod1)
		{
			FindSameContextWords(contextCase, words);
			contextCase[0]->FindPermutaionsAdapt();
			Assert::IsTrue(contextCase[0]->ReturnPermutations() == answ);
		}
	};
}
