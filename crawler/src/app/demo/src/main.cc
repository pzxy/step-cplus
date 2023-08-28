#include <iostream>
#include <iterator>
#include <algorithm>
#include <boost/lambda/lambda.hpp>
#include <string>
using namespace std;

int main() {
    using namespace boost::lambda;
    typedef std::istream_iterator<int> in;
    string s = R"(asd)";
    cout << s << endl;
    std::for_each(
            in(std::cin), in(), std::cout << (_1 * 3) << " ");

}
// g++ -v -I/opt/homebrew/Cellar/boost/1.82.0_1/include -L/opt/homebrew/Cellar/boost/1.82.0_1/lib file