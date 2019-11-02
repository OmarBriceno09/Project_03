//
// Created by OmarB on 11/2/2019.
//

#ifndef PROJECT_03_RELATION_H
#define PROJECT_03_RELATION_H
#include <fstream>
#include <vector>
#include "Tuple.h"

using namespace std;

class Relation {
public:
    Relation(string);
    ~Relation();
    string getName();
    void setName(string);
    string toStringTuples();
    vector <string> attributes;
    vector <Tuple> tuples_list;
private:
    string name = "";
};


#endif //PROJECT_03_RELATION_H
