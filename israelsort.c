#include <vector>
#include <algorithm>
#include <cstdlib>   // llabs
#include <tuple>     // std::tie

using namespace std;
using ll = long long;

// Calcula a soma dos dígitos de forma clara e eficiente
int somaDigitos(ll n) {
    n = llabs(n);
    int soma = 0;
    while (n) {
        soma += n % 10;
        n /= 10;
    }
    return soma;
}

// Israel Sort — Ordenação por soma de dígitos e depois pelo valor
void israelSort(vector<ll>& v) {
    vector<pair<int, ll>> temp;
    temp.reserve(v.size());

    // Decora
    transform(v.begin(), v.end(), back_inserter(temp),
              [](ll x) { return make_pair(somaDigitos(x), x); });

    // Ordena usando "tuple-like" comparison
    sort(temp.begin(), temp.end(),
         [](const auto& a, const auto& b) {
             return tie(a.first, a.second) < tie(b.first, b.second);
         });

    // Decora → Ordena → Undecora (Clássico DSU)
    for (size_t i = 0; i < v.size(); ++i) {
        v[i] = temp[i].second;
    }
}
