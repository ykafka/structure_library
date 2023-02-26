//creates a class called ratio (basically a fraction) with buil tin adding, printing, and simplifying (reduce function)

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int gcd(int x, int y) {
  int d = 1;
  for (int i = 2; i <= min(x,y); i++) {
    if (x % i == 0 && y % i == 0) {
      d = i;
    }
  }
  return d;
}

class Ratio {
  public:
    int num, den;

    Ratio(): num(0), den(1) {}

    Ratio(int num, int den): num(num), den(den) {}

    Ratio add(const Ratio &other) {
      Ratio c(num * other.den + other.num * den, den * other.den);
      c.reduce();
      return c;
    }

    void reduce() {
      int common = gcd(num, den);
      num /= common;
      den /= common;
    }

    void print() {
      cout << num << "/" << den;
    }
};

int main(void) {
  int n;
  cin >> n;
  Ratio sum;
  for (int i = 0; i < n; i++) {
    Ratio temp;
    cin >> temp.num >> temp.den;
    sum = sum.add(temp);
  }
  sum.print();
}







