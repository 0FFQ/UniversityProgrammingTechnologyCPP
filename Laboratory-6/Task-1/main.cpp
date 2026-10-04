#include <iostream>
#include <string>

using namespace std;

struct Application
{
    string destination;
    int flightNumber;
    string passenger;
    string departureDate;
};

struct Node
{
    Application data;
    Node *next;
};

class Stack
{
private:
    Node *top;
    int count;

public:
    Stack();
    ~Stack();

    void Push(const Application &application);
    bool Pop(Application &application);
    bool IsEmpty() const;
    int GetCount() const;

    void ShowAll() const;
    void Find(int flightNumber, const string &departureDate) const;
    void Clear();
};

Stack::Stack()
{
    top = nullptr;
    count = 0;
}

Stack::~Stack()
{
    Clear();
}

void Stack::Push(const Application &application)
{
    Node *newNode = new Node;

    newNode->data = application;
    newNode->next = top;

    top = newNode;
    count++;
}

bool Stack::Pop(Application &application)
{
    if (IsEmpty())
        return false;

    Node *temp = top;

    application = top->data;
    top = top->next;

    delete temp;
    count--;

    return true;
}

bool Stack::IsEmpty() const
{
    return top == nullptr;
}

int Stack::GetCount() const
{
    return count;
}

void Stack::ShowAll() const
{
    if (IsEmpty())
    {
        cout << "Стек пуст." << endl;
        return;
    }

    Node *current = top;

    cout << "Все заявки:" << endl;

    while (current != nullptr)
    {
        cout << "Пункт назначения: "
             << current->data.destination << endl;

        cout << "Номер рейса: "
             << current->data.flightNumber << endl;

        cout << "Пассажир: "
             << current->data.passenger << endl;

        cout << "Дата вылета: "
             << current->data.departureDate << endl;

        cout << "------------------------" << endl;

        current = current->next;
    }
}

void Stack::Find(int flightNumber, const string &departureDate) const
{
    Node *current = top;
    bool found = false;

    while (current != nullptr)
    {
        if (current->data.flightNumber == flightNumber &&
            current->data.departureDate == departureDate)
        {
            cout << "Заявка найдена:" << endl;

            cout << "Пункт назначения: "
                 << current->data.destination << endl;

            cout << "Номер рейса: "
                 << current->data.flightNumber << endl;

            cout << "Пассажир: "
                 << current->data.passenger << endl;

            cout << "Дата вылета: "
                 << current->data.departureDate << endl;

            found = true;
        }

        current = current->next;
    }

    if (!found)
    {
        cout << "Заявка не найдена." << endl;
    }
}

void Stack::Clear()
{
    while (!IsEmpty())
    {
        Application application;
        Pop(application);
    }
}

int main()
{
    Stack applications;

    Application application1;
    application1.destination = "Москва";
    application1.flightNumber = 101;
    application1.passenger = "Иванов И.И.";
    application1.departureDate = "10.10.2026";

    Application application2;
    application2.destination = "Санкт-Петербург";
    application2.flightNumber = 205;
    application2.passenger = "Петров П.П.";
    application2.departureDate = "12.10.2026";

    Application application3;
    application3.destination = "Казань";
    application3.flightNumber = 310;
    application3.passenger = "Сидоров С.С.";
    application3.departureDate = "15.10.2026";

    applications.Push(application1);
    applications.Push(application2);
    applications.Push(application3);

    cout << "Количество заявок: "
         << applications.GetCount() << endl;

    cout << endl;

    applications.ShowAll();

    cout << endl;

    cout << "Поиск заявки:" << endl;
    applications.Find(205, "12.10.2026");

    cout << endl;

    Application deletedApplication;

    if (applications.Pop(deletedApplication))
    {
        cout << "Удалена заявка:" << endl;

        cout << "Пункт назначения: "
             << deletedApplication.destination << endl;

        cout << "Номер рейса: "
             << deletedApplication.flightNumber << endl;

        cout << "Пассажир: "
             << deletedApplication.passenger << endl;

        cout << "Дата вылета: "
             << deletedApplication.departureDate << endl;
    }

    cout << endl;

    cout << "Количество заявок после удаления: "
         << applications.GetCount() << endl;

    return 0;
}