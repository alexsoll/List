#pragma once
#include <iostream>
#include "THeadList.h"
using namespace std;

class TPolinom : public THeadList<TMonom> {
public:
	TPolinom() : THeadList<TMonom>() {
		pHead->value.coeff = 0;
		pHead->value.z = -1;
	}

	TPolinom(TMonom *tmp, int size) : THeadList<TMonom>() {
		pHead -> value.coeff = 0;
		pHead -> value.z = -1;
		for(int i = 0; i < size; i++)
			inslast(tmp[i]);
	}

	void InsByOrder(const TMonom& tmp) {
		for (Reset(); !IsEnd(); GoNext())
		{
			if(this == pCurr -> value == tmp) {
				pCurr -> value -> coeff += tmp.coeff;
				if (pCurr -> value -> coeff == 0)
					delCurr();
				return;
			}
			if (pCurr -> value < tmp) {
				inscurr(tmp);
				return;
			}

		}
		inslast(tmp);
	}

	void operator*(double c) {
		for(Reset(); !IsEnd(); GoNext())
			pCurr -> value -> coeff *= c;
	}


	void operator+=(const TPolinom& q) {
		q.Reset();
		Reset();
		while(!q.IsEnd() || !IsEnd()) {
			if(pCurr -> value == q.pCurr -> value) {
				pCurr -> value -> coeff += q.pCurr -> value -> coeff;
				if(pCurr -> value -> coeff == 0) {
					delCurr();
					q.GoNext();
				}
			}
			else {
				if(pCurr -> value < q.pCurr -> value) {
					inscurr(q.pCurr -> value);
					q.GoNext();
				}
			}
			else 
				GoNext();
		}
	}

};