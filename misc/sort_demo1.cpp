#include <bits/stdc++.h>

using namespace std;

struct Stud
{
    int no;
    string name;
    Stud(int no, string name) : no(no), name(name) {}
    bool operator<(const Stud &s)
    {
        return no > s.no; //递减排序
    }
};

struct Cmp
{
    bool operator()(const Stud &a, const Stud &b) const
    {
        return a.name < b.name; //按字典序（升序）
    }
};

void Disp(vector<Stud> &myv) //输出vector的元素
{
    vector<Stud>::iterator it;
    for (it = myv.begin(); it != myv.end(); it++)
        cout << it->no << ", " << it->name << "\t";
    cout << endl;
}

int main(int argc, char const *argv[])
{
    Stud a[] = {Stud(2, "Mary"), Stud(1, "John"), Stud(5, "Smith")};
    int n = sizeof(a) / sizeof(a[0]);
    vector<Stud> myv(a, a + n);
    cout << "初始myv:    ";
    Disp(myv);
    //输出：2, Mary   1, John  5, Smith
    sort(myv.begin(), myv.end()); //默认使用<运算符排序
    cout << "按no递减排序:   ";
    Disp(myv);
    //输出：5, Smith  2, Mary  1, John
    sort(myv.begin(), myv.end(), Cmp()); //使用Cmp中的()运算符进行排序
    cout << "按name递增排序: ";
    Disp(myv);
    //输出：1, John   2, Mary  5, Smith

    system("pause");
    return 0;
}
