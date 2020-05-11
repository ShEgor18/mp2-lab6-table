#pragma once
#include <iostream>
#include "Record.h"

using namespace std;

template<class Key, class Data>
class SortTable;

//Table
template<class Key, class Data>
class Table {
protected:
    int Size;
    int Count;
    Record<Key, Data>* dataArray;

public:
    Table() {}

    Table(int _size)  : Size(_size), Count(0)
    {
        dataArray = new Record<Key, Data>[Size];
    }

    void Add(Key key, Data data) {
        dataArray[Count].key = key;
        dataArray[Count].data = data;
        Count++;
    }

    Data Find(Key key) {
        for (int i = 0; i < Count; i++)
        {
            if (dataArray[i].key == key)
                return dataArray[i].data;
        }
        throw exception("Not found");
    }

    void Print()
    {
        for (int i = 0; i < Count; i++)
            cout << "Key: " << dataArray[i].key << " Data: " << dataArray[i].data << " " << endl;
    }

    Record<Key, Data>* begin()
    {
        return this->dataArray;
    }
    Record<Key, Data>* end()
    {
        return this->dataArray + this->Count;
    }

    template<class Key, class Data>
    friend class SortTable;
};


//Sort Table
template<class Key, class Data>
class SortTable : public Table<Key, Data> {
public:
    SortTable(size_t _size);
    SortTable(const SortTable<Key, Data>& table);
    SortTable(const Table<Key, Data>& table);
    void Add(Key key, Data data);
    void Delete(const Key& key);
    Data Find(Key key);
    Data& operator[](const Key& key);

};

template<class Key, class Data>
SortTable<Key, Data>::SortTable(size_t _size) : Table<Key, Data>::Table(_size) {}

template<class Key, class Data>
SortTable<Key, Data>::SortTable(const SortTable<Key, Data>& table)
{
    this->Size = table.Size;
    this->Count = table.Count;
    this->dataArray = new Record<Key, Data>[this->Size];
    for (int i = 0; i < this->Count; i++)
        this->dataArray[i] = table->dataArray[i];
}

template<class Key, class Data>
SortTable<Key, Data>::SortTable(const Table<Key, Data>& table)
{
    this->Size = table.Size;
    this->Count = table.Count;
    this->dataArray = new Record<Key, Data>[this->Size];
    for (int i = 0; i < this->Count; i++)
        this->dataArray[i] = table.dataArray[i];
    quicksort(this->dataArray, 0, this->Count - 1);
}

template<class Key, class Data>
void quicksort(Record<Key, Data>* arr,  int first, int last)
{
    int f = first;
    int l = last;
    Record<Key, Data> mid = arr[(f + l) / 2];
    Record<Key, Data> tmp;
    do
    {
        while (arr[f].key < mid.key) f++;
        while (arr[l].key > mid.key) l--;
        if (f <= l)
        {
            tmp = arr[f];
            arr[f] = arr[l];
            arr[l] = tmp;
            f++;
            l--;
        }
    } while (f < l);
    if (first < l) quicksort(arr, first, l);
    if (f < last) quicksort(arr, f, last);
}

template<class Key, class Data>
void SortTable<Key, Data>::Add(Key key, Data data)
{
    int i = 0, j = 0;
    while (i < this->Count)
    {
        if (this->dataArray[i].key <= key)
        {
            i++;
            continue;
        }
        break;
    }
    for (j = this->Count; j > i; j--)
    {
        this->dataArray[j].key = this->dataArray[j - 1].key;
        this->dataArray[j].data = this->dataArray[j - 1].data;
    }
    this->dataArray[i].key = key;
    this->dataArray[i].data = data;
    this->Count++;
}

template<class Key, class Data>
void SortTable<Key, Data>::Delete(const Key& key)
{
    int i = 0, j = 0;
    while (this->dataArray[i].key != key && i < this->Count)
    {
        i++;
    }

    if (i >= this->Count)
        runtime_error("Not found");

    for (j = i + 1; j < this->Count; j++)
    {
        this->dataArray[j - 1].key = this->dataArray[j].key;
        this->dataArray[j - 1].data = this->dataArray[j].data;
    }
    this->Count--;
}

template<class Key, class Data>
Data SortTable<Key, Data>::Find(Key key)
{
    int l = 0;
    int r = this->Count - 1;
    while (l + 1 < r)
    {
        int mid = (l + r) / 2;
        if (this->dataArray[mid].key > key)
            r = mid;
        else
            l = mid;
    }
    if (this->dataArray[l] == key)
        return this->dataArray[l].data;
    if (this->dataArray[r] == key)
        return this->dataArray[r].data;
    cout << "Error: not found!";
    exit(-1);
}

template<class Key, class Data>
Data& SortTable<Key, Data>::operator[](const Key& key)
{
    int l = 0;
    int r = this->Count - 1;
    while (l + 1 < r)
    {
        int mid = (l + r) / 2;
        if (this->dataArray[mid].key > key)
            r = mid;
        else
            l = mid;
    }
    if (this->dataArray[l] == key)
        return this->dataArray[l].data;
    if (this->dataArray[r] == key)
        return this->dataArray[r].data;
    throw "Not found";
}