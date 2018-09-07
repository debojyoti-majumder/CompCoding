#include <iostream>
#include <string>
#include <tuple>

using namespace std;

// Use this instead of typedefs
using UserInfromation = tuple<string, string, int>;

enum class UiInformationField {Name, Email, Rating};

int main(int argc, char const *argv[]) {
    // This does not look good
    tuple<string, string, int> userInfo = make_tuple("Deb", "debojyoti.majumder@harman.com", 8);
    cout << "User name is:" << get<0>(userInfo) << endl;

    // Comparatively better but still using hardcoded string is not good
    UserInfromation cppInfo = make_tuple("CppProg", "kindof@harman.com", 9);
    cout << "User name is:" << get<0>(cppInfo) << endl;

    // Better than the other two
    UserInfromation developer = make_tuple("goodProgrammer", "progammer@google.com", 10);
    cout << "User name is " << get<static_cast<size_t>(UiInformationField::Name)>(developer);
    return 0;
}
