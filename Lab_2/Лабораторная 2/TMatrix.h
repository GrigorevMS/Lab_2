#pragma once
#include"TVector.h"
// ����������������� �������
template <class ValType>
class TMatrix : public TVector<TVector<ValType> >
{
public:
	TMatrix(int s = 10);
	TMatrix(const TMatrix& mt);                    // �����������
	TMatrix(const TVector<TVector<ValType> >& mt); // �������������� ����
	bool operator==(const TMatrix& mt) const;      // ���������
	bool operator!=(const TMatrix& mt) const;      // ���������
	TMatrix& operator= (const TMatrix& mt);        // ������������
	TMatrix  operator+ (const TMatrix& mt);        // ��������
	TMatrix  operator- (const TMatrix& mt);        // ���������

	// ���� / �����
	friend istream& operator>>(istream& in, TMatrix& mt)
	{
		for (int i = 0; i < mt.Size; i++)
			in >> mt.pVector[i];
		return in;
	}
	friend ostream& operator<<(ostream& out, const TMatrix& mt)
	{
		for (int i = 0; i < mt.Size; i++)
			out << mt.pVector[i] << endl;
		return out;
	}
};

template <class ValType>
TMatrix<ValType>::TMatrix(int s) : TVector<TVector<ValType> >(s)
{
	if (s >= MAX_MATRIX_SIZE)
		throw - 1;
	for (int i = 0; i < s; i++)
		this->pVector[i] = TVector<ValType>(s - i, i);
	this->Size = s;
	//this->StartIndex = 0;
} /*-------------------------------------------------------------------------*/

template <class ValType> // ����������� �����������
TMatrix<ValType>::TMatrix(const TMatrix<ValType>& mt) :
	TVector<TVector<ValType> >(mt) {}

template <class ValType> // ����������� �������������� ����
TMatrix<ValType>::TMatrix(const TVector<TVector<ValType> >& mt) :
	TVector<TVector<ValType> >(mt) {}

template <class ValType> // ���������
bool TMatrix<ValType>::operator==(const TMatrix<ValType>& mt) const
{
	if (this->Size != mt.Size)
		return false;
	for (int i = 0; i < this->Size; i++)
		if (this->pVector[i] != mt.pVector[i])
			return false;
	return true;
} /*-------------------------------------------------------------------------*/

template <class ValType> // ���������
bool TMatrix<ValType>::operator!=(const TMatrix<ValType>& mt) const
{
	return !(*this == mt);
} /*-------------------------------------------------------------------------*/

template <class ValType> // ������������
TMatrix<ValType>& TMatrix<ValType>::operator=(const TMatrix<ValType>& mt)
{
	if (this->pVector != NULL)
		delete[] this->pVector;
	this->Size = mt.Size;
	//pVector = new ValType[mt.Size];
	this->pVector = new TVector<ValType>[mt.Size];
	if (this->pVector == NULL)
		throw - 1;
	for (int i = 0; i < this->Size; i++)
		this->pVector[i] = mt.pVector[i];
	return *this;
} /*-------------------------------------------------------------------------*/

template <class ValType> // ��������
TMatrix<ValType> TMatrix<ValType>::operator+(const TMatrix<ValType>& mt)
{
	return TVector<TVector<ValType>>::operator+(mt);
} /*-------------------------------------------------------------------------*/

template <class ValType> // ���������
TMatrix<ValType> TMatrix<ValType>::operator-(const TMatrix<ValType>& mt)
{
	return TVector<TVector<ValType>>::operator-(mt);
} /*-------------------------------------------------------------------------*/

