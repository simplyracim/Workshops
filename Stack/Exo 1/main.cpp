#include <vector>
#include <iostream>

void tri_insertion(std::vector<int>& l) {
    int n = l.size();

    for (int i = 1; i < n; ++i) {
        int v = l[i];
        int j = i;

        while (j > 0 && l[j - 1] > v) {
            l[j] = l[j - 1];
            --j;
        }

        l[j] = v;
    }
}


int main() {
    std::vector<int> t = {5, 2, 4, 6, 1, 3};

    tri_insertion(t);

    for (int x : t) {
        std::cout << x << " ";
    }
}
