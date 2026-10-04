#include <iostream>
#include <new>

using namespace std;

class Matrix
{
private:
    int* data;
    int rows;
    int columns;
    int state;

public:
    Matrix()
    {
        data = new (nothrow) int[1];

        if (data == nullptr)
        {
            rows = 0;
            columns = 0;
            state = 1;
            return;
        }

        rows = 1;
        columns = 1;
        data[0] = 0;
        state = 0;
    }

    Matrix(int n)
    {
        if (n <= 0)
        {
            data = nullptr;
            rows = 0;
            columns = 0;
            state = 2;
            return;
        }

        data = new (nothrow) int[n * n];

        if (data == nullptr)
        {
            rows = 0;
            columns = 0;
            state = 1;
            return;
        }

        rows = n;
        columns = n;
        state = 0;

        for (int i = 0; i < rows * columns; i++)
        {
            data[i] = 0;
        }
    }

    Matrix(int r, int c)
    {
        if (r <= 0 || c <= 0)
        {
            data = nullptr;
            rows = 0;
            columns = 0;
            state = 2;
            return;
        }

        data = new (nothrow) int[r * c];

        if (data == nullptr)
        {
            rows = 0;
            columns = 0;
            state = 1;
            return;
        }

        rows = r;
        columns = c;
        state = 0;

        for (int i = 0; i < rows * columns; i++)
        {
            data[i] = 0;
        }
    }

    ~Matrix()
    {
        delete[] data;
    }

    int get(int i, int j)
    {
        if (i < 0 || i >= rows || j < 0 || j >= columns)
        {
            state = 2;
            return 0;
        }

        state = 0;
        return data[i * columns + j];
    }

    int* getAddress(int i, int j)
    {
        if (i < 0 || i >= rows || j < 0 || j >= columns)
        {
            state = 2;
            return nullptr;
        }

        state = 0;
        return &data[i * columns + j];
    }

    void set(int i, int j, int value)
    {
        if (i < 0 || i >= rows || j < 0 || j >= columns)
        {
            state = 2;
            return;
        }

        data[i * columns + j] = value;
        state = 0;
    }

    void print() const
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                cout << data[i * columns + j] << " ";
            }

            cout << endl;
        }
    }

    Matrix add(const Matrix& other) const
    {
        if (rows != other.rows || columns != other.columns)
        {
            Matrix result;
            result.state = 3;
            return result;
        }

        Matrix result(rows, columns);

        if (result.state != 0)
        {
            return result;
        }

        for (int i = 0; i < rows * columns; i++)
        {
            result.data[i] = data[i] + other.data[i];
        }

        return result;
    }

    Matrix subtract(const Matrix& other) const
    {
        if (rows != other.rows || columns != other.columns)
        {
            Matrix result;
            result.state = 3;
            return result;
        }

        Matrix result(rows, columns);

        if (result.state != 0)
        {
            return result;
        }

        for (int i = 0; i < rows * columns; i++)
        {
            result.data[i] = data[i] - other.data[i];
        }

        return result;
    }

    Matrix multiply(const Matrix& other) const
    {
        if (columns != other.rows)
        {
            Matrix result;
            result.state = 3;
            return result;
        }

        Matrix result(rows, other.columns);

        if (result.state != 0)
        {
            return result;
        }

        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < other.columns; j++)
            {
                result.data[i * result.columns + j] = 0;

                for (int k = 0; k < columns; k++)
                {
                    result.data[i * result.columns + j] +=
                        data[i * columns + k] *
                        other.data[k * other.columns + j];
                }
            }
        }

        return result;
    }

    Matrix multiply(int number) const
    {
        Matrix result(rows, columns);

        if (result.state != 0)
        {
            return result;
        }

        for (int i = 0; i < rows * columns; i++)
        {
            result.data[i] = data[i] * number;
        }

        return result;
    }

    int getState() const
    {
        return state;
    }
};

int main()
{
    Matrix a(2, 2);
    Matrix b(2, 2);

    a.set(0, 0, 1);
    a.set(0, 1, 2);
    a.set(1, 0, 3);
    a.set(1, 1, 4);

    b.set(0, 0, 5);
    b.set(0, 1, 6);
    b.set(1, 0, 7);
    b.set(1, 1, 8);

    cout << "Матрица A:" << endl;
    a.print();

    cout << "\nМатрица B:" << endl;
    b.print();

    cout << "\nA + B:" << endl;
    Matrix sum = a.add(b);
    sum.print();

    cout << "\nA - B:" << endl;
    Matrix difference = a.subtract(b);
    difference.print();

    cout << "\nA * B:" << endl;
    Matrix product = a.multiply(b);
    product.print();

    cout << "\nA * 3:" << endl;
    Matrix numberProduct = a.multiply(3);
    numberProduct.print();

    cout << "\nЭлемент A[0][1]: "
         << a.get(0, 1) << endl;

    cout << "Адрес элемента A[0][1]: "
         << a.getAddress(0, 1) << endl;

    a.get(10, 10);

    cout << "\nКод состояния после выхода за границы: "
         << a.getState() << endl;

    return 0;
}