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
