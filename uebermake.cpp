#include "parser.h"
#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, const char *argv[])
{
	ifstream  file;
	file.open("Makefile");

	Parser p(file);
 	vector<Target> targets = p.parse();
	
	for (std::vector<Target>::iterator it = targets.begin();
	     it != targets.end(); ++it)
	{
		cout << (*it).name << endl;
	}
	return 0;
}
