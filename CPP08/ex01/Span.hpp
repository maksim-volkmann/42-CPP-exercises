#pragma once

#include <string>
#include <stdexcept>
#include <vector>
#include <iterator>

class Span{
private:
	std::vector<int> _storage;
	unsigned int _maxSize;

public:
	Span();
	Span(unsigned int);
	~Span();
	Span(const Span&);
	Span& operator=(const Span&);

	void addNumber(int);

	template <typename InputIterator>
	void addNumbers(InputIterator start, InputIterator end){
		size_t inputRange = std::distance(start, end);
		size_t storageAvailable = _maxSize - _storage.size();

		if(inputRange > storageAvailable){
			throw std::runtime_error("Storage is FULL!");
		}

		_storage.insert(_storage.end(), start, end);
	}

	int shortestSpan() const;
	int longestSpan() const;
};

