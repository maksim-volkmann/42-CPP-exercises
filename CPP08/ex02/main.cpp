#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main() {
	std::cout << "--- SUBJECT TESTS ---" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);

	std::cout << "--- BASIC COMMAND TEST ---" << std::endl;

	MutantStack<int> basicStack;
	basicStack.push(100);
	basicStack.push(200);

	std::cout << "Top element: " << basicStack.top() << std::endl;

	basicStack.pop(); //remove top/first element
	std::cout << "Top element: " << basicStack.top() << std::endl;

	if(basicStack.empty()){
		std::cout << "Stack is empty!" << std::endl;
	} else {
		std::cout << "Stack is NOT empty!" << std::endl;
	}

	basicStack.pop();

	if(basicStack.empty()){
		std::cout << "Stack is EMPTY!" << std::endl;
	} else {
		std::cout << "Stack is NOT EMPTY!" << std::endl;
	}

	std::cout << "--- BASIC ITERATION TEST ---" << std::endl;

	basicStack.push(300);
	basicStack.push(400);
	basicStack.push(500);

	MutantStack<int>::iterator it1 = basicStack.begin();
	MutantStack<int>::iterator ite1 = basicStack.end();
	MutantStack<int>::reverse_iterator rit1 = basicStack.rbegin();
	MutantStack<int>::reverse_iterator rite1 = basicStack.rend();

	std::cout << "Normal: " << std::endl;
	for(; it1 != ite1; ++it1){
		std::cout << *it1 << std::endl;
	}

	std::cout << "-----------------" << std::endl;

	std::cout << "Reverse: " << std::endl;
	for(; rit1 != rite1; ++rit1){
		std::cout << *rit1 << std::endl;
	}

	std::cout << "--- CONST ITERATION TEST ---" << std::endl;

	MutantStack<int> constStack;

	constStack.push(111);
	constStack.push(222);
	constStack.push(333);

	MutantStack<int>::const_iterator const_it1 = constStack.begin();
	MutantStack<int>::const_iterator const_ite1 = constStack.end();
	MutantStack<int>::const_reverse_iterator const_rit1 = constStack.rbegin();
	MutantStack<int>::const_reverse_iterator const_rite1 = constStack.rend();

	std::cout << "Const Normal: " << std::endl;
	for(; const_it1 != const_ite1; ++const_it1){
		std::cout << *const_it1 << std::endl;
	}

	std::cout << "-----------------" << std::endl;

	std::cout << "Const Reverse: " << std::endl;
	for(; const_rit1 != const_rite1; ++const_rit1){
		std::cout << *const_rit1 << std::endl;
	}

	std::cout << "--- USING LIST AS BASE CONTAINER TEST ---" << std::endl;

	MutantStack<int, std::list<int>> basicMutantList;
	basicMutantList.push(666);
	basicMutantList.push(777);
	basicMutantList.push(888);

	MutantStack<int, std::list<int>>::iterator list_it1 = basicMutantList.begin();
	MutantStack<int, std::list<int>>::iterator list_ite1 = basicMutantList.end();
	MutantStack<int, std::list<int>>::reverse_iterator list_rit1 = basicMutantList.rbegin();
	MutantStack<int, std::list<int>>::reverse_iterator list_rite1 = basicMutantList.rend();

	std::cout << "Normal: " << std::endl;
	for(; list_it1 != list_ite1; ++list_it1){
		std::cout << *list_it1 << std::endl;
	}

	std::cout << "-----------------" << std::endl;

	std::cout << "Reverse: " << std::endl;
	for(; list_rit1 != list_rite1; ++list_rit1){
		std::cout << *list_rit1 << std::endl;
	}

	std::cout << "--- COPY AND ASSIGMENT TEST ---" << std::endl;
	MutantStack<int> stack1;
	MutantStack<int> stack2;

	stack1.push(9999);
	stack2.push(1);

	std::cout << stack1.top() << std::endl;
	std::cout << stack2.top() << std::endl;

	std::cout << "Copy stack2 to stack1" << std::endl;
	stack1 = stack2;

	std::cout << stack1.top() << std::endl;
	std::cout << stack2.top() << std::endl;

	stack1.pop();
	stack1.push(8888);

	std::cout << "Create (copy) stack3 from stack1" << std::endl;
	MutantStack<int> stack3(stack1);
	std::cout << stack3.top() << std::endl;

	std::cout << "--- COMPARING TO BASIC LIST ---" << std::endl;

	MutantStack<int> stackC;
	std::list<int> listC;

	stackC.push(1);
	stackC.push(2);
	stackC.push(3);
	stackC.push(4);

	listC.push_back(1);
	listC.push_back(2);
	listC.push_back(3);
	listC.push_back(4);

	MutantStack<int>::iterator stackC_it1 = stackC.begin();
	MutantStack<int>::iterator stackC_ite1 = stackC.end();

	std::list<int>::iterator listC_it1 = listC.begin();
	std::list<int>::iterator listC_ite1 = listC.end();

	std::cout << "Mutant Stack: " << std::endl;
	for(; stackC_it1 != stackC_ite1; ++stackC_it1){
		std::cout << *stackC_it1 << std::endl;
	}

	std::cout << "Normal List: " << std::endl;
	for(; listC_it1 != listC_ite1; ++listC_it1){
		std::cout << *listC_it1 << std::endl;
	}

	stackC.pop();
	listC.pop_back();

	//reset
	stackC_it1 = stackC.begin();
	stackC_ite1 = stackC.end();
	listC_it1 = listC.begin();
	listC_ite1 = listC.end();

	std::cout << "Mutant Stack after pop: " << std::endl;
	for(; stackC_it1 != stackC_ite1; ++stackC_it1){
		std::cout << *stackC_it1 << std::endl;
	}

	std::cout << "Normal List after pop_front: " << std::endl;
	for(; listC_it1 != listC_ite1; ++listC_it1){
		std::cout << *listC_it1 << std::endl;
	}

	return 0;
}
