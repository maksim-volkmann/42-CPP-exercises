#include "Span.hpp"
#include <exception>
#include <climits>
Span::Span() : _maxSize(1){}

Span::Span(unsigned int size) : _maxSize(size) {}

Span::~Span(){}

Span::Span(const Span& other)
	: _storage(other._storage), _maxSize(other._maxSize){}

Span& Span::operator=(const Span& other){
	if(this != &other){
		_storage = other._storage;
		_maxSize = other._maxSize;
	}
	return *this;
}

void Span::addNumber(int n){
	if(_storage.size() < _maxSize){
		_storage.push_back(n);
	} else {
		throw std::runtime_error("Span is FULL!");
	}
}

int Span::shortestSpan() const{
	if(_storage.size() >= 2){
		std::vector<int> sorted(_storage);
		std::sort(sorted.begin(), sorted.end());
		int min_diff = INT_MAX;

		for(size_t i = 1; i < sorted.size(); ++i){
			int current_diff = sorted[i] - sorted[i-1];
			if(current_diff < min_diff){
				min_diff = current_diff;
			}
		}

		return min_diff;
	} else {
		throw std::runtime_error("Have to be 2 or more numbers");
	}
}

int Span::longestSpan() const{
	if(_storage.size() >= 2){
		int min = *std::min_element(_storage.begin(), _storage.end());
		int max = *std::max_element(_storage.begin(), _storage.end());
		return (max - min);
	} else {
		throw std::runtime_error("Have to be 2 or more numbers");
	}
}
