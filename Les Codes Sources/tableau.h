#include <vector>
#include <iostream>
using namespace std;

class tableau
{
    public:
        tableau(int a);
        ~tableau();

        void set(float v, int pos);
        float get(int pos);
        
    protected:
        const int taille;

    private:
        vector<float> data;
        float calculeMoyenne();
};

