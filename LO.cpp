#include <iostream>
#include <string>
using namespace std;

template<typename T>
class List
{
public:
    List();
    ~List();

    void push_back(T data);
    void push_front(T data);
    void pop_front();
    void pop_back();
    void insert(T value, int index);
    void remove_add(int index);
    void clear();
    int GetSize() { return Size; };


    T& operator[](const int index);

private:

    template<typename T>
    class Node
    {
    public:
        Node* pNext;
        T data;

        Node(T data = T(), Node* pNext = nullptr)
        {
            this->data = data;
            this->pNext = pNext;

        }
    };

    int Size;
    Node<T>* head;

};


template<typename T>
List<T>::List()
{
   Size = 0;
   head = nullptr;
}


template<typename T>
List<T>::~List()
{
    clear();
}

template<typename T>
void List<T>::push_back(T data)
{
    if ( head == nullptr)
    {
        head = new Node<T>(data);
    }
    else
    {
        Node<T>* current = this->head;

        while (current->pNext != nullptr )
        {
            current = current->pNext;
        }
        current->pNext = new Node<T>(data);
    }
    Size++;
}

template<typename T>
void List<T>::push_front(T data)
{
    head = new Node<T>(data, head);
    Size++;
}

template<typename T>
void List<T>::pop_front()
{
    Node<T>* temp = head;
    head = head->pNext;
    delete temp;
    Size--;

}

template<typename T>
void List<T>::pop_back()
{
    remove_add(Size - 1);
}

template<typename T>
void List<T>::insert(T value, int index)
{
    if (index == 0)
    {
        push_front(value);
    }
    else 
    {
        if (index >= Size)
        {
            push_back(value);
        }
        else 
        {
            Node<T>* previous = this->head;
            for (int i = 0; i < index - 1; i++)
            {
                previous = previous->pNext;
            }
 
            previous->pNext = new Node<T>(value, previous->pNext);
            Size++;
        }

    }


}

template<typename T>
void List<T>::remove_add(int index)
{
    if (index == 0)
    {
        pop_front();
    }
    else
    {
        Node<T>* previous = this->head;
        for (int i = 0; i < index - 1; i++)
        {
            previous = previous->pNext;
        }

        Node<T>* toDelete = previous->pNext;
        previous->pNext = toDelete->pNext;

        delete toDelete;
        Size--;
        
    }
}

template<typename T>
void List<T>::clear()
{
    while (Size)
    {
        pop_front();
    }
}

template<typename T>
T& List<T>::operator[](const int index)
{
    int counter = 0;

    Node<T>* current = this->head;


    while (current != nullptr)
    {
        if (counter == index)
        {
            return current->data;
        }
        current = current->pNext;
        counter++;
    }
    
}

int main()
{
    setlocale(LC_ALL, "ru");

    List<int> lst;

    int numbersCount;
    cin >> numbersCount;

    for (int i = 0; i < numbersCount; i++)
    {
        lst.push_back(rand() % 10);
        cout << lst[i] << " ";
    }

    cout << endl <<"Размер списка: " << lst.GetSize() << endl;

    lst.pop_back();

    for (int i = 0; i < lst.GetSize(); i++)
    {
        cout << lst[i] << " ";
    }

}

