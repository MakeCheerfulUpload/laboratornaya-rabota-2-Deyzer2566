#include <iostream>
#include <string>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	string s;
	bool e = 1;
	cout << "1234567" << endl;
	do{
		e = 1;
		cin >> s;
		for (char c : s)
		{
			e = e && (c == '0' || c == '1');
			if (!e)
				break;
		}
	}while (s.length() != 7 || !e);
	for (char & c : s)
		c -= '0';
	bool r1 = s[2] ^ s[4] ^ s[6];
	bool r2 = s[2] ^ s[5] ^ s[6];
	bool r3 = s[4] ^ s[5] ^ s[6];
	size_t p = 0;
	if (r1 != s[0]) p += 1;
	if (r2 != s[1]) p += 2;
	if (r3 != s[3]) p += 4;
	if (p != 0)
		s[p - 1] ^= 1;
	s.erase(3, 1);
	s.erase(0, 2);
	for (char & c : s)
		c += '0';
	cout << s << endl;
	if (p > 0)
		cout<< "Ошибка в " << p << " бите" << endl;
	cin.get();
}