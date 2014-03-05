#include <iostream>
#include "polynomial.h"
using namespace std;
  

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

void Polynomial::printTerms()
// Function for debugging.
{
    Term* cursor = head;
    for (int i = 1; (cursor != NULL); i++)
    {
	cout << "Term #" << i << endl;
	cout << "Coefficient: " << cursor->coef << endl;
	cout << "Exponent: " << cursor->exp << endl << endl;
	cursor = cursor->link;
    }
}

Polynomial Polynomial::sum(const Polynomial &other_poly)
// TODO maybe replace sum with operator+
{
    cout << "#####summing polynomials#####\n\n";
    Polynomial result;
    /* TODO Need to ensure we can't inadvertently modify origial object.
       Having problems declaring parameters as const.*/
    
    Term* eq_left = head;
    Term* eq_right = other_poly.head;

    while ((eq_left != NULL) && (eq_right != NULL))
    {
	cout<< "Left exp: "<< eq_left->exp << " Right exp: " << eq_right->exp << endl;
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
	    if (new_coef == 0)
	    {
	    	continue;
	    }

	    result.appendTerm(new_coef, exp);
	}
    }
    
    return result;
}


