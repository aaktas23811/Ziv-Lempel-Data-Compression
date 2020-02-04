// Abdulsamet AKTAS cs300 Hw2 Enjoy :)
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	ifstream input; ofstream output;
	string inputName = "compout.txt"; string outputName = "decompout.txt";
	input.open(inputName.c_str());
	output.open(outputName.c_str());
	input.clear();
	input.seekg(0);

	string myvec[4096]; 
	int i = 0;
	for (i = 0; i < 256; i++) // initializing hash array
	{
		char ch = i;
		string asci(1, ch);
		myvec[i] = asci;
	}


	int p, c, index = 255; 
	input >> p; c = p;
	
	output << myvec[p]; // outputs the first character
	while (input>>p) 
	{
		if (p <= index)
		{
			index++;
			myvec[index] = myvec[c] + myvec[p].at(0); 
			output << myvec[p] ;
		}
		else
		{
			index++;
			myvec[index] = myvec[c] + myvec[c].at(0);
			output << myvec[index] ;
		}
		c = p;
	}
	

	return 0;
}