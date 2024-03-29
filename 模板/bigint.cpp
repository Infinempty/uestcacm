#include <iostream>
#include <iomanip>
#include <vector>
#include <cassert>
#include <stack>
#include <map>
#include <cstring>
#include <string>
#include <sstream>
using namespace std;
typedef long long LL;
int MyAtoi(const char* s, const char* t) {
    int ans = 0;
    for (; s != t; ++s)
        (ans *= 10) += *s - '0';
    return ans;
}

template<typename T, typename MT>
MT Add(T x, MT p) {
    return x >= p ? x - p : x;
}

const LL tens[] = {1LL,10LL,100LL,1000LL,10000LL,100000LL,1000000LL,10000000LL,100000000LL,1000000000LL};
const int pow2[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728, 268435456, 536870912, 1073741824
};

struct UnsignedBigInt {
    static const int BASE = 1000000000;
    static const int WIDTH = 9;

    vector <int> s;

    UnsignedBigInt() {}
    __attribute__((optimize("O3"))) explicit UnsignedBigInt(int num) {
        assert(num >= 0);
        if (num)
            s.push_back(num);
    }
    explicit UnsignedBigInt(LL num) {
        assert(num >= 0);
        while (num) {
            s.push_back(num % BASE);
            num /= BASE;
        }
    }
    explicit UnsignedBigInt(const string& str) {
        *this = str;
    }
    explicit UnsignedBigInt(const char* str) {
        *this = str;
    }
    explicit UnsignedBigInt(const vector<int>& in): s(in) {
        clean();
    }
    UnsignedBigInt& clean() {
        while(!s.empty() && !s.back())
            s.pop_back();
        return *this;
    }

    explicit operator int() const {
        return s.empty() ? 0 : s[0];
    }
    explicit operator double() const {
        double ans = 1;
        double k = 1;
        for (size_t i = 0; i < s.size(); ++i, k *= BASE)
            ans *= k * s[i];
        return ans;
    }
    explicit operator string() const {
        ostringstream ans;
        if (s.empty()) {
            ans << '0';
        } else {
            ans << s.back();
            for(int i = (int)s.size()-2; i >= 0; --i)
                ans << setfill('0') << setw(WIDTH) << s[i];
        }
        return ans.str();
    }
    explicit operator bool() const {
        return !s.empty();
    }

    UnsignedBigInt& operator = (const int num) {
        return *this = UnsignedBigInt(num);
    }
    UnsignedBigInt& operator = (LL num) {
        return *this = UnsignedBigInt(num);
    }
    UnsignedBigInt& assign(const char* str, int ended) {
        s.clear();
        for (; ended > 0; ended -= WIDTH)
            s.push_back(MyAtoi(str + max(0, ended - WIDTH), str + ended));
        return clean();
    }
    UnsignedBigInt& operator = (const string& str) {
        return assign(str.c_str(), str.length());
    }
    UnsignedBigInt& operator = (const char* str) {
        return assign(str, strlen(str));
    }

    UnsignedBigInt& AddEq(const UnsignedBigInt& b, int as = 0, int bs = 0) {
        int rem = 0;
        if (s.size() < as)
            s.resize(as, 0);
        for (; bs < b.s.size() || rem; ++as, ++bs) {
            if (as == s.size())
                s.push_back(rem);
            else
                s[as] += rem;
            rem = 0;
            if (bs < b.s.size())
                s[as] += b.s[bs];
            if (s[as] >= BASE) {
                s[as] -= BASE;
                rem = 1;
            }
        }
        return *this;
    }
    UnsignedBigInt& operator += (const UnsignedBigInt& b) {
        return AddEq(b);
    }
    UnsignedBigInt operator + (const UnsignedBigInt& b) const {
        return UnsignedBigInt(*this) += b;
    }

    UnsignedBigInt& operator += (int b) {
        assert(0 <= b && b < BASE);
        for (size_t i = 0; b; ++i) {
            if (i == s.size())
                s.push_back(0);
            s[i] += b;
            if (s[i] > BASE) {
                b = 1;
                s[i] -= BASE;
            } else {
                b = 0;
            }
        }
        return *this;
    }
    UnsignedBigInt operator + (int b) const {
        return UnsignedBigInt(*this) += b;
    }

    UnsignedBigInt& operator *= (int num) {
        assert(0 <= num && num < BASE);
        if(num) {
            LL rem = 0;
            for (int& v : s) {
                rem += (LL)v * num;
                v = rem % BASE;
                rem /= BASE;
            }
            if(rem)
                s.push_back(rem);
        } else {
            s.clear();
        }
        return *this;
    }
    inline UnsignedBigInt operator * (int num) const {
        return UnsignedBigInt(*this) *= num;
    }
    friend UnsignedBigInt operator * (int a, const UnsignedBigInt& b);
    UnsignedBigInt operator * (const UnsignedBigInt& b) const {
        UnsignedBigInt ans; //0
        for (size_t j = 0; j < b.s.size(); ++j)
            ans.AddEq(*this * b.s[j], j);
        return ans;
    }
    UnsignedBigInt& operator *= (const UnsignedBigInt& b) {
        return *this = *this * b;
    }

    int cmp(const UnsignedBigInt& b) const {
        if (s.size() != b.s.size()) {
            return (int) s.size() - (int) b.s.size();
        } else if (s.size() == 0 && b.s.size() == 0) {
            return 0;
        } else {
            int i;
            for(i = (int)s.size()-1; i > 0 && s[i] == b.s[i]; --i);

            return s[i] - b.s[i];
        }
    }
    bool operator < (const UnsignedBigInt& b) const {
        return cmp(b) < 0;
    }
    bool operator > (const UnsignedBigInt& b)const {
        return cmp(b) > 0;
    }
    bool operator == (const UnsignedBigInt& b)const {
        return cmp(b) == 0;
    }
    bool operator != (const UnsignedBigInt& b) const {
        return cmp(b) != 0;
    }
    bool operator <= (const UnsignedBigInt& b)const {
        return cmp(b) <= 0;
    }
    bool operator >= (const UnsignedBigInt& b)const {
        return cmp(b) >= 0;
    }

    //0 <= b < BASE
    bool operator == (int b) const {
        return s.size() == 1 ? (s[0] == b) : (s.size() ? false : b == 0);
    }
    bool operator < (int b) const {
        return s.size() == 1 ? (s[0] < b) : (s.size() ? false : b != 0);
    }
    bool operator <= (int rhs) const {
        return *this < rhs || *this == rhs;
    }
    bool operator >= (int rhs) const {
        return !(*this < rhs);
    }
    bool operator > (int rhs) const {
        return !(*this <= rhs);
    }
    bool operator != (int rhs) const {
        return !(*this == rhs);
    }

    friend bool operator < (int lhs, const UnsignedBigInt& rhs);
    friend bool operator == (int lhs, const UnsignedBigInt& rhs);
    friend bool operator <= (int lhs, const UnsignedBigInt& rhs);
    friend bool operator > (int lhs, const UnsignedBigInt& rhs);
    friend bool operator >= (int lhs, const UnsignedBigInt& rhs);
    friend bool operator != (int lhs, const UnsignedBigInt& rhs);

    UnsignedBigInt& operator -= (const UnsignedBigInt& b) {
        assert(*this >= b);
        int r = 0;
        size_t i;
        for(i = 0; i < b.s.size(); ++i) {
            s[i] -= b.s[i] + r;
            if(s[i] < 0) {
                s[i] += BASE;
                r = 1;
            } else {
                r = 0;
            }
        }
        while(r) {  //i < s.size()
            if(--s[i] < 0)
                s[i++] += BASE;
            else
                r = 0;
        }
        return clean();
    }
    UnsignedBigInt operator - (const UnsignedBigInt& b) const {
        return UnsignedBigInt(*this) -= b;
    }

    UnsignedBigInt& operator -= (int b) {
        assert(*this >= b);
        size_t i = 0;
        while (b) {
            if((s[i] -= b) < 0) {
                s[i++] += BASE;
                b = 1;
            } else {
                b = 0;
            }
        }
        return clean();
    }
    UnsignedBigInt operator - (int b) const {
        return UnsignedBigInt(*this) -= b;
    }

    friend int operator - (int lhs, const UnsignedBigInt& rhs);

    int DivEq_Mod(int rhs) {
        assert(rhs);
        LL rem = 0;
        for (int i = s.size()-1; i >= 0; --i) {
            rem = rem * BASE + s[i];
            s[i] = rem / rhs;
            rem %= rhs;
        }
        clean();
        return rem;
    }
    int operator % (int rhs) const {
        return UnsignedBigInt(*this).DivEq_Mod(rhs);
    }
    UnsignedBigInt& operator /= (int rhs) {
        DivEq_Mod(rhs);
        return *this;
    }
    UnsignedBigInt operator / (int rhs) {
        UnsignedBigInt ans = *this;
        ans.DivEq_Mod(rhs);
        return ans;
    }
    UnsignedBigInt& operator %= (int rhs) {
        return *this = DivEq_Mod(rhs);
    }

    //You should make sure that ans == 0 before invoke the function.
    __attribute__((optimize("O3"))) void div_mod(const UnsignedBigInt& b, UnsignedBigInt& ans, UnsignedBigInt& rem) const {
        assert(!b.s.empty());
        UnsignedBigInt expNum(1), divisor(b);

        rem = *this;
        while(divisor <= rem) {
            divisor *= 2;
            expNum *= 2;
        }
        divisor /= 2;
        expNum /= 2;
        while(!expNum.s.empty()) {
            if(rem >= divisor) {
                rem -= divisor;
                ans += expNum;
            }
            divisor /= 2;
            expNum /= 2;
        }
        ans.clean();
    }
    __attribute__((optimize("O3"))) UnsignedBigInt operator / (const UnsignedBigInt& b)const {
        UnsignedBigInt ans, rem; //ans = remain = 0;
        div_mod(b, ans, rem);
        return ans;
    }
    __attribute__((optimize("O3"))) UnsignedBigInt& operator /= (const UnsignedBigInt& b) {
        return *this = *this / b;
    }

    //void div_mod(const UnsignedBigInt& b, UnsignedBigInt& ans, UnsignedBigInt& rem)
    __attribute__((optimize("O3"))) UnsignedBigInt operator % (const UnsignedBigInt& b) const {
        UnsignedBigInt ans, rem; //ans = remain = 0;
        div_mod(b, ans, rem);
        return rem;
    }
    __attribute__((optimize("O3"))) UnsignedBigInt& operator %= (const UnsignedBigInt& b) {
        return *this = *this % b;
    }

    __attribute__((optimize("O3"))) inline UnsignedBigInt Move_right_BASE(int n) const {
        return n >= (int)s.size() ? UnsignedBigInt() : UnsignedBigInt(vector<int>(s.begin() + n, s.end()));
    }

    __attribute__((optimize("O3"))) UnsignedBigInt& MoveEq_right_small_10(int n) {
        assert(n < WIDTH);
        LL rem = 0;
        for(int i = (int)s.size() - 1; i >= 0; --i) {
            (rem *= BASE) += s[i];
            s[i] = rem / tens[n];
            rem %= tens[n];
        }
        return clean();
    }
    __attribute__((optimize("O3"))) inline UnsignedBigInt Move_right_10(int n) const {
        return Move_right_BASE(n / WIDTH).MoveEq_right_small_10(n % WIDTH);
    }

    __attribute__((optimize("O3"))) inline UnsignedBigInt Move_left_BASE(int n) {
        UnsignedBigInt ans = *this;
        ans.s.insert(ans.s.begin(), n, 0);
        return ans;
    }

    __attribute__((optimize("O3"))) UnsignedBigInt operator ^ (int m) const {
        if(0 == m)
            return UnsignedBigInt(1);
        assert(m > 0);
        UnsignedBigInt ans = *this;
        while(--m)
            ans *= *this;
        return ans;
    }

    //Independent
    //Number of digits in decimal
    size_t digit() const {
        size_t ans;
        if(s.size()) {
            ans = ((int)s.size() - 1) * WIDTH;
            for(int t = s.back(); t; t /= 10, ++ans);
        } else {
            ans = 0;
        }
        return ans;
    }
};

UnsignedBigInt operator * (int a, const UnsignedBigInt& b) {
    return b * a;
}

int operator - (int lhs, const UnsignedBigInt& rhs) {
    assert(lhs >= rhs);
    return lhs - (int)rhs;
}

bool operator < (int lhs, const UnsignedBigInt& rhs) {
    return rhs.s.size() == 1 ? (lhs < rhs.s[0]) : !rhs.s.empty();
}
bool operator == (int lhs, const UnsignedBigInt& rhs) {
    return rhs == lhs;
}
bool operator <= (int lhs, const UnsignedBigInt& rhs) {
    return lhs < rhs || lhs == rhs;
}
bool operator > (int lhs, const UnsignedBigInt& rhs) {
    return !(lhs <= rhs);
}
bool operator >= (int lhs, const UnsignedBigInt& rhs) {
    return !(lhs < rhs);
}
bool operator != (int lhs, const UnsignedBigInt& rhs) {
    return !(lhs == rhs);
}

UnsignedBigInt sqrt(const UnsignedBigInt& x, int m) {
    UnsignedBigInt x0;
    int n = x.s.size();

    if(m <= 1) {
        assert(m >= 0);
        if(1 == m)
            x0 = x;
    } else if(n <= m) {
        int L = 0, R = x.BASE - 1, mid;
        while(L < R) {
            mid = L + ((R - L + 1) >> 1);
            if((UnsignedBigInt(mid) ^ m) <= x)
                L = mid;
            else
                R = mid - 1;
        }
        x0.s.push_back(L);
    } else if(n <= (m << 1)) {
        x0.s.resize(2, 0);
        int L = 0, R = x.BASE - 1, mid;
        while(L < R) {
            mid = L + ((R - L + 1) >> 1);
            x0.s[1] = mid;
            if((x0 ^ m) <= x)
                L = mid;
            else
                R = mid - 1;
        }
        x0.s[1] = L;
        L = 0, R = x.BASE - 1;
        while(L < R) {
            mid = L + ((R - L + 1) >> 1);
            x0.s[0] = mid;
            if((x0 ^ m) <= x)
                L = mid;
            else
                R = mid - 1;
        }
        x0.s[0] = L;
    } else {
        int mov=(n/m) >> 1;//??????????????
        x0.s.assign(x.s.begin()+mov*m,x.s.end());
        x0=(sqrt(x0, m)+1).Move_left_BASE(mov);//+1,?????????
        UnsignedBigInt x1;
        do {
            x1= ((m-1)*x0+x/(x0^(m-1)))/m;
            swap(x0, x1);
        } while(x0 < x1);
        swap(x0, x1);
    } return x0;
}

ostream& operator << (ostream& out, const UnsignedBigInt& a) {
    return out << (string)a;
}

istream& operator >> (istream& in, UnsignedBigInt& a) {
    string str;
    if(in >> str)
        a = str;
    return in;
}
UnsignedBigInt Quickpow(int t) {
    UnsignedBigInt Now(2),ans(1);
    int n=t;
    while(n) {
        if(n&1) ans=ans*Now;
        Now=Now*Now;
        n>>=1;
    } return ans;
}

UnsignedBigInt a,b,c;
void solve(int T){
    int n;
    cin>>n;
    c=Quickpow(n);
    a=2;
    b=2;
    for(int i=3;i<=n;i++){
        
    }
}
signed main(){
    int t=1;
    //scanf("%d",&t);
    for(int i=1;i<=t;i++){
        solve(i);
    }
}
