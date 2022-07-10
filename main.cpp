#include <iostream>

template <typename T>
class Node final
{
public:
	T data{};
	Node* next = nullptr;
	Node* prev = nullptr;
};

template <typename T>
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
		void setPtr(Node<T>* setPtr)
		{
			this->ptr = setPtr;
		}
	private:
		Node<T>* ptr = nullptr;
	};

	iterator begin()
	{
		iterator it;
		it.setPtr(begin_);
		return it;
	}

	void operator<<(const T& data)
	{
		pushBack(data);
	}

	void pushBack(const T& data)
	{
		size++;
		auto newNode = new Node<T>;
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


	void pushFront(const T& data)
	{
		size++;
		auto newNode = new Node<T>;
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
		Node<T>* temp = begin_;

		for (std::size_t i = 1; i <= index; ++i)//дофіга тактів
			temp = temp->next;

		return temp->data;
	}

	std::size_t getSize()
	{
		return size;
	}
private:
	Node<T>* begin_ = nullptr;
	Node<T>* end_ = nullptr;
	std::size_t size = 0;
};

int main()
{
	List<int> list;

	list.pushFront( 5 );
	list.pushFront( 7 );

	list.pushBack( 9 );

	list << 18;

	std::cout << list[0] << " " << list.at(3) << std::endl;

	for (std::size_t i = 0; i < list.getSize(); i++)
		std::cout << list.at(i) << " ";

	std::cout << std::endl;

	List<int>::iterator it = list.begin();
	it++;
	std::cout << *it << std::endl;

	return 0;
}