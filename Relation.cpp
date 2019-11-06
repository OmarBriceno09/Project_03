//
// Created by OmarB on 11/2/2019.
//

#include "Relation.h"

Relation::Relation(string nm) {
    setName(nm);
}

/*Relation::Relation(Relation & relation) {
    Relation& operator = (Relation & relation){};
}*/

Relation::~Relation() {
}

int Relation::getCols() {
    return attributes.size();
}

int Relation::getRows() {
    return tuples_list.size();
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

void Relation::setAttribute(string attribute) {
    attributes.push_back (attribute);
}

string Relation::getAttribute(int i) {
    return attributes.at(i);
}

void Relation::setTuple(Tuple tpl) { // make sure tuple is added in alphabetical order, based on 1st element of tuple
    bool does_it_match = false;
    for (int i=0; i<getRows(); i++){
        if (tpl.getValuesList() == getTuple(i).getValuesList()) {
            does_it_match = true;
        }
    }
    if (!does_it_match) {
        int insert_index = returnRowToInsert(tpl);  //row of insertion is determined here, ordered alphabetically
        tuples_list.insert(tuples_list.begin() + insert_index, tpl);
    }
}

Tuple Relation::getTuple(int i) {
    return tuples_list.at(i);
}

int Relation::returnRowToInsert(Tuple tpl) {
    int insert_index = 0;
    int curr_r = 0;
    bool stop = false;
    while(curr_r<=getRows()-1){
        int curr_c = 0;
        while (curr_c<=getCols()-1){
            if ((tpl.get_value(curr_c).compare(tuples_list.at(curr_r).get_value(curr_c))) == 0) {
                curr_c++;   //move ahead 1 col
            } else if ((tpl.get_value(curr_c).compare(tuples_list.at(curr_r).get_value(curr_c))) > 0) {
                curr_r++;   //next row
                curr_c = getCols(); //restart cols
            } else{// if dif < 0, stop all!!!!
                stop = true;
                insert_index = curr_r;
                curr_r = getRows();
                curr_c = getCols();
            }
        }
    }
    if (!stop){
        insert_index = tuples_list.size();
    }
    return insert_index;
}

void Relation::rename(vector <string> tokens,vector<string> input) {
    for(int i=0;i<tokens.size();i++){
        if (tokens.at(i) == "ID"){
            if(attributes.at(i) != input.at(i)){
                attributes.at(i) = input.at(i); //Renaming Takes Place
            }
        }
    }
}

void Relation::select(vector <string> tokens,vector<string> input) {
    for(int i=0;i<tokens.size();i++){
        if (tokens.at(i) == "STRING"){
            for (int j=0;j<tuples_list.size();j++){
                if (tuples_list.at(j).get_value(i) != input.at(i)){
                    tuples_list.erase(tuples_list.begin()+j);
                    j=-1;    //reset search, will be zero back at beginning of for loop
                }
            }
        }
    }
    vector <Tuple> temp_tuples = tuples_list;
    tuples_list.clear();
    for (int k=0;k<temp_tuples.size();k++){
        setTuple(temp_tuples.at(k));
    }
}

void Relation::project(vector <string> tokens) {
    for(int i=0;i<tokens.size();i++){
        if (tokens.at(i) != "ID"){
            attributes.erase(attributes.begin()+i);
            for (int j=0;j<tuples_list.size();j++){
                tuples_list.at(j).remove_value(i);
            }
        }
    }
    vector <Tuple> temp_tuples = tuples_list;
    tuples_list.clear();
    for (int k=0;k<temp_tuples.size();k++){
        setTuple(temp_tuples.at(k));
    }
}