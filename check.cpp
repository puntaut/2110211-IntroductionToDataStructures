#include <iostream>
#include <string>
#include <vector>

int main() {
    int n, m;
    std::cout << "How many TIMES do you want to check? ";
    std::cin >> m;
    std::cin.ignore();  // ignore leftover newline from std::cin
    std::cout << "How many LINES do you want to check? ";
    std::cin >> n;
    std::cin.ignore();  // ignore leftover newline from std::cin

    std::vector<std::string> inputs(n);
    std::string input;

    std::vector<std::string> grader_outputs(n);
    std::string grader_output;

    std::vector<std::string> my_outputs(n);
    std::string my_output;

    std::vector<int> index_list;

    std::cout << "Enter " << n << " input lines:\n";
    for (int i = 0; i < n; i++) {
        std::getline(std::cin, input);
        inputs[i] = input;
    }

    std::cout << "Enter " << n << " grader output lines:\n";
    for (int i = 0; i < n; i++) {
        std::getline(std::cin, grader_output);
        grader_outputs[i] = grader_output;
    }

    while (m--) {
        std::cout << "Enter " << n << " your output lines:\n";
        for (int i = 0; i < n; i++) {
            std::getline(std::cin, my_output);
            my_outputs.push_back(my_output);
            my_outputs[i] = my_output;
            if (my_output != grader_outputs[i]) {
                index_list.push_back(i);
            }
        }
        for (auto &i : index_list) {
            std::cout << std::endl;
            std::cout << "input: " <<  inputs[i] << std::endl;
            std::cout << "expected: " << grader_outputs[i] << std::endl;
            std::cout << "actual: " << my_outputs[i] << std::endl;
        }
        index_list.clear();
    }




    // std::cout << "\nYou entered:\n";
    // for (int i = 0; i < n; i++) {
    //     std::cout << i+1 << ": " << inputs[i] << "\n";
    // }
}
