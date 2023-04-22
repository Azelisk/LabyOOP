#include<iostream>
using namespace std;

class money
{
private:
	double sum;
	long rub;
	int kop;
	void split(double sum)
	{
		rub = (int)sum;
		kop = abs(((sum - (int)sum) * 100));
	}
	
public:
	money()
	{
		cout << "Konstr without par " << this << endl;
		this->sum = 0.0;
		this->rub = 0;
		this->kop = 0;
	};
	money(double sum)
	{
		cout << "\nKonstr with par " << this << endl;
		this->sum = sum;
		split(sum);
	}

	friend ostream& operator<<(ostream& stream, const money& m);

	money operator-(const double& sub)
	{
		return (this->sum - sub);
	}

	bool operator==(const money& other)
	{
		if (this->sum == other.sum)
			return true;
		else
			return false;
	}

	bool operator!=(const money& other)
	{
		return !(this->sum == other.sum);
	}

	void print()
	{
		cout << "\nAmount: " << rub << "," << kop << endl;
	}

	~money()
	{
		cout << "\nDestr " << this;
		cout << endl;
	}
};

ostream& operator<<(ostream& stream, const money& m)
{
	stream <<"\nRubles: " << m.rub << "\nKopecks: " << m.kop;
	return stream;
};

int main()
{
	system("chcp 1251 >> null");

	double sub,sum;
	money one;
	one.print();

	cout << "\n\nEnter the amount(double): ";
	cin >> sum;
	money two(sum);
	two.print();

	cout << "\nEnter the fractional number to be subtracted from the sum: ";
	cin >> sub;

	money tre = sum - sub;
	tre.print();

	bool res = two == tre;
	cout << "\nResult of comparing amounts ==(1 - equal; 0 - unequal): " << res << endl;

	bool res2 = two != tre;
	cout << "\nResult of comparing amounts !=(1 - equal; 0 - unequal): " << res2 << endl;

	cout << two;

	return 0;
}