#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <QMessageBox>
#include <QFileDialog>
#include <QMainWindow>
#include <QApplication>
#include <QMargins>
#include "main_window.h"
#include "mydatastore.h"
#include "util.h"

MainWindow::MainWindow(myDataStore* datastore)
{
	ds=datastore;
	ds->initializeCart();
	mainUserList=ds->getUserList();
	mapUsertoProd=ds->getUserCart();
	//title
	setWindowTitle("Amazon");
	//overall layout
	outsideOverallLayout=new QVBoxLayout();
	overallLayout=new QHBoxLayout();
	QFont titleFont;
    titleFont.setBold(true);
    titleFont.setPointSize(14);
	//User display
	userLayout=new QVBoxLayout();
	userLabelLayout=new QHBoxLayout();
	user=new QLabel("User");
	user->setFont(titleFont);
	userLabelLayout->addWidget(user);
	userLabelLayout->setSpacing(0);
	userLayout->addLayout(userLabelLayout);;
	//currentUser Layout
	currentUserLayout=new QHBoxLayout();
	currentUser=new QLabel("Current User");
	currentUserLayout->addWidget(currentUser);
	displayCurrentUser=new QLabel(QString::fromStdString(mainUserList[0]->getName()));
	currentUserLayout->addWidget(displayCurrentUser);
	userLayout->addLayout(currentUserLayout);
	//userNameInput
	userNameLayout=new QHBoxLayout();
	userNameInput=new QLineEdit();
	chooseUserButton=new QPushButton("Select");
	userNameLayout->addWidget(userNameInput);
	userNameLayout->addWidget(chooseUserButton);
	userLayout->addLayout(userNameLayout);

	//combobox
	selectUser=new QComboBox();
	for (unsigned int i = 0; i < mainUserList.size(); i++){
		QString name=QString::fromStdString(mainUserList[i]->getName());
		selectUser->addItem(name);
	}
	userLayout->addWidget(selectUser);

	//search layout
	searchLayout=new QVBoxLayout();
	searchLine=new QHBoxLayout();
	search=new QLabel("Search");
	search->setFont(titleFont);
	searchLayout->addWidget(search);
	terms= new QLineEdit();
	searchButton=new QPushButton("Search");
	searchLine->addWidget(terms);
	searchLine->addWidget(searchButton);
	searchLayout->addLayout(searchLine);
	groupBox1=new QGroupBox();
	selectAnd=new QRadioButton("And");
	selectAnd->setChecked(true);
	selectOr=new QRadioButton("Or");
	radioButton=new QHBoxLayout();
	selectAnd->setChecked(true);
	radioButton->addWidget(selectAnd);
	radioButton->addWidget(selectOr);
	groupBox1->setLayout(radioButton);
	groupBox1->setContentsMargins(0,-8,0,-5);
	searchLayout->addWidget(groupBox1);
	userLayout->addLayout(searchLayout);
	
	//savefile layout
	saveFileLayout=new QVBoxLayout();
	saveFile=new QLabel("Save File");
	saveFileLayout->addWidget(saveFile);
	saveFileButton=new QPushButton("Save");
	saveFileLayout->addWidget(saveFileButton);
	userLayout->addLayout(saveFileLayout);

	//quit button
	quitButton=new QPushButton("Quit");
	userLayout->addWidget(quitButton);
	overallLayout->addLayout(userLayout);

	//Product List
	productLayout=new QVBoxLayout();
	product=new QLabel("Product List");
	product->setFont(titleFont);
	productLayout->addWidget(product);
	listOfProduct=new QListWidget();
	productLayout->addWidget(listOfProduct);
	addToCartButton=new QPushButton("Add to Cart");
	viewCartButton=new QPushButton("View Cart");
	byRate=new QRadioButton("by Rate");
	byRate->setChecked(true);
	byAlpha=new QRadioButton("by Alphabetic");
	searchCriteLayout=new QHBoxLayout;
	searchCriteLayout->addWidget(byRate);
	searchCriteLayout->addWidget(byAlpha);
	groupBox2=new QGroupBox();
	groupBox2->setLayout(searchCriteLayout);
	groupBox2->setContentsMargins(0,-8	,0,-5);
	productLayout->addWidget(groupBox2);
	productLayout->addWidget(addToCartButton);
	productLayout->addWidget(viewCartButton);
	overallLayout->addLayout(productLayout);

	//Review Layout
	reviewLayout=new QVBoxLayout();
	review=new QLabel("Review");
	review->setFont(titleFont);
	reviewLayout->addWidget(review);
	listOfReview=new QListWidget();
	reviewLayout->addWidget(listOfReview);
	addReviewButton=new QPushButton("Add Review");
	reviewLayout->addWidget(addReviewButton);
	//overallLayout->addLayout(reviewLayout);
	outsideOverallLayout->addLayout(overallLayout);
	outsideOverallLayout->addLayout(reviewLayout);
	setFixedWidth(800);
	setLayout(outsideOverallLayout);

	//allocate widget for cart
	cartWin=new QWidget();
	cartWin->setFixedWidth(300);
	cartLayout=new QVBoxLayout();
	cart=new QLabel("Cart");
	cart->setFont(titleFont);
	cartItem=new QListWidget();
	buyCartButton=new QPushButton("Buy Cart");
	closeCartButton=new QPushButton("Close");
	removeCartButton=new QPushButton("Remove Item");
	//set up layout
	cartLayout->addWidget(cart);
	cartLayout->addWidget(cartItem);
	cartLayout->addWidget(buyCartButton);
	cartLayout->addWidget(removeCartButton);
	cartLayout->addWidget(closeCartButton);
	cartWin->setLayout(cartLayout);


	//allocate widget for addreview window
	reviewWin=new QWidget();
	reviewWinLayout=new QVBoxLayout();
	reviewLabel=new QLabel("Review Edit");
	textBox=new QTextEdit();
	timeLayout=new QHBoxLayout();
	timeLabel=new QLabel("Date");
	year= new QComboBox();
	for (int i = 2016; i < 2031; i++){
		QString x;
		x.setNum(i);
		year->addItem(x);
	}
	month=new QComboBox();
	for (int i = 1; i < 13; i++){
		QString x;
		x.setNum(i);
		month->addItem(x);
	}
	date=new QComboBox();
	for (int i = 1; i < 32; i++){
		QString x;
		x.setNum(i);
		date->addItem(x);
	}
	rateLayout=new QHBoxLayout();
	submitButton=new QPushButton("Submit");
	rateLabel=new QLabel("Rate");
	rateInput=new QComboBox();
	for (int i = 1; i < 6; i++){
		QString x;
		x.setNum(i);
		rateInput->addItem(x);
	}
	//set up layout
	reviewWinLayout->addWidget(reviewLabel);
	reviewWinLayout->addWidget(textBox);
	rateLayout->addWidget(rateLabel);
	rateLayout->addWidget(rateInput);
	reviewWinLayout->addLayout(rateLayout);
	timeLayout->addWidget(timeLabel);
	timeLayout->addWidget(year);
	timeLayout->addWidget(month);
	timeLayout->addWidget(date);
	reviewWinLayout->addLayout(timeLayout);
	reviewWinLayout->addWidget(submitButton);
	reviewWin->setLayout(reviewWinLayout);
	reviewWin->setFixedWidth(400);


	//connect signals and slots
  	connectSlots();

}


MainWindow::~MainWindow(){
	//deallocate reviews allocated in addreview
	for(unsigned int i=0; i<reviewAllocated.size();i++){
		delete reviewAllocated[i];
	}
	//other private data are not in destructor because
	//they are destructed in mydatastore
}

void MainWindow::connectSlots(){
	QObject::connect(viewCartButton, SIGNAL(clicked()), this, SLOT(viewCart()));
  	QObject::connect(closeCartButton, SIGNAL(clicked()),this, SLOT(closeCart()));
  	QObject::connect(chooseUserButton, SIGNAL(clicked()),this, SLOT(chooseUser()));
	QObject::connect(selectUser, SIGNAL(currentIndexChanged(int)),this,SLOT(chooseFromCombo(int)));
	QObject::connect(searchButton,SIGNAL(clicked()),this,SLOT(searchProduct()));
	QObject::connect(saveFileButton, SIGNAL(clicked()),this,SLOT(saveFileFunction()));
	QObject::connect(quitButton,SIGNAL(clicked()),QApplication::instance(), SLOT(quit()));
	QObject::connect(addToCartButton,SIGNAL(clicked()),this,SLOT(addToCartFunction()));
	QObject::connect(byRate,SIGNAL(clicked()),this, SLOT(byRateClicked()));
	QObject::connect(byAlpha,SIGNAL(clicked()),this, SLOT(byAlphaClicked()));
	QObject::connect(buyCartButton,SIGNAL(clicked()),this, SLOT(buyCartFunction()));
	QObject::connect(addReviewButton,SIGNAL(clicked()),this, SLOT(addReviewFunction()));
	QObject::connect(listOfProduct, SIGNAL(itemClicked(QListWidgetItem*)), 
            this, SLOT(prodClicked(QListWidgetItem*)));
	QObject::connect(month,SIGNAL(currentIndexChanged(int)),this,SLOT(monthSelected(int)));
	QObject::connect(year,SIGNAL(currentIndexChanged(int)),this,SLOT(yearSelected(int)));
	QObject::connect(submitButton,SIGNAL(clicked()),this, SLOT(submitFunction()));
	QObject::connect(removeCartButton,SIGNAL(clicked()),this, SLOT(removeCartFunction()));
}

void MainWindow::viewCart(){
	cartWin->show();
}

void MainWindow::closeCart(){
	cartWin->hide();
}


//User Section
void MainWindow::chooseUser(){
	cartItem->clear();
	if (userNameInput->text().isEmpty()){
		return;
	}
	std::string stringName;
	stringName=userNameInput->text().toStdString();
	QString name;
	if (checkUser(stringName)==false){
		return;
	}
	else{
		name=QString::fromStdString(convToLower(stringName));
		displayCurrentUser->setText(name);
	}
	User* theUser=convUserstrToUser(convToLower(stringName));
	addCartList(ds->getUserCart().find(theUser)->second);
	userNameInput->setText("");
}
void MainWindow::chooseFromCombo(int n){
	cartItem->clear();
	QString name;
	name=QString::fromStdString(mainUserList[n]->getName());
	displayCurrentUser->setText(name);
	User* theUser=convUserstrToUser(mainUserList[n]->getName());
	ds->getUserCart().find(theUser)->second;
	addCartList(ds->getUserCart().find(theUser)->second);
}

bool MainWindow::checkUser(std::string inputName){
	for (unsigned int i = 0; i < mainUserList.size(); i++){
		if (convToLower(inputName)==(mainUserList[i]->getName()))
		return true;
	}
	return false;
}



//Search Section
std::vector<std::string> MainWindow::convToString(QString line){
	std::string wholeLine=line.toStdString();
	std::stringstream ss(wholeLine);
	std::string oneTerm;
	std::vector<std::string> stringList;
	while(ss>>oneTerm){
		stringList.push_back(oneTerm);
	}
	return stringList;
}

void MainWindow::searchProduct(){
	if(!selectAnd->isChecked()&&!selectOr->isChecked()){
		QMessageBox msg;
		msg.setWindowTitle("Note");
		msg.setText("Please Select And/Or ");
		msg.exec();
	}

	if (!listOfProduct->count()==0){
		listOfProduct->clear();
	}
	std::vector<std::string> saveTerms= convToString(terms->text());
	if (selectAnd->isChecked()){
		holdProduct=ds->search(saveTerms,0);
		if (byRate->isChecked()){
			ds->calcAverageRating();
			rateCompare byRate;
			ds->sortRate(byRate);
			holdProduct=ds->getSearchResult();
		}
		if (byAlpha->isChecked()){
			alphaCompare byAlpha;
			ds->sortA(byAlpha);
			holdProduct=ds->getSearchResult();
		}
		addList(holdProduct);
		terms->setText("");
	}

	if (selectOr->isChecked()){
		holdProduct=ds->search(saveTerms,1);
		if (byRate->isChecked()){
			ds->calcAverageRating();
			rateCompare byRate;
			ds->sortRate(byRate);
			holdProduct=ds->getSearchResult();
		}
		if (byAlpha->isChecked()){
			alphaCompare byAlpha;
			ds->sortA( byAlpha);
			holdProduct=ds->getSearchResult();
		}
		addList(holdProduct);
		terms->setText("");
	}
}


void MainWindow::addList(std::vector<Product*> productHolder){
	for (unsigned int i = 0; i < productHolder.size(); i++){
			std::stringstream conv;
			conv<<i+1;
			std::string num;
			conv>>num;
			std::string category=productHolder[i]->getCategory()+'\n';
			std::string name=productHolder[i]->getName()+'\n';
			//price
			std::stringstream priceConv;
			priceConv<<productHolder[i]->getPrice();
			std::string price;
			priceConv>>price;
			price=price+"    ";
			//qty
			std::stringstream qtyConv;
			qtyConv<<productHolder[i]->getQty();
			std::string qty;
			qtyConv>>qty;
			qty=qty+'\n';
			//special info
			std::string specialInfo1=productHolder[i]->getSpecialInfo1()+'\n';
			std::string specialInfo2=productHolder[i]->getSpecialInfo2()+'\n';
			std::string firstLine=num+" "+category+name+price+qty
			+specialInfo1+specialInfo2;
			QString firstLineInfo=QString::fromStdString(firstLine);
			listOfProduct->addItem(firstLineInfo);
		}
}

void MainWindow::saveFileFunction(){
	reviewWin->hide();
	cartWin->hide();
	QString filename = QFileDialog::getSaveFileName(this,tr("Save File"),
		"home/student/Desktop/cs104/hw-ruoxijia/hw5",tr("Text file(*.txt)"));
	std::string file=filename.toStdString();
	std::ofstream ofile(file.c_str());
	ds->dump(ofile);
	ofile.close();
}


void MainWindow::addToCartFunction(){
	//clear cart
	if (cartItem->count()!=0){
		cartItem->clear();
	}
	//if no product selected
	int count=listOfProduct->count()-1;
	if(listOfProduct->currentRow()<0||listOfProduct->currentRow()>count){
		return;
	}
	//after a product selected
	int selected=listOfProduct->currentRow();
	QString currentUser=displayCurrentUser->text();
	std::string selectedUser=currentUser.toStdString();
	ds->addToCart(selectedUser, holdProduct[selected]);
	User* theUser=convUserstrToUser(selectedUser);
	mainUserCart=ds->getUserCart().find(theUser)->second;
	addCartList(mainUserCart);
}

User* MainWindow::convUserstrToUser(std::string Userstr){
	for (unsigned  i = 0; i < mainUserList.size(); i++){
		if(mainUserList[i]->getName()==Userstr)
			return mainUserList[i];
	}
	return mainUserList[0];
}
void MainWindow::addCartList(std::vector<Product*> productHolder){
	if (productHolder.size()==0){
		return;
	}
	for (unsigned int i = 0; i < productHolder.size(); i++){
			std::stringstream conv;
			conv<<i+1;
			std::string num;
			conv>>num;
			std::string category=productHolder[i]->getCategory()+'\n';
			std::string name=productHolder[i]->getName()+'\n';
			//price
			std::stringstream priceConv;
			priceConv<<productHolder[i]->getPrice();
			std::string price;
			priceConv>>price;
			price=price+"    ";
			//qty
			std::stringstream qtyConv;
			qtyConv<<productHolder[i]->getQty();
			std::string qty;
			qtyConv>>qty;
			qty=qty+'\n';
			//special info
			std::string specialInfo1=productHolder[i]->getSpecialInfo1()+'\n';
			std::string specialInfo2=productHolder[i]->getSpecialInfo2()+'\n';
			std::string firstLine=num+" "+category+name+price+qty
			+specialInfo1+specialInfo2;
			QString firstLineInfo=QString::fromStdString(firstLine);
			cartItem->addItem(firstLineInfo);
		}
}

void MainWindow::byRateClicked(){
	listOfProduct->clear();
	ds->calcAverageRating();
	//conv userStr to user
	rateCompare byRate;
	ds->sortRate(byRate);
	holdProduct=ds->getSearchResult();
	addList(holdProduct);

}


void MainWindow::byAlphaClicked(){
	listOfProduct->clear();
	//conv userStr to user
	alphaCompare byAlpha;
	ds->sortA(byAlpha);
	holdProduct=ds->getSearchResult();
	addList(holdProduct);
}

void MainWindow::buyCartFunction(){
	if (cartItem->currentRow()==-1){
		return;
	}
	cartItem->clear();
	QString currentUser=displayCurrentUser->text();
	std::string selectedUser=currentUser.toStdString();
	User* theUser=convUserstrToUser(selectedUser);
	ds->buyCart(selectedUser);
	mainUserCart=ds->getUserCart().find(theUser)->second;
	addCartList(mainUserCart);
	if (mainUserCart.size()!=0){
		QMessageBox msg;
		msg.setWindowTitle("Alert");
		msg.setText("Out of stock or not enough money! ");
		msg.exec();
	}
	holdProduct=ds->getSearchResult();
	listOfProduct->clear();
	addList(holdProduct);
}

void MainWindow::addReviewFunction(){
	if(listOfProduct->currentRow()!=-1)
	reviewWin->show();
	else{
		QMessageBox msg;
		msg.setWindowTitle("Alert");
		msg.setText("Please Select a Product ");
		msg.exec();
	}
}

void MainWindow::addReviewList(std::vector<Review*> reviewList){
	unsigned int size=reviewList.size();
	for (unsigned int i = 0; i < size; i++){
		std::stringstream ss;
		ss<<reviewList[i]->rating;
		std::string rate;
		ss>>rate;
		std::string review;
		review=reviewList[i]->date+"		";
		review=review+rate+"\n";
		review=review+reviewList[i]->prodName+'\n';
		review=review+reviewList[i]->reviewText+'\n';
		review=review+reviewList[i]->username+'\n';
		QString qreview=QString::fromStdString(review);
		listOfReview->addItem(qreview);
	}
}

void MainWindow::prodClicked(QListWidgetItem* item){
	listOfReview->clear();
	int saveNum=0;
	for (int i = 0; i < listOfProduct->count(); i++){
		if(item==listOfProduct->item(i)){
			saveNum=i;
			break;
		}
	}
	reviewCompare comp;
	holdProduct=ds->getSearchResult();
	std::string name =holdProduct[saveNum]->getName();
	mapProdtoReview=ds->getProdReview(holdProduct[saveNum]->getName());
	ds->sortR(holdProduct[saveNum]->getName(),comp);
	addReviewList(mapProdtoReview);
}

//review time combo box
void MainWindow::monthSelected(int theMonth){
	date->clear();
	if ((year->currentIndex()+2016)%4==0){
		if (theMonth==1){
			for (int i = 1; i < 30; i++){
				QString x;
				x.setNum(i);
				date->addItem(x);
			}
			return;
		}
	}
	int arr1[7]={0,2,4,6,7,9,11};
	bool bigMonth=false;
	for (int i = 0; i < 7; i++){
		if (theMonth==arr1[i]){
			bigMonth=true;
			break;
		}
	}
	if (bigMonth){
		for (int i = 1; i < 32; i++){
			QString x;
			x.setNum(i);
			date->addItem(x);
		}
	}
	else if(theMonth==1){
		for (int i = 1; i < 29; i++){
			QString x;
			x.setNum(i);
			date->addItem(x);
		}
	}
	else{
		for (int i = 1; i < 31; i++){
			QString x;
			x.setNum(i);
			date->addItem(x);
		}
	}

}

void MainWindow::yearSelected(int theYear){
	date->clear();
	if ((theYear+2016)%4==0){
		if (month->currentIndex()==1){
			for (int i = 1; i < 30; i++){
				QString x;
				x.setNum(i);
				date->addItem(x);
			}
			return;
		}
	}
	int arr1[7]={0,2,4,6,7,9,11};
	bool bigMonth=false;
	for (int i = 0; i < 7; i++){
		if (month->currentIndex()==arr1[i]){
			bigMonth=true;
			break;
		}
	}
	if (bigMonth){
		for (int i = 1; i < 32; i++){
			QString x;
			x.setNum(i);
			date->addItem(x);
		}
	}
	else if(month->currentIndex()==1){
		for (int i = 1; i < 29; i++){
			QString x;
			x.setNum(i);
			date->addItem(x);
		}
	}
	else{
		for (int i = 1; i < 31; i++){
			QString x;
			x.setNum(i);
			date->addItem(x);
		}
	}

}


void MainWindow::submitFunction(){
	//user
	QString currentUser=displayCurrentUser->text();
	const std::string selectedUser=currentUser.toStdString();

	//product
	if (listOfProduct->currentRow()==-1){
		return;
	}
	int selected=listOfProduct->currentRow();
	QString prod=QString::fromStdString(holdProduct[selected]->getName());
	const std::string prodName=prod.toStdString();

	//rate
	int rate=rateInput->currentIndex()+1;

	//reviewText
	const std::string reviewText=(textBox->toPlainText()).toStdString();
	//date
	int yearNum=year->currentIndex()+2016;
	int monthNum=month->currentIndex()+1;
	int dateNum=date->currentIndex()+1;
	std::stringstream ss1,ss2,ss3;
	ss1<<yearNum;
	ss2<<monthNum;
	ss3<<dateNum;
	std::string yearStr, monthStr, dateStr;
	ss1>>yearStr;
	ss2>>monthStr;
	ss3>>dateStr;
	if (monthNum<10){
		monthStr="0"+monthStr;
	}
	if (dateNum<10){
		dateStr="0"+dateStr;
	}

	const std::string time=yearStr+"-"+monthStr+"-"+dateStr;
	//add review
	Review *r=new Review(prodName,rate,selectedUser,time,reviewText);
	ds->addReview(r);
	reviewAllocated.push_back(r);

	//update review data here
	int prodNum=listOfProduct->currentRow();
	reviewCompare comp;
	ds->sortR(holdProduct[prodNum]->getName(),comp);
	mapProdtoReview=ds->getProdReview(holdProduct[prodNum]->getName());
	listOfReview->clear();
	addReviewList(mapProdtoReview);
	//clear reviewText
	textBox->clear();
	reviewWin->hide();

	//update productList
	listOfProduct->clear();
	ds->calcAverageRating();
	rateCompare compRate;
	ds->sortRate(compRate);
	holdProduct=ds->getSearchResult();
	addList(holdProduct);
}	

void MainWindow::removeCartFunction(){
	int currentRow=cartItem->currentRow();
	if (currentRow==-1){
		return;
	}
	QString currentUser=displayCurrentUser->text();
	std::string selectedUser=currentUser.toStdString();
	ds->removeCart(selectedUser, currentRow);
	if (cartItem->count()!=0){
		cartItem->clear();
	}
	User* theUser=convUserstrToUser(selectedUser);
	mainUserCart=ds->getUserCart().find(theUser)->second;
	addCartList(mainUserCart);
}
 
