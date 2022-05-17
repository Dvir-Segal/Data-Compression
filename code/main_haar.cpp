
#include "haar.hpp"
#include "haar_decode.hpp"
using namespace std;

int main() {
	int arr[8] = {1985,1931,1849,1797,1425,1419,1363,1360};
    string ans = haar_algorithm::haar_new_trasform(arr,3);
    haar_decode::haar_new_trasform_decode(ans);
	cout <<ans << endl;  
    cout <<ans.size() << endl;    
    return 0;
}