#ifndef TO_STRING_H_INCLUDED
#define TO_STRING_H_INCLUDED

#include <sstream>
#include <string>

//enable the "to_string" function of std:: as code-blocks has bugs with it not working correctly
template <typename T>
std::string to_string(T value){
      //create an output string stream
      std::ostringstream os ;
      //throw the value into the string stream
      os << value ;
      //convert the string stream into a string and return
      return os.str() ;
}

#endif // TO_STRING_H_INCLUDED
