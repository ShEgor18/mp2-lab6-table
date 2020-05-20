#include <ctime>
#include <typeinfo>
#include <iostream>
#include <string>
#include <algorithm>
#include "Table.h"


using namespace std;


template<class Key>
int funcHash(Key key, int maxsize)
{
    return ((101 * key + 83) % 211) % maxsize;
}


int main()
{
    //String//
    //HashTable<string, int> htable(10);
    //htable.Add("a", 10);
    //htable.Add("b", 20);
    //htable.Add("c", 30);
    //htable.Add("d", 40);
    //htable.Add("e", 50);
    //htable.Add("f", 60);
    //htable.Print();

    //cout << endl << endl;
    //htable.Delete("a");

    //htable.Print();
    //cout << endl;
    //END STRING//


    //INT//
    HashTable<int, int> htable(10, funcHash<int>);
    for (int i = 0; i < 10; i++)
        htable.Add(1000 + i, i * 10 + 33);
    htable.Print();

    htable.Delete(1000);
    htable.Delete(1009);
    htable.Delete(1027);

    htable.Print();
    cout << endl;

    cout << "Find by key 1008: " << htable.Find(1008) << endl;
    //END INT//

    system("pause");
}

//Test SortTable
/*int main()
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

        cout << "Время работы своей сортировки:: " << search_time << endl;

        cout << endl;

        start_time = clock();
        sort(table.begin(), table.end(), [](Record<int, int>a, Record<int, int>b) ->bool {return a.key < b.key; });
        end_time = clock();
        search_time = end_time - start_time;

        auto& ti3 = typeid(table);
        cout << ti3.name() << endl;

        cout << "Время работы std::sort: " << search_time << endl;
        cout << endl;

        cout << "Добавление данных по ключу 99 << endl;

        cout << endl;

        table3.Add(99, -99);

        cout << "Поиск по ключу 99: " << table3.Find(99) << endl;

        cout << endl;

        cout << "Удаление данных по ключу 99:" << endl;
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

}*/