#include <ctime>
#include <typeinfo>
#include <iostream>
#include <string>
#include <algorithm>
#include "Table.h"


using namespace std;



int main()
{
    setlocale(LC_ALL, "rus");


    try
    {
        Table<int, int> table(15000000);

        auto& ti1 = typeid(table);
        cout << ti1.name();

        cout << endl;

        for (int i = 15000000; i > 0; i--)
        {
            table.Add(100 + i, i * 10);
        }
        cout << endl;

        unsigned int start_time = clock();
        SortTable<int, int> table3(table);
        unsigned int end_time = clock();
        unsigned int search_time = end_time - start_time;

        auto& ti2 = typeid(table3);
        cout << ti2.name() << endl;

        cout << "Время работы своей сортировки: " << search_time << endl;

        cout << endl;

        start_time = clock();
        sort(table.begin(), table.end(), [](Record<int, int>a, Record<int, int>b) ->bool {return a.key < b.key; });
        end_time = clock();
        search_time = end_time - start_time;

        auto& ti3 = typeid(table);
        cout << ti3.name() << endl;

        cout << "Время работы std::sort: " << search_time << endl;
        cout << endl;

        cout << "Добавление данных по ключу 99" << endl;

        cout << endl;

        table3.Add(99, -99);

        cout << "Поиск по ключу 99: " << table3.Find(99) << endl;

        cout << endl;

        cout << "Удаление данных по ключу 99" << endl;
        table3.Delete(99);
        cout << endl;

        cout << "Поиск по ключу 99: ";
        cout << table3.Find(99) << endl;
    }
    catch (exception& e)
    {
        cerr << "Error: " << e.what() << endl;
    };

    system("pause");

}
