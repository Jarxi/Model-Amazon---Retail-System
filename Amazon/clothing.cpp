#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include "clothing.h"
#include "util.h"
using namespace std;




Clothing::Clothing(const std::string category, const std::string name, 
	double price, int qty,string size, string brand)
	:Product(category, name, price, qty), size_(size), brand_(brand)
{
}


std::set<std::string> Clothing::keywords() const{
	set<string> setName=parseStringToWords(name_);
	set<string> setBrand=parseStringToWords(brand_);
	set<string> keywords;
	set<string>::iterator it;
	for(it=setName.begin();it!=setName.end();++it){
		keywords.insert(*it);
	}
		
	for(it=setBrand.begin();it!=setBrand.end();++it){
		keywords.insert(*it);
	}

	return keywords;
}

std::string Clothing::displayString() const{
	stringstream priceConv;
	priceConv<<price_;
	stringstream qtyConv;
	qtyConv<<qty_;
	string info="";
	info=name_+"\n"+"Size: "+size_+" "+"Brand: "
	+ brand_+"\n"+priceConv.str()+" "+qtyConv.str()
	+" left.";
	
	return info;
}

bool Clothing::isMatch(std::vector<std::string>& searchTerms) const{
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

void Clothing::dump(std::ostream& os) const{
	os<<category_<<endl;
	os<<name_<<endl;
	os<<fixed<<setprecision(2)<< price_<<endl;
	os<<qty_<<endl;
	os<<size_<<endl;
	os<<brand_<<endl;
}

std::string Clothing::getSpecialInfo1() const{
	return brand_;
}

std::string Clothing::getSpecialInfo2() const{
	return size_;
}

