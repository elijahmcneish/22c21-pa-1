#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_

class Polynomial
{
public:
    Polynomial();
    void appendTerm(float, int);
    void printTerms() const;
    // Polynomial sum(const Polynomial &other_poly) const;
    Polynomial sum(const Polynomial &other_poly) const;
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
