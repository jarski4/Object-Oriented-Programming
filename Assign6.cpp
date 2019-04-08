/*
   COPYRIGHT (C) 2019 Jared Skinner (jss136) All rights reserved.
   Object Oriented Programming
   Author.  Jared Skinner
            jss136@zips.uakron.edu
   Version. 1.01 04.02.2019

  Implement a JSON data structure using inheritance.
*/
#include "json.hpp"

#include <iterator>
#include <iostream>
#include <string>

int
main(int argc, char* argv[])
{
  std::istreambuf_iterator<char> first(std::cin);
  std::istreambuf_iterator<char> last;
  std::string s(first, last);

  json::Value* val = json::parse(s);

  // std::cout << size(val) << ' ' << height(val) << '\n';
  std::cout << *val << '\n';
}
