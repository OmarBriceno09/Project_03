//
// Created by OmarB on 11/2/2019.
//

#ifndef PROJECT_03_RULE_H
#define PROJECT_03_RULE_H
#include <fstream>
#include <vector>
#include "Predicate.h"
using namespace std;

//headPredicate COLON_DASH predicate predicateList PERIOD
class Rule {
public:
    Rule(int&, vector<string>&, vector<string>&, vector<int>&);
    ~Rule();

    int get_rule_count();
    string out_rule();

    string the_headPredicate="";
    vector <string> the_predicateList;

private:
    string this_rule_flow="";
    static int rule_count;

    void the_rule(int&, vector<string>&, vector<string>&, vector<int>&);
    void headPredicate(int&, vector<string>&, vector<string>&, vector<int>&);

    void predicateList(int&, vector<string>&, vector<string>&, vector<int>&);
    void idList(int&, vector<string>&, vector<string>&, vector<int>&, string&);

    bool does_token_match(string, const string[], int);

    void set_rule_count(int);

    const string rl_first = "ID";
    const string hPd_first = "ID";
    const string pdL_first[2] = {"COMMA",""};
    const string idL_first[2] = {"COMMA",""};

    const string pdL_follow[12] = {"COMMA","PERIOD","Q_MARK","LEFT_PAREN","RIGHT_PAREN","COLON",
                                   "MULTIPLY","ADD","QUERIES","ID","STRING","EOF"};
    const string idL_follow[15]= {"COMMA","PERIOD","Q_MARK","LEFT_PAREN","RIGHT_PAREN","COLON","COLON_DASH",
                                  "MULTIPLY","ADD","FACTS","RULES","QUERIES","ID","STRING","EOF"};
};


#endif //PROJECT_03_RULE_H
