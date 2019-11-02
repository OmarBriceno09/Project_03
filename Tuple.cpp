//
// Created by OmarB on 11/2/2019.
//

#include "Tuple.h"
Tuple::Tuple() {
}

Tuple::~Tuple() {
}

void Tuple::add_value(string val) {
    values_list.push_back(val);
}

string Tuple::get_value(int i) {
    return values_list.at(i);
}

int Tuple::get_size() {
    return values_list.size();
}