#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> orders, vector<int> course);

int main()
{
    vector<string> orders;
    orders.push_back("ABCFG");
    orders.push_back("AC");
    orders.push_back("CDE");
    orders.push_back("ACDE");
    orders.push_back("BCFG");
    orders.push_back("ACDEH");

    vector<int> course;
    course.push_back(2);
    course.push_back(3);
    course.push_back(4);

    solution(orders, course);
}

vector<string> solution(vector<string> orders, vector<int> course)
{
    vector<string> answer;

    vector<string> menu_candidate;

    for (vector<int>::iterator it = course.begin(); it != course.end(); it++)
    {
        for (vector<string>::iterator it_orders = orders.begin(); it_orders != orders.end(); it_orders++)
        {
            //sort((*it_orders).begin(), (*it_orders).end());
            //cout << (*it_orders) << endl;
            //cout << "+++++++++++++++" << endl;
            reverse((*it_orders).begin(), (*it_orders).end());

            if ((*it) <= (*it_orders).size())
            {
                int n = (*it_orders).size();
                int k = (*it);
                //cout << n  << " " << k << endl;

                //
                vector<int> tempVec;
                for (int i = 0; i < k; i++)
                {
                    tempVec.push_back(1);
                }

                for (int i = 0; i < (*it_orders).size() - k; i++)
                {
                    tempVec.push_back(0);
                }

                sort(tempVec.begin(), tempVec.end());
                //string menu_ = "";
                do
                {
                    string menu_ = "";
                    for (int i = 0; i < tempVec.size(); i++)
                    {
                        if (tempVec[i] == 1)
                        {
                            menu_.push_back((*it_orders)[i]);
                        }
                    }
                    sort(menu_.begin(), menu_.end());
                    menu_candidate.push_back(menu_);
                    //cout << menu_ << endl;
                } while (next_permutation(tempVec.begin(), tempVec.end()));
                //menu_candidate.push_back(menu_);
            }

            //cout << "-------------------------------------------" << endl;
        }
        //cout << "***************************************" << endl;
    }

    /*for (vector<string>::iterator it = menu_candidate.begin(); it != menu_candidate.end(); it++)
    {
        cout << (*it) << " ";
    }*/

    for (vector<string>::iterator it = menu_candidate.begin(); it != menu_candidate.end(); it++)
    {
        int same_cnt = 0;
        for (vector<string>::iterator it_same = it; it_same != menu_candidate.end(); it_same++)
        {
            if ((*it) == (*it_same))
                same_cnt++;
        }

        if (same_cnt >= 2)
        {
            answer.push_back((*it));
        }
    }

    sort(answer.begin(), answer.end());

    /*for (vector<string>::iterator it = answer.begin(); it != answer.end(); ++it)
    {
        cout << (*it) << endl;
    }*/


    vector<int> same_temp;
    int cnt = 0;
    for (vector<string>::iterator it = answer.begin(); it != answer.end(); ++it)
    {
        for (vector<string>::iterator it_same = it; it_same != answer.end(); ++it_same)
        {
            if ((*it) == (*it_same))
            {
                cnt++;
            }
        }
        same_temp.push_back(cnt);
        cnt = 0;
    }

    /*for (vector<string>::iterator it = answer.begin(); it != answer.end(); ++it)
    {
        cout << (*it) << endl;
    }*/

    vector<pair<string, int>> menu_candi;
    vector<string> menu__;
    vector<string> answer_final;

    for (vector<int>::iterator it_num = course.begin(); it_num != course.end(); ++it_num)
    {
        for (vector<string>::iterator it = answer.begin(); it != answer.end(); ++it)
        {
            if ((*it_num) == (*it).length())
            {
                menu__.push_back((*it));
            }
        }

        for (int i = 0; i < menu__.size(); i++)
        {
            int sameCnt = 0;
            for (int j = 0; j < menu__.size(); j++)
            {
                if (menu__[i] == menu__[j])
                {
                    sameCnt++;
                }
            }

            int orgCnt = 0;
            for (int j = 0; j < menu_candi.size(); j++)
            {
                if (menu_candi[j].first == menu__[i])
                {
                    orgCnt++;
                }
            }

            if (orgCnt == 0)
                menu_candi.push_back(make_pair(menu__[i], sameCnt));

            sameCnt = 0;
        }

        int maxValue = 0;
        for (int i = 0; i < menu_candi.size(); i++)
        {
            if (menu_candi[i].second >= maxValue)
                maxValue = menu_candi[i].second;
        }

        for (int i = 0; i < menu_candi.size(); i++)
        {
            if (menu_candi[i].second == maxValue)
                answer_final.push_back(menu_candi[i].first);
        }

        menu_candi.clear();
        menu__.clear();
    }

    answer = answer_final;
    sort(answer.begin(), answer.end());

    for (vector<string>::iterator it = answer.begin(); it != answer.end(); ++it)
    {
        cout << (*it) << endl;
    }

    return answer;
}