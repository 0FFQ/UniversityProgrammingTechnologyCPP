#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

struct Student
{
    string surname;
    int day;
    int month;
    int year;
    int grade1;
    int grade2;
    int grade3;
};

int main()
{
    const int N = 6;
    Student students[N];

    // Ввод данных
    cout << "Введите данные о " << N << " студентах:" << endl;

    for (int i = 0; i < N; i++)
    {
        cout << "\nСтудент " << i + 1 << endl;

        cout << "Фамилия: ";
        cin >> students[i].surname;

        char dot1, dot2;

        cout << "Дата рождения (дд.мм.гггг): ";
        cin >> students[i].day >> dot1 >> students[i].month >> dot2 >> students[i].year;

        cout << "Оценки по трем предметам: ";
        cin >> students[i].grade1 >> students[i].grade2 >> students[i].grade3;
    }

    // Сохранение данных в файл
    ofstream file("students.txt");

    if (!file)
    {
        cout << "Ошибка открытия файла!" << endl;
        return 1;
    }

    for (int i = 0; i < N; i++)
    {
        file << students[i].surname << " "
             << students[i].day << "."
             << students[i].month << "."
             << students[i].year << " "
             << students[i].grade1 << " "
             << students[i].grade2 << " "
             << students[i].grade3 << endl;
    }

    file.close();

    // Сортировка по дате рождения
    sort(students, students + N, [](const Student &a, const Student &b)
         {
        if (a.year != b.year)
            return a.year < b.year;

        if (a.month != b.month)
            return a.month < b.month;

        return a.day < b.day; });

    cout << "\nСтуденты, отсортированные по дате рождения:" << endl;

    for (int i = 0; i < N; i++)
    {
        cout << students[i].surname << " - "
             << students[i].day << "."
             << students[i].month << "."
             << students[i].year << endl;
    }

    // Поиск студентов, родившихся зимой
    bool found = false;

    cout << "\nСтуденты, родившиеся зимой:" << endl;

    for (int i = 0; i < N; i++)
    {
        if (students[i].month == 12 ||
            students[i].month == 1 ||
            students[i].month == 2)
        {
            cout << "\nФамилия: " << students[i].surname << endl;

            cout << "Дата рождения: "
                 << students[i].day << "."
                 << students[i].month << "."
                 << students[i].year << endl;

            cout << "Оценки: "
                 << students[i].grade1 << " "
                 << students[i].grade2 << " "
                 << students[i].grade3 << endl;

            found = true;
        }
    }

    if (!found)
    {
        cout << "Студентов, родившихся зимой, нет." << endl;
    }

    return 0;
}