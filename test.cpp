#include <iostream>
#include <fstream>
using namespace std;

void symbolInStr(char *str, char *str2, char *symbol)
{

    int symbolInStr = 0;
    int symbolInStr2 = 0;

    for (int i = 0; i <= sizeof(str); i++)
    {
        if (str[i] == symbol[0])
        {
            cout << str[i] << endl;
            symbolInStr++;
            cout << symbolInStr << endl;
        }
    };

    for (int j = 0; j <= sizeof(str2); j++)
    {
        if (str2[j] == symbol[0])
        {
            cout << str2[j] << endl;
            symbolInStr2++;
        }
    };

    // сравниваем где больше
    if (symbolInStr > symbolInStr2)
    {
        cout << str << endl;
    }
    else if (symbolInStr2 > symbolInStr)
    {
        cout << str2 << endl;
    }
    else
    {
        cout << "The number of the symbol is the same" << endl;
    }
};

void DublicateOfWord(char *str, char *str2)
{
    int i, j, l, indexPovtorSlova = 0;
    int beginWord, endWord, beginWord2, endWord2 = 0;
    int lenStr, lenStr2 = 0;
    bool fl = true;
    char povtorSlova[256];

    // инициализация переменных
    // идем до конца 1й строки
    i = 0;
    while (str[i] != '\0')
    {
        while ((str[i] != '\0') && (str[i] == ' '))
        {
            i++;
        }
        beginWord = i; // первый элемент
        //
        while (str[i] != '\0' && str[i] != ' ')
        {
            i++;
        }
        endWord = i - 1;                  // последний элемент
        lenStr = endWord - beginWord + 1; // длина слова 1 строки

        // 2 строка
        j = 0;
        while (str2[j] != '\0')
        {
            while ((str2[j] != '\0') && (str2[j] == ' '))
            {
                j++;
            }
            beginWord2 = j; // 1 элемент
            while (str2[j] != '\0' && str2[j] != ' ')
            {
                j++;
            }
            endWord2 = j - 1;                    // последний элемент
            lenStr2 = endWord2 - beginWord2 + 1; // длина слова 2 строки

            // сравниваем длины
            if (lenStr == lenStr2)
            {
                l = beginWord2; // 1 элемент слова со 2 строки
                fl = true;      // поднимает флаг
                for (int k = beginWord; k <= endWord; k++)
                { // идем по длине
                    if (str[k] == str2[l])
                    {        // если элементы совпали
                             // записываем 1 элемент в повтор слов
                             // шаг вперед в повторе слова
                        l++; // шаг вепед в слове из 2 строки
                    }
                    else
                    {
                        fl = false; // опускаем флаг
                    }
                }
                indexPovtorSlova = 0; // обнуляем индексы
                l = 0;
                if (fl) // если флаг поднят
                {
                    for (int o = 0; o <= endWord; o++)
                    {
                        cout << povtorSlova[o];
                    } // выводим
                }
                cout << endl;
            }
        }
    }
}

int main()
{
    // инициализация переменных

    const char *FNAME = "C:\\Users\\korol\\.vscode\\Labs-University-C-\\test1.txt";
    // const char *FNAME = "D:\\VS\\AllLabs\\test2.txt";
    // const char *FNAME = "D:\\VS\\AllLabs\\test3.txt";
    // const char *FNAME = "D:\\VS\\AllLabs\\test4.txt";
    // const char *FNAME = "D:\\VS\\AllLabs\\test5.txt";
    // const char *FNAME = "D:\\VS\\AllLabs\\test6.txt";
    // const char *FNAME = "D:\\VS\\AllLabs\\test7.txt";
    // const char *FNAME = "D:\\VS\\AllLabs\\test8.txt";

    char str[256];
    char str2[256];
    char symbol[256];

    // начало чтения
    ifstream fin(FNAME);

    if (!fin)
    {
        cout << "file " << FNAME << " not found" << endl;
        return 1; // выход по ошибке
    }

    // читаем из файла
    fin.getline(symbol, 10); // 1 строка
    fin.getline(str, 255);   // 2 строка
    fin.getline(str2, 255);  // 3 строка

    // проверки состояния файла
    if ((fin.eof()) && (fin.fail())) // файл пуст
    {
        cout << "file " << FNAME << " empty" << endl;
        fin.close(); // закрыть файл
        return 2;    // выход по ошибке
    }

    // Вывод строк из файла
    cout << "Symbol = <" << symbol[0] << ">" << endl;
    cout << "Str 1 = <" << str << ">" << endl;
    cout << "Str 2 = <" << str2 << ">" << endl;
    // конец четния

    // Применение функций
    symbolInStr(str, str2, symbol); // Первая функция
    DublicateOfWord(str, str2);     // Вторая функция

    return 0;
}