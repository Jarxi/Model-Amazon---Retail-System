#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <sstream>
#include "book.h"
#include "util.h"
#include <iomanip>
using namespace std;




Book::Book(const std::string category, const std::string name, 
	double price, int qty,string ISBN, string author)
	:Product(category, name, price, qty), ISBN_(ISBN), author_(author)
{
}


std::set<std::string> Book::keywords() const{
	//name, author, ISBN
	std::set<string> setName=parseStringToWords(name_);
	std::set<string> setAuthor=parseStringToWords(author_);
	std::set<string> keywords;
	std::set<string>::iterator it;
	for(it=setName.begin();it!=setName.end();++it){
		keywords.insert(*it);
	}
		
	for(it=setAuthor.begin();it!=setAuthor.end();++it){
		keywords.insert(*it);
	}
	keywords.insert(ISBN_);
	return keywords;
}

bool Book::isMatch(std::vector<std::string>& searchTerms) const{
	std::set <string> words=keywords();
	std::set <string>::iterator it;
	bool allfind=true;
	for (unsigned int i = 0; i < searchTerms.size(); i++){
		it=words.find(searchTerms[i]);
		if (it==words.end()){
			allfind=false;
			break;
		}
	}
	return allfind;
}

std::string Book::displayString() const{
	stringstream priceConv;
	priceConv<<price_;
	stringstream qtyConv;
	qtyConv<<qty_;
	string info="";
	info=name_+"\n"+"Author: "+author_+" "+"ISBN: "
	+ ISBN_+"\n"+priceConv.str()+" "+qtyConv.str()
	+" left.";
	
	return info;
}

void Book::dump(std::ostream& os) const{
	os<<category_<<endl;
	os<<name_<<endl;
	os<<fixed<<setprecision(2)<<price_<<endl;
	os<<qty_<<endl;
	os<<ISBN_<<endl;
	os<<author_<<endl;
}

std::string Book::getSpecialInfo1() const{
	return author_;
}

std::string Book::getSpecialInfo2() const{
	return ISBN_;
}

