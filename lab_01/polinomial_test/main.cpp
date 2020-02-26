#include <iostream>
#include "polinomial.h"

using namespace std;

// Тесты пройдены

double myPow(double value, int pow){
    double result = 1;

    while (pow > 0){
        if (pow % 2 == 1)
            result *= value;
        value *= value;
        pow /= 2;
    }

    return result;
}

int main()
{
    /*
    cout << "======================= p1 =======================" << endl;

    Polinomial p1(2, 2);
    p1.show();
    cout << endl << endl;

    cout << "======================= p2 =======================" << endl;

    Polinomial p2(1, 3);
    p2.show();
    cout << endl << endl;


    cout << "======================= p1+p2 =======================" << endl;

    Polinomial sum = p1 + p2;
    sum.show();
    cout << endl << endl;


    cout << "======================= int p1 =======================" << endl;

    auto integrated = p1.integrate();
    integrated.show();
    cout << endl << endl;


    cout << "======================= p1*p2 =======================" << endl;

    auto mult = p1*p2;
    mult.show();
    cout << endl << endl;

    */
    /*
    cout << "start" << endl;
    Polinomial start(1, 2);
    size_t a = 2;
    start.show();
    cout << endl << "====================================" << endl;

    cout << "integrated start: " << endl;
    auto integrated = start.integrate();
    integrated.show();
    cout << endl << "====================================" << endl;

    for (size_t i=0; i < a; ++i){
        auto squared = integrated * integrated;
        cout << "squared: " << endl;
        squared.show();
        cout << endl << "====================================" << endl;

        cout << "tmp: " << endl;
        auto tmp = start + squared;
        tmp.show();
        cout << endl << "====================================" << endl;

        cout << "integrated: " << endl;
        integrated = tmp.integrate();
        integrated.show();
        cout << endl << "====================================" << endl;
    }
*/
    double a = 1.0046;
    auto res = myPow(a, 53);

    cout << "result: " << res << endl;
    /*
    Polinomial start(1, 2);
    double x = 2;
    auto result = start.count(x);
    cout << "result: " << result << endl;
    */
    return 0;
}
