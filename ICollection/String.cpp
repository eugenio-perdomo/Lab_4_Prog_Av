#include <stddef.h>
#include <stdexcept>
#include <string.h>
#include "./String.h"


String::String(std::string str) : s(str){
    /*if(str == NULL)
        throw std::invalid_argument("str es NULL");

    int strSize = strlen(str);
    s = strcpy(new char[strSize+1], str);*/
}

ComparisonRes String::compare(OrderedKey* k) const
{
    String *str = dynamic_cast<String *>(k);
    if(str == NULL)
        throw std::invalid_argument("Invalid key k");

    int cmp = s.compare(str->s);
    if(cmp == 0)
        return EQUAL;
    else if(cmp > 0)
        return GREATER;
    else
        return LESSER;
}

std::string String::getValue() const
{
    return s;
}

String::~String(){
    //delete s;
}
