#include "std_lib_facilities.h"

using namespace std;

template<typename T>//1
struct S
{
    S(T s):val(s){}
    T get();
    T get() const;//2.
    S& operator=(const T);

private://7.
    T val;

};
template<typename T>//5.
T S<T>::get()
{
    return val;
}
template<typename T>
T S<T>::get() const
{
    return val;
}

template<typename T>
S<T>& S<T>::operator=(const T s)
{
    val = s;
    return *this;
}

template<typename T>
ostream& operator<<(ostream& os, S<T>& t)
{
    return os << t.get();

}
template<typename T>
istream& operator>>(istream& os, S<T>& t)
{
    return os >> t;

}
template<typename T>
void read_val(T& v)//12.
{
    cin >> v ;
}
int main()
{

    S<int> si {12};//4.
    S<char> sc {'b'};
    S<double> sd {2.5};
    S<string> s {"string"};
    S<vector<int>> svi { vector<int>{1, 1, 2, 3, 5, 8}};
    cout << si.get() << endl;
    cout << sc.get() << endl;
    cout << sd.get() << endl;//4.
    for(int i = 0; i < svi.get().size(); ++i)
    {
        cout << svi.get()[i] << endl;
    }
    si=30;
    cout << si.get() << endl;

    read_val(si);//13.
    read_val(sc);
    read_val(sd);

};
//6. 8. 9.