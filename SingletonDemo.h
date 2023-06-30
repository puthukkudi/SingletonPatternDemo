#pragma once

#include <iostream>

class SingletonDemo
{
	private:
		static int counter;
		static SingletonDemo mInstance;		
		SingletonDemo();
		SingletonDemo(const SingletonDemo& obj) = delete;
		SingletonDemo& operator = (const SingletonDemo& obj) = delete;
		SingletonDemo(SingletonDemo&& obj) = delete;
		SingletonDemo& operator = (SingletonDemo&& obj) = delete;
	public:
		static SingletonDemo& GetInstance();
		void Print();
		~SingletonDemo();
};

