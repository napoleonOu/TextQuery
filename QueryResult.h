#ifndef QUERYRESULT_H
#define QUERYRESULT_H
#include<vector>
#include<memory>
#include<map>
#include<string>
using std::vector;
class QueryResult
{
public:
	friend std::ostream& print(std::ostream& ,const QueryResult& );
	using lineno=vector<std::string>::size_type ;
	using setlineno=std::set<lineno>::size_type;
	using sitr=std::set<lineno>::const_iterator;
	QueryResult(std::string s,std::shared_ptr<std::set<lineno>> lines,std::shared_ptr<std::vector<std::string>> file):wordtofind(s),Lines(lines),File(file){}
	sitr pointbegin() const{
		return Lines->cbegin();
	}
	sitr pointend() const{
		return Lines->cend();
	} 
	setlineno size() const{
		return Lines->size();
	}
	std::string linestring (lineno num) const
	{
		return (*File)[num];
	}	
	
private:
	std::string wordtofind;
	std::shared_ptr<std::set<lineno>> Lines;
	std::shared_ptr<std::vector<std::string>> File;

};

//std::ostream& print(std::ostream& os,const QueryResult& cqr)
//{
//	os<<"the word to find ocurs:"<<cqr.size();
//	for(auto itr=cqr.pointbegin();itr!=cqr.pointend();itr++)	
//	{
//		os<<"line"<<*itr<<" "<<cqr.linestring(*itr)<<std::endl;
//	}
//	return os;
//
//}
//void runQuery(const std::ifstream& ifss)
//{
//	TextQuery tq(ifss);
//	string wordfind;
//	std::cout<<"please input aword:";
//	while(std::cin>>wordfind)
//	{
//		print(std::cout,tq.query(wordfind))<<std::endl;
//	} 
//}

#endif
