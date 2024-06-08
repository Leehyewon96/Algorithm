#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
using namespace std;

bool Comp(tuple<string, int, int, int> t1, tuple<string, int, int, int> t2)
{
    if (get<1>(t1) != get<1>(t2))
    {
        return get<1>(t1) > get<1>(t2);
    }
    
    if (get<2>(t1) != get<2>(t2))
    {
        return get<2>(t1) < get<2>(t2);
    }

    if (get<3>(t1) != get<3>(t2))
    {
        return get<3>(t1) > get<3>(t2);
    }

    if (get<0>(t1) != get<0>(t2))
    {
        return get<0>(t1) < get<0>(t2);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;


    vector<tuple<string, int, int, int>> tupleVec;
    string name;
    int korean;
    int english;
    int math;
    for (int i = 0; i < N; ++i)
    {
        cin >> name >> korean >> english >> math;
        tupleVec.push_back(make_tuple(name, korean, english, math));
    }

    sort(tupleVec.begin(), tupleVec.end(), Comp);

    for (int i = 0; i < N; ++i)
    {
        cout << get<0>(tupleVec[i]) << '\n';
    }
    return 0;
}