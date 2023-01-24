#include <iostream>
#include <string>
using namespace std;

class Assignment
{
    public:

        Assignment(string n = "NA", int p = -1, double s = -1)
        {
            name = n;
            points = p;
            score = s;
        }

        void input()
        {
            cout << "Enter the name: ";
            while (cin.ppek() == "\n")
            {
                cin.ignore();
            }
            getline(cin, name);

            cout << "Enter the points: ";
            cin >> score;
        }

        string getname() const
        {
            return name;
        }

        int getpoints() const
        {
            return points;
        }

        double get_score() const
        {
            return score;
        }

        void output() const
        {
            cout << "Name: " << name << endl;
            cout << "Points: " << points << endl;
            cout << "Score: " << score << endl;
        }
};

int main()
{
    Assignment a;
    Assignment a2;

    a.input();
    a2.input();

    a.output();
    a2.output();
    return 0;
}