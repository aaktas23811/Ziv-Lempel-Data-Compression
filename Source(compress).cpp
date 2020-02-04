// Abdulsamet AKTAS cs300 Hw2 Enjoy :)
#include<iostream>
#include<string>
#include<fstream>
#include"Hashmap.h"

using namespace std;

int main()
{
	string compin = "compin.txt"; string compout = "compout.txt";
	ifstream input; ofstream output;
	input.open(compin.c_str());
	output.open(compout.c_str());
	input.clear();
	input.seekg(0);

	HashMap<string, int> myTable;

	// initialize the table according to ascii values
	for (int i = 0; i < 256; i++) 
	{
		char ch = i;
		string asci(1, ch);
		myTable.insertion(asci, i);
	}
	
	int emptyIndex = 256; // keeps next available index
	char ch;
	string p = "";

	while (!input.eof())
	{
		input.get(ch);
		string c(1, ch);

		if (!(myTable.ifexist(p + c)) && !input.eof())
		{
			myTable.insertion((p + c), emptyIndex);
			emptyIndex++;
			output << myTable.getValue(p) << " ";
			p = c;
		}
		else if ((myTable.ifexist(p + c)) && !input.eof())
			p = p + c;
	}
	output << myTable.getValue(p) << " ";
	input.close();
	output.close();
	return 0;
}