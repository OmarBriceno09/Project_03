//
// Created by OmarB on 11/2/2019.
//

#ifndef PROJECT_03_TUPLE_H
#define PROJECT_03_TUPLE_H
#include <fstream>
#include <vector>

using namespace std;

class Tuple {
public:
    Tuple();
    ~Tuple();
    void add_value(string);
    string get_value(int);
    int get_size();
    vector <string> values_list;
};


#endif //PROJECT_03_TUPLE_H
