#include <string>
#include <vector>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) 
{
    int answer = 0;

    int hp = health;
    int series = 0;
    int attackIdx = 0;
    int tick = 0;
    while (1)
    {
        ++tick;
        if (attackIdx == attacks.size())
        {
            //hp += attacks[attackIdx - 1][1];
            break;
        }

        if (attacks[attackIdx][0] == tick)
        {
            hp -= attacks[attackIdx][1];

            attackIdx++;
            series = 0;

            if (hp <= 0)
            {
                hp = -1;
                break;
            }

            continue;
        }

        hp += bandage[1];
        series++;

        if (series == bandage[0])
        {
            hp += bandage[2];
            series = 0;
        }

        if (hp > health)
        {
            hp = health;
        }
    }

    return hp;
}