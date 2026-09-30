#include<iostream>
#include<iomanip>
#include<numbers>
using namespace std;

int main()
{
    cout << numbers::pi << "\n";
}
// c++20 & after 提供標準函式庫numbers其中在namespace numbers中定義了許多常數可使用::來使用請記得是c++20後 在編譯時候也記得使用-std=c++20來編譯
// namespace std::numbers {
//     inline constexpr double e = 2.71828182845904523536;
//     inline constexpr double log2e = 1.44269504088896340736;
//     inline constexpr double log10e = 0.434294481903251827651;
//     inline constexpr double pi = 3.14159265358979323846;
//     inline constexpr double inv_pi = 0.318309886183790671538;
//     inline constexpr double inv_sqrtpi = 0.564189583547756286948;
//     inline constexpr double ln2 = 0.693147180559945309417;
//     inline constexpr double ln10 = 2.30258509299404568402;
//     inline constexpr double sqrt2 = 1.41421356237309504880;
//     inline constexpr double sqrt3 = 1.73205080756887729353;
//     inline constexpr double inv_sqrt3 = 0.577350269189625764509;
//     inline constexpr double egamma = 0.577215664901532860606;
//     inline constexpr double phi = 1.61803398874989484820;
// }

