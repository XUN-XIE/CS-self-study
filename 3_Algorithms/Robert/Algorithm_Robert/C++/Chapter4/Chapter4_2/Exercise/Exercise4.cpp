#include "../Digraph.hpp"

int main()
{
    Digraph DG("../tinyDG.txt");
    cout << DG.PathTo( 1, 9 ) << endl;
    cout << DG.PathTo( 2, 5 ) << endl;
}