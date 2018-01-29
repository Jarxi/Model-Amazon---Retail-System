#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include <string>
#include <set>
#include <vector>
#include "product.h"
#include "user.h"
#include "datastore.h"
#include "msort.h"
#include <sstream>
#include <map>

struct reviewCompare{
    bool operator()(const Review* x, const Review* y) const{
        std::string date1=x->date;
        std::string date2=y->date;
        std::stringstream ss1,ss2;
        ss1<<date1;
        ss2<<date2;
        for (unsigned int i = 0; i < 3; i++){
            int x1;
            int y1;
            ss1>>x1;
            ss2>>y1;
            if (x1>y1){
                return (x1>y1);
            }
            else if(x1<y1){
                return false;
            }
            else{
                char ch1;
                char ch2;
                ss1>>ch1;
                ss2>>ch2;
            }
        }
    return false;
    }
};



struct rateCompare{
    bool operator()(Product* x, Product* y){
        return (x->rating>y->rating);
    }
};

struct alphaCompare{
    bool operator()(Product* x, Product* y){
        return (x->getName()<y->getName());
    }
};





class myDataStore: public DataStore{

public:
    ~myDataStore();
    /**
     * Adds a product to the data store
     */
     void addProduct(Product* p);

    /**
     * Adds a user to the data store
     */
     void addUser(User* u);

     //adds a review to the product
     void addReview(Review* r);
    /**
     * Performs a search of products whose keywords match the given "terms"
     *  type 0 = AND search (intersection of results for each term) while
     *  type 1 = OR search (union of results for each term)
     */
     std::vector<Product*> search(std::vector<std::string>& terms, int type);

    /**
     * Reproduce the database file from the current Products and User values
     */
     void dump(std::ostream& ofile);
     void initializeCart();
     void addToCart(std::string userStr, Product* p);
     void buyCart (std::string userStr);
     void mapWord();
     //sort Usercart
     void sortRate(rateCompare comp);
     void sortA(alphaCompare comp);
     void sortR(std::string user,reviewCompare comp);
     void calcAverageRating();
     void removeCart(std::string prodName, int index);
     std::vector<Product*> getSearchResult();
     std::vector<User*> getUserList();
     std::vector<Product*> getProductList();
     std::vector<Product*> viewCart(std::string userStr);
     std::vector<Review*> getReviewList();
     std::vector<Review*> getProdReview(std::string prodName);
     std::map<User*, std::vector<Product*> > getUsertoProd();
     //access a certain user's cart
     std::map<User*, std::vector<Product*> > getUserCart();

private:
	std::vector <Product*> productList;
	std::vector <User*> userList;
    std::vector <Review*> reviewList;
    std::set <std::string> allProductName;
    std::map<std::string, std::vector<Review*> > mapProdtoReview;
    std::map<std::string, std::set<Product*> > mapWordtoProd;
	std::map<User*, std::vector<Product*> > userCart;
    //hold search result
    std::vector<Product*> productHolder;
};



#endif