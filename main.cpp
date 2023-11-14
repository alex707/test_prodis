//
//  main.cpp
//  Prodis_testing
//
//  Created by liveafun on 12.11.2023.
//

#include <iostream>
#include <sstream>
#include <cmath>
#include <numeric>

using namespace std;

class Animal {
public:
    int kind, weight, heigth, wingspan;
    string name;

    Animal(vector<string> &v) {
        kind = stoi(v[0]);
        name = v[1];
        weight = stoi(v[2]);
        heigth = stoi(v[3]);

        if(kind == 1) {
            wingspan = stoi(v[4]);
        }
    }
    
    double weight_index() {
        return (double)this->weight / (double)pow(this->heigth, 2);
    }
};


double median(vector<int> &v) {
    unsigned long n = v.size();
    if(n % 2 == 0) {
        nth_element(v.begin(), v.begin() + (n / 2), v.end());
        nth_element(v.begin(), v.begin() + (n - 1) / 2, v.end());

        return (double)(v[(n - 1) / 2] + v[n / 2]) / 2.0;
    } else {
        nth_element(v.begin(), v.begin() + (n / 2), v.end());
        
        return (double)(v[n / 2]);
    }
}

double median(vector<double> &v) {
    unsigned long n = v.size();
    if(n % 2 == 0) {
        nth_element(v.begin(), v.begin() + (n / 2), v.end());
        nth_element(v.begin(), v.begin() + (n - 1) / 2, v.end());

        return (double)(v[(n - 1) / 2] + v[n / 2]) / 2.0;
    } else {
        nth_element(v.begin(), v.begin() + (n / 2), v.end());
        
        return (double)(v[n / 2]);
    }
}

//enter total count: 5
//enter data: 0 k 2000 40
//enter data: 1 si 20 15 25
//enter data: 0 sl 3500000 320
//enter data: 1 d 80 45 45
//enter data: 0 m 400 120

int main(int argc, const char * argv[]) {

    // recieve count
    int input_count;
    cout << "enter total count: ";
    cin >> input_count;
    cin.ignore();
    
    // recieve data
    vector<string> string_array;
    for(int i = 0; i < input_count; i++) {
        string local_string;
        cout << "enter data: ";
        std::getline(cin, local_string);
        string_array.push_back(local_string);
    }
    
    
    // parse data
    vector<vector<string>> parsed_arr;
    for(int i = 0; i < input_count; i++) {
        vector<string> parsed_data;
        stringstream ss(string_array[i]);
        string temp_string;
        while(getline(ss, temp_string, ' ')){
            parsed_data.push_back(temp_string);
        };

        parsed_arr.push_back(parsed_data);
    }
    
    // build records
    vector<Animal> records;
    for(int i = 0; i < parsed_arr.size(); i++) {
        Animal record(parsed_arr[i]);
        records.push_back(record);
    }
    
    // aggrigate
    vector<double> BMIs;
    vector<int> wingspans;
    for(int i = 0; i < records.size(); i++) {
        cout << "wi:" << records[i].weight_index() << "\n";
        BMIs.push_back(records[i].weight_index());
        if(records[i].kind == 1) {
            wingspans.push_back(records[i].wingspan);
        }
    }
    sort(BMIs.begin(), BMIs.end());
    sort(wingspans.begin(), wingspans.end());
    
    // calculate
    double average_BMIs = accumulate(BMIs.begin(), BMIs.end(), 0.0) / (double)BMIs.size();
    double median_BMIs = median(BMIs);
    double median_wingspans = median(wingspans);
    
    // view
    cout << "average BMI: " << average_BMIs << "\n";
    cout << "median BMIs: " << median_BMIs << "\n";
    cout << "median wingspans: " << median_wingspans << "\n";
    
    return 0;
}
