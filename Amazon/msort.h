#include <iostream>
#include <vector>


template <class T, class Comparator>
void mergeSort (std::vector<T>& myArray, Comparator comp){
	int size=myArray.size();
	if (size>1){
		mergeSortH(myArray, 0, size-1, comp);
	}
	else{
		return;
	}
}


template<class T, class Comparator>
void mergeSortH(std::vector<T>& myArray, int left, int right, Comparator comp){
	if (right==left){
		return;
	}
	else{
		mergeSortH( myArray, left,left+(right-left)/2 ,comp);
		mergeSortH(myArray, left+(right-left)/2+1,right,comp);
		merge(myArray, left, right, left+(right-left)/2 ,comp);
	}
}

template<class T, class Comparator>
void merge(std::vector<T>& myArray, int left, 
	int right, int middle, Comparator comp){
	
	//copy the whole vector into two vectors
	int size1=middle-left+1;
	int size2=right-(middle+1)+1;
	std::vector<T> arr1;
	std::vector<T> arr2;

	for (int i = 0; i < size1; i++){
		arr1.push_back(myArray[left+i]);
	}
	for (int i = 0; i < size2; i++){
		arr2.push_back(myArray[middle+i+1]);
	}


	//compare two vectors
	int first=0;
	int second=0;
	std::vector<T> holder;
	int count=0;
	while(first<size1&&second<size2){
		if(comp(arr1[first],arr2[second])){
			myArray[left+count]=arr1[first];
			first++;
			count++;
		}
		else{
			myArray[left+count]=arr2[second];
			second++;
			count++;
		}
	}

	//when there are unequal number of elements in two vectors
	while(first<size1){
		myArray[left+count]=arr1[first];
		first++;
		count++;
	}

	while(second<size2){
		myArray[left+count]=arr2[second];
		second++;
		count++;
	}
}