#include <iostream>

class fractions {
private:
	int numerator = 1;
	int denominator = 1;
	int number = 0;

	int rouding(fractions& temp) {
		int num = temp.get_number();
		if (temp.get_numerator() < temp.get_denominator()) { 
			if (temp.get_numerator() < 0) {
				if (temp.get_numerator() * -1 < temp.get_denominator()) {
					return 0;
				}
				if (temp.get_denominator() < 0) {
					temp.set_denominator(temp.get_denominator() * -1);
				}
				temp.set_numerator(temp.get_numerator() + temp.get_denominator());
				temp.set_number(--num);
				return rouding(temp);
			}
			return 0; }
		else if (temp.get_numerator() == 0) { temp.set_number(++num); temp.set_denominator(0); return 0; }
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

	void transformation(fractions& temp) {
		if (temp.get_number() > 0) {
			temp.set_numerator(temp.get_denominator() * temp.get_number() + temp.get_numerator());
			temp.set_number(temp.get_number() * 0);
		}
		else if (temp.get_number() < 0) {

			temp.set_numerator(temp.get_denominator() * temp.get_number() - temp.get_numerator());
			temp.set_number(temp.get_number() * 0);
		}
	}
public:
	fractions() {}
	fractions(int numerator, int denominator) : numerator(numerator), denominator(denominator) {}
	fractions(int number, int numerator, int denominator) : number(number), numerator(numerator), denominator(denominator) {}
	fractions(const fractions& temp) {
		this->number = temp.number;
		this->numerator = temp.numerator;
		this->denominator = temp.denominator;
	}

	void set_number(int number) { this->number = number; }
	void set_numerator(int numerator) { this->numerator = numerator; }
	void set_denominator(int denominator) { this->denominator = denominator; }

	int get_number() { return number; }
	int get_numerator() { return numerator; }
	int get_denominator() { return denominator; }

	void prtint_fractions() {
		if (this->number != 0) { std::cout << this->number << " "; }
		if (this->numerator != 0 && this->denominator != 0) { std::cout << this->numerator << "\\" << this->denominator; }
	}

	fractions summa(fractions temp) {
		fractions result;

		transformation(*this);
		transformation(temp);

		if (temp.get_denominator() == this->denominator)
		{
			result.set_numerator(temp.get_numerator() + this->numerator);
			result.set_denominator(temp.get_denominator());
		}
		else
		{
			result.set_numerator(this->numerator * temp.get_denominator() + temp.get_numerator() * this->denominator);
			result.set_denominator(this->denominator * temp.get_denominator());
		}

		reduction(result);

		if (result.get_numerator() >= result.get_denominator() || result.get_numerator() < 0) { rouding(result); }

		return result;
	}

	fractions minus(fractions temp) {
		fractions result;

		transformation(*this);
		transformation(temp);

		if (temp.get_denominator() == this->denominator)
		{
			result.set_numerator(temp.get_numerator() - this->numerator);
			result.set_denominator(temp.get_denominator());
		}
		else
		{
			result.set_numerator(this->numerator * temp.get_denominator() - temp.get_numerator() * this->denominator);
			result.set_denominator(this->denominator * temp.get_denominator());
		}

		reduction(result);

		if (result.get_numerator() >= result.get_denominator() || result.get_numerator() < 0) { rouding(result); }

		return result;
	}

	fractions multiplication(fractions temp) {
		fractions result;

		transformation(*this);
		transformation(temp);

		result.set_numerator(temp.get_numerator() * this->numerator);
		result.set_denominator(temp.get_denominator() * this->denominator);

		reduction(result);

		if (result.get_numerator() >= result.get_denominator() || result.get_numerator() < 0) { rouding(result); }

		return result;
	}

	fractions division(fractions temp) {
		fractions result;

		transformation(*this);
		transformation(temp);

		result.set_numerator(this->numerator * temp.get_denominator());
		result.set_denominator(this->denominator * temp.get_numerator());

		reduction(result);

		if (result.get_numerator() >= result.get_denominator() || result.get_numerator() < 0) { rouding(result); }

		return result;
	}

	void operator = (fractions temp) {
		this->number = temp.number;
		this->numerator = temp.numerator;
		this->denominator = temp.denominator;
	}

	fractions operator + (fractions temp) {
		return this->summa(temp);
	}

	fractions operator - (fractions temp) {
		return this->minus(temp);
	}

	fractions operator * (fractions temp) {
		return this->multiplication(temp);
	}

	fractions operator / (fractions temp) {
		return this->division(temp);
	}

	bool operator == (fractions temp) {
		return this->number == temp.number && this->numerator == temp.numerator && this->denominator == temp.denominator;
	}

	bool operator != (fractions temp) {
		return this->number != temp.number || this->numerator != temp.numerator || this->denominator != temp.denominator;
	}

	bool operator > (fractions temp) {
		if (this->denominator == temp.denominator) {
			return this->number >= temp.number && this->numerator > temp.numerator;
		}
		else {
			fractions temp_fraction = *this;
			this->set_numerator(this->numerator * temp.denominator);
			this->set_denominator(this->denominator * temp.denominator);
			temp.set_numerator(temp.numerator * temp_fraction.denominator);
			temp.set_denominator(temp.denominator * temp_fraction.denominator);
			return this->number >= temp.number && this->numerator > temp.numerator;
		}
	}

	bool operator < (fractions temp) {
		if (this->denominator == temp.denominator) {
			return this->number <= temp.number && this->numerator < temp.numerator;
		}
		else {
			fractions temp_fraction = *this;
			this->set_numerator(this->numerator * temp.denominator);
			this->set_denominator(this->denominator * temp.denominator);
			temp.set_numerator(temp.numerator * temp_fraction.denominator);
			temp.set_denominator(temp.denominator * temp_fraction.denominator);
			return this->number <= temp.number && this->numerator < temp.numerator;
		}
	}

	bool operator >= (fractions temp) {
		if (this->denominator == temp.denominator) {
			return this->number >= temp.number && this->numerator >= temp.numerator;
		}
		else {
			fractions temp_fraction = *this;
			this->set_numerator(this->numerator * temp.denominator);
			this->set_denominator(this->denominator * temp.denominator);
			temp.set_numerator(temp.numerator * temp_fraction.denominator);
			temp.set_denominator(temp.denominator * temp_fraction.denominator);
			return this->number >= temp.number && this->numerator >= temp.numerator;
		}
	}

	bool operator <= (fractions temp) {
		if (this->denominator == temp.denominator) {
			return this->number <= temp.number && this->numerator <= temp.numerator;
		}
		else {
			fractions temp_fraction = *this;
			this->set_numerator(this->numerator * temp.denominator);
			this->set_denominator(this->denominator * temp.denominator);
			temp.set_numerator(temp.numerator * temp_fraction.denominator);
			temp.set_denominator(temp.denominator * temp_fraction.denominator);
			return this->number <= temp.number && this->numerator <= temp.numerator;
		}
	}
};


int main() {
	fractions one(1, 3), two(2, 4);

	return 0;
}