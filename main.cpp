#include <iostream>
#include "List.h"
using namespace std;

int main() {
    List<int> l;
    List<int>::iterator it = l.begin();
    it = l.insert(it, 0);
    it = l.insert(it, 1);
    it = l.insert(it, 2);
    for(it = l.begin(); it != l.end(); it++)
        cout << *it << endl;

}