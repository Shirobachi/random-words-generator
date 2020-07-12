#include "D:/Dropbox/Projects/Shiro.h"

#include <fstream>
#include <time.h>
#include <conio.h>

using namespace std;

string temporyVariable;

fstream file;

vector < string > langPL, langEN, langNL, langCU, history, generated; //lang## have data from file, history has history

bool problemWithHistorySave = false;
bool correct = NULL; // for generating wthout repets
bool ifCustom = false;

char choose;

int words; //on generating words it is answer to "how many words ? "

void loading(char lang);
void randoming(char lang);

int main()
{
	for (;;)
	{
		choose = NULL;

		system("cls");

		if (problemWithHistorySave)
		{
			changeColor("red");
			cout << "We have problem with save your words to file. So your history can be diffrent that is in real. I am sorry!" << endl << endl;
			changeColor();
		}

		cout << "Copyright 2018 Shirobachi (Sebastina Hryszko) Licence CC" << endl;
		cout << "Hello, choose language!" << endl << endl;				changeColor("green");
		cout << "1 - polski" << endl;
		cout << "2 - English!" << endl;
		cout << "3 - Nederlands" << endl;						changeColor();
		cout << "4 - Customs! ( your data put on Custom.txt )" << endl;						changeColor();
		cout << "5 - show history" << endl;
		cout << "6 - Generate words to file!" << endl;
		cout << "7 - Generate words without repeats to file!" << endl;
		cout << "0 - Exit" << endl << endl;
		cout << "Choose: ";

		choose = _getch();

		if (choose == '1' || choose == '2' || choose == '3' || choose == '4')
		{
			randoming(choose);
		}
		else if (choose == '5')
		{
			history.clear();

			file.open("history.txt");
			if (file.good())
			{
				while (getline(file, temporyVariable))
					if (temporyVariable != "")history.push_back(temporyVariable);

				file.close();

				system("cls");

				cout << "YOUR HISTORY: " << endl;

				for (unsigned int i = 0; i < history.size(); i++)
				{
					cout << i + 1 << ". " << history[i] << endl;
				}

				cout << endl << "If you want you can see history on file history.txt" << endl;

				system("pause");

			}
			else
			{
				cout << "You did not randoming some words. Try it now and give subscription for KAZIK.TV on YouTube and on www.kazik.tv";
				system("pause");
			}
		}
		else if (choose == '6')
		{
			system("cls");

			cout << "If you continue, data in the file 'generated.txt' will be lost." << endl;
			cout << "Do you want continue ? (Y/N) ?" << endl << endl;
			cout << "choose: ";

			choose = _getch();

			if (choose == 'Y' || choose == 'y')
			{
				system("cls");

				cout << "How many words do you need ?" << endl << endl;
				cout << "Needed words: ";

				cin >> words;

				cout << endl << "What language ?" << endl;
				cout << "1 - polski" << endl;
				cout << "2 - English!" << endl;
				cout << "3 - Nederlands" << endl;
				cout << "4 - Customs! ( your data put on Custom.txt )" << endl;

				choose = _getch();

				loading(choose);

				file.open("Generated.txt", ios::out | ios::trunc);
				if (file.good())
				{
					for (int i = 0; i < words; i++)
					{
						if (choose == '1')//pl
						{
							file << langPL[rand() % langPL.size()];
						}
						else if (choose == '2')//en
						{
							file << langEN[rand() % langEN.size()];
						}
						else if (choose == '3')//nl
						{
							file << langNL[rand() % langNL.size()];
						}
						else if (choose == '4')//custom
						{
							file << langCU[rand() % langCU.size()];
						}

						if (i != words - 1)file << endl;

					}

					file.close();
					system("cls");
					cout << "You words is on file 'generated.txt'" << endl << "Have a nice live and see www.kazik.tv" << endl << endl;
					system("pause");
				}
				else
				{
					cout << "We have problem with save data to file. Chceck your permissions and try again.";
					system("pause");
				}
			}
		}
		
		else if (choose == '7')
		{
			system("cls");

			cout << "If you continue, data in the file 'generated.txt' will be lost." << endl;
			cout << "Do you want continue ? (Y/N) ?" << endl << endl;
			cout << "choose: ";

			choose = _getch();

			if (choose == 'Y' || choose == 'y')
			{
				system("cls");

				cout << "How many words do you need ?" << endl << endl;
				cout << "Needed words: ";

				cin >> words;

				cout << endl << "What language ?" << endl;
				cout << "1 - polski" << endl;
				cout << "2 - English!" << endl;
				cout << "3 - Nederlands" << endl;
				cout << "4 - Customs! ( your data put on Custom.txt )" << endl;

				choose = _getch();

				loading(choose);

				if (choose != '1' && choose != '2' && choose != '3' && choose != '4')
				{
					cout << "Wrong number. Defeaul language is English and this will be using"; 
					choose = '2';
				}

				if (choose == '1' && words > langPL.size())
				{
					words = langPL.size();
					cout << "You need too more words. Your value was changed to " << langPL.size() << "." << endl;
					system("pause");
				}

				if (choose == '2' && words > langEN.size())
				{
					words = langEN.size();
					cout << "You need too more words. Your value was changed to " << langEN.size() << "." << endl;
					system("pause");
				}

				if (choose == '3' && words > langNL.size())
				{
					words = langNL.size();
					cout << "You need too more words. Your value was changed to " << langNL.size() << "." << endl;
					system("pause");
				}
				if (choose == '4' && words > langCU.size())
				{
					words = langCU.size();
					cout << "You need too more words. Your value was changed to " << langCU.size() << "." << endl;
					system("pause");
				}

				generated.clear();

				file.open("Generated.txt", ios::out | ios::trunc);
				if (file.good())
				{
					for (int i = 0; i < words;)
					{
						correct = true;
						if (choose == '1')//pl
						{
							temporyVariable = langPL[rand() % langPL.size()];
							if (generated.size()>0)
								for (int j = 0; j < generated.size(); i++)
								{
									if (temporyVariable == generated[j])correct = false;
								}
						}
						if (choose == '2')//en
						{
							temporyVariable = langEN[rand() % langEN.size()];
							if (generated.size()>0)
								for (int j = 0; j < generated.size(); i++)
								{
									if (temporyVariable == generated[j])correct = false;
								}
						}
						if (choose == '3')//nl
						{
							temporyVariable = langNL[rand() % langNL.size()];
							if (generated.size()>0)
								for (int j = 0; j < generated.size(); i++)
								{
									if (temporyVariable == generated[j])correct = false;
								}
						}
						if (choose == '4')//custom
						{
							temporyVariable = langCU[rand() % langCU.size()];
							if (generated.size()>0)
								for (int j = 0; j < generated.size(); i++)
								{
									if (temporyVariable == generated[j])correct = false;
								}
						}

						if (correct && temporyVariable != "FILE IS EMPTY!")
						{
							file << temporyVariable;
							if (i != words - 1)file << endl;
							i++;
						}
					}

					file.close();
					system("cls");
					cout << "You words is on file 'generated.txt'" << endl << "Have a nice live and see www.kazik.tv" << endl << endl;
					system("pause");
				}
				else
				{
					cout << "We have problem with save data to file. Chceck your permissions and try again.";
					system("pause");
				}
			}
		}
		else if (choose == '0')exit(0);
		else
		{
			cout << "Your value is not correct!";
			Sleep(1500);
		}
	}
	return 0;
}

void randoming(char  lang)
{
	while (choose != '0')
	{
		loading(lang);

		srand(time(NULL));

		
		for (int i = 0; i < 25; i++)
		{
			if (lang == '1')//pl
			{
				temporyVariable = langPL[rand() % langPL.size()];
			}
			else if (lang == '2')//en
			{
				temporyVariable = langEN[rand() % langEN.size()];
			}
			else if (lang == '3')//nl
			{
				temporyVariable = langNL[rand() % langNL.size()];
			}
			else if (lang == '4')//custom
			{
				temporyVariable = langCU[rand() % langCU.size()];
			}

			system("cls");
			cout << "----------------------" << endl;
			cout << "RANDOMED WORD: ";								changeColor("dyellow");
			cout << temporyVariable << endl;		changeColor();
			cout << "----------------------" << endl;
			Sleep(10);

			if (i == 24)
			{
				file.open("history.txt", ios::out | ios::app);
				if (file.good() && temporyVariable != "FILE IS EMPTY!")
				{
					file << temporyVariable << endl;
					file.close();
				}
			}

		}///for

		cout << "1. More words" << endl;
		cout << "0. Back" << endl;

		choose = _getch();

		switch (choose)
		{
		case '1':
		{
			randoming(lang);
		}break;
		case '0':
		{

		}break;
		default:
		{
			cout << "\nIncorrect value, more words!";
			Sleep(750);
			randoming(lang);
		}break;
		}
	}
}

void loading(char lang)
{
	if (lang == '1')//pl
	{
		langPL.clear();

		file.open("LangPL");
		if (file.good())
		{
			while (getline(file, temporyVariable))
				if (temporyVariable != "")langPL.push_back(temporyVariable);

			file.close();
		}
		else
		{
			cout << "I cannot load data from file!\n";
			system("pause");
			exit(0);
		}
	}

	else if (lang == '2')//en
	{

		langEN.clear();

		file.open("LangEN");
		if (file.good())
		{
			while (getline(file, temporyVariable))
				if (temporyVariable != "")langEN.push_back(temporyVariable);

			file.close();
		}
		else
		{
			cout << "I cannot load data from file!\n";
			system("pause");
			exit(0);
		}
	}

	else if (lang == '3')//nl
	{

		langNL.clear();

		file.open("LangNL");
		if (file.good())
		{
			while (getline(file, temporyVariable))
				if (temporyVariable != "")langNL.push_back(temporyVariable);

			file.close();
		}
		else
		{
			cout << "I cannot load data from file!\n";
			system("pause");
			exit(0);
		}
	}

	else if (lang == '4')//custom
	{
		if (ifCustom == false)
		{
			cout << endl << "Your data put / write on 'Custom.txt'" << endl;
			system("pause");
		}
		ifCustom = true;


		langCU.clear();

		file.open("Custom.txt");
		if (file.good())
		{
			while (getline(file, temporyVariable))
				if (temporyVariable != "")langCU.push_back(temporyVariable);

			file.close();
		}
		else
		{
			cout << "I cannot load data from file!" << endl << "App will be close";
			system("pause");
			exit(0);
		}

		if (langCU.size() == 0)
		{
			cout << "Your custom file is empty!" << endl;
			langCU.push_back("FILE IS EMPTY!");
			system("pause");
		}
	}
}