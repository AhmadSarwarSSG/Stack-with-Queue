#include<iostream>
#include"Queue.h"
#include"Queue.cpp"
using namespace std;

int main()
{
	queue<int>q1,q2;
	int num;
	cout << "Enter the number of elements you want to enter in Stack: ";
	cin >> num;//To get the number of elements
	int n;
	for (int i = 0; i < num; i++)
	{
		cout << "Enter the elements of Stack: ";
		cin >> n;
		if (q1.isempty())//If q1 is empty we enter the element
		{
			q1.enqueue(n);
		}
		else
		{
			while (!(q1.isempty()))//if q1 is not empty we put all its elements in q2
			{
				q2.enqueue(q1.dequeue());
			}
			q1.enqueue(n);//Then we enter new element
			while (!(q2.isempty()))//Then again we pour all the elements from q2 to q1 again
			{
				q1.enqueue(q2.dequeue());
			}
		}
	}
	cout << "Poping and Printig Values from Stack\n";
	q1.showstructire();
	return 0;
}