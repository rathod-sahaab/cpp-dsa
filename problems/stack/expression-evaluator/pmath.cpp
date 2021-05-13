#include <bits/stdc++.h>
#include <cassert>
#include <cctype>
using namespace std;

static bool paranthesis_valid(const string &expression_string) {
  stack<int> s;

  for (const auto &character : expression_string) {
    if (character == '(') {
      s.push(character);
    } else if (character == ')') {
      if (s.empty()) {
        return false;
      }
      s.pop();
    }
  }

  return s.empty();
}

string post_fixer(const string &expression_string) {
  static map<char, int> precedence{
      {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'^', 3},
  };

  if (not paranthesis_valid(expression_string)) {
    return "";
  }

  stack<char> s; // operators
  string result;

  bool is_same_number = true;
  for (const auto &character : expression_string) {
    if (isdigit(character)) {
      if (not is_same_number and isdigit(result.back())) {
        result.push_back(',');
      }
      result.push_back(character);
      is_same_number = true;
    } else if (character == '(') {
      s.push(character);
    } else if (character == ')') {
      while (s.top() != '(') {
        result.push_back(s.top());
        s.pop();
      }
      s.pop();
    } else {
      is_same_number = false;

      const int char_pre = precedence[character];
      while (not s.empty() and char_pre <= precedence[s.top()]) {
        result.push_back(s.top());
        s.pop();
      }
      s.push(character);
    }
  }

  while (not s.empty()) {
    result.push_back(s.top());
    s.pop();
  }

  return result;
}

static float binary_operation_eval(float a, float b, char op) {
  switch (op) {
  case '+':
    return a + b;
  case '-':
    return a - b;
  case '*':
    return a * b;
  case '/':
    return a / b;
  case '^':
    return pow(a, b);
  }
  return FP_NAN;
}

float evaluate_postfix(const string &post_fix) {
  stack<float> s;

  bool is_same_number = false;
  for (const auto &character : post_fix) {
    if (not isdigit(character)) {
      is_same_number = false;

      if (character != ',') {
        const float b = s.top();
        s.pop();
        const float a = s.top();
        s.pop();

        float result = binary_operation_eval(a, b, character);
        s.push(result);
      }

    } else {
      const int digit = character - '0';
      if (is_same_number) {
        s.top() *= 10;
        s.top() += digit;
      } else {
        s.push(digit);
      }
      is_same_number = true;
    }
  }

  return s.top();
}
