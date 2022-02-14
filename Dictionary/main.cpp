#include "Dictionary.h"
#include <iostream>

int main() {
	Dictionary<const char*, int> dictionary = Dictionary<const char*, int>();
	Dictionary<const char*, int> dictionary1 = Dictionary<const char*, int>();

	dictionary.addItem("Mom", 10);
	dictionary.addItem("Tom", 12);
	dictionary.addItem("Jom", 17);
	dictionary.addItem("Yom", 42);
	dictionary.addItem("Pom", 32);
	dictionary.addItem("Lom", 13);

	int x = dictionary["Yom"];

	dictionary1 = dictionary;
	
	std::cout << dictionary["Yom"] << std::endl;
	std::cout << dictionary["Jom"] << std::endl;
	std::cout << dictionary["Pom"] << std::endl;
	std::cout << dictionary1["Yom"] << std::endl;

	dictionary.remove("Yom");

	std::cout << dictionary1["Yom"] << std::endl;
	std::cout << x << std::endl;

	std::cout << "dic1: " << dictionary1.getCount() << std::endl;
	std::cout << "dic: " << dictionary.getCount() << std::endl;

	system("pause");

	return 0;
}