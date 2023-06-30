/*
* SingletonPointerDemo
* Singleton pattern with 
*/


#pragma once

#include <iostream>
#include <mutex>

class SingletonPointerDemo
{
	private:
		static int counter;
		static std::mutex mtx;
		static SingletonPointerDemo *mInstance;
		SingletonPointerDemo();
		SingletonPointerDemo(const SingletonPointerDemo& obj) = delete;
		SingletonPointerDemo& operator = (const SingletonPointerDemo& obj) = delete;
		SingletonPointerDemo(SingletonPointerDemo&& obj) = delete;
		SingletonPointerDemo& operator = (SingletonPointerDemo&& obj) = delete;
	public:
		static SingletonPointerDemo& GetInstance();
		void Print();
		~SingletonPointerDemo();
};

