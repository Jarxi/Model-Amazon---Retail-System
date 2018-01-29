#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include "movie.h"
#include "util.h"
using namespace std;




Movie::Movie(const std::string category, const std::string name, 
	double price, int qty,string genre, string rating)
	:Product(category, name, price, qty), genre_(genre), rating_(rating)
{
}


std::set<std::string> Movie::keywords() const{
	set<string> setName=parseStringToWords(name_);
	set<string> setGenre=parseStringToWords(genre_);
	set<string> keywords;
	set<string>::iterator it;
	for(it=setName.begin();it!=setName.end();++it){
		keywords.insert(*it);
	}
		
	for(it=setGenre.begin();it!=setGenre.end();++it){
		keywords.insert(*it);
	}

	return keywords;
}

std::string Movie::displayString() const{
	stringstream priceConv;
	priceConv<<price_;
	stringstream qtyConv;
	qtyConv<<qty_;
	string info="";
	info=name_+"\n"+"Genre: "+genre_+" "+"Rating: "
	+ rating_+"\n"+priceConv.str()+" "+qtyConv.str()
	+" left.";
	
	return info;
}

bool Movie::isMatch(std::vector<std::string>& searchTerms) const{
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
void Movie::dump(std::ostream& os) const{
	os<<category_<<endl;
	os<<name_<<endl;
	os<<fixed<<setprecision(2)<<price_<<endl;
	os<<qty_<<endl;
	os<<genre_<<endl;
	os<<rating_<<endl;
}

std::string Movie::getSpecialInfo1() const{
	return genre_;
}

std::string Movie::getSpecialInfo2() const{
	return rating_;
}

