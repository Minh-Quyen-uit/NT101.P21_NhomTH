#include <iostream>
#include <string>
using namespace std;

char EnCrytion(char input, char key)
{
	if (isupper(input))
	{
		key = toupper(key);
		return 'A' + (input - 'A' + (key - 'A') + 26) % 26;
	}
	else if (islower(input))
	{
		key = tolower(key);
		return 'a' + (input - 'a' + (key - 'a') + 26) % 26;
	}
	else
		return input;
}

char DeCrytion(char input, char key)
{
	if (isupper(input))
	{
		toupper(key);
		return 'A' + (input - 'A' - (key - 'A') + 26) % 26;
	}
	else if (islower(input))
	{
		tolower(key);
		return 'a' + (input - 'a' - (key - 'a') + 26) % 26;
	}
	else
		return input;
}

int main()
{
	cout << "-----VIGENERE CIPHER-----\n";
	cout << "Enter the text = ";
	string s, key;
	getline(cin, s);
	int n = s.length();

	cout << "Key = ";
	getline(cin, key);
	int m = key.length();

	int j = 0;
	int choice = 0;
	while (choice == 0)
	{
		cout << "Encryt (1) or Decryt (2): ";
		cin >> choice;
	}
	if (choice == 1)
	{
		for (int i = 0; i < n; i++)
		{
			if (s[i] == ' ')
				continue;
			s[i] = EnCrytion(s[i], key[j]);
			j++;
			if (j == m)
				j = 0;
		}
		cout << "Ciphertext = " << s << endl;
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (s[i] == ' ')
				continue;
			s[i] = DeCrytion(s[i], key[j]);
			j++;
			if (j == m)
				j = 0;
		}
		cout << "Plaintext = " << s << endl;
	}
	return 0;
}