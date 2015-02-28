#ifndef TEXTQUERY_H
#define TEXTQUERY_H
#include<iostream>
#include<vector>
#include<memory>
#include<fstream>
#include<map>
#include<set>
#include<string>
#include"QueryResult.h"
using std::vector;
using std::map;
using std::set;
using std::shared_ptr;
using std::string;
class QueryResult;
class TextQuery
{
public:
	using lineno=vector<string>::size_type;
	TextQuery(std::ifstream&);
	QueryResult query(const string&) const;
private:
	shared_ptr<vector<string>> file;
	map<string,shared_ptr<set<lineno>>> wm;
};
#endif
