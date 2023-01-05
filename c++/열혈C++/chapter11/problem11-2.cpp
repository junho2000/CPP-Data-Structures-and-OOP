// #include <iostream>
// #include <cstdlib>
// using namespace std;

// class Point
// {
// private:
// 	int xpos, ypos;
// public:
// 	Point(int x=0, int y=0) : xpos(x), ypos(y) {  }
// 	friend ostream& operator<<(ostream& os, const Point& pos);
//     friend ostream& operator<<(ostream& os, const Point* pos);
// };

// ostream& operator<<(ostream& os, const Point& pos)
// {
// 	os<<'['<<pos.xpos<<", "<<pos.ypos<<']'<<endl;
// 	return os;
// }
// ostream& operator<<(ostream& os, const Point* pos)
// {
// 	os<<'['<<pos->xpos<<", "<<pos->ypos<<']'<<endl;
// 	return os;
// }

// typedef Point * POINT_PTR;

// class BoundCheckPointPtrArray 
// {
// private:
// 	POINT_PTR * arr;
// 	int arrlen;

// 	BoundCheckPointPtrArray(const BoundCheckPointPtrArray& arr) { }
// 	BoundCheckPointPtrArray& operator=(const BoundCheckPointPtrArray& arr) { }

// public:
// 	BoundCheckPointPtrArray(int len) :arrlen(len)
// 	{
// 		arr=new POINT_PTR[len];
// 	}
// 	POINT_PTR& operator[] (int idx)
// 	{
// 		if(idx<0 || idx>=arrlen)
// 		{
// 			cout<<"Array index out of bound exception"<<endl;
// 			exit(1);
// 		}
		
// 		return arr[idx];
// 	}
// 	// Point operator[] (int idx) const 
// 	// {
// 	// 	if(idx<0 || idx>=arrlen)
// 	// 	{
// 	// 		cout<<"Array index out of bound exception"<<endl;
// 	// 		exit(1);
// 	// 	}
		
// 	// 	return *(arr[idx]);
// 	// }
//     POINT_PTR operator[] (int idx) const 
// 	{
// 		if(idx<0 || idx>=arrlen)
// 		{
// 			cout<<"Array index out of bound exception"<<endl;
// 			exit(1);
// 		}
		
// 		return arr[idx];
// 	}
// 	int GetArrLen() const 
// 	{
// 		return arrlen;
// 	}
// 	~BoundCheckPointPtrArray()
// 	{
// 		delete []arr;
// 	}
// };

// int main(void)
// {
// 	BoundCheckPointPtrArray arr(3);
// 	arr[0]=new Point(3, 4);
// 	arr[1]=new Point(5, 6);
// 	arr[2]=new Point(7, 8);

// 	for(int i=0; i<arr.GetArrLen(); i++)
// 		cout<<*(arr[i]);

// 	delete arr[0];
// 	delete arr[1];
// 	delete arr[2];
// 	return 0;
// }
#include <iostream>
#include <cstdlib>
using namespace std;

class BoundCheckIntArray
{
private:
	int *arr;
	int arrlen;

	BoundCheckIntArray(const BoundCheckIntArray &arr) { }
	BoundCheckIntArray& operator= (const BoundCheckIntArray &arr) { }

public:
	BoundCheckIntArray(int len) : arrlen(len)
	{
		arr = new int[len];
	}
	int& operator[] (int idx)
	{
		if(idx<0 || idx>=arrlen)
		{
			cout<<"Array index out of bound exception"<<endl;
			exit(1);
		}
		return arr[idx];
	}
	int operator[] (int idx) const
	{
		if(idx<0 || idx>=arrlen)
		{
			cout<<"Array index out of bound exception"<<endl;
			exit(1);
		}
		return arr[idx];
	}
	int GetArrayLen() const
	{
		return arrlen;
	}
	~BoundCheckIntArray()
	{
		delete []arr;
	}
};

typedef BoundCheckIntArray* BoundCheckIntArrayPtr;

class BoundCheck2DIntArray
{
private:
	BoundCheckIntArray **arr;
	int arrlen;
	BoundCheck2DIntArray(const BoundCheck2DIntArray &arr) { }
	BoundCheck2DIntArray& operator= (BoundCheck2DIntArray &arr) { }
public:
	BoundCheck2DIntArray(int col, int row) : arrlen(col)
	{
		arr = new BoundCheckIntArrayPtr[col];
		for(int i=0; i<col; i++)
			arr[i] = new BoundCheckIntArray(row);
	}
	BoundCheckIntArray& operator[] (int idx)
	{
		if(idx<0 || idx>=arrlen)
		{
			cout<<"Array index out of bound exception"<<endl;
			exit(1);
		}
		return *(arr[idx]);
	}
	~BoundCheck2DIntArray()
	{
		for(int i=0; i<arrlen; i++)
			delete arr[i];
		delete []arr;
	}
};

int main(void)
{
	BoundCheck2DIntArray arr2d(3, 4);

	for(int n=0; n<3; n++)
		for(int m=0; m<4; m++)
			arr2d[n][m]=n+m;
	
	for(int n=0; n<3; n++)
	{
		for(int m=0; m<4; m++)
			cout<<arr2d[n][m]<<' ';
		cout<<endl;
	}
	return 0;
}