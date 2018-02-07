#pragma once
#include <iostream>
#include "TList.h"
using namespace std;

struct TMonom {
	double coeff;
	int x, y, z; 
};

bool operator<(const TMonom& t1, const TMonom& t2) {
	int buf1 = t1.x * 100 + t1.y * 10 + t1.z;
	int buf2 = t2.x * 100 + t2.y * 10 + t2.z;
	if (buf1 < buf2)
		return true;
	else 
		return false;
}

bool operator==(const TMonom& t1, const TMonom& t2) {
	int buf1 = t1.x * 100 + t1.y * 10 + t1.z;
	int buf2 = t2.x * 100 + t2.y * 10 + t2.z;
	if (buf1 == buf2)
		return true;
	else 
		return false;
}

template <class T>
class THeadList:public TList {
protected:
	TList *pHead;
public:
	THeadList():TList() {
	pHead = new TLink<T>;
	pStop = pHead;
	pHead->pNext = pHead;
	}

	~THeadList() {
		TList::~TList();
		delete pHead;
	}

	void insfirst(const T& elem) {
		TList::insfirst(elem);
		pHead->pNext = pFirst;
	}

	void delfirst(){
		TList::delfirst();
		pHead->pNext = pFirst;
	}
};