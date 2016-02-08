#include <vector>
#include <iostream>
#include <stack>
using namespace std;

class Cal {
public:
    Cal();
    ~Cal();
    float compute(string exprStr);

private:
    vector<string> scan(string exprStr);
    vector<string> toRPolish(vector<string> &expr);
    float evaluate(vector<string> &expr);
    float innerEval(float x, float y, string op);
    int pred(string x);
    bool isOp(string c);
    bool isOp(char c);
};
