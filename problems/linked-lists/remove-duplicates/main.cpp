#include <bits/stdc++.h>
using namespace std;

struct Node {
  int val;
  Node *next;

  Node() : val{0}, next{nullptr} {}
  Node(int val) : val{val}, next{nullptr} {}
  Node(int val, Node *next) : val{val}, next{next} {}

  static Node *make_list(vector<int> &nums) {
    Node *head = nullptr, *rear = nullptr;
    for (const auto &num : nums) {
      Node *const ptr = new Node(num);
      if (not rear) {
        head = rear = ptr;
        continue;
      }
      rear->next = ptr;
      rear = rear->next;
    }
    return head;
  }

  static void print_list(Node *head) {
    auto ptr = head;

    while (ptr) {
      cout << ptr->val << " ";
      ptr = ptr->next;
    }
    cout << "\n";
  }
};

Node *remove_duplicates(Node *head) {
  if (not head) {
    return nullptr;
  }

  Node *n_rear_prev = head, *n_rear = head->next;

  while (n_rear) {
    const auto original_next = n_rear->next;

    if (n_rear_prev->val == n_rear->val) {
      n_rear_prev->next = n_rear->next;

      delete n_rear;

      n_rear = original_next;
      continue;
    }

    n_rear_prev = n_rear;
    n_rear = original_next;
  }

  return head;
}

void solve() {
  int N;
  cin >> N;

  vector<int> numbers(N);

  for (auto &num : numbers) {
    cin >> num;
  }

  Node *head = Node::make_list(numbers);

  const auto new_head = remove_duplicates(head);

  Node::print_list(new_head);
}

int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;
  while (T--) {
    solve();
  }

  return 0;
}
