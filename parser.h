#ifndef PARSER_H
#define PARSER_H

#include "target.h"
#include <istream>
class Parser
{
private: 
	istream& inputStream;     
public:
        Parser(istream& inputFile);
	
	vector<Target> parse();
};

#endif
