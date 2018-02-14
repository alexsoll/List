#pragma once
#include <iostream>
using namespace std;

template <class T>
struct TLink {
	T value;
	TLink *pNext;
};

template <class T>
class TList {
	TLink<T> *pFirst, *pPrev, *pCurr, *pStop, *pLast;
	int size, pos;
public:
	TList() {
		pFirst = pLast = pCurr = pStop = NULL;
		size = 0;
		pos = -1;
	}

	virtual void insfirst(const T& elem) {
		TLink<T> *tmp = new TLink <T>;
		tmp->value = elem;
		tmp->pNext = pFirst;
		if (pFirst == pStop)
		{
			pFirst = pLast = pCurr = tmp;
			pos = 0;
		}
		else {
			pFirst = tmp;
		}	
		pos++;
		size++;
	}

	void inslast(const T& elem) {
		TLink<T> *tmp = new TLink <T>;
		tmp->value = elem;
		tmp->pNext = pStop;
		if (pFirst == pStop)
		{
			pFirst = pLast = pCurr = tmp;
			pos = 0;
		}
		else {
			pLast->pNext = tmp;
			pLast = tmp;
		}
		size++;
	}

	virtual void inscurr(const T& elem) {
		if (pCurr == pFirst)
			insfirst(elem);
		else {
			if (pCurr == pStop)
				inslast(elem);
			else {
				TLink<T> *tmp = new TLink < T > ;
				tmp->value = elem;
				tmp->pNext = pCurr;
				pPrev->pNext = tmp;
				pCurr = tmp;
				size++;
			}
		}
	}

	void Reset() {
		pPrev = pCurr = pFirst;
		pos = 0;
	}

	void goNext() {
		pPrev = pCurr;
		pCurr = pCurr->pNext;
		pos++;
	}

	bool isEnd() {
		return (pCurr == pStop);
	}

	T getElelm(){ return pCurr->value; }

	virtual void deleteFirst() {
		if (size == 1) {
			delete pFirst;
			pFirst = pLast = pCurr = pPrev = pStop;
		}
		else {
			TLink<T> *tmp = pFirst;
			pFirst = pFirst->pNext;
			delete tmp;
		}
		size--;
		if (pos > 0)
			pos--;
	}

	int getsize() { return size; }

	int getpos() { return pos; }

	bool isEmpty(){
		return pFirst == pStop;
	}

	virtual void delLast(){
		if (pLast == pFirst) deleteFirst();
		else{
			for (Reset(); !(pCurr->pNext == pStop); goNext()){}
			delete pLast;
			pLast = pCurr = pPrev;
			Reset();
			size--;
			pos--;
		}
	}



	virtual void delCurr(){
		if (pCurr == pFirst)
			deleteFirst();
		else
		{
			pCurr = pCurr->pNext;
			delete pPrev->pNext;
			pPrev->pNext = pCurr;
			size--;
		}
	}



	T operator[](int m){
		for (Reset(); !isEnd(); goNext()){
			if (pos == m - 1)
				return pCurr->value;
		}
	}


	virtual void sortInput(T elem){
		if (pFirst == pStop || elem < pFirst->value) { insfirst(elem); return; }
		if (elem >= pLast->value){ inslast(elem); return; }
		for (Reset(); !isEnd(); goNext()){
			if (pCurr->value > elem) { inscurr(elem); return; }
		}
	}
};