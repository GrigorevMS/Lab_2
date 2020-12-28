#include <iostream>
using namespace std;
const int MAX_VECTOR_SIZE = 100000000;
const int MAX_MATRIX_SIZE = 10000;

// ������ �������
template <class ValType>
class TVector
{
public:
	ValType* pVector;
	int Size;       // ������ �������
	int StartIndex; // ������ ������� �������� �������
public:
	TVector(int s = 10, int si = 0);
	TVector(const TVector& v);                // ����������� �����������
	ValType& GetValue(int pos);				  // ������ �� �������
	~TVector();
	int GetSize() { return Size; } // ������ �������
	int GetStartIndex() { return StartIndex; } // ������ ������� ��������
	ValType& operator[](int pos);             // ������
	bool operator==(const TVector& v) const;  // ���������
	bool operator!=(const TVector& v) const;  // ���������
	TVector& operator=(const TVector& v);     // ������������

	// ��������� ��������
	TVector  operator+(const ValType& val);   // ��������� ������
	TVector  operator-(const ValType& val);   // ������� ������
	TVector  operator*(const ValType& val);   // �������� �� ������

	// ��������� ��������
	TVector  operator+(const TVector& v);     // ��������
	TVector  operator-(const TVector& v);     // ���������
	ValType  operator*(const TVector& v);     // ��������� ������������

	// ����-�����
	friend istream& operator>>(istream& in, TVector& v)
	{
		for (int i = 0; i < v.Size; i++)
			in >> v.pVector[i];
		return in;
	}
	friend ostream& operator<<(ostream& out, const TVector& v)
	{
		for (int i = 0; i < v.StartIndex; i++)
			out << 0 << ' ';
		for (int i = 0; i < v.Size; i++)
			out << v.pVector[i] << ' ';
		return out;
	}
};

template <class ValType>
TVector<ValType>::TVector(int s, int si)
{
	if (s >= MAX_VECTOR_SIZE || s < 0 || si < 0)
		throw - 1;
	Size = s;
	StartIndex = si;
	pVector = new ValType[s];
	if (pVector == NULL)
		throw - 1;
	//for (int i = 0; i < s; i++)
	//    pVector[i] = 0;
} /*-------------------------------------------------------------------------*/

template <class ValType> //����������� �����������
TVector<ValType>::TVector(const TVector<ValType>& v)
{
	Size = v.Size;
	StartIndex = v.StartIndex;
	pVector = new ValType[Size];
	if (pVector == NULL)
		throw - 1;
	for (int i = 0; i < Size; i++)
		pVector[i] = v.pVector[i];
} /*-------------------------------------------------------------------------*/

template <class ValType>
TVector<ValType>::~TVector()
{
	if (pVector != NULL)
		delete[] pVector;
} /*-------------------------------------------------------------------------*/

template <class ValType>
ValType& TVector<ValType>::GetValue(int pos) {
	if (pos >= 0 || pos < Size) {
		return(pVector[pos]);
	}
	else {
		throw - 1;
	}
}

template <class ValType> // ������
ValType& TVector<ValType>::operator[](int pos)
{
	if (pos < 0 || pos >= (Size + StartIndex))
		throw - 1;
	return pVector[pos - StartIndex];
} /*-------------------------------------------------------------------------*/

template <class ValType> // ���������
bool TVector<ValType>::operator==(const TVector& v) const
{
	if (Size != v.Size || StartIndex != v.StartIndex)
		return false;
	for (int i = 0; i < Size; i++)
		if (pVector[i] != v.pVector[i])
			return false;
	return true;
} /*-------------------------------------------------------------------------*/

template <class ValType> // ���������
bool TVector<ValType>::operator!=(const TVector& v) const
{
	return !(*this == v);
} /*-------------------------------------------------------------------------*/

template <class ValType> // ������������
TVector<ValType>& TVector<ValType>::operator=(const TVector& v)
{
	if (Size != v.Size)
	{
		delete[] pVector;
		pVector = new ValType[v.Size];
		if (pVector == NULL)
			throw - 1;
	}
	Size = v.Size;
	StartIndex = v.StartIndex;
	for (int i = 0; i < Size; i++)
		pVector[i] = v.pVector[i];
	return *this;
} /*-------------------------------------------------------------------------*/

template <class ValType> // ��������� ������
TVector<ValType> TVector<ValType>::operator+(const ValType& val)
{
	TVector<ValType> temp(Size, StartIndex);
	for (int i = 0; i < Size; i++)
		temp.pVector[i] = pVector[i] + val;
	return temp;
} /*-------------------------------------------------------------------------*/

template <class ValType> // ������� ������
TVector<ValType> TVector<ValType>::operator-(const ValType& val)
{
	TVector<ValType> temp(Size, StartIndex);
	for (int i = 0; i < Size; i++)
		temp.pVector[i] = pVector[i] - val;
	return temp;
} /*-------------------------------------------------------------------------*/

template <class ValType> // �������� �� ������
TVector<ValType> TVector<ValType>::operator*(const ValType& val)
{
	TVector<ValType> temp(Size, StartIndex);
	for (int i = 0; i < Size; i++)
		temp.pVector[i] = pVector[i] * val;
	return temp;
} /*-------------------------------------------------------------------------*/

template <class ValType> // ��������
TVector<ValType> TVector<ValType>::operator+(const TVector<ValType>& v)
{
	if (Size != v.Size || StartIndex != v.StartIndex)
		throw - 1;
	TVector<ValType> temp(Size, StartIndex);
	for (int i = 0; i < Size; i++)
		temp.pVector[i] = pVector[i] + v.pVector[i];
	return temp;
} /*-------------------------------------------------------------------------*/

template <class ValType> // ���������
TVector<ValType> TVector<ValType>::operator-(const TVector<ValType>& v)
{
	if (Size != v.Size || StartIndex != v.StartIndex)
		throw - 1;
	TVector<ValType> temp(Size, StartIndex);
	for (int i = 0; i < Size; i++)
		temp.pVector[i] = pVector[i] - v.pVector[i];
	return temp;
} /*-------------------------------------------------------------------------*/

template <class ValType> // ��������� ������������
ValType TVector<ValType>::operator*(const TVector<ValType>& v)
{
	if (Size != v.Size || StartIndex != v.StartIndex)
		throw - 1;
	ValType ans = 0;
	for (int i = StartIndex; i < Size; i++)
		ans = ans + pVector[i] * v.pVector[i];
	return ans;
} /*-------------------------------------------------------------------------*/