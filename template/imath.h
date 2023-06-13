#include<bits/stdc++.h>

#ifndef IMATH
#define IMATH


using std::pair;
using std::make_pair;
using std::vector;
using std::__gcd;
using std::istream;
using std::ostream;



//commonly used
template<class T>
T __lcm(T a,T b){return a*b/__gcd(a,b);}

struct frac {
    int __num;
    int __denom;
    int& fz=__num;
    int& fm=__denom;

    frac(int num = 0, int denom = 1) : fz(num), fm(denom) {}
    frac(const frac& var) : fz(var.fz), fm(var.fm) {}

    template<typename T1, typename T2>
    frac(T1&& num, T2&& denom) : fz(std::forward<T1>(num)), fm(std::forward<T2>(denom)) {}
    template<typename T>
    frac(T&& var) : fz(std::forward<T>(var).fz), fm(std::forward<T>(var).fm) {}

    auto& operator=(const frac& var) { fz = var.fz; fm = var.fm; return *this; }
    operator double() { return fz * 1.0 / fm; }

    void __simplify() { int gcd = __gcd(fz, fm); fz /= gcd; fm /= gcd; }

    #define rate __lcm(var1.fm, var2.fm)
    template<typename T1, typename T2>
    friend auto operator+(T1&& var1, T2&& var2) -> frac& { return (std::forward<T1>(var1) += std::forward<T2>(var2)); }
    template<typename T1, typename T2>
    friend auto operator-(T1&& var1, T2&& var2) -> frac& { return (std::forward<T1>(var1) -= std::forward<T2>(var2)); }
    template<typename T1, typename T2>
    friend auto operator*(T1&& var1, T2&& var2) -> frac& { return (std::forward<T1>(var1) *= std::forward<T2>(var2)); }
    template<typename T1, typename T2>
    friend auto operator/(T1&& var1, T2&& var2) -> frac& { return (std::forward<T1>(var1) /= std::forward<T2>(var2)); }
    #undef rate

    #define rate __lcm(fm, var.fm)
    template<typename T>
    auto& operator+=(T&& var) { fz = fz * rate / fm + std::forward<T>(var).fz * rate / std::forward<T>(var).fm; fm = rate; __simplify(); return *this; }
    template<typename T>
    auto& operator-=(T&& var) { fz = fz * rate / fm - std::forward<T>(var).fz * rate / std::forward<T>(var).fm; fm = rate; __simplify(); return *this; }
    template<typename T>
    auto& operator*=(T&& var) { fz *= std::forward<T>(var).fz; fm *= std::forward<T>(var).fm; __simplify(); return *this; }
    template<typename T>
    auto& operator/=(T&& var) { fz *= std::forward<T>(var).fm; fm *= std::forward<T>(var).fz; __simplify(); return *this; }
    #undef rate

    friend istream& operator>>(istream& in, frac& var) { in >> var.__num >> var.__denom; return in; }
    friend ostream& operator<<(ostream& out, const frac& var) { out << var.__num; if (var.__denom != 1) out << '/' << var.__denom; return out; }

};


class MyException:public std::exception{
public:
    MyException(const char* msg) : m_msg(msg) {}
    virtual const char* what() const noexcept override {
        return m_msg.c_str();
    }
private:
    std::string m_msg;
};

namespace LinearAlegebra{

template<typename T>
class Vector {
private:
    vector<T> __data;
    int __n;
public:
    int size(){return __n;}
    auto Get() const { return make_pair(__n, __data); }
    Vector() : __n(0) {}
    Vector(int n, T *const src) : __n(n), __data(__n) {FOR(i, 0, n - 1) __data[i] = src[i];}
    Vector(const Vector& var) : __n(var.Get().first), __data(var.Get().second) {}

    auto& operator[](int index) { return __data[index]; }

    template<typename U,typename... Args>
    void Resize(U size_s, Args&&... args) {__data.resize(size_s, std::forward<Args>(args)...);}

    template<typename U>
    friend auto operator+(U&& var1, U&& var2) {
        assert(var1.size() == var2.size());
        using P = std::decay_t<decltype(var1[0] + var2[0])>;
        Vector<P> ret(std::max(var1.size(), var2.size()));
        for (size_t i = 0; i < ret.size(); i++) {
            P val = (i < var1.size() ? std::forward<U>(var1)[i] : 0)
                + (i < var2.size() ? std::forward<U>(var2)[i] : 0);
            ret[i] = val;
        }
        return ret;
    }

    template<typename U>
    friend auto operator-(U&& var1, U&& var2) {
        assert(var1.size() == var2.size());
        using P = std::decay_t<decltype(var1[0] - var2[0])>;
        Vector<P> ret(std::max(var1.size(), var2.size()));
        for (size_t i = 0; i < ret.size(); i++) {
            P val = (i < var1.size() ? std::forward<U>(var1)[i] : 0)
                - (i < var2.size() ? std::forward<U>(var2)[i] : 0);
            ret[i] = val;
        }
        return ret;
    }

    template<typename U>
    friend auto operator*(U&& var1, U&& var2) {
        assert(var1.size() == var2.size());
        using P = std::decay_t<decltype(var1[0] * var2[0])>;
        P sum = 0;
        for (size_t i = 0; i < var1.size(); i++) {
            sum += var1[i] * var2[i];
        }
        return sum;
    }

    template<typename U>
    friend auto operator^(U&& var1, U&& var2) {
        assert(var1.size() == var2.size());
        using P = std::decay_t<decltype(var1[0] * var2[0])>;
        P sum = 0;
        for (size_t i = 0; i < var1.size(); i++) {
            sum += var1[i] * var2[i];
        }
        return sum;
    }

    template<typename U>
    friend auto operator*(const U& factor, const Vector<U>& var) {
        Vector<typename std::common_type<U, typename Vector<U>::value_type>::type> ret(var.__n);
        for (size_t i = 0; i < var.__n; i++) {
            ret[i] = factor * var[i];
        }
        return ret;
    }

    template<typename U>
    friend auto operator*(const Vector<U>& var, const U& factor) {
        return factor * var;
    }
};

};

#endif 