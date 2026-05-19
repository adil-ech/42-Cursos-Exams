#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <algorithm>

class bigint {
    private: 
        std::string value;
        std::string addValue(const std::string &num1, const std::string &num2) const {
            std::string result;
            int carry = 0;
            int i = num1.size() - 1;
            int j = num2.size() - 1;
            while (i >= 0 || j >= 0 || carry) {
                int sum = carry;
                if (i >= 0)
                    sum += num1[i--] - '0';
                if (j >= 0)
                    sum += num2[j--] - '0';
                result += (sum % 10) + '0';
                carry = sum / 10;
            }
            std::reverse(result.begin(), result.end());
            return result;
        }

        unsigned long long strtoULL(const std::string &str) const {
            char *end = NULL;
            unsigned long long res = std::strtoul(str.c_str(), &end, 0);
            if (*end != '\0' || str[0] == '0')
                throw std::invalid_argument("Invalid Number format");
            return res;
        }

        void removeLeadingZeros() {
            while (value.size() > 1 && value[0] == '0')
                value.erase(0, 1);
        }
    public :
        bigint() : value("0") {}
        bigint(unsigned long long num) {
            std::stringstream ss;
            ss << num;
            value = ss.str();
        }
        bigint(const std::string &str) : value(str) {
            removeLeadingZeros();
        }
        bigint(const bigint &obj) : value(obj.value) {}
        bigint &operator=(const bigint &obj) {
            if (this != &obj)
                this->value = obj.value;
            return *this;
        }
        bigint operator+(const bigint &obj) const {
            return bigint(addValue(value, obj.value));
        }
        bigint operator+(unsigned long long num) const {
            return *this + bigint(num);
        }

        bigint &operator+=(const bigint &obj){
            value = addValue(value, obj.value);
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

        bigint operator<<(const bigint &obj) const {
            return *this << strtoULL(obj.value);
        }
        bigint operator>>(const bigint &obj) const {
            return *this >> strtoULL(obj.value);
        }
        bigint &operator>>=(const bigint &obj){
            removeLeadingZeros();
            return *this >>= strtoULL(obj.value);
        }
        bigint &operator<<=(const bigint &obj){
            removeLeadingZeros();
            return *this <<= strtoULL(obj.value);
        }

        bool operator<(const bigint &obj) const {
            if (value.size() != obj.value.size())
                return value.size() < obj.value.size();
            return value < obj.value;
        }
        bool operator>(const bigint &obj) const {
            if (value.size() != obj.value.size())
                return value.size() > obj.value.size();
            return value > obj.value;
        }
        bool operator<=(const bigint &obj) const{
            return !(*this > obj);
        }
        bool operator>=(const bigint &obj) const{
            return !(*this < obj);
        }

        bool operator==(const bigint &obj) const {
            if (value == obj.value)
                return true;
            return false;
        }
        bool operator!=(const bigint &obj) const {
            if (value != obj.value)
                return true;
            return false;
        }
        friend std::ostream &operator<<(std::ostream &os, const bigint &obj) {
            os << obj.value;
            return os;
        }
};
