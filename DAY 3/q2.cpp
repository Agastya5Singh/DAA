#include <iostream>
using namespace std;

int GCDEuclid(int a, int b)
{
    int rem;
    while (a > 0)
    {
        rem = b % a;
        b = a;
        a = rem;
    }
    return b;
}

int consecIntegerChecking(int a, int b)
{
    int t;

    if (a > b)
        t = b;
    else
        t = a;
    while (t > 0)
    {
        if (a % t == 0 && b % t == 0)
        {
            return t;
        }
        else
        {
            t--;
        }
    }
    return 0;
}

int primarySchoolMethod(int num1, int num2)
{
    int factor1, factor2;
    int product = 1;

    for (factor1 = 2, factor2 = 2; num1 >= factor1, num2 >= factor2; factor1++, factor2++)
    {
        while (num1 % factor1 == 0 && num2 % factor2 == 0)
        {
            num1 = num1 / factor1;
            num2 = num2 / factor2;

            product = product * factor1;
        }
    }
    return product;
}

int main()
{
    cout<<"GCD of 162375 and 75 by Euclid's algorithm = "<<" "<<GCDEuclid(162375, 75)<<endl;

    cout<<"GCD of 162375 and 75 by Consecutive integer checking algorithm = "<<" "<<consecIntegerChecking(162375, 75)<<endl;

    cout<<"GCD of 162375 and 75 by using prime factorization method = "<<" "<<primarySchoolMethod(162375, 75);
    return 0;
}