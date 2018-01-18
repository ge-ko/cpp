#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <istream>
#include <ostream>

struct sudoku
{
    std::vector<int> m;

    explicit sudoku(std::istream_iterator<int> it)
    {
        std::copy_n(it, 81, back_inserter(m));
    }

    bool valid_row(int r)
    {
        std::set<int> used;
        for (int i = 0; i < 9; ++i)
        {
            int e = m[i + r*9];
            if (e == 0)
            {
                continue;
            }
            if (used.find(e) != used.end())
            {
                return false;
            }
            used.insert(e);
        }

        return true;
    }

    bool valid_column(int c)
    {
        std::set<int> used;
        for (int i = 0; i < 9; ++i)
        {
            int e = m[c + i*9];
            if (e == 0)
            {
                continue;
            }
            if (used.find(e) != used.end())
            {
                return false;
            }
            used.insert(e);
        }

        return true;
    }

    bool valid_square(int r, int c)
    {
        std::set<int> used;
        for (int i = r*3; i < r*3+3; ++i)
        {
            for (int j = c*3; j < c*3 + 3; ++j)
            {
                int e = m[i + j*9];
                if (e == 0)
                {
                    continue;
                }
                if (used.find(e) != used.end())
                {
                    return false;
                }
                used.insert(e);
            }
        }

        return true;
    }

    bool valid()
    {
        for (int i = 0; i < 9; ++i)
        {
            if (!valid_row(i))
            {
                return false;
            }
        }

        for (int j = 0; j < 9; ++j)
        {
            if (!valid_column(j))
            {
                return false;
            }
        }

        for (int x = 0; x < 3; ++x)
        {
            for (int y = 0; y < 3; ++y)
            {
                if (!valid_square(x, y))
                {
                    return false;
                }
            }
        }

        return true;
    }

    void solve()
    {
        solve(0);
    }

    bool solve(int p)
    {
        if (p == 81)
        {
            return true;
        }

        if (m[p] != 0)
        {
            return solve(p+1);
        }
        else
        {
            for (int i = 1; i < 10; ++i)
            {
                m[p] = i;
                if (valid())
                {
                    if (solve(p+1))
                    {
                        return true;
                    }
                }
            }
            m[p] = 0;
            return false;
        }
    }

    void print()
    {
        int p = 0;
        for (int i = 0; i < 9; ++i)
        {
            if (i != 0 && i % 3 == 0)
            {
                std::cout << std::endl;
            }
            for (int j = 0; j < 9; ++j)
            {
                if (j != 0 && j % 3 == 0)
                {
                    std::cout << " ";
                }
                std::cout << m[p++];
                std::cout << " ";
             }
            std::cout << std::endl;
        }
    }
};

int main()
{
    sudoku s ((std::istream_iterator<int>(std::cin)));

    std::cout << s.valid() << std::endl;

    s.solve();

    s.print();
    return 0;
}