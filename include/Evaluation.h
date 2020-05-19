#ifndef EVALUATION_H
#define EVALUATION_H
#include <string>


using namespace std;

class Evaluation
{
    public:
        Evaluation();
        virtual ~Evaluation();

        int GetNCNI() { return NCNI; }
        void SetNCNI(int val) { NCNI = val; }
        double Getnote() { return note; }
        void Setnote(double val) { note = val; }
        string Getcode() { return code; }
        void Setcode(string val) { code = val; }

         void test();
    protected:

    private:
        int NCNI;
        double note;
        string code;
};

#endif // EVALUATION_H
