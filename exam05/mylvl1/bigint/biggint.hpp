#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <algorithm>

class bigint {
    private :
        std::string value;
        std::string addValue(const std::string &num1, const std::string &num2) const {
            std::string result;
            int carry = 0;
            int i = num1.size() - 1;
            int j = num1.size() - 1;
            while (i >= 0 || j >= 0 || carry){
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
        unsigned long long strToUll(const std::string &str) const {
            char *end = NULL;
            unsigned long  long res = std::strtoul(str.c_str(), &end, 0);
            if (*end != '\0' || str[0] == '-')
                throw std::invalid_argument("invalid number format");
            return res;
        }
        
        void removeLeadingZeros() {
            while (value.size() > 1 && value[0] == '0')
                value.erase(0,1);
        }
    public :
        bigint() : value("0") {};
        bigint(unsigned long long num) {
            std::stringstream ss;
            ss << num;
            value = ss.str();
        }
        bigint(const std::string &str) : value(str) {
            removeLeadingZeros();
        }
};