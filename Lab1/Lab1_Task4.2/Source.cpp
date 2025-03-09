#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

#define SIZE 5

void fillMatrix(std::string key, char matrix[SIZE][SIZE]) {
    set<char> used;  
    int row = 0, col = 0;
    for (char& ch : key) {
        ch = toupper(ch); 
        if (ch == 'J') ch = 'I';  
        if (used.find(ch) == used.end() && isalpha(ch)) {  
            matrix[row][col] = ch;
            used.insert(ch);
            if (++col == SIZE) {
                col = 0;
                row++;
            }
        }
    }
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        if (ch == 'J') continue; 
        if (used.find(ch) == used.end()) { 
            matrix[row][col] = ch;
            used.insert(ch);
            if (++col == SIZE) {
                col = 0;
                row++;
            }
        }
    }
}

void printMatrix(char matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) 
            cout << matrix[i][j] << " ";
        cout << "\n";
    }
}

string processString(const string& input) {
    string cleanedInput;
    for (char ch : input)
        if (ch != ' ')
            cleanedInput += toupper(ch);
    string result;
    for (size_t i = 0; i < cleanedInput.length(); i += 2) {
        char first = cleanedInput[i];
        char second = (i + 1 < cleanedInput.length()) ? cleanedInput[i + 1] : 'X';
        if (first == second) {
            result += first;
            result += 'X';
            i--;
        }
        else {
            result += first;
            result += second;
        }
        if (i + 2 < cleanedInput.length())
            result += ' ';
    }
    return result;
}

typedef struct Point
{
    char character;
    int col;
    int row;
};

void EnCrytion(char &input1, char &input2, char matrix[SIZE][SIZE])
{
    Point p1, p2;
    p1.character = input1;
    p2.character = input2;
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (p1.character == matrix[i][j])
            {
                p1.row = i; 
                p1.col = j;
                break;
            }
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (p2.character == matrix[i][j])
            {
                p2.row = i;
                p2.col = j;
                break;
            }
    if (p1.row == p2.row)
    {
        p1.col = (p1.col + 1) % SIZE;
        p2.col = (p2.col + 1) % SIZE;
    }
    else if (p1.col == p2.col)
    {
        p1.row = (p1.row + 1) % SIZE;
        p2.row = (p2.row + 1) % SIZE;
    }
    else 
        swap(p1.col, p2.col);
    input1 = matrix[p1.row][p1.col];
    input2 = matrix[p2.row][p2.col];
}

void DeCrytion(char& input1, char& input2, char matrix[SIZE][SIZE])
{
    Point p1, p2;
    p1.character = input1;
    p2.character = input2;
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (p1.character == matrix[i][j])
            {
                p1.row = i;
                p1.col = j;
                break;
            }
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (p2.character == matrix[i][j])
            {
                p2.row = i;
                p2.col = j;
                break;
            }
    if (p1.row == p2.row)
    {
        p1.col = (p1.col - 1 + SIZE) % SIZE;
        p2.col = (p2.col - 1 + SIZE) % SIZE;
    }
    else if (p1.col == p2.col)
    {
        p1.row = (p1.row - 1 + SIZE) % SIZE;
        p2.row = (p2.row - 1 + SIZE) % SIZE;
    }
    else
        swap(p1.col, p2.col);
    input1 = matrix[p1.row][p1.col];
    input2 = matrix[p2.row][p2.col];
}
int main()
{
    cout << "-----PLAYFAIR-----\n";
    string s, key;
    cout << "Enter the text = ";
    getline(cin, s);
    s = processString(s);

    char matrix[SIZE][SIZE] = {};
    cout << "Key = ";
    cin >> key;
    fillMatrix(key, matrix);
    cout << "Matrix: \n";
    printMatrix(matrix);
    int choice = 0;
    while (choice == 0)
    {
        cout << "EnCryt (1) or Decryt (2): ";
        cin >> choice;
    }
    if (choice == 1)
    {
        cout << "\nPlaintext = " << s << "\n\n";
        int i = 0;
        while (i < s.length())
        {
            if (i % 3 == 2)
            {
                i++;
                continue;
            }
            EnCrytion(s[i], s[i + 1], matrix);
            i += 2;
        }

        cout << "Ciphertext = " << s << "\n";
    }
    else 
    {
        int i = 0;
        while (i < s.length())
        {
            if (i % 3 == 2)
            {
                i++;
                continue;
            }
            DeCrytion(s[i], s[i + 1], matrix);
            i += 2;
        }

        cout << "Plaintext = " << s << "\n";
    }
    
	return 0;
}