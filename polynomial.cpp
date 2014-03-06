/* polynomial.cpp
 * Copyright (c) 2014 Elijah McNeish. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>
#include "polynomial.h"

Polynomial::Polynomial()
{
    head = NULL;
}

void Polynomial::appendTerm(float coef, int exp)
{
    Term* new_term = new Term;
    new_term->coef = coef;
    new_term->exp = exp;
    new_term->link = NULL;

    if (head == NULL) // Linked list is empty.
    {
    	head = new_term;
    	return;
    }
    Term* cursor;
    cursor = head;
    while (cursor->link != NULL) // Find tail node.
    {
    	cursor = cursor->link;
    }
    cursor->link = new_term;
    
}

void Polynomial::printTerms() const
/*
  Print the polynomial in the form
  a1x^n + a2x^n-1...
*/
{
    Term* cursor = head;
    
    while (true)
    {
	switch (cursor->exp) // Handle x^1 and x^0 cases.
	{
	case 0:
	    std::cout << cursor->coef;
	    break;
	case 1:
	    std::cout << cursor->coef << "x";
	    break;
	default:
	    std::cout << cursor->coef << "x^" << cursor->exp;
	}

	// Get the next term.
	cursor = cursor->link;
	if (cursor == NULL) {break;}

	// If another term follows, print the correct operator.
	char op = '+';
	if (cursor->coef < 0) { op = '-'; }
	else if (cursor->coef == 0) { op = '\0'; }
	std::cout << " " << op << " ";
    }
}

Polynomial Polynomial::sum(const Polynomial &other_poly) const
{
    Polynomial result;
    Term* eq_left = head;
    Term* eq_right = other_poly.head;

    while ((eq_left != NULL) && (eq_right != NULL))
    {
	if (eq_left->exp > eq_right->exp)
	{
	    result.appendTerm(eq_left->coef, eq_left->exp);
	    eq_left = eq_left->link;
	}

	else if (eq_left->exp < eq_right->exp)
	{
	    result.appendTerm(eq_right->coef, eq_right->exp);
	    eq_right = eq_right->link;
	}
	
	else // Exponents are equal.
	{
	    float new_coef = eq_left->coef + eq_right->coef;
	    int exp = eq_left->exp;
	    
	    eq_left = eq_left->link;
	    eq_right = eq_right->link;
	    if (new_coef == 0) { continue; }

	    result.appendTerm(new_coef, exp);
	}
    }
    
    return result;
}
