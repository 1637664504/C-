/* 
字符串流
 */
#include <string>       // std::string
#include <iostream>     // std::cout
#include <sstream>      // std::stringstream
 
int main () {
 
  std::stringstream ss;
 
  ss << "hello world";
  std::cout << ss.str() << '\n';
 
  return 0;
}