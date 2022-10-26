#include <exception>
#include <stdexcept> // rt error..
using namespace std;

int main() {
    try {
        throw runtime_error("test rt err")
        throw string("...");
        throw ("Const char s")
    } catch (runtime_error rte) {

    } catch (exception e) {

    } catch (string s) {
        //
    }
    catch (const char  *msg) {
    }
}
