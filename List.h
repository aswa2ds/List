//
// Created by Edward Martin on 2018/10/26.
//

#ifndef LIST_LIST_H
#define LIST_LIST_H

#include <iostream>

template <class T>
struct _List_node{
    _List_node<T> *prev;
    _List_node<T> *next;
    T data;
};

template <class T>
struct _List_iterator{
    _List_node<T>* _p_node;
    explicit _List_iterator(_List_node<T>* x):_p_node(x){};
    ~_List_iterator(){};
    bool operator == (const _List_iterator &it2){ return this->_p_node == it2._p_node; }
    bool operator != (const _List_iterator &it2){ return this->_p_node != it2._p_node; }
    _List_iterator &operator++(){ _p_node = _p_node->next; return *this;}
    _List_iterator operator++(int){ _List_iterator temp(_p_node); _p_node = _p_node->next; return temp; }
    _List_iterator &operator--(){ _p_node = _p_node->prev; return *this;}
    _List_iterator operator--(int){ _List_iterator temp(_p_node); _p_node = _p_node->prev; return temp; }
    T operator *(){ return _p_node->data; }
};

template <class T>
class List{
public:
    typedef _List_node<T> link_type;
    typedef _List_iterator<T> iterator;
    List(){
        link_type * p = new link_type;
        p->next = p;
        p->prev = p;
        msize = 0;
        node = p;
    }
    ~List(){
        for(link_type *p = node->next; p != node; p = p->next){
            delete p;
        }
        delete node;
        msize = 0;
    }
    bool empty(){
        return msize == 0;
    }
    iterator begin(){
        iterator it(node->next);
        return it;
    }
    iterator end(){
        iterator it(node);
        return it;
    }
    iterator insert(iterator it, T e){
        link_type * s2 = it._p_node;
        link_type * s1 = it._p_node->prev;
        link_type * p = new link_type;
        p->data = e;
        s1->next = p;
        p->prev = s1;
        s2->prev = p;
        p->next = s2;
        it--;
        return it;
    }
    iterator erase(iterator it){
        link_type * s1 = it._p_node->prev;
        link_type * s2 = it._p_node->next;
        link_type * p = it._p_node;
        it++;
        s1->next = s2;
        s2->prev = s1;
        delete p;
        return it;
    }
private:
    link_type *node;
    int msize;
};

#endif //LIST_LIST_H