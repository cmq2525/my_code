#include <iostream>
#include <string>
#include <bitset>
 
std::string decimalToBinaryBmk(int n){
    std::string binary = std::bitset<32>(n).to_string();
    return binary;
}

std::string decimalToBinary(int n){
    if(n == INT_MIN){
        return "1" + std::string(31, '0');
    }
    bool is_negative = false;
    if(n < 0){
        is_negative = true;
        n = -n;
    }
    std::string result;
    while(n){
        result += (n % 2) + '0';
        n /= 2;
    }
    reverse(result.begin(), result.end());
    if(is_negative){
        // 取反 + 1
        for(int i = 0; i < result.size(); ++i){
            if(result[i] == '1'){
                result[i] = '0';
            } else {
                result[i] = '1';
            }
        }
        int c = 1;
        for(int j = result.size() - 1; j >=0; --j){
            int num_j = result[j] - '0' + c;
            c = num_j / 2;
            result[j] = '0' + num_j % 2;
        }
        std::string one_before(32 - result.size() + c, '1');
        result = one_before + result;
    } else {
        std::string zero_before(32 - result.size(), '0');
        result = zero_before + result;
    }
    return result;
}
int countOneTest(int num){
    int count = 0;
    while(num){
        if(num == INT_MIN){
            ++count;
            break;
        }
        printf("num:[%d], binary:[%s]\n", num, decimalToBinaryBmk(num).c_str());
        num &= (num - 1);
        ++count;
    }
    return count;
}
int countOne(std::string s){
    int count = 0;
    for(char c:s){
        if(c == '1'){
            ++count;
        }
    }
    return count;
}
int main()
{
    // std::cout<< "BMK:\t\t" << decimalToBinaryBmk(-123) << std::endl;
    // std::cout<< "result:\t\t" << decimalToBinary(-123) << std::endl;
 
    // std::cout << "countOne:\t\t" << countOne(decimalToBinaryBmk(-123)) << std::endl;
    // std::cout << "test:\t\t" << countOneTest(-123) << std::endl;
    // std::cout<< "-1:" << decimalToBinaryBmk(-1) << std::endl;
    // std::cout<< "-2:" << decimalToBinaryBmk(-2) << std::endl;
    // std::cout<< "-3:" << decimalToBinaryBmk(-3) << std::endl;
    // std::cout<< "-4:" << decimalToBinaryBmk(-4) << std::endl;
    std::cout<< (-8 >> 1) <<std::endl;
    std::cout<< (-8 >> 2) <<std::endl;
    std::cout<< (-8 >> 3) <<std::endl;
    return 0;
}

