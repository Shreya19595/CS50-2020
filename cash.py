from cs50 import get_float

def main():

    while True:
        change = get_float("Change owed: ")
        if(change >= 0):
            break

    dollar = round(change * 100)

    quarters = int(dollar / 25)
    left1 = dollar % 25

    dimes = int(left1 / 10)
    left2 = left1 % 10

    nickels = int(left2 / 5)
    left3 = left2 % 5

    count = int(quarters) + int(dimes) + int(nickels) + int(left3)

    print(count)

if __name__ == "__main__":
    main()