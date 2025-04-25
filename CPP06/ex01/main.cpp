#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>
#include <iomanip>

int main(){

	Data randomObject;
	randomObject.value = 42;

	Data* original_ptr = &randomObject;

	uintptr_t serialized = Serializer::serialize(&randomObject);
	std::cout << "Serialized randomObject: " << serialized << std::endl;
	std::cout << "----------------------------------------" << std::endl;
	Data* deserialize = Serializer::deserialize(serialized);

	std::cout << "Original pointer     : " << original_ptr << std::endl;
	std::cout << "Deserialized pointer : " << deserialize << std::endl;

	if(original_ptr == deserialize){
		std::cout << "------------------------------" << std::endl;
		std::cout << "SUCCESS: POINTERS ARE THE SAME!" << std::endl;
		std::cout << "original_ptr value : " << original_ptr->value << std::endl;
		std::cout << "deserialize value  : " << deserialize->value << std::endl;
	} else {
		std::cout << "------------------------------" << std::endl;
		std::cout << "ERROR: POINTERS ARE THE SAME!" << std::endl;
		std::cout << "original_ptr value : " << original_ptr->value << std::endl;
		std::cout << "deserialize value  : " << deserialize->value << std::endl;
	}

}
