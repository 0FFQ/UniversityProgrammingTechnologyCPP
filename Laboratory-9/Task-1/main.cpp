#include <iostream>

using namespace std;

template <class T>
class Polynom
{
private:
    int degree;
    T *coefficients;

public:
    Polynom()
    {
        degree = 0;
        coefficients = new T[1];
        coefficients[0] = 0;
    }

    Polynom(int n)
    {
        degree = n;
        coefficients = new T[degree + 1];

        for (int i = 0; i <= degree; i++)
        {
            coefficients[i] = 0;
        }
    }

    Polynom(const Polynom &other)
    {
        degree = other.degree;
        coefficients = new T[degree + 1];

        for (int i = 0; i <= degree; i++)
        {
            coefficients[i] = other.coefficients[i];
        }
    }

    ~Polynom()
    {
        delete[] coefficients;
    }

    Polynom &operator=(const Polynom &other)
    {
        if (this != &other)
        {
            delete[] coefficients;

            degree = other.degree;
            coefficients = new T[degree + 1];

            for (int i = 0; i <= degree; i++)
            {
                coefficients[i] = other.coefficients[i];
            }
        }

        return *this;
    }

    T &operator[](int index)
    {
        return coefficients[index];
    }

    const T &operator[](int index) const
    {
        return coefficients[index];
    }

    Polynom operator+(const Polynom &other) const
    {
        int maxDegree = (degree > other.degree) ? degree : other.degree;

        Polynom result(maxDegree);

        for (int i = 0; i <= maxDegree; i++)
        {
            T a = (i <= degree) ? coefficients[i] : 0;
            T b = (i <= other.degree) ? other.coefficients[i] : 0;

            result.coefficients[i] = a + b;
        }

        return result;
    }

    Polynom operator-(const Polynom &other) const
    {
        int maxDegree = (degree > other.degree) ? degree : other.degree;

        Polynom result(maxDegree);

        for (int i = 0; i <= maxDegree; i++)
        {
            T a = (i <= degree) ? coefficients[i] : 0;
            T b = (i <= other.degree) ? other.coefficients[i] : 0;

            result.coefficients[i] = a - b;
        }

        return result;
    }

    Polynom operator*(const Polynom &other) const
    {
        Polynom result(degree + other.degree);

        for (int i = 0; i <= degree; i++)
        {
            for (int j = 0; j <= other.degree; j++)
            {
                result.coefficients[i + j] +=
                    coefficients[i] * other.coefficients[j];
            }
        }

        return result;
    }

    Polynom &operator++()
    {
        for (int i = 0; i <= degree; i++)
        {
            ++coefficients[i];
        }

        return *this;
    }

    Polynom &operator--()
    {
        for (int i = 0; i <= degree; i++)
        {
            --coefficients[i];
        }

        return *this;
    }

    T Calculate(T x) const
    {
        T result = 0;

        for (int i = degree; i >= 0; i--)
        {
            result = result * x + coefficients[i];
        }

        return result;
    }

    void Print() const
    {
        bool first = true;

        for (int i = degree; i >= 0; i--)
        {
            if (coefficients[i] == 0)
                continue;

            if (!first)
            {
                if (coefficients[i] > 0)
                    cout << " + ";
                else
                    cout << " - ";
            }
            else if (coefficients[i] < 0)
            {
                cout << "-";
            }

            T value = coefficients[i];

            if (value < 0)
                value = -value;

            if (i == 0)
            {
                cout << value;
            }
            else if (i == 1)
            {
                if (value != 1)
                    cout << value << "*";
                cout << "x";
            }
            else
            {
                if (value != 1)
                    cout << value << "*";
                cout << "x^" << i;
            }

            first = false;
        }

        if (first)
            cout << "0";

        cout << endl;
    }
};

template <class T>
Polynom<T> SumPolynoms(Polynom<T> arr[], int size)
{
    Polynom<T> result;

    for (int i = 0; i < size; i++)
    {
        result = result + arr[i];
    }

    return result;
}

int main()
{
    Polynom<double> p1(2);
    p1[0] = 3;
    p1[1] = 2;
    p1[2] = 1;

    Polynom<double> p2(2);
    p2[0] = 1;
    p2[1] = -2;
    p2[2] = 2;

    Polynom<double> p3(1);
    p3[0] = 5;
    p3[1] = 4;

    cout << "P1(x) = ";
    p1.Print();

    cout << "P2(x) = ";
    p2.Print();

    cout << "P3(x) = ";
    p3.Print();

    cout << endl;

    Polynom<double> sum = p1 + p2;

    cout << "P1 + P2 = ";
    sum.Print();

    Polynom<double> difference = p1 - p2;

    cout << "P1 - P2 = ";
    difference.Print();

    Polynom<double> product = p1 * p3;

    cout << "P1 * P3 = ";
    product.Print();

    cout << endl;

    cout << "P1(2) = " << p1.Calculate(2.0) << endl;

    Polynom<double> array[3];

    array[0] = p1;
    array[1] = p2;
    array[2] = p3;

    Polynom<double> total = SumPolynoms(array, 3);

    cout << "Сумма полиномов массива = ";
    total.Print();

    ++p1;

    cout << "После ++P1 = ";
    p1.Print();

    --p1;

    cout << "После --P1 = ";
    p1.Print();

    return 0;
}