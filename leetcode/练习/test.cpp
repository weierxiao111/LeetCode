#if 0
#include <iostream>
using namespace std;

class Base {
public:
	virtual void a()
	{
		cout << "base::a" << endl;
	}
	void b(int i) {
		cout << "base::b(int)}" << i << endl;
	}
	void b(float i)
	{
		cout << "Base::b(float)" <<i<< endl;
	}
};
class Child:public Base
{
public:
	void a() {
		cout << "chlid ::a" << endl;
	}
	void b(int i) {
		cout << "chlid::b(int i)" << i << endl;
	}
};

int main()
{
	Child c;
	Base *pb = &c;
	Child *pc = &c;
	pb->a();
	pb->b(1);
	pb->b(3.14f);
	pc->b(1);
	pc->b(3.14f);
	return 0;
}
#endif
