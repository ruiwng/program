enum ExpressionType {
    NUMBER,
    OPERATOR
};

struct ExpressionElement {
    ExpressionType expression_type;

    union {
        int number;
        char op;
    };
    
    ExpressionElement(ExpressionType t, char o): expression_type(t), op(o) {}
    ExpressionElement(ExpressionType t, int n) : expression_type(t), number(n) {}
};

class Solution {
public:
    bool isOperator(char c) {
        return c == '+' || c == '-' || c == '*';
    }

    int evaluate(int x, int y, char op) {
        if (op == '+') {
            return x + y;
        }
        else if (op == '-') {
            return x - y;
        }
        else if (op == '*') {
            return x * y;
        }
        return 0;
    }

    vector<int> evaluateVec(vector<int>& lhs, vector<int>& rhs, char op) {
        vector<int> result;
        for (auto i = 0; i < lhs.size(); ++i) {
            for (auto j = 0; j < rhs.size(); ++j) {
                result.push_back(evaluate(lhs[i], rhs[j], op));
            }
        }
        return result;
    }

    vector<int> doCompute(int start, int end) {
        if (start + 1 == end) {
            return vector<int>({mExpressionVec[start].number});
        }
        vector<int> result;
        for (int i = start; i < end; ++i) {
            if (mExpressionVec[i].expression_type == OPERATOR) {
                auto lhs = doCompute(start, i);
                auto rhs = doCompute(i + 1, end);
                auto r = evaluateVec(lhs, rhs, mExpressionVec[i].op);
                result.insert(result.end(), r.begin(), r.end());
            }
        }
        return result;
    }

    vector<int> diffWaysToCompute(string expression) {
        mExpressionVec.clear();
        int number = 0;
        bool is_number_init = false;
        for (auto i = 0; i < expression.length(); ++i) {
            if(expression[i] == ' ' || isOperator(expression[i])) {
                if (is_number_init) {
                    mExpressionVec.push_back(ExpressionElement(NUMBER, number));
                    number = 0;
                    is_number_init = false;
                }
                if (isOperator(expression[i])) {
                    mExpressionVec.push_back(ExpressionElement(OPERATOR, expression[i]));
                }
            }
            else {
                number = number * 10 + (expression[i] - '0');
                is_number_init = true;
            }
        }
        if (is_number_init) {
            mExpressionVec.push_back(ExpressionElement(NUMBER, number));
        }
        return doCompute(0, mExpressionVec.size());
    }
private:
    vector<ExpressionElement> mExpressionVec;
};

int main() {
}
