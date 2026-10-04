#include <iostream>
#include <string>

using namespace std;

struct Person
{
    string surname;
    int birthYear;
    Person *next;
};

class List
{
private:
    Person *Head;
    int Count;

public:
    List();
    ~List();

    void Add(string surname, int birthYear);
    void Print();
    void DelAll();
    int GetCount();
};

List::List()
{
    Head = NULL;
    Count = 0;
}

List::~List()
{
    DelAll();
}

void List::Add(string surname, int birthYear)
{
    Person *newPerson = new Person;

    newPerson->surname = surname;
    newPerson->birthYear = birthYear;
    newPerson->next = NULL;

    // Если список пустой или новый человек старше первого
    if (Head == NULL || birthYear < Head->birthYear)
    {
        newPerson->next = Head;
        Head = newPerson;
        Count++;
        return;
    }

    // Поиск места для вставки
    Person *current = Head;

    while (current->next != NULL &&
           current->next->birthYear <= birthYear)
    {
        current = current->next;
    }

    newPerson->next = current->next;
    current->next = newPerson;

    Count++;
}

void List::Print()
{
    if (Head == NULL)
    {
        cout << "Список пуст." << endl;
        return;
    }

    Person *current = Head;

    cout << "Список людей по возрасту:" << endl;

    while (current != NULL)
    {
        cout << "Фамилия: " << current->surname
             << ", год рождения: " << current->birthYear
             << endl;

        current = current->next;
    }

    cout << endl;
}

void List::DelAll()
{
    while (Head != NULL)
    {
        Person *temp = Head;
        Head = Head->next;
        delete temp;
    }

    Count = 0;
}

int List::GetCount()
{
    return Count;
}

int main()
{
    List people;

    people.Add("Иванов", 1985);
    people.Add("Петров", 2001);
    people.Add("Сидоров", 1975);
    people.Add("Кузнецов", 1990);
    people.Add("Смирнов", 1968);

    cout << "Количество записей: "
         << people.GetCount() << endl;

    cout << endl;

    people.Print();

    return 0;
}