#include "UnionFind.h"

int main() {
    int n, r;
    std::cout << "Input" << std::endl;

    std::cin >> n;
    if (n < 1 || n > 9) {
        std::cerr << "Invalid number of elements (1-9 required)." << std::endl;
        return 0;
    }

    UnionFind uf(n);

    std::cin >> r;
    if (r <= 0) {
        std::cerr << "Invalid number of relations." << std::endl;
        return 0;
    }

    // 输入关系：例如 (1,2)
    for (int i = 0; i < r; i++) {
        int a, b;
        char c;
        std::cin >> c >> a >> c >> b >> c;
        uf.unite(a, b);
    }

    uf.processAndOutput();

    return 0;
}
