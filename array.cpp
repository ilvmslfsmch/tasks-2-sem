#include <iostream>
#include "Array.h"
#include <sstream>

vector::vector(): array(nullptr), size (0) {}

vector::vector(const std::initializer_list<int> list) : size(list.size()) {
	array = new int[size];
	size_t i = 0;
	for (int elem : list)
	       	array[i++] = elem;
}

vector::~vector() {
	delete[] array;
} 

vector::vector(const vector& other) : size(other.size) {
	array = (size > 0) ? new int[size] : nullptr;
	for (size_t i = 0; i < size; ++i)
		array[i] = other.array[i];
}

vector::vector(vector&& other) : size(other.size), array(other.array) {
	other.size = 0;
	other.array = nullptr;
}

bool vector::isEmpty() const {
	return size == 0;
}

size_t vector::getSize() const {
	return size;
}

std::string vector::toString() const {
	if (isEmpty())
		return "Empty";
	std::stringstream ss;
	for (size_t i = 0; i < size; ++i) {
		ss << array[i];
		if (i < size - 1)
			ss << " ";
	}
	return ss.str();
}

void vector::push(size_t index, const int element) {
	if (index > size)
		index = size;
	int* newArray = new int[size+1];
	for (size_t i = 0, j = 0; i < size + 1; ++i) {
		if (i == index)
			newArray[i] = element;
		else newArray[i] = array[j++];
	}
	delete[] array;
	array = newArray;
	size++;
}

void vector::pop(const size_t index) {
	if (index >= size)
		return;
	int* newArray = (size > 1) ? new int[size - 1] : nullptr;
	for (size_t i = 0, j = 0; i < size; ++i) {
		if (i == index)
			continue;
		newArray[j++] = array[i];
	}
	delete[] array;
	array = newArray;
	size--;
}

void vector::replace(const size_t index, const int element) {
	if (index < size)
		array[index] = element;
}

int& vector::operator[](const size_t index) {
	if (index >= size) {
		throw std::out_of_range("No such element in this array.");
	}
	return array[index];
}

const int& vector::operator[](const size_t index) const {
	if (index >= size) {
		throw std::out_of_range("No such element in this array.");
	}
	return array[index];
}

vector& vector::operator=(const vector& other) {
	if (this != &other) {
		delete[] array;
		size = other.size;
		array = (size > 0) ? new int[size] : nullptr;
		for (size_t i = 0; i < size; ++i)
			array[i] = other.array[i];
	}
	return *this;
}

vector& vector::operator=(vector&& other) {
	if (this != &other) {
		delete[] array;
		size = other.size;
		array = other.array;
		
		other.size = 0;
		other.array = nullptr;
	}
	return *this;
}

bool vector::operator==(const vector& other) const {
	if (size != other.size)
		return false;
	for (size_t i = 0; i < size; ++i)
		if (array[i] != other.array[i])
			return false;
	return true;
}

bool vector::operator!=(const vector& other) const {
	return !(*this == other);
}

std::ostream& operator<<(std::ostream& os, const vector& vec) {
	os << vec.toString();
	return os;
}

std::istream& operator>>(std::istream& is, vector& vec) {
	int val = 0;
	if (is >> val) {
		vec.push(vec.size, val);
	}
	return is;
}
