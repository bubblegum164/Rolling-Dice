#include <iostream>
#include <time.h>
#include <stdlib.h>
#include<math.h>

using namespace std;

int main() {

    int num;
    int times;
    int result;
    int addNum;
    int r;
    int* histNum = &num;

    double getAvg(int* h, int a, int b);
    double getStd(int* h, int a, int b);
    int getMax(int* h, int a, int b);
    int getMin(int* h, int a, int b);

    cout << "Enter in sides of die: " << endl;
    cin >> num;

    cout << "Enter in num of die: " << endl;
    cin >> addNum;

    int hist[*histNum * addNum];
         
    for (int i = 0; i <= *histNum * addNum; i++) {
        hist[i] = 0;
    }

    cout << "How many rolls? " << endl;
    cin >> times;

    for (int i = 0; i < times; i++) {
        result = 0;
        for (int j = 0; j < addNum; j++) {
            srand(i * j * time(NULL) + r);
            r = rand();
            result += r % num + 1;
        }
        cout << i << "\t" << result << endl;
        hist[result - 1] += 1;
    }

    cout << "\n--------------------\n" << endl;
    cout << "Sum\tFreq" << endl;
    for (int i = addNum - 1; i < *histNum * addNum; i++) {

        cout << i + 1 << "\t" << hist[i] << endl;

    }


    cout <<"\n--------------------\n" << endl;
    cout <<"Average is: " << getAvg(hist, addNum, num) << endl;
    cout <<"Standard Deviation is: " << getStd(hist, addNum, num) << endl;
    cout <<"\nHighest Value: " << getMax(hist, addNum, num) << endl;
    cout <<"Lowest Value: " << getMin(hist, addNum, num) << endl;
    cout <<"\n--------------------\n" << endl;

    return 0;
}

double getAvg(int* h, int a, int b) {

    double sum = 0;
    double div = 0;
    double avg = 0;

    for (int i = 0; i < a * b; i++) {
        sum += (i + 1) * *(h + i);
        div += *(h + i);
    }

    avg = sum / div;
    return avg;
}

double getStd(int* h, int a, int b) {

    double term = 0;
    double avg = getAvg(h, a, b);
    int k = 0;

    for (int i = 0; i < a * b; i++) {

        for (int j = 0; j < h[i]; j++) {
            term += pow((i + 1) - avg, 2);
            k++;
        }

    }
    double std = pow(term / k, 0.5); 
    return std;
}

int getMin(int* h, int a , int b) {

    int min = a * b;

    for (int i = a - 1; i < a * b; i++) {
        if (*(h + i) > 0 && i < min) {
            min = i + 1;
            break;
        }
    }

    return min;
}

int getMax(int* h, int a , int b) {

    int max = 0;

    for (int i = a * b; i > a - 1; i--) {
        if (*(h + i) > 0) {
            max = i + 1;
            break;
        }
    }

    return max;
}
