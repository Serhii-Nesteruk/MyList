#include <iostream>

class Node final
{
public:
	int data = 0;
	Node* next = nullptr;
	Node* prev = nullptr;
};

class List final
{
public:
	class iterator
	{
	public:
		void operator++(int)
		{
			ptr = ptr->next;
		}
		int operator*()
		{
			return ptr->data;
		}
		void setPtr(Node* setPtr)
		{
			this->ptr = setPtr;
		}
	private:
		Node* ptr = nullptr;
	};

	iterator begin()
	{
		iterator it;
		it.setPtr(begin_);
		return it;
	}

	void operator<<(int data)
	{
		pushBack(data);
	}

	void pushBack(int data)
	{
		size++;
		auto newNode = new Node;
		newNode->data = data;

		if (!begin_ && !end_)
			begin_ = end_ = newNode;
		else
		{
			end_->next = newNode;
			newNode->prev = end_;
			end_ = newNode;
		}
	}


	void pushFront( int data )
	{
		size++;
		auto newNode = new Node;
		newNode->data = data;

		if (!begin_ && !end_)
			begin_ = end_ = newNode;
		else
		{
			begin_->prev = newNode;
			newNode->next = begin_;
			begin_ = newNode;
		}

	}

	int operator[](std::size_t index) noexcept
	{
		return at(index);
	}

	int at(std::size_t index) noexcept
	{
		Node* temp = begin_;

		for (std::size_t i = 1; i <= index; ++i)
			temp = temp->next;

		return temp->data;
	}

	std::size_t getSize()
	{
		return size;
	}
private:
	Node* begin_ = nullptr;
	Node* end_ = nullptr;
	std::size_t size = 0;
};

int main()
{
	List list;

	list.pushFront( 5 );
	list.pushFront( 7 );

	list.pushBack( 9 );

	list << 18;

	std::cout << list[0] << " " << list.at(3) << std::endl;

	for (std::size_t i = 0; i < list.getSize(); i++)
		std::cout << list.at(i) << " ";

	std::cout << std::endl;

	List::iterator it = list.begin();
	it++;
	std::cout << *it << std::endl;

	return 0;
}