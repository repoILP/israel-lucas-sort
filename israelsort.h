#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int somaDigitos(ll n) {
    n = abs(n);
    int s = 0;
    while (n) { s += n % 10; n /= 10; }
    return s ? s : 0;
}

void israelSort(vector<ll>& v) {
    vector<pair<int, ll>> temp;
    temp.reserve(v.size());
    for (auto x : v) temp.emplace_back(somaDigitos(x), x);
    sort(temp.begin(), temp.end(), [](const auto& a, const auto& b) {
        return a.first != b.first ? a.first < b.first : a.second < b.second;
    });
    for (int i = 0; i < v.size(); i++) v[i] = temp[i].second;
}
