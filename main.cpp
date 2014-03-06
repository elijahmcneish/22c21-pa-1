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

Polynomial create_poly(int);

Polynomial create_poly(int n_deg)
// Get polynomial terms from user.
{
    Polynomial poly;
    float coef;

    while (n_deg >= 0)
    {
	std::cout << "x^" << n_deg << " coefficient: ";
	std::cin >> coef;
	poly.appendTerm(coef, n_deg);
	--n_deg;
    }

    std::cout << std::endl;
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
    std::cout << "Sum: ";
    result.printTerms();
    std::cout << std::endl;
    
    return 0;
}
