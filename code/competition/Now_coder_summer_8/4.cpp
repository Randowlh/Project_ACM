#include <bits/stdc++.h>
 
using ul = std::uint32_t;
using ull = std::uint64_t;
using ll = std::int64_t;
using li = std::int32_t;
using pulul = std::pair<ul, ul>;
using us = std::uint16_t;
 
ul T;
const ul maxT = 1000;
 
class query {
public:
    ul Case = 0;
    ul n = 0;
    ul m = 0;
    std::string out;
    ul val = 0;
};
 
query qs[maxT + 1];
 
const ul maxm = 15;
const ul maxn = 1000;
 
bool able[1 << maxm];
ul cover[1 << maxm];
 
const ul sz = 43691;
 
std::vector<pulul> states;
 
std::vector<pulul> ablenext[sz];
 
us ans[maxn + 1][sz];
us ansprev[maxn + 1][sz];
 
const ul inf = 1e5;
 
std::string out(ul x, ul m)
{
    std::string str;
    for (ul i = 0; i != m; ++i) {
        if (x >> i & 1) {
            str.push_back('*');
        } else {
            str.push_back('.');
        }
    }
    return str;
}
 
void deal(ul m)
{
    able[0] = true;
    for (ul set = 1; set != (1 << m); ++set) {
        if (able[set >> 1] && !((set & 1) && (set >> 1 & 1))) {
            able[set] = true;
            cover[set] = cover[set >> 1] << 1;
            if (set >> 1 & 1) {
                cover[set] |= 1;
            }
            if (set & 1) {
                cover[set] |= 3;
            }
            cover[set] &= (1 << m) - 1;
        }
    }
    states.resize(0);
    for (ul set = 0; set != (1 << m); ++ set) {
        if (able[set]) {
            ul nexr = (1 << m) - 1 & ~set;
            for (ul nex = nexr; ; nex = nex - 1 & nexr) {
                if (able[nex]) {
                    states.push_back(pulul(set | cover[nex], nex));
                }
                if (!nex) {
                    break;
                }
            }
        }
    }
    std::sort(states.begin(), states.end());
    states.resize(std::unique(states.begin(), states.end()) - states.begin());
    ul cnt = 0;
    for (ul i = 0; i != states.size(); ++i) {
        const auto& p = states[i];
        ul prev = p.first;
        ul curr = p.second;
        ul nexr = prev & ~curr;
        ul need = (1 << m) - 1 & ~prev;
        ablenext[i].resize(0);
        for (ul next = nexr; ; next = next - 1 & nexr) {
            if (able[need | next]) {
                ul id = std::lower_bound(states.begin(), states.end(), pulul(curr | cover[need | next], need | next)) - states.begin();
                ablenext[i].push_back(pulul(__builtin_popcount(next | need), id));
                ++cnt;
            }
            if (!next) {
                break;
            }
        }
    }
    for (ul n = 1; n <= maxn; ++n) {
        for (ul i = 0; i != states.size(); ++i) {
            ans[n][i] = inf;
        }
    }
    for (ul i = 0; i != states.size(); ++i) {
        if (cover[states[i].second] == states[i].first) {
            ans[1][i] = __builtin_popcount(states[i].second);
        }
    }
    for (ul n = 1; n + 1 <= maxn; ++n) {
        for (ul i = 0; i != states.size(); ++i) {
            if (ans[n][i] == inf) {
                continue;
            }
            for (auto p : ablenext[i]) {
                if (ans[n][i] + p.first < ans[n + 1][p.second]) {
                    ans[n + 1][p.second] = ans[n][i] + p.first;
                    ansprev[n + 1][p.second] = i;
                }
            }
        }
    }
}
 
void getans(std::string& out, ul n, ul m, ul& val)
{
    static std::vector<ul> tmp;
    out.resize(0);
    tmp.resize(0);
    ul curr = 0;
    val = inf;
    for (ul i = 1; i != states.size(); ++i) {
        if (states[i].first == (1 << m) - 1 && ans[n][i] < val) {
            val = ans[n][i];
            curr = i;
        }
    }
    while (n) {
        tmp.push_back(states[curr].second);
        curr = ansprev[n][curr];
        --n;
    }
    std::reverse(tmp.begin(), tmp.end());
    for (auto v : tmp) {
        for (ul i = 0; i != m; ++i) {
            if (v >> i & 1) {
                out.push_back('*');
            } else {
                out.push_back('.');
            }
        }
        out.push_back('\n');
    }
}
 
int main()
{
    std::scanf("%u", &T);
    for (ul Case = 1; Case <= T; ++Case) {
        std::scanf("%u%u", &qs[Case].n, &qs[Case].m);
        qs[Case].Case = Case;
    }
    std::sort(qs + 1, qs + T + 1, [](const query& a, const query& b) {return a.m < b.m;});
    for (ul i = 1, j = 1; i <= T; i = j) {
        while (j <= T && qs[j].m == qs[i].m) {
            ++j;
        }
        deal(qs[i].m);
        for (ul it = i; it != j; ++it) {
            getans(qs[it].out, qs[it].n, qs[it].m, qs[it].val);
        }
    }
    std::sort(qs + 1, qs + T + 1, [](const query& a, const query& b) {return a.Case < b.Case;});
    for (ul Case = 1; Case <= T; ++Case) {
        std::printf("Case #%u: %u\n", Case, qs[Case].val);
        std::cout << qs[Case].out;
    }
    return 0;
}