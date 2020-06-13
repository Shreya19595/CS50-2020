from cs50 import get_string

def main():
    text = get_string("Text: ")                                                                #getting a string as input

    word = 1
    sentence = 0
    letter = 0

    for i in range(len(text)):
        if (text[i] != '\0' and (text[i] >= 'a' and text[i] <= 'z') or (text[i] >= 'A' and text[i] <= 'Z')):                 #count of letter
            letter = letter + 1
        if (text[i] != '\0' and text[i] == ' ' and text[i + 1] != '\0'):                                                 #count of word
            word = word + 1
        if (text[i] != '\0' and text[i] == '.' or text[i] == '!' or text[i] == '?'):                                          #count of sentences
            sentence = sentence + 1

    L = (100 * float(letter) / float(word))
    S = (100 * float(sentence) / float(word))

    index = 0.0588 * L - 0.296 * S - 15.8                           #Calculating index value


    if (index < 16 and index >= 0):
        print(f"Grade {int(round(index))}")
    elif (index >= 16):
        print("Grade 16+")
    else:
        print("Before Grade 1")

if __name__ == "__main__":
    main()