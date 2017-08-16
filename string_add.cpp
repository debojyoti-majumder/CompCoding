#include <string>

class Solution {
public:
    string addStrings(string num1, string num2) {
        auto num1_length = num1.length();
        auto num2_length = num2.length();
        string op1,op2, return_string("");
        auto op_size = num1_length;

        if( num1_length > num2_length ) {
            op1 = num1;
            op2="";

            // Appending zeros
            for(int i=0; i<num1_length - num2_length; i++)
                op2 += "0";

            op2 += num2;
        }
        else {
            op1 = num2;
            op2="";

            // Appending zeros
            for(int i=0; i<num2_length - num1_length; i++)
                op2 += "0";

            op2 += num1;
        }

        int carry = 0;

        for( int i=op1.length()-1; i>=0; i-- ) {
            int x = op1[i] - 48;
            int y = op2[i] - 48;
            
            int add = x+y+carry;

            if( add >= 10 ) {
                carry = 1;
                add = add - 10;
            }
            else
                carry = 0;

            return_string = to_string(add) + return_string;
        }

        if( carry == 1 )
            return_string = "1" + return_string;

        return return_string;
    }
};
