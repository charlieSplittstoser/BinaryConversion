#include <iostream>
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

string convertToBinary(int number);
string displayAsBinary(string number);
string displayAsOctal(string number);
string displayAsHex(string number);
unsigned int displayAsDecimal(string number);
void addition(string number, string number2);
const int NUMBER = 50; //Number used throughout the program
const int NUMBER2 = 50; //Second number used at the end of the program for addition

int main() {
    cout << "Original Number: " << NUMBER << endl;
    string num = convertToBinary(NUMBER);
    string num2 = convertToBinary(NUMBER2);
    cout << "Binary Value: " << displayAsBinary(num) << endl;
    cout << "Octal Value: " << displayAsOctal(num) << endl;
    cout << "Hex Value: " << displayAsHex(num) << endl;
    cout << "Decimal Value: " << displayAsDecimal(num) << endl;
    addition(num, num2);
    return 0;
}

/*
 * Function purpose: Converts a given base 10 number into it's binary form.
 * int number -> the number that we want to convert;
 * n = the string that we are building.
 */
string convertToBinary(int number) {
    
    string n = "";
    
    for (int i = 31; i >= 0; i--) {
        n = static_cast<char>(number % 2 + '0') + n;
        number /= 2;
    }
    
    return n;
}

/*
 * Function purpose: Simply return the binary number that was previously converted.
 */
string displayAsBinary(string number) {
    
    return number;
}

/*
 * Function purpose: Convert the binary number  into it's octal representation
 * string number -> the 32 bit binary number we are converting from
 * octBitValues -> octal numbers that correspond to 1-7
 * string oct -> used to build and display the octal number
 * string num -> used to store the 3 bit octal values
 */
string displayAsOctal(string number) {
    
    string octBitValues[8] = {"000", "001", "010", "011", "100", "101", "110", "111"};
    number = '0' + number;
    string num = "";
    string oct = "";
    
    for (int i = 30; i >= 0; i -= 3) {
        num = number.substr(i, 3);
        for (int j = 0; j < 8; j++) {
            if (num == octBitValues[j])
                oct = static_cast<char>(j + '0') + oct;
        }
    }
    return oct;
}

/*
 * Function purpose: Convert binary number to hex number
 * string number -> the 32 bit binary number we are converting from
 * string num -> used to store the 4 bit values and compare them to hex values
 * char array hexValues -> Used to store hex values
 * string array hexBitValues -> used to store bit values of the corresponding hex numbers
 * int hex -> used to build and return the hex number
 */
string displayAsHex(string number) {
    
    char hexValues[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    string hexBitValues[16] = {"0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111", "1000",
        "1001", "1010", "1011", "1100", "1101", "1110", "1111"};
    string num = "";
    string hex = "";
    
    for (int i = 28; i >= 0; i -= 4) {
        num = number.substr(i, 4);
        for (int j = 0; j < 16; j++) {
            if (num == hexBitValues[j])
                hex = hexValues[j] + hex;
        }
    }
    
    return hex;
}

/*
 * Function purpose: Converts the given binary number into it's decimal representation
 * String number == 32 bit representation
 * int power is used for: 2^power
 * int dec is used to build and return the decimal value
 */
unsigned int displayAsDecimal(string number) {
    
    unsigned int dec = 0;
    int power = 0;
    
    for (int i = 31; i >= 0; i--) {
        if (number[i] == '1')
            dec += pow(2, power);
        power++;
    }
    return dec;
}

/*
 * Function purpose: Adds the binary numbers number1 and number 2 together
 * int array num1 & num2 -> used to store the two values we are adding
 * int carry -> used to store the remainder
 * int array result -> used to store the addition result
 */
void addition(string number, string number2) {
    cout << "Addition: " << endl
    << number << endl
    << "+" << endl
    << number2 << endl;
    
    int num1[32] = {0};
    int num2[32] = {0};
    int result[32] = {0};
    int carry = 0;
    
    for (int i = 0; i < 32; i++) {
        num1[i] = number[i] - '0';
        num2[i] = number2[i] - '0';
    }
    
    for (int j = 31; j >= 0; j--) {
        result[j] = carry + num1[j] + num2[j];
        if (result[j] >= 2) {
            result[j] -= 2;
            carry = 1;
        } else
            carry = 0;
    }
    
    result[0] = carry;
    cout << "=" << endl;
    
    for (int k = 0; k < 32; k++)
        cout << result[k];
    
    cout << endl << NUMBER << " + " << NUMBER2 << " = " << NUMBER + NUMBER2 << endl;
}
