from cs50 import get_string

def main():

    #loop to check if number is correct
    while True:
        number = get_string("Number: ")
        if(int(number) > 0):
            break

    #loop for implimention Luhn’s algorithm
    sum1 = 0
    for i in range((len(number) - 2), -1, -2):
        a = (int(number[i])) * 2
        b = str(a)

        #to add the digits of number
        for j in range(len(b)):
            sum1 = sum1 + int(b[j])

    sum2 = 0
    for i in range((len(number) - 1), -1, -2):
        a = (int(number[i]))
        sum2 = sum2 + a

    #total for Luhn’s algorithm
    total = sum1 + sum2

    #final check for the type of card
    i = int(number)
    if (total % 10 == 0):
        if (i >= 340000000000000 and i < 350000000000000) or (i >= 370000000000000 and i < 380000000000000):
            print("AMERICAN EXPRESS")
        elif i >= 5100000000000000 and i < 5600000000000000:
            print("MASTERCARD")
        elif (i >= 4000000000000 and i < 5000000000000) or (i >= 4000000000000000 and i < 5000000000000000):
            print("VISA")
        else:
            print("INVALID")
    else:
        print("INVALID")

if __name__ == "__main__":
    main()