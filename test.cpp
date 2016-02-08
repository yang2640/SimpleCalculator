#include "cal.h"
#include <iostream>

using namespace std;


int main() {
    Cal cal;
    string exprStr = "(12 / 5) * (3 + 4)";
    float val = cal.compute(exprStr);
    cout << exprStr << " = " << val << endl;
    return 0;
}
