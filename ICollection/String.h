/*
 * File:   String.h
 * Author: igui
 *
 * Created on 29 de mayo de 2011, 06:53 PM
 */
#ifndef STRING_H
#define STRING_H

#include "./interfaces/ICollectible.h"
#include "./interfaces/OrderedKey.h"

/**
 *  Implementación simple del datatype String que hereda tanto de ICollectible
 *  como de HashedKey
 */
class String: public ICollectible, public OrderedKey
{
private:
    std::string s;
public:
    // construye el Datatype a partir de un puntero a caracter
    String(std::string str);

    // da el valor del string
    std::string getValue() const;

    ComparisonRes compare(OrderedKey *k) const;

    virtual ~String();

};

#endif	/* PROG4_STRING_H */
