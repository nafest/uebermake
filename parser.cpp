#include "parser.h"
#include <algorithm> 
#include <functional> 
#include <cctype>
#include <locale>

// trim from start
static inline std::string &ltrim(std::string &s) {
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
        return s;
}

// trim from end
static inline std::string &rtrim(std::string &s) {
        s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
        return s;
}

// trim from both ends
static inline std::string &trim(std::string &s) {
        return ltrim(rtrim(s));
}

Parser::Parser(istream& inputFile) : inputStream(inputFile)
{
}

vector<Target> Parser::parse()
{
 	vector<Target> resultTargets;
	string         line;
        bool           in_target = false;
	while (!inputStream.eof())
	{
		getline (inputStream,line);

		Target         t;

		if (int pos = line.find(":") != string::npos)
		{
			t.name = line.substr(0,pos);
			string dep = line.substr(pos+1);
			t.dep_string = trim(dep);
			in_target = true;
			resultTargets.push_back(t);
			continue;
		}
		
		// if we are in a target an the line starts
    		// with a tab this must be part of the rule

		if (in_target && line[0] == '\t') 
		{
			Target &current_target = resultTargets.back();
			current_target.rule += trim(line);
		}
		
	}
	return resultTargets;
}
