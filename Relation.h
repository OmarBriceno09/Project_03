//
// Created by OmarB on 11/2/2019.
//

#ifndef PROJECT_03_RELATION_H
#define PROJECT_03_RELATION_H
#include <fstream>
#include <iostream>//for output ---- delete later
#include <vector>
#include "Tuple.h"

using namespace std;

class Relation {
public:
    Relation(string);
    ~Relation();
    //Relation(Relation&);
    string getName();

    int getCols();    //returns # of Cols
    int getRows();    //returns # of Rows
    void setName(string);
    string toStringTuples();
    void setAttribute(string);   //sets Attribute ^
    string getAttribute(int);   //gets Attribute from attributes ^
    void setTuple(Tuple);    //adds Tuple ^s
    Tuple getTuple(int);    //gets Tuple from tuples_list ^

    void rename(vector<string>,vector<string>);
    void select(vector<string>,vector<string>);
    void project(vector<string>);

private:
    string name = "";
    vector <string> attributes;
    vector <Tuple> tuples_list;
    int returnRowToInsert(Tuple);//cur row, curr col, tuple in contention
};


#endif //PROJECT_03_RELATION_H
