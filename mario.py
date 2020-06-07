from cs50 import get_int

def main():

    while True:
        height = get_int("Height: ")
        if height > 0 and height <= 8:
            break

    for i in range(height):
        numhash = i + 1
        numspace = height - numhash

        print(" " * numspace, end = "")
        print("#" * numhash, end = "")
        print(" ", end = "")
        print("#" * numhash)

if __name__ == "__main__":
    main()