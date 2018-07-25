#pragma once

#include<string>
#include <iostream>

class Logger {

public:
  void err(std::string str)
  { std::cerr << "ERROR: " << str << std::endl; }

  void info(std::string str) 
  { std::cout << "LOG: " << str << std::endl; }


};
