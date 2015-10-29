#include <iostream>

using namespace std;

template <class T>
class MyVector {
	public:
      MyVector();
	   MyVector(int num);
	   MyVector(const MyVector<T>& vec);
		~MyVector();
		MyVector<T>& operator= (const MyVector<T>& myvec);
		T& operator[] (int n);
		void add(const T& item);
		void clear();
		int length() const;
		int memSize() const;
		bool isEmpty() const;

	private:
		int capacity;
	   int size;
	   T *itemPtr;
};

template <class T>
MyVector<T>::MyVector(){
	capacity = 0;
	size = 0;
	itemPtr = NULL;
}

template <class T>
MyVector<T>::MyVector(int num){
	size = num;
	itemPtr = new T[num];
}

template <class T>
MyVector<T>::MyVector(const MyVector<T>& vec){
	capacity = vec.capacity;
	size = vec.size;
	itemPtr = vec.itemPtr;
}

template <class T>
MyVector<T>::~MyVector(){
}

template <class T>
MyVector<T>& MyVector<T>::operator= (const MyVector<T>& myvec){
   if(this != &myvec){
      if(itemPtr == NULL){
	      itemPtr = new T[myvec.capacity];
      }
      capacity = myvec.capacity;
      size = myvec.size;
	   itemPtr = myvec.itemPtr;
	}
	return *this;
}

template <class T>
T& MyVector<T>::operator[] (int n){
	return itemPtr[n];
}

template <class T>
void MyVector<T>::add(const T& item){
	if(capacity == size){
		capacity = capacity + 10;
		T *temp = new T[capacity];
	   for(int i =0;i<size;i++){
		   temp[i] = itemPtr[i];
	   }
	   temp[size]=item;
	   size++;
	   delete []itemPtr;
	   itemPtr = new T[capacity];
	   for(int i=0;i<size;i++){
		   itemPtr[i] = temp[i];
	   }
		delete [] temp;
	}else{
		   itemPtr[size] = item;
		   size++;
	}
}

template <class T>
void MyVector<T>:: clear(){
	size = 0;
	delete itemPtr;
	itemPtr = new T[capacity];
}

template <class T>
int MyVector<T>::length() const{
	return size;
}

template <class T>
int MyVector<T>::memSize() const{
	return capacity;
}

template <class T>
bool MyVector<T>::isEmpty() const{
	if(size == 0){
		return true;
	}else{
		return false;
	}
}

template <class T>
void printMyVector( MyVector<T> v ){
   for(int j=0;j<v.length();j++){
      cout << v[j] << " ";
   }
   cout << endl;
}

int main() {
   displayInfo();
   MyVector<int> v;
   cout << "Create MyVector" << endl;
   cout << "length: " << v.length() << " memSize: " << v.memSize() << endl;
   cout << endl;
   cout << "Add 2 items" << endl;
   v.add(10);
   v.add(11);
   // display items in v
	for (int i=0; i<v.length(); i++) {
		cout<<v[i] << " ";
   }
   cout << endl;
   cout << "length: " << v.length() << " memSize: " << v.memSize() << endl;
   cout << endl;
   // clear v
   v.clear();
   cout << "Clear" << endl;
   cout << "length: " << v.length() << " memSize: " << v.memSize() << endl;
   cout << endl;
   cout << "Add 15 items" << endl;
   for (int i=0; i<15; i++) {
		v.add(20+i);
   }
   printMyVector(v);
   cout << "length: " << v.length() << " memSize: " << v.memSize() << endl;
   cout << endl;
   cout << "Perform assignment" << endl;
   MyVector<int> v2;
   v2 = v;
   cout << "v2:" << endl;
   printMyVector(v2);
	return 0;
}
