#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[])
{
	if (argc < 2) return -1;

	ifstream File;
	File.open(argv[1], ios::binary);

	int Count = 0; //Переменная счётчик
	while (true)
	{
		int p = File.get();
		if (p == -1)
			break;
		//Подсчитывается каждый байт, который начинается с нуля или с двух единиц
		//Первое услоиве будет перехватывать каждую кодовую точку представленную одним байтом
		//Второе условие - байт каждой многобайтовой последовательности
		else if ((p & 0x80) == 0 || (p & 0xc0) == 0xc0)
			++Count;
	}

	cout << "Number of characters: " << Count;
	File.close();
}