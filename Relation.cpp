//
// Created by OmarB on 11/2/2019.
//

#include "Relation.h"
Relation::Relation(string nm) {
    setName(nm);
}

Relation::~Relation() {
}

void Relation::setName(string nm) {
    name = nm;
}

string Relation::getName() {
    return name;
}

string Relation::toStringTuples() {
    string the_output="";
    for (int i=0; i<tuples_list.size(); i++){
        for(int j=0; j<attributes.size();j++){
            the_output += (tuples_list.at(i).get_value(j)+",");
        }
        the_output+= "\n";
    }
    return the_output;
}