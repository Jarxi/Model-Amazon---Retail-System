#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H
#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QListWidget>
#include <QComboBox>
#include <QRadioButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QGroupBox>
#include <string>
#include <vector>
#include <QString>
#include <sstream>
#include "mydatastore.h"


class MainWindow: public QWidget{
	Q_OBJECT

public:
	MainWindow(myDataStore* datastore);
	~MainWindow();
	void connectSlots();
private slots:
	//user
	bool checkUser(std::string inputName);
	void chooseUser();
	void chooseFromCombo(int n);
	//search
	std::vector<std::string> convToString(QString line);
	void searchProduct();
	void addList(std::vector<Product*> productHolder);
	void saveFileFunction();
	void byRateClicked();
	void byAlphaClicked();
	//cart
	void addToCartFunction();
	void addCartList(std::vector<Product*> productHolder);
	User* convUserstrToUser(std::string Userstr);
	void viewCart();
	void closeCart();
	void buyCartFunction();
	void removeCartFunction();
	//review
	void prodClicked(QListWidgetItem* item);
	void addReviewFunction();
	void addReviewList(std::vector<Review*> mainReviewList);
	//review time
	void yearSelected(int theYear);
	void monthSelected(int theMonth);
	void submitFunction();
private:
	//layout
	QVBoxLayout* outsideOverallLayout;
	QHBoxLayout* overallLayout;

	//display user 
	QVBoxLayout* userLayout;
	QHBoxLayout* userLabelLayout;
	QLabel* user;
	QHBoxLayout* currentUserLayout;
	QLabel* currentUser;
	QLabel* displayCurrentUser;
	QHBoxLayout* userNameLayout;
	QHBoxLayout* comboBoxLayout;
	QLineEdit* userNameInput;
	QPushButton* chooseUserButton;
	QComboBox* selectUser;
	//search
	QVBoxLayout* searchLayout;
	QHBoxLayout* searchLine;
	QLabel* search;
	QPushButton* searchButton;
	QLineEdit* terms;
	QGroupBox* groupBox1;
	QHBoxLayout* radioButton;
	QRadioButton* selectAnd;
	QRadioButton* selectOr;
	//savefile
	QVBoxLayout* saveFileLayout;
	QLabel* saveFile;
	QPushButton* saveFileButton;
	//quit
	QPushButton* quitButton;


	//display products
	QVBoxLayout* productLayout;
	QHBoxLayout* searchCriteLayout;
	QLabel* product;
	QListWidget* listOfProduct;
	QPushButton* addToCartButton;
	QPushButton* viewCartButton;
	QRadioButton* byRate;
	QRadioButton* byAlpha;
	QGroupBox* groupBox2;
	//display reviews;
	QVBoxLayout* reviewLayout;
	QLabel* review;
	QListWidget* listOfReview;
	QPushButton* addReviewButton;
	QPushButton* removeReviewButton;

	//cart
	QWidget* cartWin;
	QVBoxLayout* cartLayout;
	QLabel* cart;
	QListWidget* cartItem;
	QPushButton* buyCartButton;
	QPushButton* closeCartButton;
	QPushButton* removeCartButton;
	//addreview window
	QWidget* reviewWin;
	QVBoxLayout* reviewWinLayout;
	QLabel* reviewLabel;
	QLabel* timeLabel;
	QTextEdit* textBox;
	QHBoxLayout* rateLayout;
	QLabel* rateLabel;
	QComboBox* rateInput;
	QHBoxLayout* timeLayout;
	//QCombobox;
	QComboBox* year;
	QComboBox* month;
	QComboBox* date;
	QPushButton* submitButton;
	//other data
	myDataStore* ds;
	std::vector<User*> mainUserList;
	std::vector<Review*> mapProdtoReview;
	std::vector<Product*> mainUserCart;
	std::map<User*, std::vector<Product*> > mapUsertoProd;
	std::vector<Product*> holdProduct;
	std::vector<Review*> reviewAllocated;
};
#endif