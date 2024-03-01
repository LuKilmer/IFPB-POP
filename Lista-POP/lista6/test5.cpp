#include <bits/stdc++.h>


class MyBigInt {
public:
    std::vector<int> digits;

    MyBigInt() {}

    MyBigInt(int num) {
        while (num > 0) {
            digits.push_back(num % 10);
            num /= 10;
        }
        if (digits.empty()) {
            digits.push_back(0);
        }
    }

    MyBigInt operator*(const MyBigInt& other) const {
        MyBigInt result;
        result.digits.resize(digits.size() + other.digits.size(), 0);

        for (size_t i = 0; i < digits.size(); ++i) {
            int carry = 0;
            for (size_t j = 0; j < other.digits.size() || carry; ++j) {
                long long current = result.digits[i + j] +
                                   (long long)digits[i] * (j < other.digits.size() ? other.digits[j] : 0) + carry;
                result.digits[i + j] = current % 10;
                carry = current / 10;
            }
        }

        while (result.digits.size() > 1 && result.digits.back() == 0) {
            result.digits.pop_back();
        }

        return result;
    }

    MyBigInt operator%(int m) const {
        MyBigInt result = *this;
        int carry = 0;

        for (int i = result.digits.size() - 1; i >= 0; --i) {
            long long current = result.digits[i] + carry * 10;
            result.digits[i] = current % m;
            carry = current / m;
        }

        while (result.digits.size() > 1 && result.digits.back() == 0) {
            result.digits.pop_back();
        }

        return result;
    }
};

typedef std::vector<MyBigInt> BigIntList;
typedef std::vector<BigIntList> Matrix;

MyBigInt m = 24 * 60 * 60;

Matrix matrixMult(const Matrix& a, const Matrix& b) {
    int rowsA = a.size();
    int colsA = a[0].size();
    int colsB = b[0].size();

    Matrix result(rowsA, BigIntList(colsB, MyBigInt(0)));

    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            for (int k = 0; k < colsA; ++k) {
                result[i][j] = (result[i][j] + a[i][k] * b[k][j]) % m;
            }
        }
    }

    return result;
}

Matrix matrixPow(const Matrix& a, const MyBigInt& n) {
    if (n == MyBigInt(1)) {
        return a;
    } else {
        Matrix b = matrixPow(a, n / 2);
        Matrix c = matrixMult(b, b);
        return (n % 2 == MyBigInt(0)) ? c : matrixMult(a, c);
    }
}

MyBigInt dabriel(const MyBigInt& n) {
    Matrix x0 = {{MyBigInt(1), MyBigInt(2)}};
    Matrix a = {{MyBigInt(1), MyBigInt(0)}, {MyBigInt(1), MyBigInt(2)}};
    Matrix xn = matrixMult(x0, matrixPow(a, n - MyBigInt(1)));

    return xn[0][0];
}

int main() {
    std::string n_str;
    std::cout << "Digite o valor de n: ";
    std::cin >> n_str;

    MyBigInt n(n_str);

    if (n == MyBigInt(1)) {
        std::cout << "00:00:01" << std::endl;
    } else {
        MyBigInt x = dabriel(n);
        std::cout << std::setfill('0') << std::setw(2) << x / 3600 << ":"
                  << std::setfill('0') << std::setw(2) << (x % 3600) / 60 << ":"
                  << std::setfill('0') << std::setw(2) << x % 60 << std::endl;
    }

    return 0;
}
