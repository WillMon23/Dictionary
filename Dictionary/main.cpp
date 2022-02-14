#include "Dictionary.h"
#include <iostream>

int main() {
	Dictionary<const char*, int> dictionary;
	Dictionary<const char*, int> dictionary1;

	dictionary.addItem("Mom", 10);
	dictionary.addItem("Tom", 12);
	dictionary.addItem("Jom", 17);
	dictionary.addItem("Yom", 42);
	dictionary.addItem("Pom", 32);
	dictionary.addItem("Lom", 13);

	dictionary = dictionary1;
	
	std::cout << dictionary["Lom"] << std::endl;
	std::cout << dictionary["Jom"] << std::endl;
	std::cout << dictionary["Pom"] << std::endl;
	
	dictionary.remove("Lom");

	std::cout << dictionary1["Pom"] << std::endl;

	system("pause");

	return 0;
}