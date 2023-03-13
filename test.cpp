#include <iostream>
#include <fstream>
using namespace std;

// ф-я на поиск строки где чаще встречается символ
void symbolInStr(char *str, char *str2, char *symbol)
{
    // инициализация переменных
    int i, j = 0;
    int symbolInStr, symbolInStr2 = 0;

    // поиск кол-ва встеч символа в 1 строке
    while (str[i] != '\0') // идем до конца 1 строки
    {
        if (str[i] == symbol[0]) // если нашелся
        {
            symbolInStr++; // увеличиваем
        }
        i++;
    }

    // поиск кол-ва встеч символа во 2 стоке
    while (str2[j] != '\0') // идем до конца 2 строки
    {
        if (str2[j] == symbol[0]) // если нашелся
        {
            symbolInStr2++; // увеличиваем
        }
        j++;
    }

    // сравниваем где больше
    if (symbolInStr > symbolInStr2) // если в 1 строке больше
    {
        cout << str << endl; // выводим 1
    }
    else if (symbolInStr2 > symbolInStr) // если в 2 строке больше
    {
        cout << str2 << endl; // выводим 2
    }
    else // если одинакого
    {
        cout << "The number of symbol is the same" << endl; // вывыод об одинаковом кол-ве
    }
}; // конец ф-ии

// ф-я на поиск одинковых слов в 2х строках
void DublicateOfWord(char *str, char *str2)
{
    int i, j, l = 0;
    int beginWord, endWord, beginWord2, endWord2 = 0;
    int lenStr, lenStr2 = 0;
    int povtorCount = 0;
    bool fl = true;

    // инициализация переменных
    // идем до конца 1й строки
    i = 0;                 // обнуляем индекс
    while (str[i] != '\0') // идем до конца 1ой строки
    {
        while ((str[i] != '\0') && (str[i] == ' ')) // идем до 1го элемента слова
        {
            i++;
        }
        beginWord = i; // первый элемент
        //
        while (str[i] != '\0' && str[i] != ' ') // идем по слову до полсденего элемента
        {
            i++;
        }
        endWord = i - 1;                  // последний элемент
        lenStr = endWord - beginWord + 1; // длина слова 1 строки

        // 2 строка
        j = 0;                  // обнуляем индекс
        while (str2[j] != '\0') // идем до конца 2й строки
        {
            while ((str2[j] != '\0') && (str2[j] == ' ')) // идем до 1го элемента слова
            {
                j++;
            }
            beginWord2 = j;                           // 1 элемент
            while (str2[j] != '\0' && str2[j] != ' ') // идем по слову до полсденего элемента
            {
                j++;
            }
            endWord2 = j - 1;                    // последний элемент
            lenStr2 = endWord2 - beginWord2 + 1; // длина слова 2 строки

            // сравниваем длины
            if (lenStr == lenStr2)
            {
                l = beginWord2;                            // 1 элемент слова со 2 строки
                fl = true;                                 // поднимает флаг(на случай если опустили при прошлом сравнении)
                for (int k = beginWord; k <= endWord; k++) // идем по длине
                {
                    if (str[k] == str2[l]) // если элементы совпали
                    {
                        l++; // шаг вепед в слове из 2 строки
                    }
                    else // если элементы не совпали
                    {
                        fl = false; // опускаем флаг
                    }
                }
                l = 0;  // обнуляем индекс для следующих слов
                if (fl) // если флаг поднят
                {
                    for (int k = beginWord; k <= endWord; k++)
                    {
                        cout << str[k]; // выводим
                    }
                    cout << endl;
                    povtorCount++; // cчитаем кол-во повторений
                }                  // конец проверки состояния флага
            }                      // конец проверки на совпадние длин слов
        }                          // конец цыкла до конца 2 строки
    }                              // конец цыкла до конца 1 строки
    if (povtorCount == 0)          // если кол-во слов равно 0
    {
        cout << "Not the same words" << endl; // вывод ошибки(нет одинаковы слов)
    }
} // конец ф-ии

// основная программа
int main()
{
    // инициализация переменных

    const char *FNAME = "C:\\Users\\korol\\.vscode\\Labs-University-C-\\test11.txt";
    // const char *FNAME = "C:\\Users\\korol\\.vscode\\Labs-University-C-\\test2.txt";
    // const char *FNAME = "C:\\Users\\korol\\.vscode\\Labs-University-C-\\test3.txt";
    // const char *FNAME = "C:\\Users\\korol\\.vscode\\Labs-University-C-\\test4.txt";
    // const char *FNAME = "C:\\Users\\korol\\.vscode\\Labs-University-C-\\test5.txt";
    // const char *FNAME = "C:\\Users\\korol\\.vscode\\Labs-University-C-\\test6.txt";
    // const char *FNAME = "C:\\Users\\korol\\.vscode\\Labs-University-C-\\test7.txt";
    // const char *FNAME = "C:\\Users\\korol\\.vscode\\Labs-University-C-\\test8.txt";
    // const char *FNAME = "C:\\Users\\korol\\.vscode\\Labs-University-C-\\test9.txt";
    // const char *FNAME = "C:\\Users\\korol\\.vscode\\Labs-University-C-\\test10.txt";
    // const char *FNAME = "C:\\Users\\korol\\.vscode\\Labs-University-C-\\test11.txt";
    // const char *FNAME = "C:\\Users\\korol\\.vscode\\Labs-University-C-\\test12.txt";

    // иницалицзаия переменных для содержания файла
    char str[256];
    char str2[256];
    char symbol[256];
    char emptysymbol[] = "";
    char probel[] = " ";

    // начало чтения
    ifstream fin(FNAME);

    if (!fin)
    {
        cout << "file " << FNAME << " not found" << endl; // вывод ошибки
        return 1;                                         // выход по ошибке
    }

    // читаем из файла
    fin.getline(symbol, 10); // 1 строка
    fin.getline(str, 255);   // 2 строка
    fin.getline(str2, 255);  // 3 строка

    // проверки состояния файла
    if ((fin.eof()) && (fin.fail())) // файл пуст
    {
        cout << "file " << FNAME << " empty" << endl; // вывод ошибки(файл пуст)
        fin.close();                                  // закрыть файл
        return 2;                                     // выход по ошибке
    }
    if ((symbol[0] == emptysymbol[0] || str[0] == emptysymbol[0] || str2[0] == emptysymbol[0]) || (symbol[0] == probel[0] || str[0] == probel[0] || str2[0] == probel[0]))
    {
        cout << "check file data in correct" << endl;
        return 3;
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