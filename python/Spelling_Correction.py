from textblob import TextBlob

# Function to convert a string into a list of words
def convert_string_to_list(input_string):
    # Split the input string into words based on spaces and return as a list
    word_list = list(input_string.split())
    return word_list

# Function to correct the spelling of words in a list
def correct_spelling(words):
    corrected_words = []  # Initialize an empty list to store corrected words
    for word in words:
        # Create a TextBlob object for each word and correct its spelling
        corrected_word = TextBlob(word).correct()
        corrected_words.append(corrected_word)  # Append corrected word to the list
    return corrected_words

# Main function to execute the program
def main():
    # Prompt the user to enter a string of words
    user_input = input("Enter your words (separated by spaces): ")
    
    # Convert the input string into a list of words
    words = convert_string_to_list(user_input)
    
    # Display the original words entered by the user
    print("Original words:", words)
    
    # Correct the spelling of the words
    corrected_words = correct_spelling(words)
    
    # Display the corrected words
    print("Corrected words are:")
    for word in corrected_words:
        print(word, end=" ")
    print()  # Print a newline for better formatting

# Execute the main function
if __name__ == "__main__":
    main()
