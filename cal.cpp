#include "cal.h"


Cal::Cal() {

}


float Cal::compute(string exprStr) {
    vector<string> flow = scan(exprStr);
    vector<string> rPolish = toRPolish(flow);
    float ret = evaluate(rPolish);
    return ret;
}

vector<string> Cal::scan(string exprStr) {
    // scan the exprStr into vector, keep push to cur number, 
    // conclude the previous number when seeing op
    vector<string> res;
    string num;
    for (auto c: exprStr) {
        if (c == ' ') {
            continue;
        }

        if (!isOp(c)) {
            num.push_back(c);
        }
        else {
            // conclude number
            if (!num.empty()) {
                res.push_back(num);
                num.clear();
            }
            res.push_back(string(1, c));
        }
    }
    // remember to conclude last number
    if (!num.empty()) {
        res.push_back(num);
    }
    return res;
}

vector<string> Cal::toRPolish(vector<string> &expr) {
    vector<string> res;
    // using stack for transform
    stack<string> stack;
    for (auto x: expr) {
        if (isOp(x)) {
            if (x == "(") {
                stack.push(x);    
            } 
            else if (x == ")") {
                while (!stack.empty() && stack.top() != "(") {
                    res.push_back(stack.top());
                    stack.pop();
                } 
                stack.pop();
            }
            else {
                while (!stack.empty() && pred(stack.top()) >= pred(x)) {
                    res.push_back(stack.top());
                    stack.pop();
                } 
                stack.push(x);
            }
        }
        else {
            res.push_back(x);
        }
    }
    // push the remaing stack to res
    while (!stack.empty()) {
        res.push_back(stack.top());
        stack.pop();
    }
    return res;
}

float Cal::innerEval(float x, float y, string op) {
    if (op == "+") {
        return x + y;
    }
    else if (op == "-") {
        return x - y;
    }
    else if (op == "*") {
        return x * y;
    }
    else if (op == "/") {
        return x / y;
    }
    return -1;
}

float Cal::evaluate(vector<string> &expr) {
    // using stack for evaluation
    stack<float> stack;
    for (auto c: expr) {
        if (isOp(c)) {
            float y = stack.top();
            stack.pop();
            float x = stack.top();
            stack.pop();
            stack.push(innerEval(x, y, c));
        }
        else {
            stack.push(stoi(c));
        }
    }
    return stack.top();
}

int Cal::pred(string x) {
    if (x == "(") {
        return 0;
    }
    else if (x == "+" || x == "-") {
        return 1;
    }
    else if (x == "*" || x == "/") {
        return 2;
    }
    else if (x == ")") {
        return 3;
    }
    return -1;
}

bool Cal::isOp(string c) {
    return (c == "+") || (c == "-") || (c == "*") || (c == "/") ||
        (c == "(") || (c == ")");
}

bool Cal::isOp(char c) {
    return (c == '+') || (c == '-') || (c == '*') || (c == '/') ||
        (c == '(') || (c == ')');
}

Cal::~Cal() {

}
