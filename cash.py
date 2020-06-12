from cs50 import get_float

def main():

    while True:
        change = get_float("Change owed: ")
        if(change >= 0):
            break

    dollar = round(change * 100)
    cents = dollar / 25
    left1 = dollar % 25

    dimes = left1 / 10
    left2 = left1 % 10

    count = int(cents) + int(dimes) + int(left2)

    print(count)

if __name__ == "__main__":
    main()