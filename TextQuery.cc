#include"TextQuery.h"
#include<iostream>
#include<vector>
#include<memory>
#include<fstream>
#include<map>
#include<set>
#include<string>
#include<sstream>
#include"QueryResult.h"
using std::vector;
using std::map;
using std::set;
using std::shared_ptr;
using std::istringstream;
using std::string;
TextQuery::TextQuery( std::ifstream& ifs):file(new vector<std::string>) 
{
	string stringline;
	lineno line_no=0;
	while(getline(ifs,stringline))
	{
		file->push_back(stringline);
		line_no++;
		string linewords;
		std::istringstream iline(stringline);
		while(iline>>linewords)
		{
			auto &itr=wm[linewords];
			if(!itr)
				itr.reset(new set<lineno>);
			itr->insert(line_no);
		}
	}
}
QueryResult TextQuery::query(const string& st) const
{
	auto itr=wm.find(st);
	static shared_ptr<set<lineno>> nodata(new set<lineno>);
	if(itr!=wm.end())
		return QueryResult(st,itr->second,file);
	else
		return QueryResult(st,nodata,file);
}

std::ostream& print(std::ostream& os,const QueryResult& cqr)
{
	os<<"the word to find ocurs:"<<cqr.size();
	for(auto itr=cqr.pointbegin();itr!=cqr.pointend();itr++)
	{
		os<<"line"<<*itr+1<<" "<<cqr.linestring(*itr-1)<<std::endl;
	}
	return os;

}
//void runQuery(std::ifstream& ifss)
//{
//	TextQuery tq(ifss);
//	string wordfind;
//	std::cout<<"please input aword:";
//	while(std::cin>>wordfind)
//	{
//		print(std::cout,tq.query(wordfind))<<std::endl;
//	}
//}






