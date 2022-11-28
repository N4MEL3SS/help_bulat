#include <iostream>
#include <cstdio>

using namespace std;

class Deque{
	int *A,l,r,size,maxsize;//l r указатели на ближайшие незанятые ячейки массива соответсвенно слева и справа 
	public:
	Deque(){
		A = new int[10];
		l = r = size = 0;
		maxsize = 10;
	}
	Deque(int k){
		maxsize = k;
		A = new int[k];
		l = r = size = 0;
	}
	Deque(const Deque&ob){
		l = ob.l;
		r = ob.r;
		size = ob.size;
		maxsize = ob.maxsize;
		A = new int[maxsize];
		for(int i = 0;i < maxsize;i++){
			A[i]=ob.A[i];
		}
	}
	~Deque(){
		delete []A;
	}
	int Pushleft(int x){
		if (size < maxsize){
			if(l == 0){
				A[0] = x;
				l = maxsize - 1;
				if(r%maxsize == 0){r++;}
				size++;
				return 0;
			}
			if(l!=0){
				A[l] = x;
				l--;
				size++;
				return 0;
				}
			}
			cout <<"Дек переполнен!\n"<<endl;
			return 1;
		}
	int Pushright(int x){
		if (size < maxsize){
			if(r == 0){
				A[0] = x;
				r++;
				if(l == 0){l = maxsize - 1;}
				size++;
				return 0;
			}
			if(r != 0){
				A[r] = x;
				r++;
				size++;
				return 0;
			}
		}
		cout <<"Дек переполнен!\n"<<endl;
		return 1;
	}
	int Popleft(int *x){
		if (size > 0){
			*x = A[(++l)%maxsize];
			size--;
			if(size == 0){l =  0;r = 0;}
			return 0;
		}
		cout <<"Дек пуст!\n"<<endl;
		return 1;
	}
	int Popright(int *x){
		if (size > 0){
			*x = A[abs((--r)%maxsize)];
			r = abs(r);
			size--;
			if(size == 0){l = 0;r = 0;}
			return 0;
		}
		cout <<"Дек пуст!\n"<<endl;
		return 1;
	}
	void show(){
		if((l%maxsize >= r%maxsize) & (size!=0)){
			for(int i = l%maxsize + 1;i < maxsize;i++){
				cout << A[i]<< " ";
			}
			for(int i = 0;i < r%maxsize;i++){
				cout << A[i]<< " ";
			}
		}
		if((l%maxsize < r%maxsize) & (size != 0)){
			for(int i = l%maxsize + 1;i < r%maxsize;i++){
				cout<< A[i]<<" ";
			}
		}
		if (size == maxsize){
			int l1 = l;
			int j = 0;
			for(int i = 0;i < maxsize;i++){
				if((l1+1)%maxsize != 0){
					cout << A[(++l1)%maxsize]<<" ";
				}
				else{ 
					cout << A[j++]<<" ";
				}
			}
		}
		for(int i = size;i < maxsize;i++){
				cout << "0 ";
			}
		cout<<"; size = "<<size;
		cout<<" \n"<<endl;
	}
	Deque &operator = (const Deque&ob){
		int *m;
		m = new int[ob.maxsize];
		size = ob.size;
		maxsize = ob.maxsize;
		r=ob.r;
		l=ob.l;
		for(int i = 0;i < maxsize;i++){
			m[i] = ob.A[i];
		}
		delete []A;
		A = m;
		return *this;
	}
	int Pust(){
		if (size == 0) return 0;
		return 1;
	}
	int Poln(){
		if (size == maxsize) return 0;
		return 1;
	}
	int s(){return size;}//Вспомогательный метод для оператора Дек + Дек
	int m(){return maxsize;}
	Deque operator+ (int n){
		Deque B(maxsize);
		int j = 0;
		for(int i = l+1;j < size;i++){
			B.Pushright(A[i%maxsize]+n);
			j++;
		}
		return B;
	}
	friend Deque operator+ (Deque A,Deque B);
};
 
Deque operator+ (Deque A, Deque B){
	Deque C(A.m()+B.m());
	int s = A.m() + B.m();
	int x,y;
	for(int i = 0;(i < s) & (A.s() > 0) & (B.s() > 0);i++){
		A.Popleft(&x);
		B.Popleft(&y);
		C.Pushright(x);
		C.Pushright(y);
	}
	if(A.s() == 0){
		for(int i = 0;B.s() > 0;i++){
			B.Popleft(&y);
			C.Pushright(y);
		}
	}
	if(B.s() == 0){
		for(int i = 0;A.s() > 0;i++){
			A.Popleft(&x);
			C.Pushright(x);
		}
	}
	return C;
}


int main(){
	Deque A(4);
	int x;
	cout << "Проверка методов, связанных с левым элементом"<< endl;
	for(int i = 1;i<5;i++){
		A.Pushleft(i);
		A.show();
	}
	for(int i = 1;i<5;i++){
		A.Popleft(&x);
		A.show();
	}
	cout << " "<< endl;
	cout << "==================================="<< endl;
	cout << " "<< endl;
	cout << "Проверка методов, связанных с правым элементом"<< endl;
	for(int i = 1;i<5;i++){
		A.Pushright(i);
		A.show();
	}
	for(int i = 1;i<5;i++){
		A.Popright(&x);
		A.show();
	}
	cout << " "<< endl;
	cout << "==================================="<< endl;
	cout << " "<< endl;
	cout << "Проверка оператора Дек + Число"<< endl;
	Deque B(10);
	for(int i = 0;i < 5;i ++){
		B.Pushleft(i);
		B.Pushright(i);
	}
	B.show();
	Deque C;
	C = B + 10;
	C.show();
	cout << " "<< endl;
	cout << "==================================="<< endl;
	cout << " "<< endl;
	cout << "Дек + Дек"<< endl;
	Deque D(6),E(3);
	for(int i = 1;i < 4;i++){
		D.Pushleft(i);
		D.Pushright(i);
		E.Pushleft(i);
	}
	D.show();
	E.show();
	Deque F = D + E;
	F.show();
	cout << " "<< endl;
	cout << "==================================="<< endl;
	cout << " "<< endl;
	cout << "Проверка конструктора с параметром"<< endl;
	for(int i = 0;i < 10000;i++){
		Deque TEST(i);
		for(int j = 0;j < i;j++){
			TEST.Pushleft(j);
		}
	}
	cout << "Если вы видите эту надпись, программа не вылетела, не случилось ошибки потери памяти, значит конструктор работает правильно"<< endl;
	cout << " "<< endl;
	cout << "==================================="<< endl;
	cout << "Проверка оператора присвоения"<< endl;
	Deque Test1(7),Test2;
	for(int i = 0;i < 7;i++){
		Test1.Pushleft(i);
	}
	Test2 = Test1;
	cout<<"Первый дек  ";
	Test1.show();
	cout << " "<< endl;
	cout<<"Второй дек  ";
	Test2.show();
	cout << " "<< endl;
	Test1 = Test1 + 10;
	cout<<"Меняем первый"<<endl;
	cout<<"Первый дек  ";
	Test1.show();
	cout << " "<< endl;
	cout<<"Второй дек  ";
	Test2.show();
	cout << " "<< endl;
	cout<<"После изменения первого второй не поменялся, значит операция присвоения успешно работает(В массивах элементов в первом и втором деке использу.тся разные области памяти)"<<endl;
	return 0;
}
