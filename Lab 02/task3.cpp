#include <iostream>

using namespace std;

bool is_single_line_comment(const string& line) {
    return line.find("//") == 0;
}

bool is_multi_line_comment_start(const string& line) {
    return line.find("/*") == 0;
}

bool is_multi_line_comment_end(const string& line) {
    return line.find("*/") != string::npos;
}

bool is_comment_line(const string& line) {
    if (is_single_line_comment(line))
        return true;
    else if (is_multi_line_comment_start(line)) {
        if (is_multi_line_comment_end(line))
            return true;
        else {
            // Need to check for multi-line comments until its end
            bool in_multi_line_comment = true;
            for (size_t i = 1; i < line.length(); ++i) {
                if (is_multi_line_comment_end(line.substr(i))) {
                    in_multi_line_comment = false;
                    break;
                }
            }
            return in_multi_line_comment;
        }
    }
    return false;
}

int main() {
    string user_input;
    cout << "Enter a line of code: ";
    getline(cin, user_input);

    if (is_comment_line(user_input)) {
        if (is_single_line_comment(user_input))
            cout << "The given input is a single-line comment." << endl;
        else
            cout << "The given input is a multi-line comment." << endl;
    }
    else
        cout << "The given input is not a comment line." << endl;

    return 0;
}
