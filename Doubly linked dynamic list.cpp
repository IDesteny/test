/*
 * Громов Илья Сергеевич 20ВП1
*/

#include <iostream>
using namespace std;


template <typename T = int>
class List
{
private:
	//List item
	struct Node
	{
		T data;

		Node *next; //Pointer to next item
		Node *prev; //Pointer to previous item
	};

	Node *head; //Pointer to the beginning of the list
	Node *tail; //Pointer to the end of the list

public:

	///<summary>
	///	Delegating constructor initializing variables
	///</summary>
	inline explicit __fastcall List() noexcept;


	///<summary>
	///	Copy constructor
	///</summary>
	///
	///<list name = "other">
	///	Copy List
	///</list>
	inline explicit __fastcall List(const List &other) noexcept;


	///<summary>
	///	Move constructor
	///</summary>
	///
	///<list name = "other">
	///	Move List
	///</list>
	inline explicit __fastcall List(List &&other) noexcept;


	///<summary>
	///	Destructor
	///</summary>
	inline ~List() noexcept;


	///<summary>
	///	Adds an item to the end of the list
	///</summary>
	///
	///<param name = "item">
	///	The value of the element to append
	///</param>
	void __fastcall push_back(const T &item);


	///<summary>
	///	Moves the item to the end of the list
	///</summary>
	///
	///<param name = "item">
	///	The value of the element being moved
	///</param>
	void __fastcall push_back(T &&item);


	///<summary>
	///	Inserts items at the specified location in the container
	///</summary>
	///
	///<param name = "item">
	///	The value of the element to append
	///</param>
	///
	///<param name = "index">
	///	Element number after which the new one is inserted
	///</param>
	void __fastcall insert(const T &item, const uint64_t &index = 0);


	///<summary>
	///	Moves items to a specified location in the container
	///</summary>
	///
	///<param name = "item">
	///	The value of the element being moved
	///</param>
	///
	///<param name = "index">
	///	Element number after which the new one is inserted
	///</param>
	void __fastcall insert(T &&item, const uint64_t &index = 0);


	///<summary>
	///	Removes the last element
	///</summary>
	void pop_back();


	///<summary>
	///	Displaying list items
	///</summary>
	///
	///<param name = "reverse">
	///	true: Display items in reverse order
	///</param>
	inline void __fastcall output(const bool reverse = 0) const;
};



template <class T>
__fastcall List<T>::List() noexcept : head(nullptr), tail(nullptr) {}


template <class T>
__fastcall List<T>::List(const List &other) noexcept : List() //variable init
{
	for (auto iter(other.head); iter != nullptr; iter = iter->next)
	{
		push_back(iter->data);
	}
}


template <class T>
__fastcall List<T>::List(List &&other) noexcept : List() //variable init
{
	for (auto iter(other.head); iter != nullptr; iter = iter->next)
	{
		push_back(move(iter->data)); //converting to lvalue
	}
}


template <class T>
List<T>::~List() noexcept
{
	while (head)
	{
		pop_back();
	}
}


template <class T>
void __fastcall List<T>::push_back(const T &val)
{
	//create new item
	Node *newNode(new Node);

	//init item
	newNode->data = val;
	newNode->next = nullptr;
	newNode->prev = tail;

	//set points
	if (tail) tail->next = newNode;
	if (!head) head = newNode;
	tail = newNode;
}


template <class T>
void __fastcall List<T>::push_back(T &&val)
{
	//create new item
	Node *newNode(new Node);

	//init item
	newNode->data = move(val);
	newNode->next = nullptr;
	newNode->prev = tail;

	//set points
	if (tail) tail->next = newNode;
	if (!head) head = newNode;
	tail = newNode;
}


template <class T>
void __fastcall List<T>::insert(const T &val, const uint64_t &index)
{
	//getting an item by number "index"
	auto iter(head);

	for (uint64_t i {}; i < index; ++i, iter = iter->next)
	{
		if (iter == nullptr)
		{
			cout << "!Error: Overstepping the list!" << endl;
			return;
		}
	}

	//create new item
	Node *newNode(new Node);

	//item init
	newNode->data = val;
	newNode->next = iter ? iter->next : nullptr;
	newNode->prev = iter;

	//set points
	if (iter)
	{
		if (iter->next) iter->next->prev = newNode;

		iter->next = newNode;
	}
	if (!head) head = newNode;
	if (iter == tail) tail = newNode;
}


template <class T>
void __fastcall List<T>::insert(T &&val, const uint64_t &index)
{
	//getting an item by number "index"
	auto iter(head);

	for (uint64_t i {}; i < index; ++i, iter = iter->next)
	{
		if (iter == nullptr)
		{
			cout << "!Error: Overstepping the list!" << endl;
			return;
		}
	}

	//create new item
	Node *newNode(new Node);

	//item init
	newNode->data = move(val);
	newNode->next = iter ? iter->next : nullptr;
	newNode->prev = iter;

	//set points
	if (iter)
	{
		if (iter->next) iter->next->prev = newNode;

		iter->next = newNode;
	}
	if (!head) head = newNode;
	if (iter == tail) tail = newNode;
}


template <class T>
void List<T>::pop_back()
{
	//checking if the list is empty
	if (!tail) return;

	if (head == tail)
	{
		delete tail;
		tail = head = nullptr;
	} else
	{
		tail = tail->prev;

		delete tail->next;
		tail->next = nullptr;
	}
}


template <class T>
void __fastcall List<T>::output(const bool reverse) const
{
	for (auto iter(reverse ? tail : head); iter; iter = reverse ? iter->prev : iter->next)
	{
		cout << iter->data << endl;
	}
}



int main(void)
{
	List<int> list;

	list.push_back(2);
	list.push_back(4);

	list.insert(3);

	list.output();
	cout << endl;

	list.pop_back();

	//reverse output list
	list.output(true);

	return EXIT_SUCCESS;
}