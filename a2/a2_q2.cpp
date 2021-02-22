using namespace std;
#include <iostream>
#include <cmath> //imported cmath library because I need to use powers

/*Write a program that outputs distance ball has fallen each 1-second interval for the first 30 seconds*/

/*I utilized the distance equation with various times such as 15,17,18 (calculation matches program output)
For step 2 I checked the specific t value for 15000m distance, which was 55.3095 seconds, meaning the program output was accurate

The max and min values of the float variables are min: 1.17549e-038 max: 3.40282e+038 and int is min: -2147483648 max: 2147483647 */


void increasedrestable(float seconds, float distanceperinterval, float totaldist, float GRAVITY, int HEIGHT) {
	float second = seconds + 1;
	seconds += 0.1; //+=0.1 because the for loop starts at 55.000 which screws up the increments (there will be 2 55.000 intervals)
	for (seconds; seconds <= second; seconds += 0.1) {

		distanceperinterval = (0.5) * GRAVITY * pow(seconds, 2) - (0.5) * GRAVITY * pow(seconds - 0.1, 2); //Follows same logic for the other for loop, just that the increments are in 0.1s now

		cout << seconds << "    " << distanceperinterval << "    " << (totaldist += distanceperinterval) << endl;

	}
}


void intervaltable(float seconds, float distanceperinterval, float totaldist, float GRAVITY, int HEIGHT) {
	cout << "Time (s):    " << "Distance during interval (m):    " << "Total Distance (m):" << endl;
	for (seconds = 0; seconds <= 70; seconds++) {
		//distanceperinterval 
		if (seconds > 0) { //Calculation for distanceperinterval is only possible if seconds is greater than 1 (so it isnt negative)
			distanceperinterval = (0.5) * GRAVITY * pow(seconds, 2) - (0.5) * GRAVITY * pow(seconds - 1, 2); //Determines the m travelled in 1 sec interval by finding the difference between total distance travelled in x seconds with m travelled in x-1 seconds
		}

		cout << seconds << "    " << distanceperinterval << "    " << (totaldist += distanceperinterval) << endl;

		if ((0.5) * GRAVITY * pow(seconds + 1, 2) >= HEIGHT) { //If the total distance of the next second is greater than 15, itll stop and move to another for loop with the greater resolution
			increasedrestable(seconds, distanceperinterval, totaldist, GRAVITY, HEIGHT); // If there is a way to manipulate the increments of a for loop idk how, I believe that making another for loop is the only way 
			break;
		}

	}


}


void a2q2function() {
	//STEP 1. Initialize variables
	//All are floats because in entire question they will all decimal places 
	float seconds = 0;
	float distanceperinterval = 0;
	float totaldist = 0;
	float GRAVITY = 9.80665;
	int HEIGHT = 15000;

	//STEP 2 and 3. Calculate and Output Values (need to calculate then output continuously to show all intervals without using an array)
	
	intervaltable(seconds, distanceperinterval, totaldist, GRAVITY, HEIGHT);
	
}

int main()
{
	cout.setf(ios::fixed);
	cout.precision(3);
	a2q2function();

}
//Distance = ½ g t^2

/* Output from q2 step 2
Time (s):    Distance during interval (m):    Total Distance (m):
0.000    0.000    0.000
1.000    4.903    4.903
2.000    14.710    19.613
3.000    24.517    44.130
4.000    34.323    78.453
5.000    44.130    122.583
6.000    53.937    176.520
7.000    63.743    240.263
8.000    73.550    313.813
9.000    83.357    397.169
10.000    93.163    490.333
11.000    102.970    593.302
12.000    112.776    706.079
13.000    122.583    828.662
14.000    132.390    961.052
15.000    142.196    1103.248
16.000    152.003    1255.251
17.000    161.810    1417.061
18.000    171.616    1588.677
19.000    181.423    1770.100
20.000    191.230    1961.330
21.000    201.036    2162.366
22.000    210.843    2373.209
23.000    220.650    2593.859
24.000    230.456    2824.315
25.000    240.263    3064.578
26.000    250.070    3314.648
27.000    259.876    3574.524
28.000    269.683    3844.207
29.000    279.490    4123.697
30.000    289.296    4412.993
31.000    299.103    4712.096
32.000    308.909    5021.006
33.000    318.716    5339.722
34.000    328.523    5668.245
35.000    338.329    6006.575
36.000    348.136    6354.711
37.000    357.943    6712.654
38.000    367.749    7080.403
39.000    377.556    7457.959
40.000    387.363    7845.322
41.000    397.169    8242.491
42.000    406.976    8649.467
43.000    416.783    9066.249
44.000    426.589    9492.838
45.000    436.396    9929.233
46.000    446.203    10375.436
47.000    456.009    10831.444
48.000    465.816    11297.260
49.000    475.623    11772.882
50.000    485.429    12258.311
51.000    495.236    12753.547
52.000    505.042    13258.590
53.000    514.849    13773.439
54.000    524.656    14298.096
55.000    534.462    14832.559
55.100    53.985    14886.544
55.200    54.083    14940.627
55.300    54.182    14994.810
55.400    54.280    15049.090
55.500    54.378    15103.469
55.600    54.475    15157.944
55.700    54.574    15212.519
55.800    54.672    15267.190
55.900    54.770    15321.960
56.000    54.868    15376.828

Thus, from the program, it will take about 55.3-55.4 seconds for the ball to reach the ground

*/