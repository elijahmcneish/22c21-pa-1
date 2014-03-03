#include <iostream>
using namespace std;

  
class Polynomial
{
public:
    Polynomial();
    // virtual ~Polynomial();
    void appendTerm(int, int);
    void printTerms();
    Polynomial sum(const Polynomial &other_poly);
private:
    struct Term
    {
	int coef;
	int exp;
	Term* link;
    };

    Term* head;
};

Polynomial::Polynomial()
{
    head = NULL;
}

void Polynomial::appendTerm(int coef, int exp)
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
	    int new_coef = eq_left->coef + eq_right->coef;
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


int main()
{
    Polynomial p1;
    p1.appendTerm(-2,6);
    p1.appendTerm(3,4);
    p1.appendTerm(5,3);
    p1.appendTerm(2,1);
    p1.appendTerm(1,0);

    Polynomial p2;
    p2.appendTerm(2,6);
    p2.appendTerm(5,5);
    p2.appendTerm(-1,1);
    p2.appendTerm(1,0);

    Polynomial result = p1.sum(p2);
    result.printTerms();
    
    return 0;
}
