#include <iostream>
#include <string>


using namespace std;

class Assignment{
    public:
        /**
         * @brief Construct a new Assignment object
         * 
         * @param n - the name of the assignment
         * @param p - the points possible
         * @param s - score
         */
        Assignment(std::string n = "NA", int p = -1, double s = -1);

        // I/O functions
        
        void input(std::istream& ins);

        /**
         * @brief present the assignment data to the user
         * 
         */
        void output() const;

        // Accessor functions (getters)
        /**
         * @brief Get the name object
         * 
         * @return string - the name of the assignment
         */
        string get_name() const{return name;}

        int get_points() const{return points;}

        double get_score() const{return score;}

        // Mutator functions (setters)
        /**
         * @brief Set the name object
         * 
         * @param n - the name of the assignment
         */
        void set_name(string n){name = n;}

        void set_points(int p){points = p;}

        void set_score(double s){score = s;}

    private:
        string name;
        int points;
        double score;
};

class Student{
    public:
        Student();

        string get_fname();

        void input(istream& ins);

    private:
        string fname;
        string lname;
        int year;
        string id;
        Assignment projects[5];
        Assignment labs[10];
};

class Course{
    private:
        string name;
        string semester;
        Student students[75];
};


int main(){
    const int SIZE = 5;
    Assignment a[SIZE];
    Student s;
    ifstream inF;
    string line;
    int num;

    cout << s.get_fname() << endl;

/*
    // load assignment data from the file
    inF.open("assignments.txt");
    if(!inF.fail()){
        for(int i = 0; i < SIZE - 1; i++){
            a[i].input(inF);
            /*
            // read in the name and set it
            getline(inF, line);
            a[i].set_name(line);

            // read in the points and set it
            inF >> num;
            a[i].set_points(num);

            // read in the score and set it
            inF >> num;
            a[i].set_score(num);

            // ignore any leftover newlines
            while(inF.peek() == '\n'){
                inF.ignore();
            }
            
        }
    }
    inF.close();

    a[4].input(cin);

    for(int i = 0; i < SIZE; i++){
        a[i].output();
    }
*/
    return 0;
}

void Student::input(istream& ins){
    // fname, lname, year, id, Assignment[5], Assignment[10]
    getline(ins, fname);
    getline(ins, lname);
    ins >> year;
    while(ins.peek() == '\n'){
        ins.ignore();
    }
    getline(ins, id);

    // read in the first 5 assignments to the projects array
    for(int i = 0; i < 5; i++){
        projects[i].input(ins);
    }

    // read in the 10 assignments to the labs array
    for(int i = 0; i < 10; i++){
        labs[i].input(ins);
    }
}

Student::Student():fname("ME"){
    /*
    fname = "NA";
    lname = "NA";
    id = "NA";
    year = -1;
    */
}

string Student::get_fname(){
    return fname;
}

Assignment::Assignment(string n, int p, double s){
    name = n;
    points = p;
    score = s;
}

void Assignment::input(istream& ins){
    // check to see if stream is cin before outputting prompt
    if(&ins == &cin){
        cout << "Enter the name: ";
    }
    //cin >> name; // only allow 1 word
    while(ins.peek() == '\n'){
        ins.ignore();
    }
    getline(ins, name);

    if(&ins == &cin){
        cout << "Enter the points: ";
    }
    ins >> points;

    if(&ins == &cin){
        cout << "Enter the score: ";
    }
    ins >> score;
}

void Assignment::output() const{
    cout << "  Name: " << name << endl;
    cout << "Points: " << points << endl;
    cout << " Score: " << score << endl;
}
