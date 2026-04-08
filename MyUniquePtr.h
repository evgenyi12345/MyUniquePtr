#ifndef MYUNIQUEPTR_H
#define MYUNIQUEPTR_H

class MyUniquePtr {
public:
	MyUniquePtr         ();                                   // Конструктор по умолчанию
	MyUniquePtr         (int* ptr);                           // Конструктор который принимает обычный указатель 
	MyUniquePtr         (MyUniquePtr&) = delete;              // Запрещаем копирование
	MyUniquePtr         (MyUniquePtr&& other);                // Конструктор перемещения
	~MyUniquePtr        ();                                   // Деструктор
	MyUniquePtr&        operator=(MyUniquePtr&) = delete;     // Запрещаем копирование
	MyUniquePtr&        operator=(MyUniquePtr&& other);       // Оператор перемещения 
	int& operator*      ();                                   // Оператор разыменования
	int* get            ()const;                              // Доступ к указателю
	operator bool       () const;                             // Проверка на пустоту
	void reset          (int* p);                             // Метод reset,который удаляет старый указатель указатель и присваивает новый
	int* release        ();                                   // Метод  который освобождает владение объектом и возвращает сырой указатель на него

private:
	int*                ptr;                                  // Сырой указатель

};

#endif