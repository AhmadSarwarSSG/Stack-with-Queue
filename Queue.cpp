#include "Queue.h"
#include<iostream>
using namespace std;
template<class Type>
void queue<Type>::enqueue(Type value)
{
	if (!(isfull()))//Here if queue is not full we add data
	{
		q[rear] = value;
		rear = (rear + 1) % size;//Index is provided in circular manner
		count++;//It gives the count of number
	}
	else
	{
		resize(1);//If array is full we resize it
		q[rear] = value;//Then store the value
		rear = (rear + 1) % size;
		count++;
	}
}
template<class Type>
Type queue<Type>::dequeue()
{
	if (!(isempty()))//If queue is not empty we pull out data
	{
		Type num = q[front];
		resize(2);//WE check if elements stored are 1/4 times the size we resize it
		front = (front + 1) % size;//Here front also move in circular manner
		count--;
		return num;
	}
	else
	{
		cout << "Queue is empty\n";
	}
}
template<class Type>
Type queue<Type>::Front()
{
	return q[front];//Here we get first value in queue
}
template<class Type>
Type queue<Type>::Rear()
{
	return q[rear];//Here we get last value in queue
}
template<class Type>
bool queue<Type>::isfull()
{
	if (count == size)//If number of elements become equal to size than queue is full
	{
		return true;
	}
	else
	{
		return false;
	}
}
template<class Type>
bool queue<Type>::isempty()
{
	if (count == 0)//If count of elements is zero means queue is empty
	{
		return true;
	}
	else
	{
		return false;
	}
}
template<class Type>
void queue<Type>::resize(int a)
{
	if (a == 1)//If resize is called from enqueue
	{
		if (isfull())
		{
			int psize = size;
			size = size * 2;
			Type* RS = q;//WE copy our array
			q = new Type[size];//Make a new one
			int j = 0;
			for (int i = front; j != count; i = (i + 1) % psize)
			{
				q[j++] = RS[i];//Here we paste it
			}
			front = 0;//Front is at zero because now it is linear
			rear = j;//and rear is next to the last element
		}
	}
	if (a == 2)
	{
		if (size / 4 > count)
		{
			int psize = size;
			size = size / 2;
			Type* RS = q;//WE copy our array
			q = new Type[size];//Make a new one
			int j = 0;
			for (int i = front; j != count; i = (i + 1) % psize)
			{
				q[j++] = RS[i];//Here we paste it
			}
			front = 0;//Front is at zero because now it is linear
			rear = j;//and rear is next to the last element
		}
	}
}
template<class Type>
void queue<Type>::showstructire()
{
	int j = front;
	int k = 0;
	for (int i = j; k != count; i = (i + 1) % size, k++)//Here we get the elements like we dequeue it
	{
		if (k + 1 != count)
		{
			cout << q[i] << "\n";
		}
		else
		{
			cout << q[i] << "   <----Rear\n";
		}
	}
}