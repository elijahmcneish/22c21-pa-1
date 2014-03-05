#include <iostream>
#include "polynomial.h"

int main()
{
    Polynomial p1;
    p1.appendTerm(-2,6);
    p1.appendTerm(3.6,4);
    p1.appendTerm(5,3);
    p1.appendTerm(2,1);
    p1.appendTerm(1,0);

    Polynomial p2;
    p2.appendTerm(2,6);
    p2.appendTerm(5,5);
    p2.appendTerm(-1.2,1);
    p2.appendTerm(1,0);

    Polynomial result = p1.sum(p2);
    result.printTerms();
    
    return 0;
}
