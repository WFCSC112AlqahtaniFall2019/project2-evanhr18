/***************
 * Henry Evans
 * MergeSort
 * September 19, 2019
 ***************/




#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

void mergeSort(vector<int>& a, vector<int>& tmp, int left, int right);
void mergeSortedLists(vector<int>& a, vector<int>& tmp, int left, int middle, int right);

// function declarations

int main() {

    // get input: first is random seed, second is vector length
    int seed, length;
    cin >> seed >> length;
    srand(seed);

    vector<int> v(length);  // vector to be sorted
    vector<int> t(length);  // temporary workspace
    // unit test for merge

    vector<int> trial1 = {1, 6, 7, 2};
    vector<int> trial2 = {0, 0, 0, 0};

    mergeSortedLists(trial1, trial2, 0, 2, 3);

    for(int i = 1; i < trial1.size(); i++) {
        assert(trial1.at(i-1) <= trial1.at(i));
    }

    // initialize and print input
    for(int i = 0; i < v.size(); i++) {
        v.at(i) = rand() % 100;
        cout << v.at(i) << '\t';
    }
    cout << endl;

    // sort v
    mergeSort(v, t, 0, length - 1);

    // print output
    for(int i = 0; i < v.size(); i++) {
        cout << v.at(i) << '\t';
    }
    cout << endl;

    // check output, make sure it's sorted
    for(int i = 1; i < v.size(); i++) {
        assert(v.at(i-1) <= v.at(i));
    }

    return 0;
}


void mergeSort(vector<int>& a, vector<int>& tmp, int left, int right) {

    int middle;

    if (left < right) {

        middle = (left + right) / 2;

        mergeSort(a, tmp, left, middle);
        mergeSort(a, tmp, middle + 1, right);
        mergeSortedLists(a, tmp, left, middle, right);

    }

}


void mergeSortedLists(vector<int>& a, vector<int>& tmp, int left, int middle, int right) {

    int left1;
    int right1;
    int temp1;

    left1 = left;
    right1 = middle + 1;
    temp1 = left;

    while ((left1 <= middle) && (right1 <= right)) {

        if(a.at(left1) <= a.at(right1)) {
            tmp.at(temp1) = a.at(left1);
            left1 = left1 + 1;
        }
        else {
            tmp.at(temp1) = a.at(right1);
            right1 = right1 + 1;
        }

        temp1 = temp1 + 1;

    }

    while (left1 <= middle) {

        tmp.at(temp1) = a.at(left1);
        left1 = left1 + 1;
        temp1 = temp1 + 1;

    }

    while (right1 <= right) {

        tmp.at(temp1) = a.at(right1);
        right1 = right1 + 1;
        temp1 = temp1 + 1;

    }

    for (int i = left; i <= right; i++) {
        a.at(i) = tmp.at(i);
    }

}

