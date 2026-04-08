#include <iostream>
#include "MyUniquePtr.h"

int main() {
	setlocale(LC_ALL, "RU");
	std::cout << " === Программа 'MyUniquePtr' начала свою работу! === " << "\n";
	// Выполнил перемещение значения р1 в р2
	MyUniquePtr p1(new int(10));
	if (p1) {
		std::cout << "Значение p1=" << *p1 << " по адресу=" << p1.get() << "\n";
	}
	MyUniquePtr p2 = std::move(p1);
	if (!p1 && p2) {
		std::cout << "Значение p1 успешно перенесено в р2!\nТеперь p2= " << *p2 << "\n";
	}
	// метод reset();
	std::cout << "\n";
	p2.reset(new int(10));
	std::cout << "Вызов p2.reset();" << "\n";
	p2.reset(nullptr);
	if (!p2) {
		std::cout << "p2 корректно опустошен" << "\n";
	}
	// метод release()
	std::cout << "\n";
	MyUniquePtr p3(new int(100));
	std::cout << "Значение р3= " << *p3 << " по адресу= " << p3.get()<< "\n";
	int* red_ptr = p3.release();
	if (!p3.get()) {
		std::cout << "р3-Больше не владеет памятью" << "\n";
	}
	if (red_ptr) {
		std::cout << "Значение, на которое указывает raw_ptr= " << *red_ptr << "\n";
		std::cout << "Удаляем 'red_ptr'" << "\n";
		delete red_ptr;
		std::cout << "'red_ptr' удален!" << "\n";
	}
	// выполнил перемещение значения р1 в р4
	std::cout << "\n";
	MyUniquePtr p4 = std::move(p1);
	if (!p1 && p4) {
		std::cout << "Значение успешно перенесено!" << *p4 << "\n";
	}
	else {
		std :: cout << "p4-Пустой объект!" << "\n";
	}
	// Выполнил перемещение р3 в р5
	std::cout << "\n";
	MyUniquePtr p5 = std::move(p3);
	if (!p3 && p5) {
		std::cout << "Значение p3 успешно перенесено в р5!\nТеперь p5 = " << *p5 << "\n";
	}
	// Ввиде примера выполнил присваивание значения переменной с именем 'red'                      ???????????
	std::cout << "\n";
	std::unique_ptr<int>red = std::make_unique<int>(456);
	if (red) {
		std::cout << "Переменная 'red'= " << *red << " с адресом= "<<red.get()<<"\n";
	}
	// Создал переменную 'pop' и выполнил перемещение значения с именем 'red' в переменную 'pop'            ????????????
	std::unique_ptr<int>pop = std::move(red);
	if (!red&&pop||!pop.get()) {
		std::cout << "Переменная 'pop' теперь= " << *pop << " С адресом= " << pop << "\n";
		std::cout << "Переменная 'pop' теперь не владеет адресом!= " << pop<< "\n";
	}
	else {
		std::cout << "Пустой 'pop'!" << "\n";
	}
	// Попытался выполнить принудительное присваивание значения 'p6' переменной 'p7'
	std::cout << "\n";
	MyUniquePtr p6(new int(60));
	std::cout << "Значение р6= " << *p6 << " по адресу= " << p6.get() << "\n";
	MyUniquePtr p7(new int(20));
	std::cout << "Значение р7= " << *p7 << " по адресу= " << p7.get() << "\n";
	p7 = std::move(p6);
	std::cout << "Принудительное перемещение из р6 в р7=" << *p7 << " и новым адресом= " << p7.get() << "\n";

    std::cout << "\n === Программа 'MyUniquePtr' закончила свою работу! === " << "\n";
	return 0;
}