#pragma once
#include <iostream>
#include <string>


struct rbtree {
	int key;
	rbtree* l;
	rbtree* r;
	std::string str;
};
class amap {
	rbtree* base;
	void Print(rbtree* base) const;
	void Delete(rbtree* base);
	rbtree* Insert(int key, std::string str,rbtree* base);
	rbtree* Erase(int key, rbtree* base);

public:
	amap();
	~amap();
	bool insert(int key, std::string str);
	void print() const;
	const std::string& find(int key) const;
	bool erase(int key);
};