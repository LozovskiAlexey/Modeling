#include "polinomial.h"


Polinomial::Polinomial(const size_t power) : _power(power)
{
    polinomial = std::vector<double> (_power+1, 0.);
}


Polinomial::Polinomial(const double coeff, const size_t power) : _power(power)
{
    polinomial = std::vector<double> (_power+1, 0.);
    polinomial[_power] = coeff;
}


// Исправлено
Polinomial Polinomial::operator+(const Polinomial &other)
{
    // создаем полином с наибольшей из двух степенью
    Polinomial result(std::max(_power, other._power));

    // проходим по всем коэф-там при икс, суммируем, степень - индекс элемента
    for (size_t tmp_power=0; tmp_power<=_power; ++tmp_power){
        result.polinomial[tmp_power] += polinomial[tmp_power];
    }

    for (size_t tmp_power=0; tmp_power<=other._power; ++tmp_power){
        result.polinomial[tmp_power] += other.polinomial[tmp_power];
    }

    return result;
}


Polinomial Polinomial::operator*(const Polinomial &other)
{
    Polinomial result(_power+other._power);

    size_t tmp_power;
    double coeff;

    for (size_t i=0; i<=_power; ++i)
        for (size_t j=0; j<=other._power; ++j)
        {
            tmp_power = i+j;                           // складываем степени (x^n * x^m = x^(n+m))
            coeff = polinomial[i]*other.polinomial[j]; // считаем коэфф-ты при икс
            result.polinomial[tmp_power] += coeff;            // увеличиваем коэфф-т при икс в степени tmp_coeff
        }

    return result;
}


Polinomial Polinomial::integrate()
{
    size_t new_power = _power+1;
    Polinomial integrated = Polinomial(new_power);

    size_t integrated_power;
    double integrated_coeff;

    // интегрируем по формуле integral C * (x^n) = C * x^(n+1) / n+1
    for (size_t tmp_power=0; tmp_power<new_power; ++tmp_power)
    {
        integrated_power = tmp_power + 1;
        integrated_coeff = polinomial[tmp_power] / integrated_power;
        integrated.set(integrated_power, integrated_coeff);
    }

    return integrated;
}


void Polinomial::set(const size_t power, const double coeff)
{
    polinomial[power] = coeff;
}


double Polinomial::count(const double x)
{
    auto result = 0.;

    for (size_t tmp_power=0; tmp_power<=_power; ++tmp_power)
        result += polinomial[tmp_power] * std::pow(x, tmp_power);

    return result;
}

void Polinomial::show(){

    std::cout << "power = " << _power << std::endl;

    for (size_t i=0; i<=_power; ++i)
    {
        if (i>0){
            std::cout << " + ";
        }
        std::cout << polinomial[i] << "*X^(" << i << ")";
    }
}
