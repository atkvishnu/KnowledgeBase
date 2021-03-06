#include <algorithm>

#include <cctype>

#include <iostream>

#include <sstream>

#include <string>

#include <unordered_set>

#include <vector>

using namespace std;

string trim(const string & input) {
    string output {input};
    
    output.erase(begin(output),find_if(begin(output), end(output),[](const char ch) {return !isspace(ch);}));

    output.erase(find_if(output.rbegin(), output.rend(), [](const char ch){return !isspace(ch);} ).base(),end(output));

    return output;
}

vector<string> split(const string &source, const char *needle, size_t const max_count = string::npos) {
    vector < string > parts {};

    string needle_st {needle};

    const size_t source_len {source.length()};

    const size_t needle_len {needle_st.length()};

    if (!source_len)
        return parts;

    if (!needle_len) {
        const size_t upper_limit {
            max_count < source_len ? max_count : source_len
        };
        for (size_t i {}; i < upper_limit; i++)
            parts.emplace_back(1, source[i]);
        return parts;
    }

    size_t number_of_parts {}, prev {};

    while (true) {
        const size_t current {
            source.find(needle_st, prev)
        };

        if (string::npos == current)
            break;

        number_of_parts++;

        if ((string::npos != max_count) && (parts.size() == max_count))
            break;

        if (current - prev > 0)
            parts.emplace_back(source.substr(prev, current - prev));

        prev = current + needle_len;

        if (prev >= source_len)
            break;
    }

    if (prev < source_len) {
        if (string::npos == max_count)
            parts.emplace_back(source.substr(prev));

        else if (parts.size() < max_count)
            parts.emplace_back(source.substr(prev));
    }

    return parts;
}

string WordSplit_v1(string * str_arr, const size_t str_arr_size) {
    if (!str_arr || str_arr_size < 2)
        return "not possible";

    const string target_word {
        trim(str_arr[0])
    };
    const size_t target_word_len {
        target_word.length()
    };

    str_arr[1] = trim(str_arr[1]);
    const vector < string > words {
        split(str_arr[1], ",")
    };

    unordered_set < string > dictionary(begin(words), end(words));

    string first_word {};
    first_word.reserve(target_word_len);
    string second_word {
        target_word
    };

    for (size_t i {}; i < target_word_len - 1; i++) {
        first_word.push_back(target_word[i]);
        second_word.erase(0, 1);

        if (dictionary.find(first_word) != end(dictionary) &&
            dictionary.find(second_word) != end(dictionary)) {
            ostringstream oss {};
            oss << first_word << ',' << second_word;
            return oss.str();
        }
    }

    return "not possible";
}

int main() {
    // string A[] = gets(stdin);
    // cout << WordSplit_v1(A, sizeof(A)/sizeof(A[0]));
    string B[] = {
        "hellocat",
        "apple,bat,cat,goodbye,hello,yellow,why"
    };
    cout << WordSplit_v1(B, sizeof(B) / sizeof(B[0])) <<
        '\n'; // expected output: "hello,cat"
    string C[] = {
        "baseball",
        "a,all,b,ball,bas,base,cat,code,d,e,quit,z"
    };
    cout << WordSplit_v1(C, sizeof(C) / sizeof(C[0])) <<
        '\n'; // expected output: "base,ball"
    string D[] = {
        "abcgefd",
        "a,ab,abc,abcg,b,c,dog,e,efd,zzzz"
    };
    cout << WordSplit_v1(D, sizeof(D) / sizeof(D[0])) <<
        '\n'; // expected output: "abcg,efd"

    return 0;
}