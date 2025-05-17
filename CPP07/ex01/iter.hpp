#pragma once

template <typename T>
void iter(T* arr, int length, void (*f)(T&)){
	if(!arr || !f || length <= 0)
		return;
	for(int i = 0; i < length; ++i){
		f(arr[i]);
	}
}

template <typename T>
void iter(const T* arr, int length, void (*f)(const T&)){
	if(!arr || !f || length <= 0)
		return;
	for(int i = 0; i < length; ++i){
		f(arr[i]);
	}
}

