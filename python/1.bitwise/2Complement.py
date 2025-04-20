def OneComplement(c):
    return "1" if (c == '0') else "0"


def main():
    num =  str(input("Enter a binary integer: "))
    ones = ''
    for n in num:
        ones += OneComplement(n)

    print("1's Complements is: ", ones)


    twos = ''
    carry = 1
    for i in range(len(num)-1, -1, -1):
        if (ones[i] == "0" and carry == 1):
            twos += '1'
        elif (ones[i] == '1' and carry == 1):
            twos += '0'
            carry = 0
        else:
            twos += ones[i]

    print("2's Complements is: ", twos[::-1])


main()