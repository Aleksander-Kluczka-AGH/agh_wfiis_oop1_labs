#pragma once

#include <iostream>

template <typename T>
class List;

template<typename T>
std::ostream &operator<<(std::ostream &stream, const List<T> &list);

template <typename T>
class Node;

/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////

template<class T, class EL = Node<T>>
class Iterator
{
	friend class List<T>;
public:
	Iterator()
	:
	object(nullptr),
	position(0u)
	{ }

	Iterator(EL *object)
	:
	object(object)
	{
		this->position = 0u;
		EL *ptr = this->object;
		while(ptr->prev)
		{
			ptr = ptr->prev;
			this->position++;
		}
	}

	T &operator*()
	{
		return this->object->data;
	}

	T *operator->()
	{
		return &(this->object->data);
	}

	const bool operator!=(const Iterator<T, EL> &second)
	{
		return this->position != second.position;
	}

	Iterator<T, EL> &operator++()
	{
		this->object = this->object->next;
		this->position++;
		return *this;
	}

	Iterator<T, EL> operator++(int)
	{
		Iterator<T, EL> temp(this->object);
		++(*this);
		return temp;
	}

protected:
	unsigned &operator()()
	{
		return this->position;
	}

private:
	EL *object;
	unsigned position;
};

/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////

template<class T, class EL = Node<T>>
class ReverseIterator
{
	friend class List<T>;
public:
	ReverseIterator()
	:
	object(nullptr),
	position(0u)
	{ }

	ReverseIterator(EL *object)
	:
	object(object)
	{
		this->position = 0u;
		EL *ptr = this->object;
		while(ptr->next)
		{
			ptr = ptr->next;
			this->position++;
		}
	}

	ReverseIterator<T, EL> &operator++()
	{
		this->object = this->object->prev;
		this->position++;
		return *this;
	}

	ReverseIterator<T, EL> operator++(int)
	{
		ReverseIterator<T, EL> temp(this->object);
		++(*this);
		return temp;
	}

	T &operator*()
	{
		return this->object->data;
	}

	T *operator->()
	{
		return &(this->object->data);
	}

	const bool operator!=(const ReverseIterator<T, EL> &second)
	{
		return this->position != second.position;
	}

protected:
	unsigned &operator()()
	{
		return this->position;
	}

private:
	EL *object;
	unsigned position;

};

/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
class Node
{
	friend class List<T>;
	friend class Iterator<T, Node<T>>;
	friend class ReverseIterator<T, Node<T>>;
	friend std::ostream &operator<< <>(std::ostream &stream, const List<T> &list);

public:
	Node() = default;
	explicit Node(T value)
	: 
	data(value), 
	next(nullptr), 
	prev(nullptr) 
	{ }

	virtual ~Node()
	{

	}

	T &getData()
	{
		return this->data;
	}

private:
	T data;
	Node<T> *next;
	Node<T> *prev;
};

/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////

template <typename T>
class List
{
public:
	List()
	:
	elements(nullptr),
	fr(nullptr),
	bk(nullptr)
	{ }

	explicit List(unsigned el_count, const T array[])
	:
	elements(nullptr),
	fr(nullptr),
	bk(nullptr)
	{
		for(unsigned i = 0; i < el_count; i++)
		{
			this->push_back(array[i]);
		}
	}

	virtual ~List()
	{
		while(this->elements)
		{
			this->pop_back();
		}
	}

	void operator=(List<T> &copy)
	{
		while(this->elements)
		{
			this->pop_back();
		}
		Node<T> *iter = copy.elements;
		while(iter->next)
		{
			this->push_back(iter->data);
			iter = iter->next;
		}
	}

	void push_back(T element)
	{
		if(this->elements == nullptr)//first element
		{
			this->elements = new Node<T>(element);
			this->fr = this->elements;
			this->bk = this->elements;
		}
		else//not first
		{
			Node<T> *iter = this->elements;
			while(iter->next != nullptr)
				iter = iter->next;
			iter->next = new Node<T>(element);
			iter->next->prev = iter;
			this->bk = iter->next;
		}
	}

	void pop_back()
	{
		if(this->elements)
		{
			if(this->elements->next)//more than one element
			{
				Node<T> *ptr = this->bk->prev;
				delete this->bk;
				this->bk = ptr;
				this->bk->next = nullptr;
			}
			else //first = last = only one
			{
				delete this->elements;
				this->bk = nullptr;
				this->fr = nullptr;
			}
		}
	}

	T &front()
	{
		return this->fr->data;
	}

	const T &front() const
	{
		return this->fr->data;
	}

	const Iterator<T> begin() const
	{
		return Iterator<T>(this->fr);
	}

	const Iterator<T> end() const
	{
		Node<T> temp;
		Iterator<T> it(&temp);
		Iterator<T> last(this->bk);
		it() = last() + 1;
		return it;
	}

	const ReverseIterator<T> rbegin() const
	{
		return ReverseIterator<T>(this->bk);
	}

	const ReverseIterator<T> rend() const
	{
		Node<T> temp;
		ReverseIterator<T> it(&temp);
		ReverseIterator<T> last(this->fr);
		it() = last() + 1;
		return it;
	}

	friend std::ostream &operator<< <>(std::ostream &stream, const List<T> &list);

private:
	Node<T> *elements;
	Node<T> *fr;
	Node<T> *bk;
};

/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////

template<typename T>
std::ostream &operator<<(std::ostream &stream, const List<T> &list)
{
	Node<T> *ptr = list.elements;
	if(!ptr)
	{
		return stream << "{ }";
	}
	stream << "{";
	while(ptr->next != nullptr)
	{
		stream << "\"" << ptr->data << "\", ";
		ptr = ptr->next;
	}

	stream << "\"" << ptr->data << "\"}";
	return stream;
}
