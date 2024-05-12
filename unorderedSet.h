#ifndef H_unorderedSet
#define H_unorderedSet

#include "unorderedArrayListType.h"
#include "arrayListType.h"
#include <iostream>

using namespace std;

template <class elemType>
class unorderedSet : public unorderedArrayListType<elemType>
{
public:
    void insertAt(int location, const elemType& insertItem);
    void insertEnd(const elemType& insertItem);
    void replaceAt(int location, const elemType& repItem);

    unorderedSet<elemType> operator+(const unorderedSet<elemType>& rhs) const;
    unorderedSet<elemType> operator-(const unorderedSet<elemType>& rhs) const;

    unorderedSet(int size = 100);

};

template <class elemType>
void unorderedSet<elemType>::insertAt(int location, const elemType& insertItem) {
    int itemLocation = this->seqSearch(insertItem);

    if (itemLocation == -1) {
        unorderedArrayListType<elemType>::insertAt(location, insertItem);
    }
    else {
        cout << "The requested item has already been inserted" << endl;
    }
}

template <class elemType>
void unorderedSet<elemType>::insertEnd(const elemType& insertItem) {
    int itemLocation = this->seqSearch(insertItem);
    if (itemLocation == -1) {
        unorderedArrayListType<elemType>::insertEnd(insertItem);
    }
    else {
        cout << "The requested item has already been inserted" << endl;
    }
}

template <class elemType>
void unorderedSet<elemType>::replaceAt(int location, const elemType& repItem) {
    int itemLocation = this->seqSearch(repItem);
    if (itemLocation == -1) {
        unorderedArrayListType<elemType>::replaceAt(location, repItem);
    }
}

template<class elemType>
unorderedSet<elemType>::unorderedSet(int size)
    : unorderedArrayListType<elemType>(size)
{
}

template<class elemType>
unorderedSet<elemType> unorderedSet<elemType>::operator+(const unorderedSet<elemType>& rhs) const
{
    unorderedSet<elemType> unionSet;
    for (int i = 0; i < this->length; i++)
        unionSet.insertEnd(this->list[i]);
    for (int i = 0; i < rhs.length; i++)
        unionSet.insertEnd(rhs.list[i]);
    return unionSet;
}

template<class elemType>
unorderedSet<elemType> unorderedSet<elemType>::operator-(const unorderedSet<elemType>& rhs) const
{
    unorderedSet<elemType> intersectionSet;
    for (int i = 0; i < this->length; i++)
        if (rhs.seqSearch(this->list[i]) >= 0)
            intersectionSet.insertEnd(this->list[i]);
    return intersectionSet;
}

#endif