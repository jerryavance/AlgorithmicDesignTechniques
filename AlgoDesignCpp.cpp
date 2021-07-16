/* 
// SUM OF TWO DIGITS (MY SOLUTION)
#include <iostream>
using namespace std;

int main()
{
	int a = 0;
	int b = 0;
	cin >> a;
	cin >> b;
	cout << a + b;
	return 0;
}
*/


/*
//MAXIMUM PAIRWISE PRODUCT (MY NAIVE SOLUTION 1 )
#include <iostream>
#include <new>
using namespace std;

int main()
{
	int product = 0;
	int * arr;
	int num;
	cin >> num;
	arr = new (nothrow) int[num];
	if (arr == nullptr) {
		cout << "we got an error\n";
	}	
	else {
		for (int n = 0; n < num; n++) {
			cin >> arr[n];
		}
	}
	for (int i = 0; i < num; i++) {
		int j = i + 1;
		for (j ; j < num; j++) {
			if (arr[i] * arr[j] > product) {
				product = arr[i] * arr[j];
			}
		}
	}
	delete[] arr;
	cout << product;
	return 0;
}
*/


/* 
//MAXIMUM PAIRWISE PRODUCT (MY NAIVE SOLUTION 2)
#include <iostream>
#include <vector>
using std::cout;
using std::cin;
using std::vector;

int MaxPairwiseProduct(const vector<int>& some);

int main()
{
	int n;
	cin >> n;
	vector<int> numbers(n);
	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
	}
	int result = MaxPairwiseProduct(numbers);
	cout << result ;
	return 0;

}

int MaxPairwiseProduct(const vector<int>& some) {
	int product = 0;
	int n = some.size();
	for (int i = 0; i < n; i++) {
		for (int j = i+1 ; j < n; j++) {
			if (some[j] * some[i] > product) {
				product = some[j] * some[i];
			}
		}
	}
	return product;
}

*/


/*
//MAXIMUM PAIRWISE PRODUCT FINAL (final work with stress tests) 
#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::cin;
using std::cout;
using std::endl;

int MaxPairwiseProduct(const vector<int>& numbers);
int MaxPairwiseProductFast(vector<int>& numbers);
int StressTest(int N, int M);


int main() {
	
	//int n;
	//cin >> n;
	//vector<int> numbers(n);
	//for (int i = 0; i < n; ++i) {
		//cin >> numbers[i];
	//}
	
	//int result1 = MaxPairwiseProduct(numbers);
	//cout << "MaxPairwiseProduct:  " << result1 << "\n";
	//int result2 = MaxPairwiseProductFast(numbers);
	//cout << "MaxPairwiseProductFast:  " << result2 << "\n";
	
	
	//int N = 1000, M = 200000;
	int N = 10, M = 100000;
	StressTest(N, M);
	return 0;
}



int MaxPairwiseProduct(const vector<int>& numbers) {
	int result = 0;
	int n = numbers.size();
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (numbers[i] * numbers[j] > result) {
				result = numbers[i] * numbers[j];
			}
		}
	}
	return result;
}


int MaxPairwiseProductFast(vector<int>& numbers)
{
	int num = numbers.size();
	
	//for (int i = 0; i < num; i++) {
		//cin >> numbers[i];
	//}

	int max1 = numbers[0];
	int indexmax1 = -1;
	int finalindex1 = 0;
	for (int j = 0; j < num; j++) {
		indexmax1++;
		if (numbers[j] > max1) {
			max1 = numbers[j];
			finalindex1 = indexmax1;
		}
	}

	int max2;
	if (max1 == numbers[0]) {
		max2 = numbers[1];
	}
	else {
		max2 = numbers[0];
	}

	int indexmax2 = -1;
	for (int k = 0; k < num; k++) {
		indexmax2++;
		if (numbers[k] > max2 && finalindex1 != indexmax2) {
			max2 = numbers[k];
		}
	}

	int result = max1 * max2;
	return result;
}


int StressTest(int N, int M) {
	while (true) {
		//srand((unsigned)time(NULL));
		int random1 = rand() % (N - 2) + 2;
		vector<int> arr(random1);

		for (int i = 0; i < random1; i++) {
			arr[i] = (rand() % (M-1)) +1 ;
		}

		/*
		for (int j = 0; j < random1; j++) {
			int use = rand() % M;
			arr[j] = use;
		}
		

		cout << "[ ";
		for (int k = 0; k < random1; k++) {
			cout << " " << arr[k] << " ";
		}
		cout << " ]\n";

		int result1 = MaxPairwiseProduct(arr) ;
		int result2 = MaxPairwiseProductFast(arr) ;

		if (result1 == result2) {
			cout << "OK" << endl;
		}
		else {
			cout << "Wrong answer " << result1 << " " << result2 << endl;
			break;
		}
	}
	return 0;
	
}
*/


/* 
//FIBONACCI NUMBERS RECURSIVE SOLUTION
#include <iostream>
using namespace std;

int FibRecur(int n);
int main()
{
	int ans;
	int n;
	cin >> n;
	ans = FibRecur(n);
	cout << ans << endl;
	return 0;
}

int FibRecur(int n) {
	if (n <= 1) {
		return n;
	}
	else {
		return FibRecur(int (n - 1)) + FibRecur(int (n - 2));
	}
}
*/


/* 
//FIBONACCI NUMBERS RECURSIVE SOLUTION
#include <iostream>
#include <vector>
using std::vector;
using namespace std;

int FibonacciFast(int n);

int main()
{
	int n;
	int answer;
	cin >> n;
	answer = FibonacciFast(n);
	cout << answer << endl;
	return 0;
}

int FibonacciFast(int n) {
	vector<int> use (n+1);
	use[0] = 0; use[1] = 1;
	for (int i = 2; i <= n; i++) {
		use[i] = use[i - 1] + use[i - 2];
	}
	return use[n];
}

*/


/* 
#include <iostream>
#include <cassert>
#include <vector>
#include <new>
using std::vector;
using namespace std;

// The following code calls a naive algorithm for computing a Fibonacci number.
//
// What to do:
// 1. Compile the following code and run it on an input "40" to check that it is slow.
//    You may also want to submit it to the grader to ensure that it gets the "time limit exceeded" message.
// 2. Implement the fibonacci_fast procedure.
// 3. Remove the line that prints the result of the naive algorithm, comment the lines reading the input,
//    uncomment the line with a call to test_solution, compile the program, and run it.
//    This will ensure that your efficient algorithm returns the same as the naive one for small values of n.
// 4. If test_solution() reveals a bug in your implementation, debug it, fix it, and repeat step 3.
// 5. Remove the call to test_solution, uncomment the line with a call to fibonacci_fast (and the lines reading the input),
//    and submit it to the grader.

int fibonacci_naive(int n) {
	if (n <= 1)
		return n;

	return fibonacci_naive(n - 1) + fibonacci_naive(n - 2);
}

int fibonacci_fast(int n) {
	// write your code here
	if (n <= 1) {
		return n;
	}
	else {
		vector<int> number(n + 1);
		number[0] = 0;
		number[1] = 1;
		for (int i = 2; i < n + 1; i++) { number[i] = (number[i - 1] + number[i - 2]); }
		return number.back();
	}
	//return 0;
}

void test_solution() {
	assert(fibonacci_fast(3) == 2);
	assert(fibonacci_fast(10) == 55);
	for (int n = 0; n < 20; ++n)
		assert(fibonacci_fast(n) == fibonacci_naive(n));
}

int main() {
	int n = 0;
	std::cin >> n;

	std::cout << "naive: " << fibonacci_naive(n) << '\n';
	//test_solution();
	std::cout << "fast: " << fibonacci_fast(n) << '\n';
	return 0;
}

*/


/* 
//LAST DIGIT OF FIBONACCI
#include <iostream>
#include <vector>
using std::vector;
using namespace std;

int get_fibonacci_last_digit_naive(int n) {
	if (n <= 1)
		return n;

	int previous = 0;
	int current = 1;

	for (int i = 0; i < n - 1; ++i) {
		int tmp_previous = previous;
		previous = current;
		current = tmp_previous + current;
	}

	return current % 10;
}

int get_fibonacci_last_digit_fast(int n) {
	if (n <= 1) {
		return n;
	}
	else {
		vector<int> number(n + 1);
		number[0] = 0;
		number[1] = 1;
		for (int i = 2; i < n + 1; i++) { number[i] = ((number[i - 1] + number[i - 2]) % 10); }
		return number.back();
	}
}

int main() {
	int n;
	std::cin >> n;
	int c = get_fibonacci_last_digit_naive(n);
	std::cout << "naive: " << c << '\n';

	int d = get_fibonacci_last_digit_fast(n);
	std::cout << "fast: " << d << '\n';

}
*/


/* 
//----------------------------------------------------------------------------------------------
// Part A
//GCD NAIVE WHICH ITERATES OVER ALL POSSIBLE VALUES
#include <iostream>
using namespace std;

int GCD(int a, int b);
int main()
{
	int a = 0, b = 0;
	cin >> a >> b;
	int res = GCD(a, b);
	cout << res;
	return 0;
}

int GCD(int a, int b) {
	int best = 0;

	for (int i = 1; i < (a + b) ; i++) {
		if ((a % i == 0) && (b % i == 0)) { best = i; }
	}
	return best;
}

//Part B
//SMART GCD WHICH UTILIZES LEMMA AND EUCLID METHOD
#include <iostream>
using namespace std;

int EuclidGCD(int a, int b);

int main()
{
	int a, b;
	cin >> a >> b;
	int answer = EuclidGCD(a, b);
	cout << answer << endl;
	return 0;
}

int EuclidGCD(int a, int b) {
	if (b == 0) { return a; }
	int aPrime = a % b;
	return EuclidGCD( b, aPrime);
}
//-----------------------------------------------------------------------------------------
*/


/*
// -----------------------------------------------------------------------------------------
//LCM USING GCD
#include <iostream>
using namespace std;

int EuclidGCD(int a, int b);
int LCM_using_gcd(int a, int b);

int main()
{
	int a, b;
	cin >> a >> b;
	int64_t lcm = LCM_using_gcd( a, b);
	cout << lcm;
	return 0;
}

int EuclidGCD(int a, int b) {
	if (b == 0) { return a; }
	int64_t aPrime = a % b;
	return EuclidGCD(b, aPrime);
}

int LCM_using_gcd(int a, int b) {
	int64_t gcd = EuclidGCD(a, b);
	int64_t x = (int64_t)a;
	int64_t y = (int64_t)b;
	int64_t lcm = (x*y) / gcd;
	return lcm;
}
//-------------------------------------------------------------------------------------------------
*/


/* 
//CODE NOT OPTIMIZED FOR VERY LARGE VALUES OF FIBONACCI...DO NOT USE
#include <iostream>
#include <vector>
using namespace std;

int fibonacci_fast(int64_t n);
int get_fibonacci_huge(int64_t n, int64_t m);
long pisano(int64_t m);

int main()
{
	int64_t n, m;
	cin >> n >> m;
	//int64_t result = get_fibonacci_huge(n, m);
	cout << "return from main : " << get_fibonacci_huge(n, m) << endl;
	//cout << result << " " << endl;
	return 0;
}

int fibonacci_fast(int64_t n) {
	// write your code here
	if (n <= 1) {
		return n;
	}
	else {
		vector<int64_t> number(n + 1);
		number[0] = 0;
		number[1] = 1;
		for (int64_t i = 2; i < n + 1; i++) { number[i] = (number[i - 1] + number[i - 2]); }
		return number.back();
		
	}
	//return 0;
}

long pisano(int64_t m) {
	int64_t prev = 0;
	int64_t curr = 1;
	int64_t res = 0;
	for (int64_t i = 0; i < m * m; i++) {
		int64_t temp = 0;
		temp = curr;
		curr = (prev + curr) % m;
		prev = temp;
		if (prev == 0 && curr == 1) {
			res = i + 1;
		}

	}
	cout << "return from pisano: " << res << endl; 
	return res;
}

int get_fibonacci_huge(int64_t n, int64_t m) {
	int64_t numModulo8 = n % pisano(m);
	int64_t newnum = fibonacci_fast(numModulo8);
	int64_t answer = newnum % m;
	return answer;
	//return fibonacci_fast(numModulo8) % m;
}

*/

///***************************************************************************

#include <iostream>
#include <vector>

using std::vector;

long long get_fibonacci_huge_naive(long long n, long long m) {
	if (n <= 1) return n;

	long long previous = 0;
	long long current = 1;

	for (long long i = 0; i < n - 1; ++i) {
		long long tmp_previous = previous;
		previous = current;
		current = tmp_previous + current;
	}

	return current % m;
}

long long get_fibonacci_huge(long long n, long long m) {
	if (n <= 1) return n;

	long long previous = 0;
	long long current = 1;
	long long tmp_previous = 0;

	vector<long> pisano;
	pisano.push_back(0);
	pisano.push_back(1);

	while (true) {
		tmp_previous = previous;
		previous = current;
		current = (tmp_previous + current) % m;
		if (current == 1 and previous == 0) {
			break;
		}
		else {
			pisano.push_back(current);
		}
	}
	pisano.pop_back();
	long index = n % pisano.size();
	return pisano.at(index);
}

int main() {
	long long n, m;
	std::cin >> n >> m;
	// std::cout << get_fibonacci_huge_naive(n, m) << '\n';
	std::cout << get_fibonacci_huge(n, m) << '\n';
}











































































