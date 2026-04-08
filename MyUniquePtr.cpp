#include <iostream>
#include <utility>
#include "MyUniquePtr.h"

MyUniquePtr::MyUniquePtr()
{
	std::cout << "Создан конструктор по умолчанию 'MyUniquePtr'" << "\n";
}

MyUniquePtr::MyUniquePtr(int* ptr) :ptr(ptr)
{
	std::cout << "Создан конструктор 'MyUniquePtr' который принимает обычный указатель" << "\n";
}

MyUniquePtr::MyUniquePtr(MyUniquePtr&& other) :ptr(other.ptr)
{
	other.ptr = nullptr;
}

MyUniquePtr::~MyUniquePtr()
{
	std::cout << "Создан деструктор 'MyUniquePtr' " << "\n";
	delete ptr;
}

MyUniquePtr& MyUniquePtr::operator=(MyUniquePtr&& other)
{
	if (this != &other) {
		delete ptr;
		ptr = other.ptr;
		other.ptr = nullptr;
	}
	return *this;
}

int& MyUniquePtr::operator*()
{
	return *ptr;
}

int* MyUniquePtr::get()const
{
	return ptr;
}

MyUniquePtr::operator bool()const
{
	return ptr != nullptr;
}

void MyUniquePtr::reset(int* p)
{
	std::cout << "Вызван метод reset!" << "\n";
	delete ptr;
	ptr = p;
}

int* MyUniquePtr::release()
{
	std::cout << "Вызван метод release!" << "\n";
	int* red_ptr = ptr;
	ptr = nullptr;
	return red_ptr;
}
