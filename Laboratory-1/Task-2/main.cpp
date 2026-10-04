#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct PRICE
{
    string productName;
    string storeName;
    double price;
};

int main()
{
    const int N = 8;
    PRICE products[N];

    // Ввод данных
    cout << "Введите данные о " << N << " товарах:" << endl;

    for (int i = 0; i < N; i++)
    {
        cout << "\nТовар " << i + 1 << endl;

        cout << "Название товара: ";
        cin.ignore(i == 0 ? 0 : 1);
        getline(cin, products[i].productName);

        cout << "Название магазина: ";
        getline(cin, products[i].storeName);

        cout << "Стоимость товара (руб.): ";
        cin >> products[i].price;
    }

    // Сортировка по названию товара
    sort(products, products + N, [](const PRICE &a, const PRICE &b)
         { return a.productName < b.productName; });

    // Вывод отсортированного списка
    cout << "\nТовары в алфавитном порядке:" << endl;

    for (int i = 0; i < N; i++)
    {
        cout << "\nТовар: " << products[i].productName << endl;
        cout << "Магазин: " << products[i].storeName << endl;
        cout << "Стоимость: " << products[i].price << " руб." << endl;
    }

    // Поиск товара
    string searchName;

    cout << "\nВведите название товара для поиска: ";
    cin.ignore();
    getline(cin, searchName);

    bool found = false;

    for (int i = 0; i < N; i++)
    {
        if (products[i].productName == searchName)
        {
            cout << "\nТовар найден:" << endl;
            cout << "Название: " << products[i].productName << endl;
            cout << "Магазин: " << products[i].storeName << endl;
            cout << "Стоимость: " << products[i].price << " руб." << endl;

            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "\nТовар с таким названием не найден." << endl;
    }

    return 0;
}