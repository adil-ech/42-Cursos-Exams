#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <stdexcept>

class bigint {
    private:
        std::string value;
        std::string addValue(const std::string &num1, const std::string &num2) const {
            char *end = NULL;
            long sum = std::strtol(num1.c_str(), &end, 0) + std::strtol(num2.c_str(), &end, 0);
            return std::to_string(sum);
        }

        unsigned long long strtoULL(const std::string &str) const {
            char *end = NULL;
            unsigned long long sum = std::strtoul(str.c_str(), &end, 0);
            if (*end != '\0' || str[0] == '-')
                throw std::invalid_argument("invalid number format");
            return sum;
        }

        void removeLeadingZeros() {
            while(value.size() > 1 && value[0] == '0')
                value.erase(0, 1);
        }
    public:
        bigint() : value("0") {};
        bigint(unsigned long long num) : value(std::to_string(num)){};
        bigint(const std::string &str) : value(str){
            removeLeadingZeros();
        };

        bigint(const bigint &oth) : value(oth.value) {}
        
        bigint &operator=(const bigint &oth) {
            if (this != &oth)
                this->value = oth.value;
            return *this;
        }
        bigint operator+(const bigint &oth) const {
            return bigint(addValue(oth.value, value));
        }
        bigint operator+(unsigned long long num) const {
            return *this + bigint(num);
        }
        bigint &operator+=(const bigint &oth) {
            value = addValue(oth.value, value);
            return *this;
        }
        bigint &operator+=(unsigned long long num) {
            return *this += bigint(num);
        }
        bigint &operator++(){
            *this += 1;
            return *this;
        }
        bigint operator++(int) {
            bigint temp(*this);
            ++(*this);
            return temp;
        }
        bigint operator<<(int shift) const {
            if (shift <= 0)
                return *this;
            return bigint(value + std::string(shift, '0'));
        }
        bigint operator>>(int shift) const {
            if (shift <= 0 || shift >= static_cast<int>(value.size()))
                return bigint(0);
            return bigint(value.substr(0, value.size() - shift));
        }
        bigint &operator<<=(int shift) {
            if (shift >= 0)
                value = value + std::string(shift, '0');
            removeLeadingZeros();
            return *this;
        }
        bigint &operator>>=(int shift) {
            if (shift <= 0 || shift >= static_cast<int>(value.size()))
                value = "0";
            else
                value = value.substr(0, value.size() - shift);
            removeLeadingZeros();
            return *this;
        }
        bigint operator<<(const bigint &shift) const {
            return (*this << strtoULL(shift.value));
        }
        bigint operator>>(const bigint &shift) const {
            return (*this >> strtoULL(shift.value));
        }
        bigint &operator<<=(const bigint &shift) {
            removeLeadingZeros();
            return (*this <<= strtoULL(shift.value));
        }
        bigint &operator>>=(const bigint &shift) {
            removeLeadingZeros();
            return (*this >>= strtoULL(shift.value));
        }
        bool operator<(const bigint &shift) const {
            if (value.size() != shift.value.size())
                return value.size() < shift.value.size();
            return value < shift.value;
        }
        bool operator>(const bigint &shift) const {
            if (value.size() != shift.value.size())
                return value.size() > shift.value.size();
            return value > shift.value;
        }
        bool operator<=(const bigint &shift) const {
            return !(*this > shift);
        }
        bool operator>=(const bigint &shift) const {
            return !(*this < shift);
        }
        bool operator!=(const bigint &shift) const {
            if (value != shift.value)
                return true;
            return false;
        }
        bool operator==(const bigint &shift) const {
            if (value == shift.value)
                return true;
            return false;
        }
        friend std::ostream &operator<<(std::ostream &os, const bigint &ot) {
            os << ot.value;
            return os;
        }
};