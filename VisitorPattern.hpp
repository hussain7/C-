#include "boost/variant.hpp"
#include <iostream>
 
class my_visitor : public boost::static_visitor<int>
{
public:
    int operator()(int i) const;
    int operator()(const std::string & str) const;
 
};
 
int answer();
