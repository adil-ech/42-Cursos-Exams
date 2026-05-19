#pragma once
#include <iostream>

class vect2 {
    private :
        int x, y;
    public :
        vect2() : x(0), y(y) {}
        vect2(const vect2 &oth): x(oth.x), y(oth.y) {}
        vect2(int x, int y) : x(x), y(y) {}
        vect2 &operator=(const vect2 &oth) {
            if (this != &oth) {
                x = oth.x;
                y = oth.y;
            }
            return *this;
        }
        int &operator[](int num) {
            return (num == 0 ? x : y);
        }
        int operator[](int num) const {
            return (num == 0 ? x : y);
        }
        vect2 operator++(int){
            vect2 tmp = *this;
            x++;
            y++;
            return tmp;
        }
        vect2 &operator++() {
            x++;
            y++;
            return *this;
        }
        vect2 operator--(int){
            vect2 tmp = *this;
            x--;
            y--;
            return tmp;
        }
        vect2 &operator--() {
            x--;
            y--;
            return *this;
        }
        vect2 &operator+=(const vect2 &oth) {
            x += oth.x;
            y += oth.y;
            return *this;
        }
        vect2 &operator-=(const vect2 &oth) {
            x -= oth.x;
            y -= oth.y;
            return *this;
        }
        vect2 operator+(const vect2 &oth) const {
            return vect2(x + oth.x, y + oth.y);
        }
        vect2 operator-(const vect2 &oth) {
            return vect2(x - oth.x, y - oth.y);
        }
        vect2 operator*(int num) const {
            return vect2(x * num, y * num);
        }
        friend vect2 operator*(int num, const vect2 &oth) {
            return vect2(oth.x * num, oth.y * num);
        }
        vect2 &operator*=(int num) {
            x *= num;
            y *= num;
            return *this;
        }
        vect2 operator-() {
            vect2(-x, -y);
        }
        bool operator==(const vect2 &oth) {
            return (x == oth.x && y == oth.y);
        }
        bool operator!=(const vect2 &oth) {
            return (x != oth.x && y != oth.y);
        }
        friend std::ostream &operator<<(std::ostream &os, const vect2 &vec) {
            os << "{" << vec[0] << ", " << vec[1] << "}";
            return os;
        }
}; 