#include <iostream>

using namespace std;

template<class Key, class Data>
class Record {
public:
    Key key;
    Data data;
    Record* next;
    bool status;
    
    Record<Key, Data>() 
    {
        status = false;
        this->next = nullptr;
    }
    Record<Key, Data>(Key _key, Data _data, bool status = false, Record<Key, Data>* _next = nullptr);
    bool operator ==(const Key&);
    bool operator !=(const Key&);
    bool operator<(const Record < Key, Data>& rec);
    bool operator>(const Record < Key, Data>& rec);

    Record<Key, Data>& operator=(const Record<Key, Data>& rec);
    friend ostream& operator<<(std::ostream& os, const Record<Key, Data>& d);
};

template<class Key, class Data>
bool Record<Key, Data>::operator!=(const Key& _key)
{
    return key != _key;
}

template<class Key, class Data>
bool Record<Key, Data>::operator==(const Key& _key)
{
    return key == _key;
}

template<class Key, class Data>
bool Record<Key, Data>::operator<(const Record<Key, Data>& rec)
{
    return key < rec.key;
}

template<class Key, class Data>
bool Record<Key, Data>::operator>(const Record<Key, Data>& rec)
{
    return key > rec.key;
}

template<class Key, class Data>
Record<Key, Data>& Record<Key, Data>::operator=(const Record<Key, Data>& rec)
{
    status = rec.status;
    key = rec.key;
    data = rec.data;
    next = rec.next;
    return *this;
}

template<class Key, class Data>
ostream& operator<<(ostream& os, const Record<Key, Data>& d)
{
    os << "Key: " << d.key << " Data: " << d.data << endl;
    return os;
}

template<class Key, class Data>
Record<Key, Data>::Record(Key _key, Data _data, bool _status, Record<Key, Data>* _next)
{
    status = _status;
    key = _key;
    data = _data;
    next = _next;
}
