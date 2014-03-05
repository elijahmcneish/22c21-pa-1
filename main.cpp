#include <iostream>
#include "polynomial.h"

Polynomial create_poly(int);

Polynomial create_poly(int n_deg)
{
    Polynomial poly;
    float coef;
    while (n_deg >= 0)
    {
	std::cout << "x ^ " << n_deg << " coefficient: ";
	std::cin >> coef;
	poly.appendTerm(coef, n_deg);
	--n_deg;
    }
    return poly;
}

int main()
{
    int left_deg, right_deg;
    std::cout << "Enter highest degree of first polynomial: ";
    std::cin >> left_deg;
    Polynomial left_eq = create_poly(left_deg);
    std::cout << "Enter highest degree of second polynomial: ";
    std::cin >> right_deg;
    Polynomial right_eq = create_poly(right_deg);

    Polynomial result = left_eq.sum(right_eq);
    result.printTerms();

    return 0;
}
