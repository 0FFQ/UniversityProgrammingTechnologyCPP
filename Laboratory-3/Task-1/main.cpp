#include <iostream>
#include <new>

using namespace std;

class Vector
{
private:
    int *data;
    int size;
    int state;

    static int objectCount;

public:
    Vector()
    {
        data = new (nothrow) int[1];

        if (data == nullptr)
        {
            size = 0;
            state = 1;
            return;
        }

        size = 1;
        data[0] = 0;
        state = 0;
        objectCount++;
    }

    Vector(int n)
    {
        if (n <= 0)
        {
            data = nullptr;
            size = 0;
            state = 2;
            return;
        }

        data = new (nothrow) int[n];

        if (data == nullptr)
        {
            size = 0;
            state = 1;
            return;
        }

        size = n;
        state = 0;

        for (int i = 0; i < size; i++)
        {
            data[i] = i;
        }

        objectCount++;
    }

    Vector(int n, int value)
    {
        if (n <= 0)
        {
            data = nullptr;
            size = 0;
            state = 2;
            return;
        }

        data = new (nothrow) int[n];

        if (data == nullptr)
        {
            size = 0;
            state = 1;
            return;
        }

        size = n;
        state = 0;

        for (int i = 0; i < size; i++)
        {
            data[i] = value;
        }

        objectCount++;
    }

    ~Vector()
    {
        delete[] data;

        if (data != nullptr)
        {
            objectCount--;
        }
    }

    void set(int index, int value = 0)
    {
        if (index < 0 || index >= size)
        {
            state = 2;
            return;
        }

        data[index] = value;
        state = 0;
    }

    int get(int index)
    {
        if (index < 0 || index >= size)
        {
            state = 2;
            return 0;
        }

        state = 0;
        return data[index];
    }

    void print() const
    {
        for (int i = 0; i < size; i++)
        {
            cout << data[i] << " ";
        }

        cout << endl;
    }

    Vector add(int number) const
    {
        Vector result(size);

        if (result.state != 0)
        {
            return result;
        }

        for (int i = 0; i < size; i++)
        {
            result.data[i] = data[i] + number;
        }

        return result;
    }

    Vector subtract(int number) const
    {
        Vector result(size);

        if (result.state != 0)
        {
            return result;
        }

        for (int i = 0; i < size; i++)
        {
            result.data[i] = data[i] - number;
        }

        return result;
    }

    Vector multiply(int number) const
    {
        Vector result(size);

        if (result.state != 0)
        {
            return result;
        }

        for (int i = 0; i < size; i++)
        {
            result.data[i] = data[i] * number;
        }

        return result;
    }

    bool greaterThan(int number) const
    {
        for (int i = 0; i < size; i++)
        {
            if (data[i] <= number)
            {
                return false;
            }
        }

        return true;
    }

    bool lessThan(int number) const
    {
        for (int i = 0; i < size; i++)
        {
            if (data[i] >= number)
            {
                return false;
            }
        }

        return true;
    }

    bool equalTo(int number) const
    {
        for (int i = 0; i < size; i++)
        {
            if (data[i] != number)
            {
                return false;
            }
        }

        return true;
    }

    int getState() const
    {
        return state;
    }

    static int getObjectCount()
    {
        return objectCount;
    }
};

int Vector::objectCount = 0;

int main()
{
    Vector v1;
    Vector v2(5);
    Vector v3(4, 10);

    cout << "Вектор v1: ";
    v1.print();
    cout << "Вектор v2: ";
    v2.print();
    cout << "Вектор v3: ";
    v3.print();

    v1.set(0, 15);

    cout << "\nПосле изменения v1: ";
    v1.print();

    cout << "\nv2 + 5: ";
    Vector sum = v2.add(5);
    sum.print();

    cout << "v2 - 2: ";
    Vector difference = v2.subtract(2);
    difference.print();

    cout << "v2 * 3: ";
    Vector product = v2.multiply(3);
    product.print();

    cout << "\nСравнение v3 с числом 10:" << endl;
    cout << "Больше: " << (v3.greaterThan(10) ? "да" : "нет") << endl;
    cout << "Меньше: " << (v3.lessThan(10) ? "да" : "нет") << endl;
    cout << "Равно: " << (v3.equalTo(10) ? "да" : "нет") << endl;

    v1.get(10);

    cout << "\nКод состояния после выхода за границы: "
         << v1.getState() << endl;

    cout << "\nКоличество объектов Vector: "
         << Vector::getObjectCount() << endl;

    return 0;
}