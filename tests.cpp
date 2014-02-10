#include <gtest/gtest.h>
#include "parser.h"

TEST(Case,Name)
{
	EXPECT_EQ(1,1);
}

TEST(Parser,SimpleRuleIsParsedCorrectly)
{
	string rule = "a: b";
       	istringstream  istr(rule);
       
	Parser p(istr);
        vector<Target> targets = p.parse();

	EXPECT_STREQ(targets[0].name.c_str(),"a");
	EXPECT_STREQ(targets[0].dep_string.c_str(),"b");
}

TEST(Parser,SimpleTwoLineRuleIsParsedCorrectly)
{
	string rule = "a: b\n\trule";
       	istringstream  istr(rule);
       
	Parser p(istr);
        vector<Target> targets = p.parse();

	EXPECT_STREQ(targets[0].name.c_str(),"a");
	EXPECT_STREQ(targets[0].dep_string.c_str(),"b");
	EXPECT_STREQ(targets[0].rule.c_str(),"rule");
}
