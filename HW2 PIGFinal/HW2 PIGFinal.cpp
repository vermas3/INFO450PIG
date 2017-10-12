// HW2 PIGFinal.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include <iostream>
#include <string>


using namespace std;

bool isvowel(char);
string add(string);
string PigLatin(string);

int main()
{

	char Again = 'y';

	while (Again == 'Y' || Again == 'y')
	{

		string str;
		cout << " Please Enter a word you would like to translate " << endl;
		cin >> str;
		if (str.length() > 47)
		{
			cout << "Your word is too long. Please try again" << endl;
		}
		else if ((str[0] == '1' || str[0] == '2' || str[0] == '3' || str[0] == '4' || str[0] == '5' || str[0] == '6' || str[0] == '7' || str[0] == '8' || str[0] == '9' || str[0] == '0'))
		{
			cout << "Please use letters only" << endl;
		}
		else
		{
			cout << " Your PigLatin translation is " << PigLatin(str) << endl;
		}
		cout << "Would you like to do it again? " << endl;
		cin >> Again;
	}
	if ((Again != 'Y' || Again != 'y'))
	{
		cout << " Thank you so much for your time " << endl;
	}
}

bool isvowel(char vowel)
{
	switch (vowel)
	{
	case 'A': case 'a': case 'E': case 'e': case 'I': case 'i': case 'O': case 'o': case 'U': case 'u': case 'Y': case 'y':
		return true;
	default:
		return false;
	}
}

string add(string str)
{
	string::size_type len = str.length();
	string str1;
	str1 = str.substr(1, len - 1) + str[0];
	return str1;
}

string PigLatin(string str)
{
	string::size_type len;
	bool vowel;
	string::size_type counter;
	if (str.length() <= 2)
	{
		str = str;
	}
	else if (str == "the" || str == "yet" || str == "but" || str == "nor" || str == "for" || str == "THE" || str == "YET" || str == "BUT" || str == "NOR" || str == "FOR")
	{
		str = str;
	}
	else if (isvowel(str[0]))
	{
		str = str + "ay";
	}
	else
	{
		str = str + "";
		str = add(str);
		len = str.length();vowel = false;
		for (counter = 1; counter < len - 1; counter++)
			if (isvowel(str[0]))
			{
				vowel = true;
				break;
			}
			else
				str = add(str);
		if (!vowel)
			str = str.substr(1, len) + "ay";
		else
			str = str + "ay";
	}
	return str;
}

