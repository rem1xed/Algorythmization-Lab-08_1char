#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


using namespace std;
int Count(char* s) 
{
	int k = 0;
	for (int i = 0; s[i] != '\0'; i++) 
	{
		if (strchr("+-=", s[i])) {
			k++;
		}

	}

	return k;
}
char* Change(char* s) 
{
	char* t = new char[strlen(s)];
	char* p;
	int pos1 = 0,
		pos2 = 0;
	*t = 0;

	char liS[19] = "+-==-+-+==+-+=--=+";

	bool go = true;
	for (int i = 0; i < 18 && go == true; i++) {
		cout << "CURRENT SYMBOL: " << liS[i] << endl;
		while (p = strchr(s + pos1, liS[i])) 
		{
			if (s[p -s +1] == liS[i])
			{
				p = strchr(s + pos1, s[p - s]);
				pos2 = p - s + 2; 
				strncat(t, s + pos1, pos2 - pos1 - 2);
				strcat(t, "***");
				pos1 = pos2;
			}
			else
			{
				pos2 = p - s + 1; 
				strncat(t, s + pos1, pos2 - pos1);
				pos1 = pos2;
			}
		}
		if ((i+1) % 3 == 0) {
			go = false;
			for (int i = 0; t[i] != 0; i++) {
				if (t[i] == '+' && t[i + 1] == '+' ||
					t[i] == '-' && t[i + 1] == '-' ||
					t[i] == '=' && t[i + 1] == '=') {
					go = true;
					*t = 0;
					pos1 = 0;
					pos2 = 0;
				}
			}
			
		}
		
	
	}
	
	strcat(t, s + pos1);
	strcpy(s, t);
	return t;
}
int main()
{
	char str[101];
		cout << "Enter string:" << endl;
	cin.getline(str, 100);
	cout << "String contained " << Count(str) << "'-', '+', '='" << endl;
	char* dest = new char[151];
	dest = Change(str);
	cout << "Modified string (param) : " << str << endl;
	cout << "Modified string (result): " << dest << endl;
	return 0;
}