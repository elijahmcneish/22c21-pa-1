#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_

class Polynomial
{
public:
    Polynomial();
    // virtual ~Polynomial();
    void appendTerm(float, int);
    void printTerms();
    Polynomial sum(const Polynomial &other_poly);
private:
    struct Term
    {
	float coef;
	int exp;
	Term* link;
    };

    Term* head;
};

#endif
