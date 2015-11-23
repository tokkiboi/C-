#include <iostream>

using namespace std;
int main ()
{
for (int x=0;x<5;x++)
{};
cout << x << " ";
cout << "DONE\n";
system( "read -n 1 -s -p \"Press any key to continue...\"" );
return 0;
}

