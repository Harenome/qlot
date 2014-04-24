/**
 * \file identifiant_vente.hpp
 * \brief Identifiant vente.
 * \author RAZANAJATO RANAIVOARIVONY Harenome
 * \author MEYER Jérémy
 * \date 2014
 * \copyright WTFPL version 2
 */
/* This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar. See
 * http://www.wtfpl.net/ for more details.
 */
#ifndef __IDENTIFIANT_VENTE_HPP__
#define __IDENTIFIANT_VENTE_HPP__

#include <ostream>
#include <istream>
#include <algorithm>

#include "date.hpp"

class identifiant_vente
{
public:
    identifiant_vente (void);
    identifiant_vente (const identifiant_vente & i);
    identifiant_vente (const date & d, unsigned int c);
    ~identifiant_vente (void);
    void swap (identifiant_vente & i);
    identifiant_vente & operator= (identifiant_vente i);
private:
    unsigned int _identifiant;
};

inline void swap (identifiant_vente & a, indentifiant_vente & b);

#endif /* __IDENTIFIANT_VENTE_HPP__ */
