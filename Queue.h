#pragma once
#include<iostream>
using namespace std;
template<class Type>
class queue
{
protected:
	Type* q;
	int size;
	int front;
	int rear;
	int count;
public:
	queue()//Default construtor
	{
		front = 0;
		rear = 0;
		count = 0;
		size = 5;
		q = new Type[size];
	}
	queue(int s)//parametrized construtor
	{
		front = 0;
		rear = 0;
		count = 0;
		size = s;
		q = new Type[size];
	}
	queue(const queue& obj)//Copy Constructor
	{
		size = obj.size;
		q = new Type[size];
		count = obj.count;
		for (int i = 0; i < obj.count; i++)
		{
			enqueue(obj.q[i]);
		}
		front = obj.front;
		rear = obj.rear;
	}
	void enqueue(Type);
	Type dequeue();
	Type Front();
	Type Rear();
	bool isfull();
	bool isempty();
	void resize(int);
	void showstructire();
};