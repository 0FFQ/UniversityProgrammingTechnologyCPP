#include <iostream>
#include <cstring>
#include <ctime>

class Document
{
private:
    char *title;
    char *topic;
    char *author;
    int pages;
    char *lastRevision;

    static char *copyString(const char *source)
    {
        if (source == nullptr)
        {
            source = "";
        }

        char *result = new char[std::strlen(source) + 1];
        std::strcpy(result, source);

        return result;
    }

    static char *getCurrentDateTime()
    {
        std::time_t currentTime = std::time(nullptr);
        std::tm *localTime = std::localtime(&currentTime);

        char buffer[80];

        std::strftime(
            buffer,
            sizeof(buffer),
            "%d.%m.%Y %H:%M:%S",
            localTime);

        return copyString(buffer);
    }

public:
    Document()
        : title(copyString("Без названия")),
          topic(copyString("Без темы")),
          author(copyString("Не указан")),
          pages(0),
          lastRevision(getCurrentDateTime())
    {
    }

    Document(
        const char *title,
        const char *topic,
        const char *author,
        int pages)
        : title(copyString(title)),
          topic(copyString(topic)),
          author(copyString(author)),
          pages(pages),
          lastRevision(getCurrentDateTime())
    {
    }

    Document(const char *title)
        : title(copyString(title)),
          topic(copyString("Без темы")),
          author(copyString("Не указан")),
          pages(0),
          lastRevision(getCurrentDateTime())
    {
    }

    Document(const Document &other)
        : title(copyString(other.title)),
          topic(copyString(other.topic)),
          author(copyString(other.author)),
          pages(other.pages),
          lastRevision(copyString(other.lastRevision))
    {
    }

    ~Document()
    {
        delete[] title;
        delete[] topic;
        delete[] author;
        delete[] lastRevision;
    }

    Document &setTitle(const char *newTitle)
    {
        delete[] title;
        title = copyString(newTitle);
        return *this;
    }

    Document &setTopic(const char *newTopic)
    {
        delete[] topic;
        topic = copyString(newTopic);
        return *this;
    }

    Document &setAuthor(const char *newAuthor)
    {
        delete[] author;
        author = copyString(newAuthor);
        return *this;
    }

    Document &setPages(int newPages)
    {
        pages = newPages;
        return *this;
    }

    Document &updateRevisionDateTime()
    {
        delete[] lastRevision;
        lastRevision = getCurrentDateTime();
        return *this;
    }

    void print() const
    {
        std::cout << "Название: " << title << std::endl;
        std::cout << "Тема: " << topic << std::endl;
        std::cout << "Автор: " << author << std::endl;
        std::cout << "Количество страниц: " << pages << std::endl;
        std::cout << "Последняя редакция: " << lastRevision << std::endl;
    }
};

int main()
{
    Document document("Лабораторная работа");

    document
        .setTopic("Организация сцепленного вызова функций")
        .setAuthor("Пестов Алексей Юрьевич")
        .setPages(10)
        .setTitle("Лабораторная работа №5")
        .updateRevisionDateTime();

    std::cout << "Документ после сцепленного вызова:" << std::endl;
    document.print();

    std::cout << std::endl;

    Document copyDocument(document);

    std::cout << "Копия документа:" << std::endl;
    copyDocument.print();

    return 0;
}