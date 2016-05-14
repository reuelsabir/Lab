# include <iostream>

using namespace std;

class account{
	public:
		int count;
		char string[20];
		int detail[20];
		int amount;
		account();
		void statement();
		void transfer(account&, int trans);
	
};

account::account()
{
	count = 0;
	amount = 10000;
	string[count] = 'A';
	detail[count] = amount;
	count++;
}

void account::transfer(account &m, int trans)
{
	m.amount = m.amount + trans;
	amount = amount - trans;
	string[count] = 'D';
	detail[count] = trans;
	m.string[count] = 'A';
	m.detail[count] = trans;
	count++;
	m.count++;
	
}

void account::statement()
{
	for (int i=0; i< count; i++)
	{
		cout << string[i] << detail[i];
		cout << "\n"; 
	}
	cout << "total amount = " << amount;
}


class ATM{
	public:
		void withdraw (account&, int);
		void paybill (account&, int);
		
};

void ATM::withdraw(account &m, int ded)
{
	m.amount = m.amount - ded;
	m.string[m.count] = 'D';
	m.detail[m.count] = ded;
	m.count++;
	cout << "Please collect you cash of rupees " << ded;
}

void ATM::paybill(account &m, int ded)
{
	m.amount = m.amount - ded;
	m.string[m.count] = 'B';
	m.detail[m.count] = ded;
	m.count++;
	cout << "You have paid your bill ";
}

int main (void)
{
	class account a;
	class account a2;
	class ATM b;
	a.statement();
	cout << "\n\n\n";
	a.transfer(a2,1500);
	a.statement();
	b.withdraw(a, 2000);
	cout << "\n\n\n";
	a.statement();
	cout << "\n\n\n";
	a2.statement();
	
}



