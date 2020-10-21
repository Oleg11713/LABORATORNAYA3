#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

class String
{
	char* string;
public:
	String(char* str)
	{
		string = new char[strlen(str) + 1];
		strcpy_s(string, strlen(str) + 1, str);
	}
	String(const String& str)
	{
		string = new char[strlen(str.string) + 1];
		strcpy_s(string, strlen(str.string) + 1, str.string);
	}
	~String()
	{
		delete[]string;
	}
	friend ostream& operator>>(ostream& out, const String& str);
	friend istream& operator<<(istream& in, String& str);
	char operator[](int);
	void operator()(int, int);
	void operator!();
	void display();
};

ostream& operator>>(ostream& out, const String& str)
{
	out << str.string;
	return out;
}

istream& operator<<(istream& in, String& str)
{
	in >> str.string;
	return in;
}

char String::operator[](int i)
{
	return string[i];
}

void String::operator!()
{
	if (strlen(string) == 0)
		cout << "Object is empty" << endl;
	else cout << "Object is not empty" << endl;
}

void String::operator()(int indexFrom, int indexTo)
{
	char str1[80];
	for (int i = indexFrom - 1; i <= indexTo; i++)
		str1[i - indexFrom + 1] = string[i];
	for (int i = 0; i < indexTo - indexFrom + 1; i++)
		cout << str1[i];
}

void String::display()
{
	for (int i = 0; string[i] != '\0'; i++)
		cout << string[i];
	cout << endl;
}

int writeNumbers() {
	string numbers;
	while (true) {
		int key;
		key = _getch();
		if (key == 224) {
			key = _getch();
		}
		else
			if (key == 8) {
				if (numbers.length() != 0) {
					cout << '\b' << " " << '\b';
					numbers.erase(numbers.length() - 1);
				}
			}
			else
				if (key == 13) break;
				else
					if (key >= '0' && key <= '9') {
						numbers = numbers + (char)key;
						cout << (char)key;
					}
	}
	return stoi(numbers);
}

int main()
{
	int q = 0, p = 0;
	char str[80];
	int indexTo, indexFrom;
	int index;
	cout << "Enter the string: ";
	cin.getline(str, 80);
	system("cls");
	cout << "Source string: ";
	String s(str);
	s.display();
	cout << endl;
	s.operator!();
	if (strlen(str) != 0)
	{
		cout << "\nEnter the number of the element you want to display: ";
		while (q == 0)
		{
			index = writeNumbers();
			cout << endl;
			if (index >= 1 && index <= strlen(str))
			{
				cout << "Element: " << s[index - 1] << endl;
				q = 1;
			}
			else cout << "Error, try again and enter the correct number: ";
		}
		cout << "\nEnter the start and the end of the substring boundary";
		cout << "\nFrom: ";
		while (p == 0)
		{
			indexFrom = writeNumbers();
			cout << endl;
			if (indexFrom >= 1 && indexFrom <= strlen(str))
				p = 1;
			else cout << "Error, try again and enter the correct boundary: ";
		}
		cout << "To: ";
		while (p == 1)
		{
			indexTo = writeNumbers();
			cout << endl;
			if (indexTo >= indexFrom && indexTo <= strlen(str))
				p = 2;
			else cout << "Error, try again and enter the correct boundary: ";
		}
		cout << endl;
		s.operator()(indexFrom, indexTo);
	}
	return 0;
}

