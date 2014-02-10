#ifndef TARGET_H
#define TARGET_H

#include <vector>
#include <string>

using namespace std;

class Target
{
public:
  string  name;
  string  rule;
  string  dep_string;
  
  vector<Target>  dependencies;
};

#endif
