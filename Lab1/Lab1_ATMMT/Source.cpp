#include <iostream>
#include <cctype>
#include <string>
using namespace std;

char EnCrytion(char input, int key) {
	if (isupper(input)) 
	{
		key = toupper(key);
		return 'A' + (input - 'A' + key + 26) % 26;
	}
	else if (islower(input)) 
	{
		key = tolower(key);
		return 'a' + (input - 'a' + key + 26) % 26;
	}
	return input;
}

char DeCrytion(char input, int key) {
	if (isupper(input)) 
	{  
		key = toupper(key);
		return 'A' + (input - 'A' - key + 26) % 26;
	}
	else if (islower(input)) 
	{
		key = tolower(key);
		return 'a' + (input - 'a' - key + 26) % 26;
	}
	return input;  
}

int main()
{
	cout << "-----CAESER CIPHER-----\n";
	cout << "Enter the text = ";
	string s;
	getline(cin, s);
	int n = s.length();

	int choice = 0;
	while (choice == 0)
	{
		cout << "EnCryt (1) or DeCryt (2): ";
		cin >> choice;
	}

	if (choice == 1)
	{
		int key;
		cout << "Key = ";
		cin >> key;
		for (int i = 0; i < n; i++)
		{
			s[i] = EnCrytion(s[i], key);
		}
		cout << "Ciphertext = " << s << "\n\n";
	}
	else
	{
		string p = s;
		for (int k = 1; k < 26; k++)
		{
			for (int i = 0; i < n; i++)
			{
				p[i] = DeCrytion(s[i], k);
			}
			cout << "Key = " << k << endl;
			cout << "Plaintext = " << p << "\n\n";
		}
	}
	return 0;
}