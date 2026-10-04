#include <iostream>

class RealNumber
{
private:
    double value;

public:
    RealNumber(double value = 0.0) : value(value) {}

    // Оператор ++ как метод класса
    RealNumber &operator++()
    {
        ++value;
        return *this;
    }

    // Оператор + как метод класса
    RealNumber operator+(const RealNumber &other) const
    {
        return RealNumber(value + other.value);
    }

    RealNumber operator+(double number) const
    {
        return RealNumber(value + number);
    }

    // Оператор -- как дружественная функция
    friend RealNumber operator--(RealNumber &number);

    // Оператор - как дружественная функция
    friend RealNumber operator-(const RealNumber &left,
                                const RealNumber &right);

    friend RealNumber operator-(const RealNumber &left,
                                double right);

    friend RealNumber operator-(double left,
                                const RealNumber &right);

    void print() const
    {
        std::cout << value << std::endl;
    }
};

// Оператор -- как дружественная функция
RealNumber operator--(RealNumber &number)
{
    --number.value;
    return number;
}

// Вычитание двух объектов
RealNumber operator-(const RealNumber &left,
                     const RealNumber &right)
{
    return RealNumber(left.value - right.value);
}

// Вычитание double из объекта
RealNumber operator-(const RealNumber &left,
                     double right)
{
    return RealNumber(left.value - right);
}

// Вычитание объекта из double
RealNumber operator-(double left,
                     const RealNumber &right)
{
    return RealNumber(left - right.value);
}

int main()
{
    RealNumber a(10.5);
    RealNumber b(3.2);

    std::cout << "a = ";
    a.print();

    std::cout << "b = ";
    b.print();

    ++a;
    std::cout << "++a = ";
    a.print();

    --b;
    std::cout << "--b = ";
    b.print();

    RealNumber sum1 = a + b;
    RealNumber sum2 = a + 5.0;

    std::cout << "a + b = ";
    sum1.print();

    std::cout << "a + 5.0 = ";
    sum2.print();

    RealNumber diff1 = a - b;
    RealNumber diff2 = a - 2.5;
    RealNumber diff3 = 20.0 - a;

    std::cout << "a - b = ";
    diff1.print();

    std::cout << "a - 2.5 = ";
    diff2.print();

    std::cout << "20.0 - a = ";
    diff3.print();

    return 0;
}