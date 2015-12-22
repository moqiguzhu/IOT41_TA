#include<vector>
#include<cstdlib>
#include<iostream>
#include <stdio.h>

using namespace std;

int main()
{
    vector<char> vec;
    std::string str;
    std::getline(std::cin, str);
    int num, index;
    char c;
    unsigned int i, j;
    for(i = 0; i < str.size(); i++)
    {
        vec.push_back(str.at(i));
    }
    scanf("%d\n", &num);
    for(i = 0; i < num; i++)
    {
        scanf("%d %c",&index, &c);
        int le = index,  ri = index;
        vec.insert(vec.begin()+index, c);
        do
        {
            ri = le;
            c = vec.at(le);
            while(le > -1 && vec.at(le) == c) le--;
            while(ri < vec.size() && vec.at(ri) == c) ri++;
            if(ri - le > 3) vec.erase(vec.begin()+le+1, vec.begin()+ri);
            if(le < 0) break;
        } while(ri - le > 3);

        for(j = 0; j < vec.size(); j++)
        {
            printf("%c", vec.at(j));
        }
        if(vec.size() == 0)
        {
            printf("%s", "-");
        }
        printf("\n");
    }
    return 0;
}
