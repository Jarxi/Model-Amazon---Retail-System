#include <string>
#include <set>
#include <vector>
#include <map>
#include "product.h"
#include "user.h"
#include "datastore.h"
#include "mydatastore.h"
#include "util.h"
using namespace std;


myDataStore::~myDataStore(){
	for (unsigned int i = 0; i < productList.size(); i++){
		delete productList[i];
	}

	for(unsigned int i=0; i<userList.size();i++){
		delete userList[i];
	}

	for (unsigned int i = 0; i < reviewList.size(); i++){
		delete reviewList[i];
	}
}

vector<User*> myDataStore::getUserList(){
	return userList;
}
vector<Product*> myDataStore::getProductList(){
	return productList;
}
vector<Review*> myDataStore::getReviewList(){
	return reviewList;
}
void myDataStore::addProduct(Product* p){
	productList.push_back(p);
	allProductName.insert(p->getName());
	std::map<string, std::set<Product*> >::iterator mapWordIt;
	std::set<string>::iterator setWordsIt;

	set<string> allKeywords;
	set<Product*> allProduct;
	allKeywords=p->keywords();
	for(setWordsIt=allKeywords.begin();
		setWordsIt!=allKeywords.end();++setWordsIt){
		mapWordIt=mapWordtoProd.find(*setWordsIt);
		//if the keyword already exists
		if (mapWordIt!=mapWordtoProd.end()){
			mapWordIt->second.insert(p);
		}
		else{
			set <Product*> allProduct;
			allProduct.insert(p);
			mapWordtoProd.insert(make_pair((*setWordsIt),allProduct));
		}
	}
}

void myDataStore::addUser(User* u){
	userList.push_back(u);
}


void myDataStore::addReview(Review* r){
	reviewList.push_back(r);
	
	set<string>::iterator prodNameIt;
	map<string, vector<Review*> >::iterator mapProdtoReviewIt;
	prodNameIt=allProductName.find(r->prodName);
	if (prodNameIt!=allProductName.end()){
		mapProdtoReviewIt=mapProdtoReview.find(r->prodName);
		if (mapProdtoReviewIt!=mapProdtoReview.end()){	
			mapProdtoReviewIt->second.push_back(r);
		}
		else{
			vector<Review*> allReview;
			allReview.push_back(r);
			mapProdtoReview.insert(make_pair(r->prodName,allReview));
		}
	}
}

std::vector<Review*> myDataStore::getProdReview(std::string prodName){
	return mapProdtoReview.find(prodName)->second;
}

void myDataStore::dump(std::ostream& ofile){
	ofile<<"<products>"<<endl;
	for (unsigned int i = 0; i < productList.size(); i++){
		productList[i]->dump(ofile);
	}
	ofile<<"</products>"<<endl;
	ofile<<"<users>"<<endl;
	for (unsigned int i = 0; i < userList.size(); i++){
		userList[i]->dump(ofile);
	}
	ofile<<"</users>"<<endl;
	ofile<<"<reviews>"<<endl;
	for(unsigned int i=0; i<reviewList.size(); i++){
		reviewList[i]->dump(ofile);
	}
	ofile<<"</reviews>"<<endl;

}

void myDataStore::initializeCart(){
	vector<Product*> cart;
	std::map<User*, vector<Product*> >::iterator userToProdIt;
	for (unsigned int i = 0; i < userList.size(); i++){
		userToProdIt=userCart.find(userList[i]);
		if (userToProdIt==userCart.end()){
			userCart.insert(make_pair(userList[i], cart));
		}
	}
}

void myDataStore::addToCart(string userStr, Product* p){
	initializeCart();
	User* findUser;
	bool userExist;
	for (unsigned int i = 0; i < userList.size(); i++){
		userExist=false;
		if(userList[i]->getName()==userStr){
			findUser=userList[i];
			userExist=true;
			break;
		}
	}
	if (userExist){
		std::map<User*, vector<Product*> >::iterator userToProdIt;
		userToProdIt=userCart.find(findUser);
		userToProdIt->second.push_back(p);
	}
	else{
		cout<<"Invalid request"<<endl;
	}
}

std::map<User*, std::vector<Product*> > myDataStore::getUserCart(){
	return userCart;
}

vector<Product*> myDataStore::viewCart(string userStr){
	initializeCart();
	User* findUser;
	bool userExist;
	for (unsigned int i = 0; i < userList.size(); i++){
		userExist=false;
		if(userList[i]->getName()==userStr){
			findUser=userList[i];
			userExist=true;
			break;
		}
	}

	if (userExist){
		std::map<User*, vector<Product*> >::iterator userToProdIt;
		userToProdIt=userCart.find(findUser);
		return userToProdIt->second;
	}
	
	else{
		cout<<"Invalid username"<<endl;
		vector <Product*> empty;
		return empty;
	}
}

void myDataStore::buyCart(string userStr){
	User* findUser;
	bool userExist;
	for (unsigned int i = 0; i < userList.size(); i++){
		userExist=false;
		if(userList[i]->getName()==userStr){
			findUser=userList[i];
			userExist=true;
			break;
		}
	}
	if (userExist){
		std::map<User*, vector<Product*> >::iterator userToProdIt;
		userToProdIt=userCart.find(findUser);
		vector<Product*>& cart=userToProdIt->second;
		std::vector<Product*> leftProd;
		for (unsigned int i = 0; i < cart.size(); i++){
			if (findUser->getBalance()>=cart[i]->getPrice()
				&&cart[i]->getQty()>0){
				cart[i]->subtractQty(1);
				findUser->deductAmount(cart[i]->getPrice());
			}
			else{
				leftProd.push_back(cart[i]);
			}
		}
		userToProdIt->second=leftProd;
	} 
	else{
		cout<<"Invalid username"<<endl;
	}

}



//map keywords to products
void myDataStore::mapWord(){
	//iterator of the mapWordtoProd
	std::map<string, std::set<Product*> >::iterator mapWordIt;
	std::set<string>::iterator setWordsIt;
	int productSize=productList.size();
	for (int i = 0; i < productSize; i++){
			set<string> allKeywords;
			set<Product*> allProduct;
			allKeywords=productList[i]->keywords();
		for(setWordsIt=allKeywords.begin();
			setWordsIt!=allKeywords.end();++setWordsIt){
			mapWordIt=mapWordtoProd.find(*setWordsIt);
			//if the keyword already exists
			if (mapWordIt!=mapWordtoProd.end()){
				mapWordIt->second.insert(productList[i]);
			}
			else{
				set <Product*> allProduct;
				allProduct.insert(productList[i]);
				mapWordtoProd.insert(make_pair((*setWordsIt),allProduct));
			}
		}
	}

}

std::vector<Product*> myDataStore::search(std::vector<std::string>& terms, 
	int type){
	vector <Product*> result;
if (terms.size()){
	//declare a vector to save the product
	//declare a vector of a set of products with the keyword
	vector <set<Product*> > vectorSetProd;
	int size=terms.size();
	std::map<string, std::set<Product*> >::iterator findWordIt;
	
	//and, intersection
	if (type==0){
		for (int i = 0; i < size; i++){
			//looking for the keyword
			findWordIt=mapWordtoProd.find(terms[i]);
			//check if the keyword exists, if not return empty vector
			//because and research
			if (findWordIt==mapWordtoProd.end()){
				productHolder=result;
				return result;
			}
			else{
				vectorSetProd.push_back(findWordIt->second);
			}
		}

		set<Product*> findIntersection=vectorSetProd[0];
		for (unsigned int i = 1; i < vectorSetProd.size(); i++){
			findIntersection=setIntersection(findIntersection,vectorSetProd[i]);
		}
		if (findIntersection.size()==0){
			productHolder=result;
			return result;
		}
		else{
			std::set<Product*>::iterator productIt;
			for(productIt=findIntersection.begin();
				productIt!=findIntersection.end();++productIt){
				result.push_back(*productIt);
			}
			productHolder=result;
			return result;
		}
	}

	if (type==1){
		for (int i = 0; i < size; i++){
		//looking for the keyword
		findWordIt=mapWordtoProd.find(terms[i]);
		//check if the keyword exists, if not return empty vector
		//because and research
		if (findWordIt!=mapWordtoProd.end()){
			vectorSetProd.push_back(findWordIt->second);		
		}
	}
		if(vectorSetProd.size()==0){
			productHolder=result;
			return result;
		}
	
		std::set<Product*> findUnion=vectorSetProd[0];
		for(unsigned int i=1; i<vectorSetProd.size();i++){
			findUnion=setUnion(findUnion,vectorSetProd[i]);
		}
		if (findUnion.size()==0){
			productHolder=result;
			return result;
		}
		else{
			std::set<Product*>::iterator productIt;
			for(productIt=findUnion.begin();
				productIt!=findUnion.end();++productIt){
				result.push_back(*productIt);
			}
			productHolder=result;
			return result;
		}
	}
}
productHolder=result;
return result;
}
std::vector<Product*> myDataStore::getSearchResult(){
	return productHolder;
}

void myDataStore::sortRate(rateCompare comp ){
	mergeSort(productHolder, comp);
}

void myDataStore::sortA(alphaCompare comp){
	mergeSort(productHolder, comp);
}

void myDataStore::sortR(std::string prod,reviewCompare comp){
	if(mapProdtoReview.find(prod)->second.size()<2){
		return;
	}
	mergeSort(mapProdtoReview.find(prod)->second, comp);
}

void myDataStore::calcAverageRating(){
	string productName;
	for (unsigned int i = 0; i < productHolder.size(); i++){
		productName=productHolder[i]->getName();
		map<string, vector<Review*> >::iterator mapProdtoReviewIt;
		mapProdtoReviewIt=mapProdtoReview.find(productName);
		if(mapProdtoReviewIt==mapProdtoReview.end()){
			productHolder[i]->setRating(0);
		}
		else{
			int size=mapProdtoReviewIt->second.size();
			vector<Review*> reviewList=mapProdtoReviewIt->second;
			double sum=0;
			if (size!=0){
				for (int j = 0; j < size; j++){
					sum=sum+reviewList[j]->rating;
				}
				productHolder[i]->setRating(sum/size);
			}
			else{
				productHolder[i]->setRating(0);
			}
		}
	}
}
void myDataStore::removeCart(string userStr, int index){
	User* findUser;
	bool userExist;
	for (unsigned int i = 0; i < userList.size(); i++){
		userExist=false;
		if(userList[i]->getName()==userStr){
			findUser=userList[i];
			userExist=true;
			break;
		}
	}
	if (userExist){
		std::map<User*, vector<Product*> >::iterator userToProdIt;
		userToProdIt=userCart.find(findUser);
		vector<Product*>& cart=userToProdIt->second;
		std::vector<Product*> leftProd;
		int size=cart.size();
		for ( int i = 0; i < size; i++){
			if (i!=index){
				leftProd.push_back(cart[i]);
			}
		}
		userToProdIt->second=leftProd;
	} 
	else{
		cout<<"Invalid username"<<endl;
	}
}