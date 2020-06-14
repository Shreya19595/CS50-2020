from sys import argv, exit
import csv

#function for finding max number of repetition of each sub string present in csv file
def max_num(s, sub):

    ans = [0] * len(s)

    for i in range((len(s)-len(sub)), -1, -1):
        if s[i : i + len(sub)] == sub:
            if (i + len(sub) > len(s) - 1):   #checks if sub string's length is not more than length of main string
                ans[i] = 1
            else:
                ans[i] = 1 + ans[i + len(sub)]    #stores repetition in an array
    return max(ans)                            #returns max number of repetition

#function to match the DNA with the person
def match(reader, actual):

    for line in reader:
        person = line[0]
        value = [int(val) for val in line[1:]]  #using the concept of list comprehension
        if value == actual:                     #comparing with each value in the csv file
            print(person)
            return

    print("No match")

def main():

    #checking for command line arguments
    if (len(argv) < 3):
        print("Usage: python dna.py data.csv sequence.txt")
        exit(1)

    #open csv file, storing it as a dict
    csv_path = argv[1]
    with open(csv_path) as csv_file:
        reader = csv.reader(csv_file)
        first_row = next(reader)[1:]

        # open text file
        txt_path = argv[2]
        with open(txt_path) as txt_file:
            s = txt_file.read()
            actual = [max_num(s, seq) for seq in first_row]

        #matches and gives output of the person with matching DNA
        match(reader, actual)

if __name__ == "__main__":
    main()