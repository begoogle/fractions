#include <iostream>

class fractions {
private:
	int numerator = 1;
	int denominator = 1;
	int number = 0;

	int rouding(fractions& temp) {
		int num = temp.get_number();
		if (temp.get_numerator() < temp.get_denominator()) { return 0; }
		else if (temp.get_numerator() == 0) { temp.set_number(num++); temp.set_denominator(0); return 0; }
		else {
			temp.set_numerator(temp.get_numerator() - temp.get_denominator());
			temp.set_number(++num);
			return rouding(temp);
		}
	}

	void reduction(fractions& temp) {
		while (true)
		{
			if (temp.get_numerator() % 2 == 0 && temp.get_denominator() % 2 == 0) {
				temp.set_numerator(temp.get_numerator() / 2);
				temp.set_denominator(temp.get_denominator() / 2);
				continue;
			}
			else if (temp.get_numerator() % 3 == 0 && temp.get_denominator() % 3 == 0)
			{
				temp.set_numerator(temp.get_numerator() / 3);
				temp.set_denominator(temp.get_denominator() / 3);
				continue;
			}
			else
			{
				break;
			}
		}
	}
public:
	fractions() {}
	fractions(int numerator, int denominator) : numerator(numerator), denominator(denominator) {}
	fractions(int number, int numerator, int denominator) : number(number), numerator(numerator), denominator(denominator) {}

	void set_number(int number) { this->number = number; }
	void set_numerator(int numerator) { this->numerator = numerator; }
	void set_denominator(int denominator) { this->denominator = denominator; }

	int get_number() { return number; }
	int get_numerator() { return numerator; }
	int get_denominator() { return denominator; }

	void prtint_fractions() {
		if (this->number != 0) { std::cout << this->number << " "; }
		if (this->numerator != 0 && this->denominator != 0) { std::cout << this->numerator << "\\" << this->denominator; }

		//std::cout << this->number << " " << this->numerator << "\\" << this->denominator;
	}

	fractions summa(fractions temp) {
		fractions result;

		if (temp.get_denominator() == this->denominator)
		{
			result.set_number(this->number + temp.get_number());
			result.set_numerator(temp.get_numerator() + this->numerator);
			result.set_denominator(temp.get_denominator());
		}
		else
		{
			result.set_number(this->number + temp.get_number());
			result.set_numerator(this->numerator * temp.get_denominator() + temp.get_numerator() * this->denominator);
			result.set_denominator(this->denominator * temp.get_denominator());
		}

		reduction(result);

		if (result.get_numerator() >= result.get_denominator()) { rouding(result); }

		//result.prtint_fractions();

		return result;
	}
};


int main() {
	fractions one(2, 2, 4), two(1, 2, 4), result(one.summa(two));

	one.prtint_fractions();
	std::cout << " + ";
	two.prtint_fractions();
	std::cout << " = ";
	result.prtint_fractions();



	return 0;
}