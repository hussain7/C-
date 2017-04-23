#include "VisitorPattern.hpp"
 
#include "boost/variant.hpp"
#include <iostream>
 

int my_visitor::operator()(int i) const
{
    return i;
}
 
int my_visitor::operator()(const std::string & str) const
{
    return str.length();
}
 
 
int answer()
{
    boost::variant< int, std::string > u("hello world");
    int result = boost::apply_visitor( my_visitor(), u );
    return result;
}
