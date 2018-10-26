//
// Created by Edward Martin on 2018/10/26.
//

#ifndef LIST_LIST_H
#define LIST_LIST_H

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
private:
    link_type *node;
    int msize;
};

#endif //LIST_LIST_H
