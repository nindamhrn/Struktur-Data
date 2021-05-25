#include <iostream>
#include "otak.h"
#include "admin.h"
#include "juri.h"

using namespace std;

int main()
{
    ListJ J;
    ListP P;
    ListR R;
    ListH H;

    createList(J,P,R,H);
    menuLogin(J,P,R,H);

    return 0;
}
