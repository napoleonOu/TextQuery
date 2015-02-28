#include"TextQuery.h"
#include"QueryResult.h"
//class TextQuery;
//class QueryResult;
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

void runQuery(std::ifstream& ifss)
{
	TextQuery tq(ifss);
	string wordfind;
	std::cout<<"please input aword:";
	while(std::cin>>wordfind)
	{
		print(std::cout,tq.query(wordfind))<<std::endl;
	}
}

int main(int argc,char **argv)
{
	std::ifstream ifs;
//	if(!(ifs.open(argv[1],std::ifstream::in))
	if (argc < 2 || !(ifs.open(argv[1]), ifs)) 
	{
		std::cerr<<"open error";
		return 1;
	}	
	runQuery(ifs);
	return 0;
}
