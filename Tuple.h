//
// Created by OmarB on 11/2/2019.
//

#ifndef PROJECT_03_TUPLE_H
#define PROJECT_03_TUPLE_H
#include <fstream>
#include <iostream>//for output ---- delete later
#include <vector>

using namespace std;

class Tuple {
public:
    Tuple();
    ~Tuple();
    void set_var_name(string);

    void add_value(string);
    void remove_value(int);

    string get_value(int);

    string get_var_name();

    vector <string> getValuesList();

    string toStringTuple();

    int get_size();

private:
    vector <string> values_list;
    string var_name;
};


#endif //PROJECT_03_TUPLE_H
