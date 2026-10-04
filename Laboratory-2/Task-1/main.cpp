#include <iostream>
#include <string>

using namespace std;

class Book
{
private:
    string author;
    string title;
    string publisher;
    int year;
    int pages;

public:
    // Конструктор
    Book()
    {
        author = "";
        title = "";
        publisher = "";
        year = 0;
        pages = 0;
    }

    // Методы set
    void setAuthor(const string &value)
    {
        author = value;
    }

    void setTitle(const string &value)
    {
        title = value;
    }

    void setPublisher(const string &value)
    {
        publisher = value;
    }

    void setYear(int value)
    {
        year = value;
    }

    void setPages(int value)
    {
        pages = value;
    }

    // Методы get
    string getAuthor() const
    {
        return author;
    }

    string getTitle() const
    {
        return title;
    }

    string getPublisher() const
    {
        return publisher;
    }

    int getYear() const
    {
        return year;
    }

    int getPages() const
    {
        return pages;
    }

    // Вывод информации о книге
    void show() const
    {
        cout << "Автор: " << author << endl;
        cout << "Название: " << title << endl;
        cout << "Издательство: " << publisher << endl;
        cout << "Год издания: " << year << endl;
        cout << "Количество страниц: " << pages << endl;
    }

    // Проверка автора
    bool hasAuthor(const string &value) const
    {
        return author == value;
    }

    // Проверка издательства
    bool hasPublisher(const string &value) const
    {
        return publisher == value;
    }

    // Проверка года издания
    bool isPublishedAfter(int value) const
    {
        return year > value;
    }
};

int main()
{
    const int N = 5;
    Book books[N];

    cout << "Введите данные о " << N << " книгах." << endl;

    for (int i = 0; i < N; i++)
    {
        string author;
        string title;
        string publisher;
        int year;
        int pages;

        cout << "\nКнига " << i + 1 << endl;

        cout << "Автор: ";
        getline(cin >> ws, author);

        cout << "Название: ";
        getline(cin, title);

        cout << "Издательство: ";
        getline(cin, publisher);

        cout << "Год издания: ";
        cin >> year;

        cout << "Количество страниц: ";
        cin >> pages;

        books[i].setAuthor(author);
        books[i].setTitle(title);
        books[i].setPublisher(publisher);
        books[i].setYear(year);
        books[i].setPages(pages);
    }

    // Поиск книг заданного автора
    string searchAuthor;

    cout << "\nВведите автора для поиска: ";
    getline(cin >> ws, searchAuthor);

    bool found = false;

    cout << "\nКниги заданного автора:" << endl;

    for (int i = 0; i < N; i++)
    {
        if (books[i].hasAuthor(searchAuthor))
        {
            cout << "\n";
            books[i].show();
            found = true;
        }
    }

    if (!found)
    {
        cout << "Книг данного автора нет." << endl;
    }

    // Поиск книг заданного издательства
    string searchPublisher;

    cout << "\nВведите издательство для поиска: ";
    getline(cin >> ws, searchPublisher);

    found = false;

    cout << "\nКниги заданного издательства:" << endl;

    for (int i = 0; i < N; i++)
    {
        if (books[i].hasPublisher(searchPublisher))
        {
            cout << "\n";
            books[i].show();
            found = true;
        }
    }

    if (!found)
    {
        cout << "Книг данного издательства нет." << endl;
    }

    // Поиск книг, выпущенных после заданного года
    int searchYear;

    cout << "\nВведите год: ";
    cin >> searchYear;

    found = false;

    cout << "\nКниги, выпущенные после " << searchYear << " года:" << endl;

    for (int i = 0; i < N; i++)
    {
        if (books[i].isPublishedAfter(searchYear))
        {
            cout << "\n";
            books[i].show();
            found = true;
        }
    }

    if (!found)
    {
        cout << "Книг, выпущенных после " << searchYear
             << " года, нет." << endl;
    }

    return 0;
}