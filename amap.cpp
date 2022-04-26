#include "amap.h"


amap::~amap()
{
	Delete(base);
}
amap::amap()
{
	base = NULL;
}
bool amap::insert(int key, std::string str) 
{
	if (base == NULL)
	{
		base = new rbtree;
		base->r = NULL;
		base->l = NULL;
		base->key = key;
		base->str = str;
	}
	else if (key > base->key)
	{
		base->r = Insert(key, str, base->r);
	}
	else if (key < base->key)
	{
		base->l = Insert(key, str, base->l);
	}
	else return false;
}
void amap::print() const
{
	Print(base);
}
const std::string& amap::find(int key) const 
{
	rbtree* tmp = base;
	while (tmp!= nullptr)
	{
		if (key == tmp->key) return tmp->str;
		if (key < tmp->key)
		{
			tmp = tmp->l;
		}
		else if (key > tmp->key)
		{
			tmp = tmp->r;
		}
	}
	std::cout<< "No elements"<<std::endl;
	
}
bool amap::erase(int key)
{
	base = Erase(key, base);
	return true;
}
void amap::Delete(rbtree* base)
{
	if (base) {
		Delete(base->l);
		Delete(base->r);
		delete base;
	}
}
void amap::Print(rbtree* base)const
{
	if (base != NULL)
	{
		std::cout << "Key - " << base->key << " String - " << base->str << std::endl;
		Print(base->l);
		Print(base->r);
	}
}
rbtree* amap::Insert(int key, std::string str, rbtree* base) {
	if (base == NULL) {
		base = new rbtree;
		base->l = NULL;
		base->r = NULL;
		base->key = key;
		base->str = str;
	}
	else if (key < base->key)
		base->l = Insert(key, str, base->l);
	else
		base->r = Insert(key, str, base->r);
	return(base);
}
rbtree* amap::Erase(int key, rbtree* base)
{
	if (base == NULL)
		return base;
	if (key == base->key) {
		rbtree* tmp;
		if (base->r == NULL)
			tmp = base->l;
		else {
			rbtree* tmp1 = base->r;
			if (tmp1->l == NULL) {
				tmp1->l= base->l;
				tmp = tmp1;
			}
			else {
				rbtree* mtmp = tmp1->l;
				while (mtmp->l!= NULL) {
					tmp1 = mtmp;
					mtmp = tmp1->l;
				}
				tmp1->l = mtmp->r;
				mtmp->l= base->l;
				mtmp->r= base->r;
				tmp = mtmp;
			}
		}
		delete base;
		return tmp;
	}
	else if (key < base->key)
		base->l= Erase(key, base->l);
	else
		base->r = Erase(key, base->r);
	return base;
}