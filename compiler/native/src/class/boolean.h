#include "boolean_header.h"

namespace NJS::Class
{
	// Constructors
	Boolean::Boolean() { counter++; }
	Boolean::Boolean(bool val)
	{
		Boolean();
		value = val;
	}
	// Methods
	void Boolean::Delete() noexcept
	{
		if (--counter < 1)
		{
			delete this;
		}
	}
	// Native cast
	Boolean::operator bool() const noexcept { return value; }
	Boolean::operator double() const noexcept { return value; }
	Boolean::operator int() const noexcept { return value; }
	Boolean::operator long long() const noexcept { return value; }
	Boolean::operator std::string() const noexcept
	{
		return value ? "true" : "false";
	}
	// Main operators
	NJS::VAR &Boolean::operator[](NJS::VAR key)
	{
		for (auto & search : object)
		{
			if (key.get().s->value.compare(search.first) == 0)
			{
				return search.second;
			}
		}

		key.get().s->counter++;
		if(key.get().s->value.compare("toString") == 0  || key.get().s->value.compare("toLocaleString") == 0)
		{
			object.push_back(pair_t(key.get().s->value.c_str(), __NJS_Create_Var_Scoped_Anon( return __NJS_Object_Stringify(this);)));
		}
		else if(key.get().s->value.compare("valueOf") == 0)
		{
			object.push_back(pair_t(key.get().s->value.c_str(), __NJS_Create_Var_Scoped_Anon( return this; )));
		}
		else 
		{
			object.push_back(pair_t(key.get().s->value.c_str(), __NJS_VAR()));
		}

		return object[object.size() - 1].second;
	}
	template <class... Args>
	NJS::VAR Boolean::operator()(Args... args) const { throw InvalidTypeException(); }
	// Comparation operators
	Boolean Boolean::operator!() const { return !value; }
	bool Boolean::operator==(const Boolean &_v1) const { return value == _v1.value; }
	// === emulated with __NJS_EQUAL_VALUE_AND_TYPE
	// !== emulated with __NJS_NOT_EQUAL_VALUE_AND_TYPE
	bool Boolean::operator!=(const Boolean &_v1) const { return value != _v1.value; }
	bool Boolean::operator<(const Boolean &_v1) const { return value < _v1.value; }
	bool Boolean::operator<=(const Boolean &_v1) const { return value <= _v1.value; }
	bool Boolean::operator>(const Boolean &_v1) const { return value > _v1.value; }
	bool Boolean::operator>=(const Boolean &_v1) const { return value >= _v1.value; }
	// Numeric operators
	Boolean Boolean::operator+() const { throw InvalidTypeException(); }
	Boolean Boolean::operator-() const { throw InvalidTypeException(); }
	Boolean Boolean::operator++(const int _v1) { throw InvalidTypeException(); }
	Boolean Boolean::operator--(const int _v1) { throw InvalidTypeException(); }
	Boolean Boolean::operator+(const Boolean &_v1) const { throw InvalidTypeException(); }
	Boolean Boolean::operator+=(const Boolean &_v1) { throw InvalidTypeException(); }
	Boolean Boolean::operator-(const Boolean &_v1) const { throw InvalidTypeException(); }
	Boolean Boolean::operator-=(const Boolean &_v1) { throw InvalidTypeException(); }
	Boolean Boolean::operator*(const Boolean &_v1) const { throw InvalidTypeException(); }
	Boolean Boolean::operator*=(const Boolean &_v1) { throw InvalidTypeException(); }
	// TODO: "**" and "**=" operators
	Boolean Boolean::operator/(const Boolean &_v1) const { throw InvalidTypeException(); }
	Boolean Boolean::operator/=(const Boolean &_v1) { throw InvalidTypeException(); }
	Boolean Boolean::operator%(const Boolean &_v1) const { throw InvalidTypeException(); }
	Boolean Boolean::operator%=(const Boolean &_v1) { throw InvalidTypeException(); }
	Boolean Boolean::operator&(const Boolean &_v1) const { throw InvalidTypeException(); }
	Boolean Boolean::operator|(const Boolean &_v1) const { throw InvalidTypeException(); }
	Boolean Boolean::operator^(const Boolean &_v1) const { throw InvalidTypeException(); }
	Boolean Boolean::operator~() const { throw InvalidTypeException(); }
	Boolean Boolean::operator>>(const Boolean &_v1) const { throw InvalidTypeException(); }
	Boolean Boolean::operator<<(const Boolean &_v1) const { throw InvalidTypeException(); }
	Boolean Boolean::operator&=(const Boolean &_v1) { throw InvalidTypeException(); }
	Boolean Boolean::operator|=(const Boolean &_v1) { throw InvalidTypeException(); }
	Boolean Boolean::operator^=(const Boolean &_v1) { throw InvalidTypeException(); }
	Boolean Boolean::operator>>=(const Boolean &_v1) { throw InvalidTypeException(); }
	Boolean Boolean::operator<<=(const Boolean &_v1) { throw InvalidTypeException(); }
	// TODO: ">>>" and ">>>=" operators
} // namespace NJS::Class
