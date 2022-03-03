
#include "haar.hpp"
using namespace std;

int main() {
	int arr[8] = {1985,1931,1849,1797,1425,1419,1363,1360};
    string ans = haar_algorithm::haar_integer(arr,3);
	cout <<ans << endl;  
    cout <<ans.size() << endl;    
    return 0;
}