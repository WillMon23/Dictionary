#include "Dictionary.h"
#include <iostream>

int main() {
	Dictionary<const char*, int> dictionary = Dictionary<const char*, int>();
	Dictionary<const char*, int> dictionary1 = Dictionary<const char*, int>();
	Dictionary<const char*, int> dictionary2 = Dictionary<const char*, int>();
	Dictionary<int, const char*> dictionary3 = Dictionary<int, const char*>();
	Dictionary<int, const char*> dictionary4 = Dictionary<int, const char*>();

	dictionary.addItem("Mom", 10);
	dictionary.addItem("Tom", 12);
	dictionary.addItem("Jom", 17);
	dictionary.addItem("Pom", 32);
	dictionary.addItem("Lom", 13);

	dictionary3.addItem(10, "Mom");
	dictionary3.addItem(14, "Mof");
	dictionary3.addItem(15, "Mog");
	dictionary3.addItem(16, "Moh");
	dictionary3.addItem(17, "Moj");

	int x = dictionary["Jom"];

	dictionary1 = dictionary;
	dictionary2 = dictionary1;
	dictionary4 = dictionary3;
	
	std::cout << "dic " << dictionary["Yom"] << std::endl;
	std::cout << "dic " << dictionary["Jom"] << std::endl;
	std::cout << "dic " << dictionary["Pom"] << std::endl;

	dictionary1.addItem("Yom", 3000);

	std::cout << std::endl;

	std::cout << "dic4 " << dictionary2["Yom"] << std::endl;
	std::cout << "dic4 " << dictionary2["Jom"] << std::endl;
	std::cout << "dic4 " << dictionary2["Pom"] << std::endl;
	std::cout << "dic4 " << dictionary2["Tom"] << std::endl;

	std::cout << std::endl;

	std::cout << "dic4 " << dictionary4[dictionary["Mom"]] << std::endl;
	std::cout << "dic4 " << dictionary4[14] << std::endl;
	std::cout << "dic4 " << dictionary4[17] << std::endl;
	std::cout << "dic4 " << dictionary4[16] << std::endl;

	std::cout << std::endl;

	std::cout << "dic " << dictionary["Yom"] << std::endl;

	std::cout << std::endl;

	dictionary1.remove("Lom",x);

	std::cout << "dic1 " << x << std::endl;

	system("pause");

	return 0;
}