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
        p.parse();

	EXPECT_EQ(1,0);
}
