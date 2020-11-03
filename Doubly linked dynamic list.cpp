/*
 * <Name> 20VP1
*/

#include <iostream>
using namespace std;


template <typename T = int>
class List
{
private:
	//List node
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
	inline explicit List() noexcept;


	///<summary>
	///	Copy constructor
	///</summary>
	///
	///<list name = "other">
	///	Copy List
	///</list>
	inline explicit List(const List &other) noexcept;


	///<summary>
	///	Move constructor
	///</summary>
	///
	///<list name = "other">
	///	Move List
	///</list>
	inline explicit List(List &&other) noexcept;


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
List<T>::List() noexcept : head(nullptr), tail(nullptr) {}


template <class T>
List<T>::List(const List &other) noexcept : List() //variable init
{
	for (register Node *iter(other.head); iter != nullptr; iter = iter->next)
	{
		push_back(iter->data);
	}
}


template <class T>
List<T>::List(List &&other) noexcept : List() //variable init
{
	for (register Node *iter(other.head); iter != nullptr; iter = iter->next)
	{
		push_back(move(iter->data)); //converting to r-value
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
void List<T>::push_back(register const T &val)
{
	//create new item
	register Node *newNode(new Node);

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
void List<T>::push_back(register T &&val)
{
	//create new item
	register Node *newNode(new Node);

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
void List<T>::insert(register const T &val, register const uint64_t &index)
{
	//getting an item by number "index"
	register Node *iter(head);

	for (register uint64_t i(0); i < index; ++i, iter = iter->next)
	{
		if (!iter)
		{
			cout << "!Error: Overstepping the list!" << endl;
			return;
		}
	}

	//create new node
	register Node *newNode(new Node);

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
void List<T>::insert(register T &&val, register const uint64_t &index)
{
	//getting an item by number "index"
	register Node *iter(head);

	for (register uint64_t i(0); i < index; ++i, iter = iter->next)
	{
		if (!iter)
		{
			cout << "!Error: Overstepping the list!" << endl;
			return;
		}
	}

	//create new node
	register Node *newNode(new Node);

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

	tail = head == tail ? tail : tail->prev;
	delete (head == tail ? tail : tail->next);

	if (head == tail) tail = head = nullptr;
	else tail->next = nullptr;
}


template <class T>
void List<T>::output(register const bool reverse) const
{
	for (register Node *iter(reverse ? tail : head); iter; iter = reverse ? iter->prev : iter->next)
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